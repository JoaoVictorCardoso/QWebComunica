#include "webserver.h"
#include <QWebSocket>

WebServer::WebServer(QObject *parent) : QWebSocketServer("OServidor" ,QWebSocketServer::NonSecureMode, parent)
{
    oSocket = NULL;
    connect(this, SIGNAL(newConnection()), this, SLOT(novaConectada() ) );
}

void WebServer::novaConectada()
{
    oSocket = nextPendingConnection();
    connect(oSocket , SIGNAL(textMessageReceived(QString)), this, SLOT(aMensagemRecebida(QString)) );
}

void WebServer::aMensagemRecebida(const QString &mensagem)
{
    emit mensagemRecebida(mensagem);
}
