#include "qgoods.h"
#include <QDebug>
#include"managerwindow.h"
bool QGoods::connectDataBaseG()
{
    dataMan = QSqlDatabase::addDatabase("QODBC");
    QString connectingString = "Driver={SQL Server};";
    connectingString += "Server=DESKTOP-V9DC5DP\\SQLEXPRESS;";
    connectingString += "Database=OpticaC++;";
    dataMan.setDatabaseName(connectingString);
    bool res = dataMan.open();
    return res;
}

QGoods::QGoods()
{
    this->title = "title";
    this->amount = 1;
    this->price = 1;
    this->manufacturer = "manufacturer";
    this->country = "country";
    this->type = "type";
    connectDataBaseG();
}

QGoods::QGoods(QString title, int amount, float price, QString manufacturer, QString country, QString type)
{
    this->title = title;
    this->amount = amount;
    this->price = price;
    this->manufacturer = manufacturer;
    this->country = country;
    this->type = type;
    connectDataBaseG();
}

QGoods::~QGoods()
{
    dataMan.close();
}

QString QGoods::getTitle(){
    return this->title;
};
int QGoods::getAmount(){
    return this->amount;
};
float QGoods::getPrice(){
    return this->price;
};
QString QGoods::getManufacturer(){
    return this->manufacturer;
};
QString QGoods::getCountry(){
    return this->country;
};
QString QGoods::getType(){
    return this->type;
};


void QGoods::setTitle(QString title){
    this->title = title;
};
void QGoods::setAmount(int amount){
     this->amount = amount;
};
void QGoods::setPrice(float price){
    this->price = price;
};
void QGoods::setManufacturer(QString manufacturer){
    this->manufacturer = manufacturer;
};
void QGoods::setCountry(QString country){
    this->country = country;
};
void QGoods::setType(QString type){
    this->type = type;
}

void QGoods::getGoodsFromDataBase()
{
    QString queryStr = "SELECT [products].articul, title, amount, price, [Manufacturer].manuf, Country.descriptionCountry, [Type].descriptionType ";
    queryStr += " from [products], [Type], [Country], [Manufacturer]";
    queryStr += " where products.idCountry = Country.id and products.idType = Type.id and products.idManufacturer = Manufacturer.id;";
    QSqlQuery sqlGoods;
    sqlGoods.exec(queryStr);
    managerWindow man;
    while(sqlGoods.next()){
        qDebug() << sqlGoods.value("title").toString();
        man.goods.insert(sqlGoods.value("articul").toInt(),new QGoods(sqlGoods.value("title").toString(),
                                                                    sqlGoods.value("amount").toInt(),
                                                                    sqlGoods.value("price").toFloat(),
                                                                    sqlGoods.value("manuf").toString(),
                                                                    sqlGoods.value("descriptionCountry").toString(),
                                                                    sqlGoods.value("descriptionType").toString()));
    }




    for(QMap<int, QGoods*>::iterator it = man.goods.begin(); it!=man.goods.end();it++){
            qDebug() <<  man.goods[0]->getAmount();
    }
}


