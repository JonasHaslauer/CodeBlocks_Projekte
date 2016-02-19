#include "streamCipher.h"

string streamCipher::encrypt(string s, int key){
    srand(key);

    for(int i = 0; i < s.size(); i++){
        s[i] = xorsubstitution::encrypt((char) s[i], rand());
    }
    return s;
}

string streamCipher::decrypt(string s, int key){
    srand(key);

    for(int i = 0; i < s.size(); i++){
        s[i] = xorsubstitution::decrypt((char) s[i], rand());
    }
    return s;
}
