#include <iostream>
#include "client.h"

using namespace std;

int main()
{
    Client test("192.168.1.106",15020);
    test.launch();
    for(int i=0; i<50; i++)
     {
        test.Communication(1 , 200);
     }
    for(int i=0; i<50; i++)
     {
        test.Communication(2 , 200);
     }
    for(int i=0; i<50; i++)
     {
        test.Communication(3 , 200);
     }
    for(int i=0; i<50; i++)
     {
        test.Communication(4 , 200);
     }
    for(int i=0; i<50; i++)
     {
        test.Communication(5 , 120);
     }
    cout << "fin communication"<<endl;
    return 0;
}

