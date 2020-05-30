#ifndef QOURUSER_H
#define QOURUSER_H
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QVector>

class QOurUser
{
private:
    QString login;
    QString password;

public:
    QSqlDatabase dataL;

    QOurUser();
    QOurUser(QString login, QString password);
    ~QOurUser();

    QString getLogin();
    QString getPassword();

    void setLogin(QString login);
    void setPassword(QString password);

    QString singIn();
    void singUP(QString surName, QString name, QString lastName,
    QString phone, QString loginForm, QString password, int position);
    void deleteUser(int number);
    void getAallUserInString();
};

#endif // QOURUSER_H
