#ifndef SCATTERPLOT_H
#define SCATTERPLOT_H
#include <QMainWindow>
class Plot;

class ScatterPlot: public QMainWindow
{
    Q_OBJECT

public:
    ScatterPlot();

private:
    void setSamples( int samples );

private:
    Plot *d_plot;
};
#endif // SCATTERPLOT_H

