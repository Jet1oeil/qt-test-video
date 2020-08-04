# qt-test-video
Program de test pour fuite mémoire Buster + XOrg

apt install git make cmake g++ qtbase5-dev 

git clone https://github.com/Jet1oeil/qt-test-video.git
cd qt-test-video
mkdir build && cd build
cmake ../
make

./TestVideo [IMAGE_DIR] [INTERVAL_MS]
./TestVideo ./image 30
