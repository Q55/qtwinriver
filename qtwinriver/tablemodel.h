#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QtWidgets>
//#include <QtSql>
#include <QAbstractTableModel>
#include <QMap>

class MyTableModel : public QAbstractTableModel
{
public:
    MyTableModel(QObject *parent = 0);
    ~MyTableModel ();

    void setDataMap(const QMap<QString, double> &map);
    void setUnitMap(const QMap<QString, QString> &map);
    int rowCount(const QModelIndex &/*parent*/) const;
    int columnCount(const QModelIndex &/*parent*/) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
     QString itemAt(int offset) const;
     QString unitAt(int offset) const;

     //FIXME: sql update.
     QMap<QString, double> dataMap;
     QMap<QString, QString> unitMap;

};

//void initialzeModel(QSqlTableModel *model);
//QTableView *createView(QSqlTableModel *model, const QString &title = "");

#endif // TABLEMODEL_H

