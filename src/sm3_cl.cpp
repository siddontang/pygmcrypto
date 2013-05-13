#include <string.h>

#include "sm3_cl.hpp"

unsigned int SM3::block_size = 64;
unsigned int SM3::digest_size = 32;
unsigned int SM3::digestsize = 32;
const char* SM3::name = "sm3";

SM3::SM3(const unsigned char* input, int inputLen)
{
    memset(&m_context, 0, sizeof(sm3_context));

    sm3_starts(&m_context);

    if (inputLen > 0)
    {
        update(input, inputLen);
    }
}

SM3::SM3(const SM3& obj)
{
    memcpy(&m_context, &obj.m_context, sizeof(sm3_context));
}

SM3::~SM3()
{

}

void SM3::update(const unsigned char* input, int inputLen)
{
    sm3_update(&m_context, (unsigned char*)input, inputLen);   
}

void SM3::digest(unsigned char output[32])
{
    sm3_context temp;
    memcpy(&temp, &m_context, sizeof(sm3_context));    

    sm3_finish(&temp, output);
}

void SM3::hexdigest(unsigned char output[64])
{
    unsigned char raw[32];
    int i, j;
    digest(raw);

    for(i = j = 0; i < 32; i++)
    {
        char c;
        c = raw[i] / 16; 
        c = (c > 9) ? c +'a'-10 : c + '0';
        output[j++] = c;
        c = raw[i] % 16; 
        c = (c > 9) ? c +'a'-10 : c + '0';
        output[j++] = c;
    }
}
    
SM3 SM3::copy()
{
    return SM3(*this);
}
