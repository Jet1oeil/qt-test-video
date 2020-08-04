# qt-test-video
Program that reproduce the memory leak problem of XOrg on Debian Buster with Qt 5.11.3.

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
