#include "Rift.h"

int main(int argc, char** argv) {
  Rift * rift = new Rift();
  rift->printDeviceInfo();
  rift->inputLoop();	
	return 0;
}
