#!/usr/bin/python

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
 
module1 = Extension("openhmd", 
    ["pyopenhmd.pyx", "OpenHMD.cpp"],
    language="c++",
    libraries=["openhmd"],
    include_dirs=['/usr/include/openhmd'])
 
setup(name = 'openhmd',
    version = '1.0',
    description = 'Python OpenHMD Wrapper',
    ext_modules=[module1],
    cmdclass = {'build_ext': build_ext})
