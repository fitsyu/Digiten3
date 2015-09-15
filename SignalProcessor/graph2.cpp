#include "graph2.h"
#include <QMouseEvent>

Graph2::Graph2(QWidget *parent) :
    QWidget(parent)
{
    plot = new QCustomPlot(this);
    initPlot();

    current = 0;


    connect (plot, SIGNAL(mouseRelease(QMouseEvent*)),
             this, SLOT(emitXRange()));

}

Graph2::~Graph2()
{
    delete plot;
}

void Graph2::setGeometry(int x, int y, int w, int h)
{
    plot->setGeometry(x, y, w, h);
    return QWidget::setGeometry(x,y,w,h);
}

QSize Graph2::sizeHint() const
{
    return QSize(600, 300);
}

void Graph2::appendSample(qreal sample)
{
    plot->graph(0)->addData(current, sample);
    current++;
    if (current > 100){
//        plot->rescaleAxes(true);
        plot->xAxis->setRange(current-100, current);
    }
    plot->replot();
}

void Graph2::appendSample(QVector3D sample)
{
    plot->graph(0)->addData(current, sample.x());
    plot->graph(1)->addData(current, sample.y());
    plot->graph(2)->addData(current, sample.z());
    current++;
    if (current > 100){
//        plot->rescaleAxes(true);
        plot->xAxis->setRange(current-100, current);
    }
    plot->replot();
}

void Graph2::syncRangeWith(QCPRange xRange, QCPRange yRange)
{
    plot->xAxis->setRange(xRange);
    plot->yAxis->setRange(yRange);
    plot->replot();
}

void Graph2::emitXRange()
{
    emit rangeChanged(plot->xAxis->range(), plot->yAxis->range());
}

void Graph2::initPlot()
{
    plot->xAxis->setLabel("X");
    plot->yAxis->setLabel("Y");
    plot->xAxis->setRange(0, 100);
    plot->yAxis->setRange(-10, 10);

    plot->xAxis->setLabelColor(Qt::white);
    plot->yAxis->setLabelColor(Qt::white);

    QCPGraph * accX = plot->addGraph();
    accX->setPen(QPen(Qt::red, 2));

    QCPGraph * accY = plot->addGraph();
    accY->setPen(QPen(Qt::green, 2));

    QCPGraph * accZ = plot->addGraph();
    accZ->setPen(QPen(Qt::blue, 2));

    // set some pens, brushes and backgrounds:
    plot->xAxis->setBasePen(QPen(Qt::white, 1));
    plot->yAxis->setBasePen(QPen(Qt::white, 1));
    plot->xAxis->setTickPen(QPen(Qt::white, 1));
    plot->yAxis->setTickPen(QPen(Qt::white, 1));
    plot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    plot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    plot->xAxis->setTickLabelColor(Qt::white);
    plot->yAxis->setTickLabelColor(Qt::white);
    plot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    plot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    plot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    plot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    plot->xAxis->grid()->setSubGridVisible(true);
    plot->yAxis->grid()->setSubGridVisible(true);
    plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    plot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    plot->axisRect()->setBackground(axisRectGradient);

    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void Graph2::setLineColor(const QColor &value)
{
    plot->graph(0)->setPen(QPen(value, 2));
}

void Graph2::resizeEvent(QResizeEvent *ev)
{
//    plot->geometry().setHeight(ev->size().height());
//    plot->geometry().setWidth(ev->size().width());
    plot->setGeometry(0,
                      0,
                      ev->size().width(),
                      ev->size().height());

    ev->accept();
}



