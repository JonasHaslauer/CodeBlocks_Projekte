#include "cipher.h"

#ifndef XORSUBSTITUTION_H
#define XORSUBSTITUTION_H

class xorsubstitution : public cipher
{
protected:
    char encrypt(char ch, int key)
    {
        return ch ^ key;
    }
    char decrypt(char ch, int key)
    {
        return ch ^ key;
    }
};

#endif

