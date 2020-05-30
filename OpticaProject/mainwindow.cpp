#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qouruser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_action_triggered(){

}


void MainWindow::on_pushButton_clicked()
{
    QString login = ui->editLogin->text();
    QString password = ui->editPassword->text();
    QOurUser user = QOurUser(login,password);
    QString strReturn = user.singIn();
    if(strReturn == "Admin"){
        hide();
        user.dataL.close();
        admW = new adminWindow(this);
        admW->show();
    }else if(strReturn == "Manager"){
        hide();
        user.dataL.close();
        manW = new managerWindow(this);
        manW->show();
    }else if(strReturn == "login not correct "){
        ui->errorsLabel->setText("Не правльный логин");
    }else if(strReturn == "password not correct "){
        ui->errorsLabel->setText("Не правильный пароль");
    }else{
        ui->errorsLabel->setText("Вы не ввели поля");
    }


}
