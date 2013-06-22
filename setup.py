#!/usr/bin/python

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
 
module1 = Extension("balanceboard", 
    ["balanceboard.pyx", "BalanceBoard.cpp"], 
    language="c++",
    libraries=["wiicpp"],
    include_dirs=['/usr/include/wiic'])
 
setup(name = 'balanceboard',
    version = '1.0',
    description = 'Python WiiCpp Wrapper',
    ext_modules=[module1],
    cmdclass = {'build_ext': build_ext})
