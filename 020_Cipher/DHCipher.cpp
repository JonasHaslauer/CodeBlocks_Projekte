#include "DHCipher.h"
#include <math.h>

dhcipher::dhcipher(int n, int g){
    srand(time(NULL));
    privateKey = rand();
    publicKey = (int) pow(g, privateKey) % n;
    n_ = n;
}

string dhcipher::encrypt(string s, int key){
    int k = (int) pow(key, privateKey) % n_;
    for(int i = 0; i < s.size(); i++){
        s[i] = xorsubstitution::encrypt((char) s[i], k);
    }
    return s;
}

string dhcipher::decrypt(string s, int key){
    int k = (int) pow(key, privateKey) % n_;
    for(int i = 0; i < s.size(); i++){
        s[i] = xorsubstitution::encrypt((char) s[i], k);
    }
    return s;
}
