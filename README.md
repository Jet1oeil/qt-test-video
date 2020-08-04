# qt-test-video
Program that reproduce the memory leak problem with XOrg :

Tested environement :
- Shuttle XH310
- Intel Core i7-7700
- Debian 10 Buster 64 bits
- qtbase5-dev (5.11.3+dfsg1-1+deb10u3) 
- xserver-xorg (1:7.7+19)
- Mate 1.20.4
- linux amd64 4.19.0-9

Install dependencies :
```
apt install git make cmake g++ qtbase5-dev
```

Build the project :
```
git clone https://github.com/Jet1oeil/qt-test-video.git
cd qt-test-video
mkdir build && cd build
cmake ../
make
```

Usage :
```
./TestVideo [IMAGE_DIR] [INTERVAL_MS]
./TestVideo ./image 30
```
