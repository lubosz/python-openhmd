#include <time.h>
#include <sys/time.h>
#include <stdio.h>

#include "Rift.h"

Rift::Rift() {
  rotation = std::vector<float>(4);

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

Rift::~Rift() {
  ohmd_ctx_destroy(ctx);
}

void Rift::printDeviceInfo() {

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

	printf("\n");
}

void Rift::inputLoop() {
	// Ask for n rotation quaternions
	for(int i = 0; i < 10000; i++){
		poll();
		printSensors();
	}
}

void Rift::printSensors() {
	  printf("rotation quat:");
	  for(int i = 0; i < 4; i++)
		  printf("%f ", rotation[i]);
	  printf("\n");
}

void Rift::poll() {
    float rot[4];
		ohmd_ctx_update(ctx);
		ohmd_device_getf(hmd, OHMD_ROTATION_QUAT, rot);
		for(int i = 0; i < 4; i++)
		  rotation[i] = rot[i];
		sleep(.01);
}

void Rift::sleep(double seconds) {
	struct timespec sleepfor;
	sleepfor.tv_sec = (time_t)seconds;
	sleepfor.tv_nsec = (long)((seconds - sleepfor.tv_sec) * 1000000000.0);
	nanosleep(&sleepfor, NULL);
}


// gets float values from the device and prints them
void Rift::print(std::string name, int len, ohmd_float_value val) {
	float f[len];
	ohmd_device_getf(hmd, val, f);
	printf("%-20s", name.c_str());
	for(int i = 0; i < len; i++)
		printf("%f ", f[i]);
	printf("\n");
}
