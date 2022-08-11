import io.qt.GA4 1.0
import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("GA4 test")

    GA4{
        id: ga4
        measurementID: "YOUR_ID"
    }

    onActiveChanged: { ga4.sendEvent("Gandalf", ["talk", "YouShallNotPass"]) }
}
