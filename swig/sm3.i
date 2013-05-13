%module sm3
%{
#include "sm3_cl.hpp"
%}


%typemap(in) (const unsigned char* input, int inputLen) {
    $1 = (unsigned char*)PyString_AsString($input);
    $2 = PyString_Size($input);
}


%typemap(in, numinputs = 0) unsigned char [ANY] (unsigned char temp[$1_dim0]) {
    $1 = temp;
}

%typemap(argout) unsigned char [ANY] {
    Py_XDECREF($result);
    $result = PyString_FromStringAndSize((const char*)$1, $1_dim0);
}


class SM3 
{
public:
    SM3(const unsigned char* input, int inputLen);
    ~SM3();

    void update(const unsigned char* input, int inputLen);
    void digest(unsigned char output[32]);
    void hexdigest(unsigned char output[64]);
    SM3 copy();

%immutable;
    static unsigned int block_size;
    static unsigned int digest_size;
    static unsigned int digestsize;
    static const char* name;
%mutable;
};

%pythoncode %{
def new(key):
    return SM3(key)  

%}