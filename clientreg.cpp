#include "clientreg.h"
#include "ui_clientreg.h"

clientReg::clientReg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientReg)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.sqlite");
//    if(db.open())
//    {
//        qDebug("open");
//    }
//    else
//    {
//        qDebug("no open");
//    }
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE `ClientBook` (Firstname TEXT, Lastname TEXT, Patronymic TEXT, Age INT);");
    query->exec();


    model = new QSqlTableModel(this, db);
    model->setTable("ClientBook");
    model->select();

    ui->tableView->setModel(model);
}

clientReg::~clientReg()
{
    delete ui;
}

void clientReg::on_pushButton_clicked()
{

    query->exec(QString("INSERT INTO ClientBook (Firstname, Lastname, Patronymic, Age)"
    "VALUES ('%1', '%2', '%3', %4);").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()));

}
