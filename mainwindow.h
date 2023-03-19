#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "clientreg.h"
#include "mytablemodel.h"
#include "clientdata.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sumButton_clicked();

    void on_profileButton_clicked();

    void on_visitsButton_clicked();

    void on_curGuests_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QSqlQuery *query;

public:
    clientReg clientRegPage;
};
#endif // MAINWINDOW_H
