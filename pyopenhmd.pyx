from libcpp.vector cimport vector

cdef extern from "OpenHMD.h":
    cdef cppclass OpenHMD:
        OpenHMD()
        
        vector[float] rotation
        vector[float] leftprojectionmatrix
        vector[float] leftviewmatrix
        vector[float] rightprojectionmatrix
        vector[float] rightviewmatrix

        void printDeviceInfo()
        void poll()
        void reset()
        void printSensors()
        void inputLoop()
        

cdef class PyOpenHMD:
    cdef OpenHMD* thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self):
        self.thisptr = new OpenHMD()
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
    property leftprojectionmatrix:
      def __get__(self): return self.thisptr.leftprojectionmatrix
    property leftviewmatrix:
      def __get__(self): return self.thisptr.leftviewmatrix
    property rightprojectionmatrix:
      def __get__(self): return self.thisptr.rightprojectionmatrix
    property rightviewmatrix:
      def __get__(self): return self.thisptr.rightviewmatrix