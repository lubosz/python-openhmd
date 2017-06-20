#include <openhmd.h>
#include <string>
#include <vector>

class OpenHMD {
  ohmd_context* ctx;
  ohmd_device* hmd;
  int num_devices;
  
 public:
  OpenHMD();
  ~OpenHMD();

  std::vector<float> rotation;
  std::vector<float> leftprojectionmatrix;
  std::vector<float> leftviewmatrix;
  std::vector<float> rightprojectionmatrix;
  std::vector<float> rightviewmatrix;

  void inputLoop();
  void printDeviceInfo();
  void poll();
  void printSensors();
  void reset();

 private:
  void print(std::string name, int len, ohmd_float_value val);
  void sleep(double seconds);
  void connect();
};
