#include "clientdata.h"

ClientData::ClientData()
{

}

qint32 ClientData::getSize()
{
    return Firstname.size() + Lastname.size() + Patronymic.size() + Age;
}
