#include <QtCore>


#include "tablemodel.h"
//#include "sqlconnection.h"
/*
void initializeModel(QTableModel *model)
{
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
}

QTableView *createView(QSqlTableModel *model, const QString &title = "")
{
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setWindowTitle(title);
    return view;
}
*/
MyTableModel::~MyTableModel () {
}

MyTableModel::MyTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

void MyTableModel::setDataMap(const QMap<QString, double> &map)
{
    dataMap = map;

    //FIXME: refresh all the data
    // reset();
}

void MyTableModel::setUnitMap(const QMap<QString, QString> &map)
{
    unitMap = map;
}

/*
 * return the line number
 */
int MyTableModel::rowCount(const QModelIndex &/*parent*/) const
{
    return dataMap.count();
}

/*
 * return column number
 */

int MyTableModel::columnCount(const QModelIndex &/*parent*/) const
{
    if (dataMap.empty())
        return 0;
    return 2;
}


QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    } else if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            QString rowKey = itemAt(index.row());

            if (dataMap.value(rowKey) == 0.0)
                return "####";

            double ret = dataMap.value(rowKey);

            return QString("%1").arg(ret, 0, 'f', 4);
        } else if (index.column() == 1) {
            QString rowKey = unitAt(index.row());

            //if (unitMap.value(rowKey) == n)
            //    return "#####";

            return unitMap.value(rowKey);
        }
        return QVariant();
    }
    return QVariant();
}

/*
 * set data
 */
bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole && index.column() == 0)
    {
        QString keyIndex = itemAt(index.row());
        dataMap[keyIndex] = value.toDouble();

        emit dataChanged(index, index);
        return true;
    }
    return false;
}

/*
 * return map key
 */
QString MyTableModel::itemAt(int offset) const
{
    return (dataMap.begin() + offset).key();
}

QString MyTableModel::unitAt(int offset) const
{
    return (unitMap.begin() + offset).key();
}
/*
 * return header
 */
QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Vertical)
        return itemAt(section);
    //else if (orientation == Qt::Horizontal)
    return QVariant();

    //return QVariant();
    //return QAbstractTableModel::headerData(section, orientation, role);
}





