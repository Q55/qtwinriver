
#include <QTableWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scatterplot.h"
#include "rawdatafromdb.h"
#include "tgraphdatamodel.h"

// set raw data to global, and initilized only once (or every 'timer' period).
RawDataFromDB *raw_data = new RawDataFromDB();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("QtWinRiver"));
    //QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenu = new QMenu(tr("&File"), ui->menuBar);
    QMenu *configMenu = new QMenu(tr("&Config"), ui->menuBar);
    QMenu *watchMenu = new QMenu(tr("&Watch"), ui->menuBar);
    QMenu *collectMenu = new QMenu(tr("C&ollect"), ui->menuBar);
    QMenu *replayMenu = new QMenu(tr("&Replay"), ui->menuBar);

    ui->menuBar->addMenu(fileMenu);
    ui->menuBar->addMenu(configMenu);
    ui->menuBar->addMenu(watchMenu);
    ui->menuBar->addMenu(collectMenu);
    ui->menuBar->addMenu(replayMenu);

    //QAction *watchGraph = new QAction(tr("Graph"), watchMenu);
    QMenu *graphMenu = watchMenu->addMenu(tr("&Graphs"));
    QMenu *tableMenu = watchMenu->addMenu(tr("&Tables"));

    QAction *shipSpeed = new QAction(tr("&Ship"), graphMenu);
    graphMenu->addAction(shipSpeed);

    QAction *tableTemp1 = new QAction(tr("&table1"), tableMenu);
    tableMenu->addAction(tableTemp1);

    QAction *tableTemp2 = new QAction(tr("&table2"), tableMenu);
    tableMenu->addAction(tableTemp2);

    QAction *newFile = new QAction(tr("&New"), fileMenu);
    fileMenu->addAction(newFile);
    QAction *openFile = new QAction(tr("&Open"), fileMenu);
    fileMenu->addAction(openFile);

    setMenuBar(ui->menuBar);
    this->showMaximized();
    //ui->menuBar;
    connect(shipSpeed, SIGNAL(triggered()), this, SLOT(showGraph()));

    connect(tableTemp1, SIGNAL(triggered()), this, SLOT(showTable()));
    TGraphDataModel *t_data_model = new TGraphDataModel();
    qDebug()<<t_data_model->GetRecordNum();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * show graph
 */
//FIXME: return type, graphic-viw/widget
void MainWindow::showGraph()
{
    //QWidget *table = new QWidget();
    //table->show();
    ScatterPlot *w = new ScatterPlot();
    w->resize( 800 , 600 );
    w->show();
}

/*
 * show table
 */
//FIXME:
void MainWindow::showTable()
{
    //QApplication app(argc, argv);
    //if (!createConnection())
    //    return 1;

    MyTableModel *model = new MyTableModel;

    QMap<QString, double> tempMap;
    tempMap.insert("船速", 2.090);
    tempMap.insert("航向", 2.53);
    tempMap.insert("流速", 0.341);
    tempMap.insert("流向", 116.52);
    tempMap.insert("水深", 2.712);
    tempMap.insert("航迹长度", 1390.44);
    tempMap.insert("直线距离", 1383.16);
    tempMap.insert("航迹方向", 4.39);
    tempMap.insert("历时", 711.50);
    tempMap.insert("纬度", 31);
    tempMap.insert("经度", 118);
    model->setDataMap(tempMap);

    QMap<QString, QString> temp2Map;
    temp2Map.insert("船速", "[m/s]");
    temp2Map.insert("航向", "[度]");
    temp2Map.insert("流速", "[m/s]");
    temp2Map.insert("流向", "[度]");
    temp2Map.insert("水深", "[m]");
    temp2Map.insert("航迹长度", "[m]");
    temp2Map.insert("直线距离", "[m]");
    temp2Map.insert("航迹方向", "[度]");
    temp2Map.insert("历时", "[s]");
    temp2Map.insert("纬度", "[58.232995'N]");
    temp2Map.insert("经度", "[37.768470'E]");
    model->setUnitMap(temp2Map);
    //initializeModel(&model);

    QTableView *view1 = createView(model, QObject::tr("导航(相对于底跟踪)"));
    QTableView *view2 = createView(model, QObject::tr("Table Model (View 2)"));

    view1->resize(270, 380);
    view1->show();

    view2->move(view1->x() + view1->width() + 20, view1->y());
    view2->resize(270, 380);
    view2->show();

    //return app.exec();
}

QTableView * MainWindow::createView(MyTableModel *model, const QString &title)
{
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setWindowTitle(title);
    return view;
}
