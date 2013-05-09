/*
    python wrapper for sm4
*/

#include "Python.h"
#include "sm4.h"

static PyObject * crypto(PyObject *self, PyObject *args, int encryptFlag)
{
    unsigned char *input;
    int inputLen;

    unsigned char *key;
    int keyLen;

    unsigned char *output;

    PyObject *result;

    if(!PyArg_ParseTuple(args, "s#s#", &input, &inputLen, &key, &keyLen))
        return NULL;

    if(inputLen == 0)         
    {
        return PyBytes_FromStringAndSize(NULL, 0);
    }

    if(inputLen & 0x0000000F)
    {
        PyErr_Format(PyExc_ValueError, 
                 "Input strings must be "
                 "a multiple of 16 bytes in length");
        return NULL;
    }

    if(keyLen != 0x10)
    {
        PyErr_Format(PyExc_ValueError, 
                 "Crypto Key %u must be 16 bytes in length", keyLen);
        return NULL;        
    }

    output = (unsigned char*)malloc(inputLen);
    if (output == NULL) 
    {
        PyErr_SetString(PyExc_MemoryError, 
                "Not enough memory");
        return NULL;
    }
    Py_BEGIN_ALLOW_THREADS;

    if (encryptFlag)
    {
        sm4_encrypt(output, input, inputLen, key);   
    }
    else
    {
        sm4_decrypt(output, input, inputLen, key);   
    }

    Py_END_ALLOW_THREADS;

    result=PyBytes_FromStringAndSize((char *)output, inputLen);

    free(output);
    return(result);
}

static PyObject * py_encrypt(PyObject *self, PyObject *args)
{
    return crypto(self, args, 1);
}

static PyObject * py_decrypt(PyObject *self, PyObject *args)
{
    return crypto(self, args, 0);
}

static PyMethodDef CryptoMethods[] = 
{
    {"encrypt", py_encrypt, METH_VARARGS, "sm4 encrypt function"},
    {"decrypt", py_decrypt, METH_VARARGS, "sm4 decrypt function"},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initsm4()
{
    Py_InitModule("gmcrypto.sm4", CryptoMethods);
}
