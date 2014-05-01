#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>
#include <bb/cascades/GroupDataModel>

#include <QHostAddress>

#include "TicTacService.hpp"

#include "LoginViewModel.hpp"
#include "MainViewModel.hpp"

#include "ViewState.hpp"

using namespace bb::cascades;

ApplicationUI::ApplicationUI(bb::cascades::Application *app) : QObject(app)
{
    qRegisterMetaType<GroupDataModel*>("GroupDataModel*");

    qmlRegisterType<ViewState>("enums", 1, 0, "ViewState");

    TicTacService *service = new TicTacService(this);
    service->connectToHost(QHostAddress("192.168.0.247"), 1337);

    LoginViewModel* loginVM = new LoginViewModel(service, this);
    MainViewModel* mainVM = new MainViewModel(service, this);

    // prepare the localization
    m_pTranslator = new QTranslator(this);
    m_pLocaleHandler = new LocaleHandler(this);
    if(!QObject::connect(m_pLocaleHandler, SIGNAL(systemLanguageChanged()), this, SLOT(onSystemLanguageChanged()))) {
        // This is an abnormal situation! Something went wrong!
        // Add own code to recover here
        qWarning() << "Recovering from a failed connect()";
    }
    // initial load
    onSystemLanguageChanged();

    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
    qml->setContextProperty("mainVM", mainVM);
    qml->setContextProperty("loginVM", loginVM);

    // Create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();

    // Set created root object as the application scene
    app->setScene(root);
}

void ApplicationUI::onSystemLanguageChanged()
{
    QCoreApplication::instance()->removeTranslator(m_pTranslator);
    // Initiate, load and install the application translation files.
    QString locale_string = QLocale().name();
    QString file_name = QString("TicTacTen_%1").arg(locale_string);
    if (m_pTranslator->load(file_name, "app/native/qm")) {
        QCoreApplication::instance()->installTranslator(m_pTranslator);
    }
}
