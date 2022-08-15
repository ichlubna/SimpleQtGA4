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

Use the functions like:

	sendEvent(eventName, eventParameters, turnOnDebugMode)

*QString eventName* - name of the event

*QList<QString> eventParameters* - pairs of parameters ["firstParamName", "firstParamValue",...]

*bool turnOnDebugMode* - if set to True, the events are shown in a few seconds in the Analytics realtime view and are deleted after 30 minutes

	overrideDebugMode(debug)

*bool debug* - all events will be in debug mode (ignoring the turnOnDebugMode parameter) if true, call with false to turn it off

## Additional info
You can obtain your ID when creating a Google Analytics service and creating a web data stream. Then you can get a Measurement ID there starting with G-..

If you send the events with custom parameters, you have to define them in Google Analytics settings, otherwise they will not be stored! You can do so by selecting Configure section and Custom definitions. Follow [this](https://youtu.be/Y6YyzX_7OXk) tutorial.

## Sources
[APP + WEB: Google Analytics Measurement Protocol version 2
Date
](https://www.thyngster.com/app-web-google-analytics-measurement-protocol-version-2)

[Measurement protocol V2 Google analytics Apps+Web](https://lunaxod.com/measurement-protocol-v2-google-analytics-appsweb/)

