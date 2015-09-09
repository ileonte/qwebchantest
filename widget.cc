#include <QDebug>
#include <QHBoxLayout>
#include "widget.h"

WebProxy::WebProxy(QObject *parent) : QObject(parent)
{
}

WebProxy::~WebProxy()
{
}

void WebProxy::logVariant(const QVariant &val)
{
	qDebug() << "VARIANT VAL:" << val.toJsonValue();
	qDebug() << "VARIANT OBJ:" << val.toJsonObject();
}

void WebProxy::logJSONValue(const QJsonValue &val)
{
	qDebug() << "JSON VALUE:" << val;
}

void WebProxy::logJSONObject(const QJsonObject &val)
{
	qDebug() << "JSON OBJECT:" << val;
}

void WebProxy::logString(const QString &val)
{
	qDebug() << "STRING:" << val;
}

Widget::Widget(QWidget *parent) : QWidget(parent)
{
	auto lay = new QHBoxLayout(this);
	auto webView = new QWebEngineView(this);
	auto webChan = new QWebChannel(this);
	auto webProxy = new WebProxy(this);

	webChan->registerObject("proxy", webProxy);
	webView->page()->setWebChannel(webChan);
	webView->page()->load(QUrl("qrc:///test.html"));

	lay->addWidget(webView);
}

Widget::~Widget()
{
}
