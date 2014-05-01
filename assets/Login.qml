import bb.cascades 1.0

Dialog {
    Container {
        background: Color.create("#dcd8c3")
        verticalAlignment: VerticalAlignment.Fill
        leftPadding: 20.0
        topPadding: 100.0
        rightPadding: 20.0
        bottomPadding: 20.0
        
        ImageView {
            imageSource: "asset:///images/tictactoe_big.png"
            horizontalAlignment: HorizontalAlignment.Center
        }
        
        TextField {
            id: txtName
            hintText: qsTr("Username")
            topMargin: 60.0
        }
        
        Button {
            text: qsTr("Continue")
            horizontalAlignment: HorizontalAlignment.Right
            onClicked: {
                loginVM.login(txtName.text);
                
                login.close();
            }
        }
    }
}
