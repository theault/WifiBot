#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    case Qt::Key_Z:
        break;
    case Qt::Key_Q:
        break;
    case Qt::Key_S:
        break;
    case Qt::Key_D:
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}
