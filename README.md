python-openhmd
===========
Changes were made based on this commit:

https://github.com/OpenHMD/OpenHMD/commit/2a3b34b61298a63cab72c9b3d4f665088a329204

This build is untested.


Python OpenHMD bindings

## Dependencies

* OpenHMD http://openhmd.net/
* Cython

## Install
sudo apt-get install libudev-dev libusb-1.0-0-dev libfox-1.6-dev
sudo apt-get install autotools-dev autoconf automake libtool
git clone https://github.com/signal11/hidapi.git
cd hidapi
./bootstrap
./configure
make
sudo make install
cd ..
git clone https://github.com/OpenHMD/OpenHMD.git
cd OpenHMD
mkdir build
cd build
cmake ..   <---- see project readme for proper cmake commadn
make
sudo make install
cd ../..
git clone https://github.com/hephaestus9/python-openhmd.git
cd python-openhmd
sudo pip3 install cython
python3 setup.py install


## Arch Linux Package

* https://aur.archlinux.org/packages/python-rift-git/ (old python-rift version)

## Blog Post

* http://lubosz.wordpress.com/2013/06/26/oculus-rift-support-in-blender-game-engine/
