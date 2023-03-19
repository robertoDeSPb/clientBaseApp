#ifndef CLIENTREG_H
#define CLIENTREG_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTime>

#include <QTcpSocket>
#include <QNetworkInterface>
#include "data.h"
#include "clientdata.h"
#include "mytablemodel.h"

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

    QTcpSocket *socket;
    QByteArray Data;
    quint16 nextBlockSize;
    QVector<ClientData> guests;

public:
    int number = 0;
    void setNumber(int num);

public:
    void SendToServer(ClientData *cd = nullptr, bool code = 0);
    QVector<ClientData> returnGuests();
    myTableModel guestsTab;
public slots:
    void slotReadyRead();
};

#endif // CLIENTREG_H
