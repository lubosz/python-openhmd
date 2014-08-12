from libcpp.vector cimport vector

cdef extern from "Rift.h":
    cdef cppclass Rift:
        Rift()
        
        vector[float] rotation

        void printDeviceInfo()
        void poll()
        void reset()
        void printSensors()
        void inputLoop()
        

cdef class PyRift:
    cdef Rift* thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self):
        self.thisptr = new Rift()
    def __dealloc__(self):
        del self.thisptr
 
    def printSensors(self):
        self.thisptr.printSensors()
        
    def poll(self):
        self.thisptr.poll()

    def reset(self):
        self.thisptr.reset()

    def inputLoop(self):
        self.thisptr.inputLoop()

    def printDeviceInfo(self):
        self.thisptr.printDeviceInfo()

    property rotation:
      def __get__(self): return self.thisptr.rotation
