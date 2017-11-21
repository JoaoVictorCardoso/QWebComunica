#include "dialog.h"
#include "ui_dialog.h"
#include "webserver.h"

Dialog::Dialog( QWidget *parent) :  QDialog(parent),  ui(new Ui::Dialog)
{
    ui->setupUi(this);
    oServidorWeb = new WebServer(this);
    porta = ui->spinBox->value();
    escuta(porta);
    qDebug() << porta;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::mensagemRecebida(const QString &mensagem)
{
    ui->listWidget->addItem(mensagem);
}

void Dialog::on_spinBox_valueChanged(int arg1)
{
    escuta(arg1);
}

void Dialog::escuta(quint16 porta)
{
    oServidorWeb->listen(QHostAddress::Any, porta);
    connect(oServidorWeb, SIGNAL( mensagemRecebida(QString) ), this, SLOT( mensagemRecebida(QString) ) );
}
