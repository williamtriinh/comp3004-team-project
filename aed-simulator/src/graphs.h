
#ifndef GRAPHS_H
#define GRAPHS_H

#include <QVector>
#include <QPen>
#include "qcustomplot.h"

class Graphs
{
public:
    Graphs(QCustomPlot* graph);
    void shockAdvisedECG();
    void shockNotAdvisedECG();

private:
    QCustomPlot* placeholderGraph;
};

#endif // GRAPHS_H
