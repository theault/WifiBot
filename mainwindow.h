#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "client.h"
#include <QMainWindow>
#include <QTimer>
#include <unistd.h>

#include <QWheelEvent>
#include <QKeyEvent>
#include <QMessageBox>
#include <QMainWindow>
#include <iostream>
#include <stdio.h>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);

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

    void on_Connexion_clicked();

private:
    Ui::MainWindow *ui;
    Client* robot;
    int direction;
    QTimer* timer;
    int vitesse;
};

#endif // MAINWINDOW_H


