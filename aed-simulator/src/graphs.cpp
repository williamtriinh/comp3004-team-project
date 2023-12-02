#include "graphs.h"

Graphs::Graphs(QCustomPlot* graph) : placeholderGraph(graph)
{
}


void Graphs::setupGraph(){
    placeholderGraph->clearGraphs();
    placeholderGraph->addGraph();
    placeholderGraph->graph(0)->setPen(QPen(Qt::blue)); // line color blue for the graph

    placeholderGraph->xAxis->setRange(0, 72); // Adjust based on your maximum x-value
    placeholderGraph->yAxis->setRange(-2, 12);

    placeholderGraph->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
    placeholderGraph->setBackground(QBrush(QColor(240, 240, 240)));

    placeholderGraph->xAxis->setLabel("Time");
    placeholderGraph->yAxis->setLabel("Amplitude");
    placeholderGraph->plotLayout()->insertRow(0);
    placeholderGraph->plotLayout()->addElement(0, 0, new QCPTextElement(placeholderGraph, "ECG Waveform", QFont("sans", 12, QFont::Bold)));
}


void Graphs::setDataPEAECG(){
    QVector<double> yValues = {0, 0, 0, 0, 0, 0, 0, 1, -1, 10, -1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    updateGraphData(yValues);
}

void Graphs::setDataAsystoleECG(){
    QVector<double> yValues = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    updateGraphData(yValues);
}

void Graphs::setDataVTECG(){
    QVector<double> yValues = {-2, 2, -1, 1, -1, 1, -1, 1, 0.5, -0.5, -1, 1, 0.5, -0.5, -2, 2, -1, 1, -1, 1, -1, 1, 0.5, -0.5};
    updateGraphData(yValues);
}

void Graphs::setDataVFECG(){
    QVector<double> yValues = {-2, 2, -1, 1, -1, 1, -1, 1, 0.5, -0.5, -1, 1, 0.5, -0.5, -2, 2, -1, 1, -1, 1, -1, 1, 0.5, -0.5};
    updateGraphData(yValues);
}

void Graphs::updateGraphData(const QVector<double>& yValues){
    QVector<double> repeatedYValues;
    for (int i = 0; i < 3; ++i) {
        repeatedYValues += yValues;
    }

    QVector<double> xValues(repeatedYValues.size());
    std::iota(xValues.begin(), xValues.end(), 0); // Fill xValues with indices 0, 1, 2, ...

    placeholderGraph->graph(0)->setData(xValues, repeatedYValues);
    placeholderGraph->replot();
}



//void Graphs::shockNotAdvisedPEAECG(){

//    placeholderGraph->clearGraphs();
//    placeholderGraph->addGraph();
//    placeholderGraph->graph(0)->setPen(QPen(Qt::blue)); // line color blue for the graph

//    QVector<double> yValues = {0, 0, 0, 0, 0, 0, 0, 1, -1, 10, -1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//    QVector<double> repeatedYValues;
//    for (int i = 0; i < 3; ++i) {
//        repeatedYValues += yValues;
//    }

//    QVector<double> xValues(repeatedYValues.size());
//    std::iota(xValues.begin(), xValues.end(), 0);  // Fill xValues with indices 0, 1, 2, ...

//    placeholderGraph->graph(0)->setData(xValues, repeatedYValues);

//    placeholderGraph->xAxis->setRange(0, repeatedYValues.size());
//    placeholderGraph->yAxis->setRange(-2, 12);

//    placeholderGraph->graph(0)->rescaleAxes(false);

//    placeholderGraph->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
//    placeholderGraph->setBackground(QBrush(QColor(240, 240, 240)));

//    placeholderGraph->xAxis->setLabel("Time");
//    placeholderGraph->yAxis->setLabel("Amplitude");
//    placeholderGraph->plotLayout()->insertRow(0);
//    placeholderGraph->plotLayout()->addElement(0, 0, new QCPTextElement(placeholderGraph, "ECG Waveform", QFont("sans", 12, QFont::Bold)));
//    placeholderGraph->replot();

//}

//void Graphs::shockNotAdvisedAsystoleECG(){

//    placeholderGraph->clearGraphs();


//    placeholderGraph->clearGraphs();
//    placeholderGraph->addGraph();
//    placeholderGraph->graph(0)->setPen(QPen(Qt::blue)); // line color blue for the graph

//    QVector<double> yValues = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//    QVector<double> repeatedYValues;
//    for (int i = 0; i < 3; ++i){
//        repeatedYValues += yValues;
//    }

//    QVector<double> xValues(repeatedYValues.size());
//    std::iota(xValues.begin(), xValues.end(), 0);  // Fill xValues with indices 0, 1, 2, ...

//    placeholderGraph->graph(0)->setData(xValues, repeatedYValues);

//    placeholderGraph->xAxis->setRange(0, repeatedYValues.size());
//    placeholderGraph->yAxis->setRange(-2, 12);

//    placeholderGraph->graph(0)->rescaleAxes(false);

//    placeholderGraph->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
//    placeholderGraph->setBackground(QBrush(QColor(240, 240, 240)));

//    placeholderGraph->xAxis->setLabel("Time");
//    placeholderGraph->yAxis->setLabel("Amplitude");
//    placeholderGraph->plotLayout()->insertRow(0);
//    placeholderGraph->plotLayout()->addElement(0, 0, new QCPTextElement(placeholderGraph, "ECG Waveform", QFont("sans", 12, QFont::Bold)));
//    placeholderGraph->replot();

//}

//void Graphs::shockAdvisedVTECG(){

//    placeholderGraph->clearGraphs();

//    placeholderGraph->addGraph();
//    placeholderGraph->graph(0)->setPen(QPen(Qt::blue)); // line color blue for the graph

//    QVector<double> yValues = {5, -5, 5, -5, 5, -5, 2, -2, 2, -2, 2, -2, 5, -5, 5, -5, 5, -5, 5, -5, 5, -5, 5, -5};

//    QVector<double> repeatedYValues;
//    for (int i = 0; i < 3; ++i) {
//        repeatedYValues += yValues;
//    }
//    QVector<double> xValues(repeatedYValues.size());
//    std::iota(xValues.begin(), xValues.end(), 0);
//    placeholderGraph->graph(0)->setData(xValues, repeatedYValues);

//    placeholderGraph->xAxis->setRange(0, repeatedYValues.size());
//    placeholderGraph->yAxis->setRange(-2, 12);

//    placeholderGraph->graph(0)->rescaleAxes(false);

//    placeholderGraph->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
//    placeholderGraph->setBackground(QBrush(QColor(240, 240, 240)));

//    placeholderGraph->xAxis->setLabel("Time");
//    placeholderGraph->yAxis->setLabel("Amplitude");
//    placeholderGraph->plotLayout()->insertRow(0);
//    placeholderGraph->plotLayout()->addElement(0, 0, new QCPTextElement(placeholderGraph, "ECG Waveform", QFont("sans", 12, QFont::Bold)));

//    placeholderGraph->replot();
//}

//void Graphs::shockAdvisedVFECG(){

//    placeholderGraph->clearGraphs();

//    placeholderGraph->addGraph();
//    placeholderGraph->graph(0)->setPen(QPen(Qt::blue)); // line color blue for the graph

//    QVector<double> yValues = {-2, 2, -1, 1, -1, 1, -1, 1, 0.5, -0.5, -1, 1, 0.5, -0.5, -2, 2, -1, 1, -1, 1, -1, 1, 0.5, -0.5};

//    QVector<double> repeatedYValues;
//    for (int i = 0; i < 3; ++i) {
//        repeatedYValues += yValues;
//    }

//    QVector<double> xValues(repeatedYValues.size());
//    std::iota(xValues.begin(), xValues.end(), 0);

//    placeholderGraph->graph(0)->setData(xValues, repeatedYValues);

//    placeholderGraph->xAxis->setRange(0, repeatedYValues.size());
//    placeholderGraph->yAxis->setRange(-2, 12);

//    placeholderGraph->graph(0)->rescaleAxes(false);

//    placeholderGraph->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
//    placeholderGraph->setBackground(QBrush(QColor(240, 240, 240)));

//    placeholderGraph->xAxis->setLabel("Time");
//    placeholderGraph->yAxis->setLabel("Amplitude");
//    placeholderGraph->plotLayout()->insertRow(0);
//    placeholderGraph->plotLayout()->addElement(0, 0, new QCPTextElement(placeholderGraph, "ECG Waveform", QFont("sans", 12, QFont::Bold)));

//    placeholderGraph->replot();
//}
