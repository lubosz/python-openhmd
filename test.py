#!/usr/bin/python

from openhmd import PyOpenHMD

foo = PyOpenHMD()

while True:
  foo.poll()
  print("rotation quat: %f %f %f %f" % (foo.rotation[0], 
    foo.rotation[1], 
    foo.rotation[2], 
    foo.rotation[3]))
