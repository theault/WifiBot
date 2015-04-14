#include "client.h"



Client::Client(string ip, int port )
{
    this->ip=ip.c_str();
    this->port=port;
    socket= new QTcpSocket();
}

void Client::launch()
{
    cout << "avant" << endl;
   socket->connectToHost(ip ,port ); // connexion au robot sur le port et l'adresse ip spécifié
   bool test = socket->waitForConnected(5000);

   if(test)
       ui->Status->setStyleSheet("QLabel#Status { background: green }");
       cout<<"connexion réussi"<<endl;
}

void Client::Communication( int direction, int vitesse )
{
    usleep(100000);
    QByteArray package ;

    Direction(direction, vitesse);

    package.clear();
    package.append((char)0xff);
    package.append((char)0x07);
    package.append((char) VitroueA);
    package.append((char)0);
    package.append((char) VitroueB);
    package.append((char)0);
    package.append((char)80);

    quint16 crc = Crc16( &package, 1); // calcul du crc du package envoyé
    package.append((char)crc);
    package.append((char)(crc>>8));

    socket->write(package);
    socket->flush();

    receive();
}

void Client::Direction(int direction, int vitesse)
{
    switch(direction){
        case 1 :   VitroueA = vitesse;// tourner à droite
                   VitroueB = ((vitesse/100)*60);
                   break;

        case 2 :    VitroueA =  ((vitesse/100)*60); //tourner à gauche
                    VitroueB = vitesse;
                    break;

        case 3 :    VitroueA =  vitesse;//continuer tout droit
                    VitroueB =  vitesse;
                    break;

        case 4 :    VitroueA =   vitesse;// aller en arriere
                    VitroueB =   vitesse;
                    break;

         default : cout<< "erreur direction "<<endl;
                   VitroueA =0;
                   VitroueB =0;
                   break;
    }
}

void Client::receive()
{
    char sbuf[21];
     socket->read( sbuf, 21);

         int SpeedFront=(int)((sbuf[1] << 8) + sbuf[0]);
         cout << SpeedFront<<endl;
         if(SpeedFront > 32767)
            SpeedFront=SpeedFront-65536;
         int BatLevel=sbuf[2];
         ui->progressBar->setValue(BatLevel);
         char IR=sbuf[3];
         char IR2=sbuf[4];
         int SpeedFront1=(int)(sbuf[10] << 8) + sbuf[9];
          cout << SpeedFront1<<endl;
         if(SpeedFront1 > 32767)
             SpeedFront1=SpeedFront1-65536;
         char IRbis=sbuf[11];
         char IR2bis=sbuf[12];
         char Current1=sbuf[17];
         char Current2=sbuf[17];

         cout<<"test :: "<< SpeedFront << " level bat "<<BatLevel << " vitesse " << SpeedFront1 <<endl;
}

quint16 Client::Crc16(QByteArray* byteArray, int pos){
    unsigned char *data = (unsigned char* )byteArray->constData();
    quint16 crc = 0xFFFF;
    quint16 Polynome = 0xA001;
    quint16 Parity = 0;
    for(; pos < byteArray->length(); pos++){
        crc ^= *(data+pos);
        for (unsigned int CptBit = 0; CptBit <= 7 ; CptBit++){
            Parity= crc;
            crc >>= 1;
            if (Parity%2 == true) crc ^= Polynome;
        }
    }
    return crc;
}
