#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <QAbstractTableModel>
#include "clientdata.h"
#include <QVector>

class myTableModel : public QAbstractTableModel
{
public:
    explicit myTableModel(QObject *parent = nullptr);

private:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVector<ClientData> guests;

public:
    void setGuests(QVector<ClientData> curGuests);
};

#endif // MYTABLEMODEL_H
