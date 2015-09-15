#ifndef GRAPH2_H
#define GRAPH2_H

#include <QWidget>
#include "qcustomplot.h"

class Graph2 : public QWidget
{
    Q_OBJECT
public:
    explicit Graph2(QWidget *parent = 0);
    ~Graph2();
    void setGeometry(int x, int y, int w, int h);

    QSize sizeHint() const;

    QCustomPlot *plot;

    void setLineColor(const QColor &value);

    void resizeEvent(QResizeEvent *);

signals:
    void rangeChanged(QCPRange, QCPRange);

public slots:
    void appendSample(qreal sample);  // to focus on only one axis
    void appendSample(QVector3D sample); // to focus on all at once

    void syncRangeWith(QCPRange xRange, QCPRange yRange);

    void emitXRange();

private:
    void initPlot();

    int current;
    QColor lineColor;
};

#endif // GRAPH2_H
