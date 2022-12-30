#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_2->setPixmap(QPixmap("C:/Users/dmn/Documents/clientBaseApp/pictures/empty.png"));

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
    query->exec();

}

MainWindow::~MainWindow()
{
    delete ui;
}

