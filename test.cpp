#include "OpenHMD.h"

int main(int argc, char** argv) {
  OpenHMD * openhmd = new OpenHMD();
  openhmd->printDeviceInfo();
  openhmd->inputLoop();	
	return 0;
}
