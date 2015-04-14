#include <iostream>
#include <QApplication>
#include "client.h"
#include "mainwindow.h"
#include"ui_mainwindow.h"
#include <QTimer>
using namespace std;


 void update()
{
    cout<<"hello"<<endl;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow wnd;
    wnd.show();
    return app.exec();
}
