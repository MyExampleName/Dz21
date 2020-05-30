#ifndef QADDPERSON_H
#define QADDPERSON_H

#include <QDialog>

namespace Ui {
class QaddPerson;
}

class QaddPerson : public QDialog
{
    Q_OBJECT

public:
    explicit QaddPerson(QWidget *parent = nullptr);
    ~QaddPerson();

private slots:
    void on_buttonReg_clicked();

private:
    Ui::QaddPerson *ui;
};

#endif // QADDPERSON_H
