#ifndef _GMCRYPTO_SM4_HPP_
#define _GMCRYPTO_SM4_HPP_

extern "C" {
    #include "sm4.h"    
}

class SM4 
{
public:
    SM4(unsigned char key[16]);
    ~SM4();

    void encrypt(unsigned char* output, const unsigned char* input, int inputLen);
    void decrypt(unsigned char* output, const unsigned char* input, int inputLen);

    static unsigned int block_size;
    static unsigned int key_size;
    static const char* name;

private:
    sm4_context         m_context;
    unsigned char       m_key[16];
};

#endif
