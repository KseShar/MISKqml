#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml> // Подключаем для использования qmlRegisterSingletonType
#include <QQmlEngine>
#include "datasource.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);



    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

   engine.qmlRegisterSingletonType<DataSource>("DataModule", 0, 1, "_dataSource", DataSource::getInstance());
   engine.setObjectOwnership(DataSource::getInstance(), QQmlEngine::CppOwnership);

    engine.load(url);

    return app.exec();
}
