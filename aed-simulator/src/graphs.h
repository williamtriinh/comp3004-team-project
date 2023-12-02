#ifndef GRAPHS_H
#define GRAPHS_H

#include "qcustomplot.h"
#include <QVector>

class Graphs {
public:
    explicit Graphs(QCustomPlot* graph);

    // Functions for setting up and updating the graph
    void setupGraph();
    void setDataPEAECG();
    void setDataAsystoleECG();
    void setDataVTECG();
    void setDataVFECG();

private:
    QCustomPlot* placeholderGraph;


    void updateGraphData(const QVector<double>& yValues);
};

#endif // GRAPHS_H
