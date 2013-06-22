#!/usr/bin/python

from balanceboard import PyBalanceBoard

foo = PyBalanceBoard.getInstance()

while foo.hasWiiMotes():
  foo.poll()
  #print(foo.topLeft)
  foo.printSensors()
