#include "clientreg.h"
#include "ui_clientreg.h"

clientReg::clientReg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientReg)
{
    ui->setupUi(this);
}

clientReg::~clientReg()
{
    delete ui;
}
