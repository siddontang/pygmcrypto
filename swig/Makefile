SWIG=swig 

PYDIR="../gmcrypto"
SRCDIR="../src"

all : sm3 sm4

sm3 : sm3.i
	swig -c++ -python -outdir $(PYDIR) -o $(SRCDIR)/sm3_wrap.cpp sm3.i

sm4 : sm4.i
	swig -c++ -python -outdir $(PYDIR) -o $(SRCDIR)/sm4_wrap.cpp sm4.i


clean:
	rm -rf $(PYDIR)/sm3.py
	rm -rf $(PYDIR)/sm4.py
	rm -rf $(SRCDIR)/sm3_wrap.cpp
	rm -rf $(SRCDIR)/sm4_wrap.cpp

