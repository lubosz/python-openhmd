#!/usr/bin/python

from rift import PyRift

foo = PyRift()

while True:
  foo.poll()
  print("rotation quat: %f %f %f %f" % (foo.rotation[0], 
    foo.rotation[1], 
    foo.rotation[2], 
    foo.rotation[3]))
