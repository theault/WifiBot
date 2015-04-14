#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include <QMainWindow>
#include <QTimer>
#include <unistd.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void update();
    void on_Avancer_pressed();

    void on_Avancer_released();

    void on_gauche_pressed();

    void on_gauche_released();

    void on_reculer_pressed();

    void on_reculer_released();

    void on_droit_pressed();

    void on_droit_released();

    void on_Speed_actionTriggered(int action);

    void on_Speed_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    Client* robot;
    int direction;
    QTimer* timer;
    int vitesse;
};

#endif // MAINWINDOW_H
