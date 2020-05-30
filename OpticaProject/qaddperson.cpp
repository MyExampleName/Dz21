#include "qaddperson.h"
#include "ui_qaddperson.h"
#include "qouruser.h"

QaddPerson::QaddPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QaddPerson)
{
    ui->setupUi(this);
}

QaddPerson::~QaddPerson()
{
    delete ui;
}



void QaddPerson::on_buttonReg_clicked()
{
    QOurUser user;
    QString surname = ui->surname->text();
    QString name = ui->name->text();
    QString lastName = ui->lastName->text();
    QString phone = ui->phone->text();
    QString login = ui->login->text();
    QString pass = ui->pass->text();
    if(ui->admin->isChecked()){
        user.singUP(surname,name,lastName,phone,login,pass,1);
    }else if(ui->manager->isChecked()){
        user.singUP(surname,name,lastName,phone,login,pass,0);
    }

}
