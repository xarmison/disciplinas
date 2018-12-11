#include "plotter.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <cmath>
#include <vector>

#include <QDebug>

#define PI 3.1415

qint64 max(std::vector<qint64> data) {
    qint64 max = 0;

    for(qint64 i : data ) {
        if(i > max)
            max = i;
    }

    return max;
}

qint64 min(std::vector<qint64> data) {
    qint64 min = 99;

    for(qint64 i : data) {
        if(i < min)
            min = i;
    }

    return min;
}

std::vector<float> rescaleOrdenada(std::vector<qint64> data) {
    
    std::vector<float> rData;

    for(qint64 i : data) {
        rData.push_back((i - min(data))/float((max(data) - min(data))));
    }

    return rData;
}

std::vector<float> rescaleAbscissa(std::vector<qint64> data) {
    std::vector<float> rData;

    for(qint64 i : data) {
        rData.push_back((i - data[0])/float((data[29] - data[0])));
    }

    return rData;
}

Plotter::Plotter(QWidget *parent) : QWidget(parent) {  
}

void Plotter::reciveData(std::vector<qint64> _abscissa, std::vector<qint64> _ordenada) {
    abscissa = rescaleAbscissa(_abscissa);
    ordenada = rescaleOrdenada(_ordenada);

    repaint();
}

void Plotter::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    painter.setRenderHint(QPainter::Antialiasing);

    // Draw Bg
    brush.setColor(QColor(250, 250, 250));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    
    // Draw Bounding Box
    pen.setColor(QColor(180, 180, 180));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawRect(0, 0, width(), height());

    // Draw grid
    /*
    pen.setWidth(1);
    pen.setColor(QColor(0, 0, 0));
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    for(int i = width()/30; i < width(); i = i+width()/30) {
        painter.drawLine(i, 0, i, height());
    }

    for(int i = height()/30; i < height(); i = i+height()/30) {
        painter.drawLine(0, i, width(), i);
    }
    */
    // Draw line
    pen.setWidth(2);
    pen.setColor(QColor(0, 0, 255));
    painter.setPen(pen);

    if(!abscissa.empty() || !ordenada.empty()) {

        float xOld = 0, yOld = height();

        for(int i = 0; i < 30; i++) {
            float x = abscissa[i] * width(), y = ordenada[i] * height();
            painter.drawLine(xOld, yOld, x, y);

            xOld = x;
            yOld = y;
        }

    }
}
