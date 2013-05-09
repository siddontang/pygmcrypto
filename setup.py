#coding:utf-8
#siddontang@gmail.com

from distutils.core import setup, Extension

setup(name = "gmcrypto", 
    version = "0.1",
    maintainer = "Siddon Tang",
    maintainer_email = "siddontang@gmail.com",
    description = "Implementation for Chinese National Standard Ciphers",
    packages = ["gmcrypto"],
    ext_modules = [Extension("gmcrypto.sm4", sources = ["src/sm4.c", "src/pysm4.c"])]
    )
