#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QtSql/QSqlRecord>
#include <QVector>
#include <qaddperson.h>
#include "qformfordelete.h"
namespace Ui {
class adminWindow;
}

class adminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminWindow(QWidget *parent = nullptr);
    ~adminWindow();


private slots:
    void on_action_8_triggered();
    void on_action_12_triggered();

    void on_action_15_triggered();

    void on_action_7_triggered();

private:
    Ui::adminWindow *ui;
    QSqlDatabase datB;
    bool connectDataBase();
    void getProductFromBase();
    QaddPerson *addW;
    QFormForDelete *delW;
};

#endif // ADMINWINDOW_H
