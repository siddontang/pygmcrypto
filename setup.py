#coding:utf-8
#siddontang@gmail.com

from distutils.core import setup, Extension

setup(name = "gmcrypto", 
    version = "0.1",
    maintainer = "Siddon Tang",
    maintainer_email = "siddontang@gmail.com",
    description = "Implementation for Chinese National Standard Ciphers",
    packages = ["gmcrypto"],
    ext_modules = [Extension("gmcrypto._sm3", sources = ["src/sm3.c", "src/sm3_cl.cpp", "src/sm3_wrap.cpp"]),
                   Extension("gmcrypto._sm4", sources = ["src/sm4.c", "src/sm4_cl.cpp", "src/sm4_wrap.cpp"])]
    )
