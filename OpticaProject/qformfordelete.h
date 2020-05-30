#ifndef QFORMFORDELETE_H
#define QFORMFORDELETE_H

#include <QDialog>
#include "qouruser.h"
namespace Ui {
class QFormForDelete;
}

class QFormForDelete : public QDialog
{
    Q_OBJECT

public:
    explicit QFormForDelete(QWidget *parent = nullptr);
    ~QFormForDelete();

private slots:
    void on_pushButton_clicked();

private:
    Ui::QFormForDelete *ui;
    void getInComboBox();
};

#endif // QFORMFORDELETE_H
