#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adminwindow.h"
#include "managerwindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    adminWindow *admW;
    managerWindow *manW;

};
#endif // MAINWINDOW_H