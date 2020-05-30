#include "qformfordelete.h"
#include "ui_qformfordelete.h"

QFormForDelete::QFormForDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QFormForDelete)
{
    setlocale(LC_ALL, "");
    ui->setupUi(this);
    getInComboBox();
}

QFormForDelete::~QFormForDelete()
{
    delete ui;
}

void QFormForDelete::getInComboBox()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Id" << "Surname" << "Name" << "LastName" << "Phone" << "Login" << "Password" << "Position" );
    QSqlQuery query;
    query.exec("select * from Staff");

    while(query.next()){
        int i = ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(i+1);
        for (int j = 0;j < 8; j++) {
            QTableWidgetItem* it = new QTableWidgetItem();
            it->setText(query.value(j).toString());
            ui->tableWidget->setItem(i, j, it);

        }
    }
}

void QFormForDelete::on_pushButton_clicked()
{
    int id = ui->spinBox->value();
    qDebug() << id;
    QOurUser user;
    user.deleteUser(id);
}
