#ifndef _SM4_H_
#define _SM4_H_

void sm4_encrypt(unsigned char *output, const unsigned char *input, unsigned int inputLen, const unsigned char *MK);
void sm4_decrypt(unsigned char *output, const unsigned char *input, unsigned int inputLen, const unsigned char *MK);

#endif
