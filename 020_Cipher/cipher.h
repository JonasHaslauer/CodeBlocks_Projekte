#include <string>
using namespace std;

#ifndef CIPHER_H
#define CIPHER_H

class cipher{
	public:
		string encrypt(string s, int key);
		string decrypt(string s, int key);

		// Die Unterklassen müssen diese Methoden implementieren
		virtual char encrypt(char ch, int key)=0;
		virtual char decrypt(char ch, int key)=0;
};

#endif
