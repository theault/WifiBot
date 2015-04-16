#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    direction=5;
    vitesse=0;

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Avancer_pressed()
{
    direction=3;
    cout<<"direction = avant"<<endl;
}

void MainWindow::on_Avancer_released()
{
    direction = 5; // si touche relaché remise à 0
}

void MainWindow::update()
{
    cout<<"hello"<<endl;
    cout<<"appel update"<<endl;
    robot->Communication(direction, vitesse);
}

void MainWindow::on_Connexion_clicked()
{
    robot = new Client(ui->Adresse->text().toStdString(),ui->Port->text().toInt());
    robot->launch();
    if(robot->estconnect())
    {
        ui->Port->setText("Connecter");
        ui->Status->setStyleSheet("Qlabel#Status { background: green }");
    }
    timer = new QTimer();
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();
}


void MainWindow::on_gauche_pressed()
{
    direction = 2;
    cout<<"direction =  gauche "<<endl;
}

void MainWindow::on_gauche_released()
{
    direction = 5; // si touche relaché remise à 0
}

void MainWindow::on_reculer_pressed()
{
    direction = 4;
    cout<<"direction =  arriere "<<endl;
}

void MainWindow::on_reculer_released()
{
     direction = 5; // si touche relaché remise à 0
}

void MainWindow::on_droit_pressed()
{
    direction = 1;
    cout<<"direction =  droite "<<endl;
}

void MainWindow::on_droit_released()
{
    direction = 5; // si touche relaché remise à 0
}

void MainWindow::on_Speed_actionTriggered(int action)
{
    cout<<"michel "<<action <<endl;
    vitesse = action;
}

void MainWindow::on_Speed_valueChanged(int value)
{
    cout<<"michel "<<value <<endl;
    vitesse = value;
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Z:
        on_Avancer_pressed();
        break;
    case Qt::Key_Q:
        on_gauche_pressed();
        break;
    case Qt::Key_S:
        on_reculer_pressed();
        break;
    case Qt::Key_D:
        on_droit_pressed();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}
void MainWindow::wheelEvent(QWheelEvent *event){
    if (event->delta() > 0){
        ui->Speed->setValue(ui->Speed->value()+20);
    }else{
        ui->Speed->setValue(ui->Speed->value()-20);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Z:
        direction=5;
        break;
    case Qt::Key_Q:
        direction=5;
        break;
    case Qt::Key_S:
        direction=5;
        break;
    case Qt::Key_D:
        direction=5;
        break;
    default:
        direction =5;
        QWidget::keyReleaseEvent(event);
    }
}
