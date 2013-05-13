%module sm4
%{
#include "sm4_cl.hpp"
%}

%typemap(in) (unsigned char key[16]) {
   $1 = (unsigned char*)PyString_AsString($input);
   {
       int keyLen = PyString_Size($input);
       if(keyLen != 0x10)
       {
           PyErr_Format(PyExc_ValueError, "Crypto Key %u must be 16 bytes in length", keyLen);       
           return NULL;
       }
   }
}

%typemap(in) (unsigned char* output, const unsigned char* input, int inputLen) {
   $2 = (unsigned char*)PyString_AsString($input);
   $3 = PyString_Size($input);

   if($3 & 0x0000000F)
   {
       PyErr_Format(PyExc_ValueError, 
             "Input strings must be "
             "a multiple of 16 bytes in length");
   }

   $1 = (unsigned char*)malloc($3);
}

%typemap(argout) (unsigned char* output, const unsigned char* input, int inputLen) {
   Py_XDECREF($result);
   $result = PyString_FromStringAndSize((const char*)$1, $3);
   free($1);
}

class SM4 {

public:
    SM4(unsigned char key[16]);
    ~SM4();

    void encrypt(unsigned char* output, const unsigned char* input, int inputLen);
    void decrypt(unsigned char* output, const unsigned char* input, int inputLen);

%immutable;
    static unsigned int block_size;
    static unsigned int key_size;
    static const char* name;
%mutable;
};


%pythoncode %{
def new(key):
    return SM4(key)       

%}