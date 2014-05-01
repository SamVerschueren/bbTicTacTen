import bb.cascades 1.0

Page {
    Container {
        layout: DockLayout { }
        
        ImageView {
            imageSource: "asset:///images/background_mdm.jpg"
            verticalAlignment: VerticalAlignment.Fill
            horizontalAlignment: HorizontalAlignment.Fill
        }
        
        Container {
            
            topPadding: 240
            
            Container {
                leftPadding: 35.0
                rightPadding: 35.0
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }

                Container {
                    id: zero
                    preferredHeight: 225
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1.0
                    }
                    
                    onTouch: {
                        if(event.isUp()) {
                            console.log("Clicked on position 0,0");
                        }
                    }
                }

                Container {
                    id: one
                    preferredHeight: 225
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1.0
                    }
                    
                    onTouch: {
                        if(event.isUp()) {
                            console.log("Clicked on position 0,1");
                        }
                    }
                }
                
                Container {
                    id: three
                    preferredHeight: 225
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1.0
                    }
                }

            }

        }
    }
}
