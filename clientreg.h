#ifndef CLIENTREG_H
#define CLIENTREG_H

#include <QMainWindow>

namespace Ui {
class clientReg;
}

class clientReg : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientReg(QWidget *parent = nullptr);
    ~clientReg();

private:
    Ui::clientReg *ui;
};

#endif // CLIENTREG_H
