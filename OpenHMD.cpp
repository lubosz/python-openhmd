#include <time.h>
#include <sys/time.h>
#include <stdio.h>

#include "OpenHMD.h"

OpenHMD::OpenHMD() {
  rotation = std::vector<float>(4);
  leftprojectionmatrix = std::vector<float>(16);
  rightprojectionmatrix = std::vector<float>(16);
  leftviewmatrix = std::vector<float>(16);
  rightviewmatrix = std::vector<float>(16);
  connect();
}

OpenHMD::~OpenHMD() {
  ohmd_ctx_destroy(ctx);
}

void OpenHMD::connect() {
	ctx = ohmd_ctx_create();

	// Probe for devices
	num_devices = ohmd_ctx_probe(ctx);
	if(num_devices < 0){
		printf("failed to probe devices: %s\n", ohmd_ctx_get_error(ctx));
		return;
	}

	// Open default device (0)
	hmd = ohmd_list_open_device(ctx, 0);
	
	if(!hmd){
		printf("failed to open device: %s\n", ohmd_ctx_get_error(ctx));
		return;
	}
}

void OpenHMD::printDeviceInfo() {

	printf("num devices: %d\n\n", num_devices);

	// Print device information
	for(int i = 0; i < num_devices; i++){
		printf("device %d\n", i);
		printf("  vendor:  %s\n", ohmd_list_gets(ctx, i, OHMD_VENDOR));
		printf("  product: %s\n", ohmd_list_gets(ctx, i, OHMD_PRODUCT));
		printf("  path:    %s\n\n", ohmd_list_gets(ctx, i, OHMD_PATH));
	}

	// Print hardware information for the opened device
	int ivals[2];
	ohmd_device_geti(hmd, OHMD_SCREEN_HORIZONTAL_RESOLUTION, ivals);
	ohmd_device_geti(hmd, OHMD_SCREEN_VERTICAL_RESOLUTION, ivals + 1);
	printf("resolution:         %i x %i\n", ivals[0], ivals[1]);

	print("hsize:",            1, OHMD_SCREEN_HORIZONTAL_SIZE);
	print("vsize:",            1, OHMD_SCREEN_VERTICAL_SIZE);
	print("lens separation:",  1, OHMD_LENS_HORIZONTAL_SEPARATION);
	print("lens vcenter:",     1, OHMD_LENS_VERTICAL_POSITION);
	print("left eye fov:",     1, OHMD_LEFT_EYE_FOV);
	print("right eye fov:",    1, OHMD_RIGHT_EYE_FOV);
	print("left eye aspect:",  1, OHMD_LEFT_EYE_ASPECT_RATIO);
	print("right eye aspect:", 1, OHMD_RIGHT_EYE_ASPECT_RATIO);
	print("distortion k:",     6, OHMD_DISTORTION_K);

	int bcount[1];
	ohmd_device_geti(hmd, OHMD_BUTTON_COUNT, bcount);
	printf("digital button count: %i\n", bcount[0]);
 
	printf("\n");
}

void OpenHMD::inputLoop() {
	// Ask for n rotation quaternions
	for(int i = 0; i < 10000; i++){
		poll();
		printSensors();
	}
}

void OpenHMD::printSensors() {
	  printf("rotation quat:");
	  for(int i = 0; i < 4; i++)
		  printf("%f ", rotation[i]);
	  printf("\n");
}

void OpenHMD::poll() {
    float rot[4];
    float matrix[16];
		ohmd_ctx_update(ctx);
		//Rotation Quaternion
		ohmd_device_getf(hmd, OHMD_ROTATION_QUAT, rot);
		for(int i = 0; i < 4; i++)
		  rotation[i] = rot[i];

		//Left Projection Matrix
		ohmd_device_getf(hmd, OHMD_LEFT_EYE_GL_PROJECTION_MATRIX, matrix);
		for(int i = 0; i < 16; i++)
		  leftprojectionmatrix[i] = matrix[i];

		//Left Modelview Matrix
		ohmd_device_getf(hmd, OHMD_LEFT_EYE_GL_MODELVIEW_MATRIX, matrix);
		for(int i = 0; i < 16; i++)
		  leftviewmatrix[i] = matrix[i];

		//Right Projection Matrix
		ohmd_device_getf(hmd, OHMD_RIGHT_EYE_GL_PROJECTION_MATRIX, matrix);
		for(int i = 0; i < 16; i++)
		  rightprojectionmatrix[i] = matrix[i];

		//Right Modelview Matrix
		ohmd_device_getf(hmd, OHMD_RIGHT_EYE_GL_MODELVIEW_MATRIX, matrix);
		for(int i = 0; i < 16; i++)
		  rightviewmatrix[i] = matrix[i];

		sleep(.01);
}

void OpenHMD::sleep(double seconds) {
	struct timespec sleepfor;
	sleepfor.tv_sec = (time_t)seconds;
	sleepfor.tv_nsec = (long)((seconds - sleepfor.tv_sec) * 1000000000.0);
	nanosleep(&sleepfor, NULL);
}


// gets float values from the device and prints them
void OpenHMD::print(std::string name, int len, ohmd_float_value val) {
	float f[len];
	ohmd_device_getf(hmd, val, f);
	printf("%-20s", name.c_str());
	for(int i = 0; i < len; i++)
		printf("%f ", f[i]);
	printf("\n");
}

void OpenHMD::reset(){
  ohmd_ctx_destroy(ctx);
  sleep(.1);
  connect();
}
