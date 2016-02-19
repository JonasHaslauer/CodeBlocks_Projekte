#include "cipher.h"

string cipher::encrypt(string s, int key){
    for(int i = 0; i < s.size(); i++){
        s[i] = encrypt((char) s[i], key);
    }
    return s;
}

string cipher::decrypt(string s, int key){
    for(int i = 0; i < s.size(); i++){
        s[i] = decrypt((char) s[i], key);
    }
    return s;
}
