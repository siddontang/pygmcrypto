#ifndef _GMCRYPTO_SM3_HPP_
#define _GMCRYPTO_SM3_HPP_

extern "C"
{
    #include "sm3.h"
}

class SM3 
{
public:
    SM3(const unsigned char* input, int inputLen);
    SM3(const SM3& obj);
    ~SM3();

    void update(const unsigned char* input, int inputLen);
    void digest(unsigned char output[32]);
    void hexdigest(unsigned char output[64]);
    
    SM3 copy();

    static unsigned int block_size;
    static unsigned int digest_size;
    static unsigned int digestsize;
    static const char* name;

private:
    sm3_context    m_context;
};


#endif