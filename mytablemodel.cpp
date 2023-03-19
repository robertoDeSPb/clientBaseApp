#include "mytablemodel.h"

myTableModel::myTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}


int myTableModel::rowCount(const QModelIndex &parent) const
{
    return guests.size(); // сделаем фиксированно 5 строк в таблице
    //если вы станете использовать скажем QList, то пишите return list.size();
}
int myTableModel::columnCount(const QModelIndex &parent) const
{
    return 4; // количество колонок сделаем также фиксированным
}

void myTableModel::setGuests(QVector<ClientData> curGuests) {
    std::copy(curGuests.begin(), curGuests.end(), guests.begin());
}

QVariant myTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        ClientData guest = guests[index.row()];
        if(index.column() == 0) {
            QString answer = guest.Firstname;
            return QVariant(answer);
        }
        else if(index.column() == 1) {
            QString answer = guest.Lastname;
            return QVariant(answer);
        }
        else if(index.column() == 2) {
            QString answer = guest.Patronymic;
            return QVariant(answer);
        }
        else if(index.column() == 3) {
            int answer = guest.Age;
            return QVariant(answer);
        }
    }
    return QVariant();
}
