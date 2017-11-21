#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}
class WebServer;
class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
private slots:
    void mensagemRecebida(const QString &mensagem);
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Dialog *ui;
    int porta;
    WebServer *oServidorWeb;
    void escuta(quint16 porta);
};

#endif // DIALOG_H
