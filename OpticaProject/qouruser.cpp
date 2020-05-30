#include "qouruser.h"
#include <QDebug>

QOurUser::QOurUser()
{
     this->login = "manager";
     this->password = "228";
}

QOurUser::QOurUser(QString login, QString password){
    this->login = login;
    this->password = password;
    this->dataL = QSqlDatabase::addDatabase("QODBC");
    QString connectingString = "Driver={SQL Server};";
    connectingString += "Server=DESKTOP-V9DC5DP\\SQLEXPRESS;";
    connectingString += "Database=OpticaC++;";
    dataL.setDatabaseName(connectingString);
    bool res = dataL.open();
    qDebug() << res;
}

QOurUser::~QOurUser()
{

}

QString QOurUser::getLogin()
{
    return this->login;
};

QString QOurUser::getPassword(){
    return this->password;
};

void QOurUser::setLogin(QString login){
    this->login = login;
};
void QOurUser::setPassword(QString password){
    this->password = password;
};

QString QOurUser::singIn(){

    QSqlQuery queryAdm;
    QString strAdms = "select [login],[password] ";
    strAdms += " from Staff";
    queryAdm.exec(strAdms);
    qDebug() << this->login;
    qDebug() << this->password;

    QVector<QString> vPassword;
    QVector<QString> vLogin;
    bool boolLog = false;
    bool boolPass = false;

    while (queryAdm.next()) {
               vLogin.push_back(queryAdm.value("login").toString());
               vPassword.push_back(queryAdm.value("password").toString());
       }


    for (QVector<QString>::iterator itP = vPassword.begin(); itP!= vPassword.end(); itP++) {
        if(*itP == this->password){
            qDebug() << "password correct";
            boolPass = true;
        }
    }

    for (QVector<QString>::iterator it = vLogin.begin(); it!= vLogin.end();it++) {
        if(*it == this->login){
            qDebug() << "login correct";
            boolLog = true;
        }
    }

    if(boolLog == true && boolPass == true){
        qDebug() << "You sing in";
        QSqlQuery queryPos;
        queryPos.exec("select [position] from Staff where [login] = '" + this->login + "'");
        int adMan = 0;
        while(queryPos.next()){
            adMan =  queryPos.value("position").toInt();
        }
        if(adMan== 0){
            return "Manager";
        }else if(adMan == 1){
            return "Admin";
        }

    }else if(boolLog == false && boolPass == true){
        qDebug() << "login not correct";
        return "login not correct";
    }else if(boolLog == true && boolPass == false){
        qDebug() << "password not correct";
         return "password not correct";
    }



    return "Error";
}

void QOurUser::singUP(QString surName, QString name, QString lastName, QString phone,
                      QString loginForm, QString passwordFrom, int position)
{
    QSqlQuery query;
        query.prepare("INSERT INTO Staff (Surname, Name, LastName, Phone, Login, Password, Position)"
                      "VALUES (?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue(surName);
        query.addBindValue(name);
        query.addBindValue(lastName);
        query.addBindValue(phone);
        query.addBindValue(loginForm);
        query.addBindValue(passwordFrom);
        query.addBindValue(position);
        query.exec();
}

void QOurUser::deleteUser(int number)
{
    QSqlQuery qry;
    QString a;
    a.setNum(number);
    qry.prepare( "DELETE FROM Staff WHERE id = " + a);
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
          qDebug( "Deleted!" );
}

void QOurUser::getAallUserInString()
{
      QSqlQuery sqlUser;
      sqlUser.exec("select * from Staff");
      while(sqlUser.next()){
          qDebug() << sqlUser.value("lastname").toString();
      }

};
