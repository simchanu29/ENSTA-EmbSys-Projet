# Build script for linux on a raspberry
# Launch this script where it is located, aka at the root of the project

mkdir cmake-build-debug
cd cmake-build-debug
cmake -DCMAKE_TOOLCHAIN_FILE=Toolschains/raspberry.cmake ..
make