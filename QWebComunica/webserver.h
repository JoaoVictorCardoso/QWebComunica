#ifndef WEBSERVER_H
#define WEBSERVER_H
#include "QWebSocketServer"


class WebServer : public QWebSocketServer
{
    Q_OBJECT
public:
    explicit WebServer(QObject *parent = nullptr);

signals:
    void mensagemRecebida(QString);
private slots:
    void novaConectada();
    void aMensagemRecebida(const QString &mensagem);
private:
    QWebSocket *oSocket;
};

#endif // WEBSERVER_H
