#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

class Plotter : public QWidget {
    Q_OBJECT

   private:
        /**
         * @brief Váriaveis a serem utilizadas pelo plot
         */
        std::vector<float> abscissa, ordenada;

   public:
        /**
         * @brief Constroi um novo objeto Plotter
         * 
         * @param parent É o ponteiro de herança
         */
        explicit Plotter(QWidget *parent = nullptr);

        /**
         * @brief Método para lidar com a renderização do 
         * plot.
         * 
         * @param event É o evento disparado.
         */
        void paintEvent(QPaintEvent *event);

        /**
         * @brief Método para lidar com o recebimento de dados
         * da janela principal.
         * 
         * @param _abscissa são os dados do eixo horizontal
         * @param _ordenada são os dados do eixo vertical
         */
        void reciveData(std::vector<qint64> _abscissa, std::vector<qint64> _ordenada);
};

#endif  // PLOTTER_H
