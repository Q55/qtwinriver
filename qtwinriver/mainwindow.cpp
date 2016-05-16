
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

    TGraphDataModel *t_data_model = new TGraphDataModel();
    qDebug()<<t_data_model->GetRecordNum();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showGraph() {
    //QWidget *table = new QWidget();
    //table->show();
    ScatterPlot *w = new ScatterPlot();
    w->resize( 800 , 600 );
    w->show();
}
