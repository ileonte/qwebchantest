#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebChannel>
#include <QVariant>
#include <QJsonValue>
#include <QJsonObject>

class WebProxy : public QObject
{
	Q_OBJECT

public:
	explicit WebProxy(QObject *parent = 0);
	virtual ~WebProxy();

	Q_INVOKABLE void logVariant(const QVariant &val);
	Q_INVOKABLE void logJSONValue(const QJsonValue &val);
	Q_INVOKABLE void logJSONObject(const QJsonObject &val);
	Q_INVOKABLE void logString(const QString &val);
};

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = 0);
	virtual ~Widget();
};

#endif // WIDGET_H
