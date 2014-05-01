import bb.cascades 1.0
import bb.system 1.0
import enums 1.0

NavigationPane {
    id: navigation
    
    Page {
        titleBar: TitleBar {
            title: qsTr("Players");
        }
        
        Container {
            background: Color.create("#dcd8c3")
            layout: DockLayout { }
            
            ListView {
                dataModel: mainVM.playerModel
                verticalAlignment: VerticalAlignment.Fill
                horizontalAlignment: HorizontalAlignment.Fill
                listItemComponents: [
                    ListItemComponent {
                        type: 'item'
                        
                        StandardListItem {
                            title: ListItemData.name
                        }            
                    }
                ]
                
                onTriggered: {
                    var item = dataModel.data(indexPath);
                    
                    mainVM.challenge(item.id);
                    
                    var page = board.createObject();                    
                    navigation.push(page);
                }
            }
            
            Container {
                id: emptyState
                visible: mainVM.state == ViewState.DEFAULT && mainVM.playerModel.isEmpty()
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                
                ImageView {
                    imageSource: "asset:///images/tictactoe_big.png"
                    horizontalAlignment: HorizontalAlignment.Center
                }
                
                Label {
                    text: qsTr("No players to play with...")
                    horizontalAlignment: HorizontalAlignment.Center
                    textStyle.fontSize: FontSize.XLarge
                }
            }
            
            Container {
                id: loadingState
                visible: mainVM.state == ViewState.LOADING
                verticalAlignment: VerticalAlignment.Fill
                horizontalAlignment: HorizontalAlignment.Fill
                layout: DockLayout { }
                
                ActivityIndicator {
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                    preferredWidth: 200
                    preferredHeight: 200
                    running: true
                }
            }
        }
        
        onCreationCompleted: {
            login.open();
            
            mainVM.playerChallenged.connect(showAlert);
        }
        
        function showAlert(id, name) {
            challengeDialog.body = name + " challenged you with a game of Tic Tac Toe.";
            
            challengeDialog.show();
        }
        
        attachedObjects: [
            Login {
                id: login
            },
            ComponentDefinition {
                id: board
                source: "asset:///Board.qml"
            },
            SystemDialog {
                id: challengeDialog
                title: "Wanna play a game?"
                onFinished: {
                    if (challengeDialog.result == SystemUiResult.CancelButtonSelection) {
                        // Send a CHALA response
                        
                    }
                    else {
                        // Send a CHALD response
                    }
                }
            }
        ]
    }    
}
