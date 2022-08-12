# SimpleQtGA4
A very simple library that allows to send Google Analytics 4 events.

## Instalation
Add *ga4.hpp* to the *HEADERS* in your project ad add Qt *network* module.

## Usage
	//C++
	GA4 ga4("YOUR_ID");
	ga4.sendEvent("ObiWan", {"talk", "HelloThere"});

	//QML
	GA4{
	  id: ga4
          measurementID: "YOUR_ID"}
	onActiveChanged: { ga4.sendEvent("Gandalf", ["talk", "YouShallNotPass"]) }

Use the function like:

	sendEvent(eventName, eventParameters, turnOnDebugMode)

*QString eventName* - name of the event

*QList<QString> eventParameters* - pairs of parameters ["firstParamName", "firstParamValue",...]

*bool turnOnDebugMode* - if set to True, the events are shown in a few seconds in the Analytics realtime view and are deleted after 30 minutes

## Additional info
You can obtain your ID when creating a Google Analytics service and creating a web data stream. Then you can get a Measurement ID there starting with G-...


