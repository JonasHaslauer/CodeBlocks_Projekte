#include "streamCipher.h"

using namespace std;

#ifndef DHCIPHER_H
#define DHCIPHER_H

class dhcipher : public xorsubstitution{
    private:
        int publicKey;
        int privateKey;
        int n_;

    public:
        dhcipher(int n, int g);
        string encrypt(string s, int key);
		string decrypt(string s, int key);

		int getPublicKey(){return publicKey;}

};

#endif // DHCIPHER_H
