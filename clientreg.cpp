#include "clientreg.h"
#include "ui_clientreg.h"

clientReg::clientReg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientReg)
{
    ui->setupUi(this);

    //настройка взаимодействи чтени и записи из слота
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &clientReg::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    nextBlockSize = 0;
    socket->connectToHost("192.168.1.104", 2323);


//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("./testDB.sqlite");
//    if(db.open())
//    {
//        qDebug("open");
//    }
//    else
//    {
//        qDebug("no open");
//    }
//    query = new QSqlQuery(db);
//    query->exec("CREATE TABLE `ClientBook` (Firstname TEXT, Lastname TEXT, Patronymic TEXT, Age INT);");
//    query->exec();


//    model = new QSqlTableModel(this, db);
//    model->setTable("ClientBook");
//    model->select();

//    ui->tableView->setModel(model);

}

clientReg::~clientReg()
{
    delete ui;
}

//void clientReg::on_pushButton_clicked()
//{

//    query->exec(QString("INSERT INTO ClientBook (Firstname, Lastname, Patronymic, Age)"
//    "VALUES ('%1', '%2', '%3', %4);").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()));

//}



//*******************************************************************************************************************

void clientReg::on_pushButton_clicked()
{
    ClientData cd;
    cd.Firstname = ui->lineEdit->text();
    cd.Lastname = ui->lineEdit_2->text();
    cd.Patronymic = ui->lineEdit_3->text();
    cd.Age = ui->lineEdit_4->text().toInt();
    SendToServer(&cd);
}

// посылаем на сервер данные дл регистрации клиента
void clientReg::SendToServer(ClientData *cd, bool code)
{
    if (code) {
        Data.clear();
        QDataStream out(&Data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_2);
        out << quint16(0) << QString("sb01");
        out.device()->seek(0);
        out << qint16(Data.size() - sizeof(qint16));
        socket->write(Data);
        qDebug() << "true";
    } else {
        Data.clear();
        QDataStream out(&Data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_2);
        out << quint16(0) << cd->Firstname << cd->Lastname << cd->Patronymic << cd->Age;
        out.device()->seek(0);
        out << qint16(Data.size() - sizeof(qint16));
        socket->write(Data);
        ui->lineEdit->clear();
        qDebug() << cd->Firstname << " " << cd->Lastname << " " << cd->Patronymic << " " << cd->Age;
    }
}

QVector<ClientData> clientReg::returnGuests() {
    return guests;
}

void clientReg::setNumber(int num)
{
    number = num;
}

void clientReg::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok)
    {
        //QString str;
        //in >> str;
        //ui->textBrowser->append(str);
        for(;;)
        {
            if(nextBlockSize == 0)
            {
                if(socket->bytesAvailable() < 2)
                {
                    break;
                }
                in >> nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize)
            {
                break;
            }
            ClientData guest;
            do {
                in >> guest.Firstname >> guest.Lastname >> guest.Patronymic >> guest.Age;
                //qDebug() << "Debug: " << guest.Firstname << guest.Lastname << guest.Patronymic << guest.Age;
                if (guest.getSize() != 0)
                {
                    guests.push_back(guest);
                }
            } while(guest.getSize() != 0);
            //qDebug() << guests[0].Firstname;
            guestsTab.setGuests(guests);
            setNumber(1);
            nextBlockSize = 0;

        }
        qDebug() << "list was readed";
    } else
    {
        ui->textBrowser->append("read error");
    }
}
