#include <string>
#include "streamCipher.h"
#include "DHCipher.h"

#include <cstdio>
#include <iostream>

using namespace std;

int main (int argc, char* argv[])
{
    string plainText;
    int key = 23;
    int g = 5;
    int n = 3;

    //plainText = string(argv[1]);
    plainText = "Hello World";

    /*
    Unverschluesselter Text
    */
    for (int i=0; i< plainText.size(); i++)
    {
        cout << plainText[i];
    }
    cout << endl;

    //sscanf(argv[2], "%i", &key);

    //cipher* ciph = new xorsubstitution();
    //streamCipher* ciph = new streamCipher();
    dhcipher* ciph1 = new dhcipher(n, g);
    dhcipher* ciph2 = new dhcipher(n, g);



    string cryptText = ciph1->encrypt(plainText, ciph2->getPublicKey());

    /*
    Die Bytes des verschlüsselten Textes werden auf der Konsole gezeigt. In der Regel kann dieser String nicht lesbar ausgegeben werden, weil bei der Verschlüsselung nichtdruckbare Zeichen entstehen.
    */
    cout << "[ ";
    for (int i=0; i< cryptText.size() -1; i++)
    {
        cout << (int) cryptText[i] << "," ;
    }
    cout << (int) cryptText[cryptText.size() -1];
    cout << " ]" << endl;

    /*
    Verschluesselten Text ausgeben
    */
    for (int i=0; i< cryptText.size(); i++)
    {
        cout << cryptText[i];
    }
    cout << endl;

    /*
    Schließlich wird der Geheimtext wieder dechiffriert und zur Kontrolle mit dem ursprünglichen Klartext verglichen. Die Ausgabe müsste true lauten:
    */
    string decoded = ciph2->decrypt(cryptText, ciph1->getPublicKey());

    /*
    Entschluesselten Text wieder ausgeben
    */
    for (int i=0; i< decoded.size(); i++)
    {
        cout << decoded[i];
    }
    cout << endl;

    if (plainText == decoded)
        cout << "true" <<endl;
    else
        cout << "false" <<endl;

    //delete ciph;
    delete ciph1;
    delete ciph2;

    return 0;
}
