#ifndef MANAGERWINDOW_H
#define MANAGERWINDOW_H

#include <QMainWindow>
#include "qgoods.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QtSql/QSqlRecord>
namespace Ui {
class managerWindow;
}

class managerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit managerWindow(QWidget *parent = nullptr);
    QMap<int, QGoods*> goods;
    ~managerWindow();

private slots:
    void on_action_6_triggered();

    void on_action_triggered();

private:
    Ui::managerWindow *ui;



};

#endif // MANAGERWINDOW_H
