#include <openhmd.h>
#include <string>

class Rift {
  ohmd_context* ctx;
  ohmd_device* hmd;
  int num_devices;
  float rotation[4];
  
 public:
  Rift();
  ~Rift();

  void inputLoop();
  void printDeviceInfo();
  void poll();
  void printSensors();

 private:
  void print(std::string name, int len, ohmd_float_value val);
  void sleep(double seconds);
};
