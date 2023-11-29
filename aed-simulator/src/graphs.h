
#ifndef GRAPHS_H
#define GRAPHS_H

#include <QVector>
#include <QPen>
#include "qcustomplot.h"

class Graphs
{
public:
    Graphs(QCustomPlot* graph);
    void shockAdvisedVTECG();
    void shockAdvisedVFECG();
    void shockNotAdvisedECG();


private:
    QCustomPlot* placeholderGraph;
};

#endif // GRAPHS_H
