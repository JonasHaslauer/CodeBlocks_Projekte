#include "xorsubstitution.h"

#ifndef STREAMCIPHER_H
#define STREAMCIPHER_H

class streamCipher : public xorsubstitution{
	public:
		string encrypt(string s, int key);
		string decrypt(string s, int key);
};

#endif
