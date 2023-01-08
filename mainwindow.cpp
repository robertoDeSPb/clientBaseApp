#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->centralwidget->setWindowTitle("Registrate");
    MainWindow::setWindowTitle("Registrate");
    ui->label_2->setPixmap(QPixmap("D:/c++/Projects/ClientBaseApp/images/user.png"));

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
    //query->exec("CREATE TABLE `ClientBook` (Firstname TEXT, Lastname TEXT, Patronymic TEXT, Age INT);");
    //query->exec();
    QSqlQuery q("SELECT * FROM ClientBook WHERE Firstname = 'Robert'");
    while (q.next()) {
        QString name = q.value(0).toString();
        QString lastname = q.value(1).toString();
        QString patronymic = q.value(2).toString();
        name += " " + lastname + " " + patronymic;
        ui->label_fio->setText(name);
        ui->label_age->setText("Возраст: " + QString(q.value(3).toString()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_sumButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_profileButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_visitsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

