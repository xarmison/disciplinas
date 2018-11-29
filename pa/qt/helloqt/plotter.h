#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

class Plotter : public QWidget {
    Q_OBJECT
    private:
        float amplitude, frequencia, angulo, velocidade;
        int temporizador;
        bool animando;

    public:
      explicit Plotter(QWidget *parent = nullptr);
      void paintEvent(QPaintEvent *event);
      void timerEvent(QTimerEvent *event);

    signals:

    public slots:
      void mudaAmplitude(int amp);
      void mudaFrequencia(int freq);
      void mudaVelociade(int vel);
      void anima();
};

#endif // PLOTTER_H
