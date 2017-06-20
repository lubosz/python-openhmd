CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(python-openhmd)

#SET(CMAKE_CXX_FLAGS "-g -Wall")
include_directories(
  /usr/include/openhmd/
)

ADD_EXECUTABLE(test test.cpp OpenHMD.cpp)
TARGET_LINK_LIBRARIES(test openhmd)
