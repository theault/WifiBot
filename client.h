#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include <iostream>
#include <string.h>
#include <string>
#include <unistd.h>
#ifndef CLIENT_H
#define CLIENT_H

using namespace std;
class Client
{
public:
    Client(string ip, int port);
    void launch();
    void Communication(int direction, int vitesse);
    void receive();
    void Direction(int direction, int vitesse);
    quint16 Crc16(QByteArray* byteArray, int pos);

private:
    int port;
    QString ip;
    QTcpSocket* socket;
    char VitroueA;
    char VitroueB;
    char flag;
};

#endif // CLIENT_H
