#include "managerwindow.h"
#include "ui_managerwindow.h"
#include <QDebug>
#include "qgoods.h"
managerWindow::managerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::managerWindow)
{
    ui->setupUi(this);

}

managerWindow::~managerWindow()
{
    delete ui;

}

void managerWindow::on_action_6_triggered()
{
    QGoods g;

    g.getGoodsFromDataBase();

}



void managerWindow::on_action_triggered()
{

}
