#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QTableView>

#include "tablemodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTableView * createView(MyTableModel *model, const QString &title = "");
    //FIXME: initial model by sql
    //void initializeModel(QSqlTableModel *model);
    //void initializeModel(QTableModel *model);
public slots:
    void showGraph();
    void showTable();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
