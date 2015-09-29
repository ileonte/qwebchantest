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

private:
	QJsonValue rawVal_;
	QJsonValue setVal_;

public:
	explicit WebProxy(QObject *parent = 0);
	virtual ~WebProxy();

	Q_INVOKABLE void logVariant(const QVariant &val);
	Q_INVOKABLE void logJSONValue(const QJsonValue &val);
	Q_INVOKABLE void logJSONObject(const QJsonObject &val);
	Q_INVOKABLE void logString(const QString &val);

	void setVal( const QJsonValue &val);
	QJsonValue getVal() const;
	Q_SIGNAL void setValChanged();

	Q_PROPERTY(QJsonValue rval MEMBER rawVal_)
	Q_PROPERTY(QJsonValue sval READ getVal WRITE setVal NOTIFY setValChanged)
};

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = 0);
	virtual ~Widget();
};

#endif // WIDGET_H
