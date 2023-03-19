#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include "data.h"
#include <QString>

class ClientData: public Data
{
public:
    ClientData();

public:
    QString Firstname;
    QString Lastname;
    QString Patronymic;
    int Age;

    qint32 getSize();
};

#endif // CLIENTDATA_H
