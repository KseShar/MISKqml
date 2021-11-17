import QtQuick 2.12
import QtQuick.Window 2.12

/*Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
}*/
// RectangleExample.qml



// The root element is the Rectangle
Rectangle {
    // name this element root
    id: root

    // properties: <name>: <value>
    width: 120; height: 240

    // color property
    color: "#4A4A4A"

    // Declare a nested element (child of root)
    Image {
        id: triangle

        // reference the parent
        x: (parent.width - width)/2; y: 40

        source: "https://e7.pngegg.com/pngimages/572/973/png-clipart-red-triangle-right-triangle-red-triangle-angle-photography.png"
    }

    // Another child of root
    Text {
        // un-named element

        // reference element by id
        y: triangle.y + triangle.height + 20

        // reference root element
        width: root.width

        color: 'white'
        horizontalAlignment: Text.AlignHCenter
        text: 'Triangle'
    }
}
