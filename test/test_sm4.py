#coding:utf-8

from gmcrypto import sm4

data = b'\x01\x23\x45\x67\x89\xab\xcd\xef\xfe\xdc\xba\x98\x76\x54\x32\x10'
key = data

obj = sm4.new(key)

encData = obj.encrypt(data)
decData = obj.decrypt(encData)

assert(decData == data)

assert(encData == b'\x68\x1e\xdf\x34\xd2\x06\x96\x5e\x86\xb3\xe9\x4f\x53\x6e\x42\x46')

temp = data
for i in xrange(1000000):
    temp = obj.encrypt(temp)

assert(temp == b'\x59\x52\x98\xc7\xc6\xfd\x27\x1f\x04\x02\xf8\x04\xc3\x3d\x3f\x66')

print 'all test!!!'