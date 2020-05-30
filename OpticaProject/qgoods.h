#ifndef QGOODS_H
#define QGOODS_H
#include <QString>
#include <QMap>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QtSql/QSqlRecord>
using namespace std;

class QGoods
{
private:

    QString title;
    int amount;
    float price;
    QString manufacturer;
    QString country;
    QString type;
    QSqlDatabase dataMan;
    bool connectDataBaseG();
public:



    QGoods();
    QGoods(QString title, int amount, float price, QString manufacturer, QString country, QString type);
    ~QGoods();

    QString getTitle();
    int getAmount();
    float getPrice();
    QString getManufacturer();
    QString getCountry();
    QString getType();


    void setTitle(QString title);
    void setAmount(int amount);
    void setPrice(float price);
    void setManufacturer(QString manufacturer);
    void setCountry(QString country);
    void setType(QString type);


    void getGoodsFromDataBase();


};

#endif // QGOODS_H
