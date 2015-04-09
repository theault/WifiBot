#include <QKeyEvent>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdio.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QObject::connect(ui->Speed, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        QMessageBox::warning(this, "titre messageBox", "la touche up a ete activee");
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}
