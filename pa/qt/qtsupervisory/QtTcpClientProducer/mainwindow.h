#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

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
        int min, max, timing, temporizador;

    public:
        /**
         * @brief Construi um nova objeto Janela Principal
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
         * @brief Método para enviar um número aleatório para 
         * o servidor
         */
        void setRandonNumber();

        /**
         * @brief Método para lidar com o evio de dados a cada ciclo 
         * do timer
         *  
         * @param event É o evento que o temporizador dispara
         */
        void timerEvent(QTimerEvent *event);

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
         * @brief Slot para inciar um novo temporizador
         */
        void start();

        /**
         * @brief Slot para parar o temporizador que está em a
         * andamento
         */
        void stop();

        // Sliders
        /**
         * @brief Slot para tratar a mudança no slider de mínimo 
         * 
         * @param _min É o valor atual do slider
         */
        void changeMin(int _min);

        /**
         * @brief Slot para tratar a mudança no slider de máximo
         * 
         * @param _max É o valor atual do slider 
         */
        void changeMax(int _max);

        /**
         * @brief Slot para tratar a mudança no slider de timing 
         * 
         * @param _timing É o valor atual do slider
         */
        void changeTiming(int _timing);                                       
};

#endif // MAINWINDOW_H
