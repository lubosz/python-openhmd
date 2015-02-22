#!/usr/bin/python

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

module1 = Extension("rift",
    ["pyrift.pyx", "Rift.cpp"],
    language="c++",
    libraries=["openhmd"],
    include_dirs=['/usr/include/openhmd','/usr/local/include/openhmd'])

setup(name = 'rift',
    version = '1.0',
    description = 'Python OpenHMD Wrapper',
    ext_modules=[module1],
    cmdclass = {'build_ext': build_ext})
