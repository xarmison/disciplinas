#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QTcpSocket>
#include <vector>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    private:
        /**
         * @brief Pointeiro para a interface gráfica
         **/
        Ui::MainWindow *ui;

        /**
         * @brief Pointeiro para o socket de conexão com o 
         * servidor
         */
        QTcpSocket *socket;

        /**
         * @brief Váriaveis a serem utilizadas pela interface
         */
        int timing, temporizador;
        QString selectedProducer;

    public:
        /**
         * @brief Constroi um novo objeto Janela Principal
         * @param parent É o ponteiro de herança da janela
         */
        explicit MainWindow(QWidget *parent = 0);

        /**
         * @brief Destrutor da Janela Principal
         */
        ~MainWindow();

        /**
         * @brief Método para realizar a conexão com o servidor
         * 
         * @param serverIP É o IP do servidor ao qual se deseja
         * conectar
         * @param serverPort É a porta do servidor ao qual se deseja
         * conectar
         */
        void tcpConnect(QString serverIP, int serverPort);

        /**
         * @brief Método para desconectar do servidor
         */
        void tcpDisconnect();

        /**
         * @brief Método para lidar com o evio de dados a cada ciclo 
         * do timer
         *  
         * @param event É o evento que o temporizador dispara
         */
        void timerEvent(QTimerEvent *event);

        /**
         * @brief Método para recuperar amostras do servidor
         * 
         * @param samples é o número de amostrar a ser recuperado
         */
        void getData(int samples);

    public slots:
        // Buttons 
        /**
         * @brief Slot para chamar a conexão com o servidor
         */
        void doConnection();

        /**
         * @brief Slot para chamar a desconexão com o servidor 
         */
        void doDisconnection();

        /**
         * @brief Slot para fazer a atualização da lista de 
         * produtores de dados 
         */
        void doUpdate();

        /**
         * @brief Slot para inciar um novo temporizador
         */
        void start();

        /**
         * @brief Slot para parar o temporizador que está em a
         * andamento
         */
        void stop();

        // Slider
        /**
         * @brief Slot para tratar a mudança no slider de timing 
         * 
         * @param _timing É o valor atual do slider
         */
        void changeTiming(int _timing);

        // Producers List 
        /**
         * @brief Slot para tratar a mudança na lista de produtores
         * 
         * @param item É o item selecionado
         */
        void changeProducer();
};

#endif  // MAINWINDOW_H
