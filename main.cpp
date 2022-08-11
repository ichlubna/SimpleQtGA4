#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ga4.hpp>


int main(int argc, char *argv[])
{
    qmlRegisterType<GA4>("io.qt.GA4", 1, 0, "GA4");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/example/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    GA4 ga4("YOUR_ID");
    ga4.sendEvent("ObiWan", {"talk", "HelloThere"});

    engine.load(url);

    return app.exec();
}
