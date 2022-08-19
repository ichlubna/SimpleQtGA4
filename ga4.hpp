#ifndef GA4_HPP
#define  GA4_HPP

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QEventLoop>

class GA4 : public QObject
{
Q_OBJECT
Q_PROPERTY(QString measurementID READ getMeasurementID WRITE setMeasurementID NOTIFY measurementIDChanged)
public:
    explicit GA4(QObject *parent = nullptr) : sessionID{initSession()}{};
    explicit GA4(QString streamMeasurementID, QObject *parent = nullptr) : measurementID{streamMeasurementID}, sessionID{initSession()}{};

    void setMeasurementID(QString streamMeasurementID) {measurementID = streamMeasurementID; emit measurementIDChanged();};
    QString getMeasurementID() const {return measurementID;};

    Q_INVOKABLE void sendEvent(QString eventName, QList<QString> parameters, bool debug=false)
    {
        QString request = analyticsURL;
        request += "&tid=" + measurementID
        + "&cid=" + clientID
        + "&sid=" + QString::fromStdString(std::to_string(sessionID))
        + "&sct=1"
        + "&en=" + eventName;

        QString requestParams;
        bool isParamName{true};
        for(auto const& param : parameters)
        {
            if(isParamName)
                requestParams += "&ep." + param;
            else
                requestParams += "=" + param;
            isParamName = !isParamName;
        }
        request += requestParams;

        if(debug || globalDebug)
            request += "&_dbg=1";

        makeRequest(request);
    };
    
    Q_INVOKABLE void overrideDebugMode(bool debug) { globalDebug = debug; }

signals:
    void measurementIDChanged();

private:
    size_t initSession()
    {
        srand (time(NULL));
        return rand();
    }
    void makeRequest(QString url)
    {
        QEventLoop eventLoop;
        QNetworkAccessManager networkManager;
        QObject::connect(&networkManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

        QNetworkRequest req{QUrl(url)};
        QNetworkReply *reply = networkManager.get(req);
        eventLoop.exec();

        //if (reply->error() == QNetworkReply::NoError)
        delete reply;
    }
    QString measurementID;
    QString clientID{"randomClient"};
    const size_t sessionID;
    bool globalDebug{false};
    QString analyticsURL{"https://www.google-analytics.com/g/collect?v=2"};
};

#endif
