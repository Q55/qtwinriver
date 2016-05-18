#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QTableView>

#include "tablemodel.h"
#include "computethread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initialTable();

    QTableView * createView(MyTableModel *model, const QString &title = "");
    //FIXME: initial model by sql
    //void initializeModel(QSqlTableModel *model);
    //void initializeModel(QTableModel *model);
public slots:
    void showGraph();
    void tableModel(double result);
    void showTable();

private:
     ComputeThread *computePiThread;
     double result;
     MyTableModel *model;
private slots:
     void slotGetResult(double result);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
