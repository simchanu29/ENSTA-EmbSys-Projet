# Build script for linux on an armadeus
# Launch this script where it is located, aka at the root of the project

mkdir cmake-build-debug
cd cmake-build-debug
cmake -DCMAKE_TOOLCHAIN_FILE=Toolschains/armadeus.cmake ..
make