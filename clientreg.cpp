#include "clientreg.h"
#include "ui_clientreg.h"

clientReg::clientReg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientReg)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.sqlite");
    if(db.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE `ClientBook` (Firstname TEXT, Lastname TEXT, Patronymic TEXT, Age INT);");
    //query->exec("CREATE TABLE `table1` (`a` INT(11), `b` INT(11), `c` INT(11));");
    query->exec();
    //QString str_insert = "INSERT INTO table1 (a, b, c) VALUES (111, 222, 333);";
    //QString str_insert = "INSERT INTO ClientBook (Firstname, Lastname, Patronymic, Age)"
    //                     "VALUES (:Firstname, :Lastname, :Patronymic, :Age);";
    //bool b = query->exec(str_insert);

    //query->bindValue(":Firstname", "Robert");
    //query->bindValue(":Lastname", "Klevtsov");
    //query->bindValue(":Patronymic", "Ev");
    //query->bindValue(":Age", "21");

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
