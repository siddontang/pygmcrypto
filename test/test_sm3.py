#coding:utf-8

from gmcrypto import sm3

a = sm3.new("abc")
assert(a.hexdigest() == "66c7f0f462eeedd9d1f2d46bdc10e4e24167c4875cf2f7a2297da02b8f4ba8e0")

b = sm3.new("abcd" * 16)

assert(b.digest() == b"\xde\xbe\x9f\xf9\x22\x75\xb8\xa1\x38\x60\x48\x89\xc1\x8e\x5a\x4d\x6f\xdb\x70\xe5\x38\x7e\x57\x65\x29\x3d\xcb\xa3\x9c\x0c\x57\x32")

print 'all test!!!'