#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qouruser.h"
#include "qgoods.h"
adminWindow::adminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminWindow)
{
    setlocale(LC_ALL, "");
    ui->setupUi(this);
    connectDataBase();
}

adminWindow::~adminWindow()
{
    delete ui;
    datB.close();
}
bool adminWindow::connectDataBase(){
    datB = QSqlDatabase::addDatabase("QODBC");
    QString connectingString = "Driver={SQL Server};";
    connectingString += "Server=DESKTOP-V9DC5DP\\SQLEXPRESS;";
    connectingString += "Database=OpticaC++;";
    datB.setDatabaseName(connectingString);
    bool res = datB.open();
    ui->statusbar->showMessage(res?"Connecting":"Not connecting");
    return res;
}


//void adminWindow::getProductFromBase(){


//    ui->AdminTableProduct->setRowCount(0);
//    ui->AdminTableProduct->setColumnCount(6);
//    ui->AdminTableProduct->setHorizontalHeaderLabels(QStringList()
//    << "Title:" << "Amount:" << "Price:" << "Manufacturer:" << "Country:" << "Type:");
//    QSqlQuery queryVip;
//    QString queryStr = "SELECT title, amount, price, [Manufacturer].manuf, Country.descriptionCountry, [Type].descriptionType ";
//    queryStr += " from [products], [Type], [Country], [Manufacturer]";
//    queryStr += " where products.idCountry = Country.id and products.idType = Type.id and products.idManufacturer = Manufacturer.id;";
//    queryVip.exec(queryStr);

//    while (queryVip.next()) {
//        int i = ui->AdminTableProduct->rowCount();
//        ui->AdminTableProduct->setRowCount(i+1);
//        for (int j = 0;j < 6; j++) {
//            QTableWidgetItem* it = new QTableWidgetItem();
//            it->setText(queryVip.value(j).toString());
//            ui->AdminTableProduct->setItem(i, j, it);
//        }
//    }



//};



void adminWindow::on_action_8_triggered()
{
    addW = new QaddPerson(this);
    addW->show();
}



void adminWindow::on_action_12_triggered()
{

}

void adminWindow::on_action_15_triggered()
{
    hide();
}

void adminWindow::on_action_7_triggered()
{
   delW = new QFormForDelete(this);
   delW->show();
}
