python-openhmd
==============

Python OpenHMD bindings

## Dependencies

* OpenHMD http://openhmd.net/
* Cython

## Install

```
$ ./setup.py install
```

## Arch Linux Package

* https://aur.archlinux.org/packages/python-rift-git/ (old python-rift version)

## Original Blog Post

* http://lubosz.wordpress.com/2013/06/26/oculus-rift-support-in-blender-game-engine/ (old python-rift version)


## Detailed Installation Instruction

### Debian based Linux Distro

Install Blender:

1. `sudo apt-get install blender`

Install OpenHMD:

1. `sudo apt-get install libopenhmd0 libopenhmd-dev`

Install Python3 and Cython3

1. `sudo apt-get install python3`
1. `pip3 install cython`

Install python-openhmd:

1. `sudo mkdir /usr/local/src`
1. `cd /usr/local/src`
1. `sudo git clone https://github.com/lubosz/python-rift.git`
1. `cd python-rift`
1. `sudo python3 setup.py build`
1. `sudo python3 setup.py install`

Enter Blender to Check if Installation 0K:

1. `blender`
1. choose: Python Console Editor
1. type: `from openhmd import PyOpenHMD`



## macOSX with brew installed

Install Blender (inclusive Python3):

1. `brew cask install blender`

Find out the exact installed Blender Python version 

1. `/Applications/Blender.app/Contents/Resources/2.X/python/bin/python3.Xm -V`

Install Python Header Files

1. point your browser at https://www.python.org/downloads/source/
1. download Gzipped source tarball from the exact same Python version as your Blender Python Version
1. `cd ~/Downloads/`
1. `tar -xzf Python-3.X.X.tgz`
1. `cp Python-3.X.X/Include/* /Applications/Blender.app/Contents/Resources/2.X/python/include/python3.Xm/`

Install Cython3 and 

1. `cd /Applications/Blender.app/Contents/Resources/2.X/python/bin/`
1. `curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py`
1. `./python3.Xm get-pip.py`
1. `./pip3 install cython`

Install OpenHMD:

1. `brew install openhmd`
1. `cp /usr/local/include/openhmd/openhmd.h /Applications/Blender.app/Contents/Resources/2.X/python/include/python3.Xm/`

Install python-openhmd:

1. `cd /Applications/Blender.app/Contents/Resources/2.X/python/lib/`
1. `git clone https://github.com/lubosz/python-rift.git`
1. `cd python-rift`
1. `../../bin/python3.Xm setup.py build`
1. `clang++ -bundle -undefined dynamic_lookup -arch x86_64 -arch x86_64 build/temp.macosx-10.X-intel-3.X/pyopenhmd.o build/temp.macosx-10.X-intel-3.X/OpenHMD.o -lopenhmd -o build/lib.macosx-10.X-intel-3.X/openhmd.cpython-3Xm-darwin.so`
1. `../../bin/python3.Xm setup.py install`

Enter Blender to Check if Installation 0K:

1. `blender`
1. choose: Python Console Editor
1. type: `from openhmd import PyOpenHMD`



## MS Windows

* to be done


# Blender and Your OpenHMD Devise

You can download this example blender file to see if now, after installation, your OpenHMD device works with the Blender game engine. 

1. https://docs.google.com/file/d/0B0bLtNyAhxgoZlgycFN4NHRNLTQ/edit
