#include <string.h>
#include "sm4_cl.hpp"

unsigned int SM4::block_size = 16;
unsigned int SM4::key_size = 16;
const char* SM4::name = "sm4";

SM4::SM4(unsigned char key[16])
{
    memcpy(m_key, key, 16);
    memset(&m_context, 0, sizeof(sm4_context));
}

SM4::~SM4()
{

}

void SM4::encrypt(unsigned char* output,  const unsigned char* input, int inputLen)
{
    sm4_setkey_enc(&m_context, m_key);
    sm4_crypt_ecb(&m_context, SM4_ENCRYPT, inputLen, (unsigned char*)input, output);
}

void SM4::decrypt(unsigned char* output,  const unsigned char* input, int inputLen)
{
    sm4_setkey_dec(&m_context, m_key);
    sm4_crypt_ecb(&m_context, SM4_DECRYPT, inputLen, (unsigned char*)input, output);
}
