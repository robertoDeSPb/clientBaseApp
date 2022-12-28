#ifndef CLIENTREG_H
#define CLIENTREG_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class clientReg;
}

class clientReg : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientReg(QWidget *parent = nullptr);
    ~clientReg();

private slots:
    void on_pushButton_clicked();

private:
    Ui::clientReg *ui;

    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    int row;
};

#endif // CLIENTREG_H
