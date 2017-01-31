set(TOOLS
        utility/MorseTools.cpp
        utility/GpioTools.cpp
        utility/CryptoTools.cpp
        utility/NetworkTools.cpp)

# Server executable
add_executable(main-server.out ${TOOLS} main-server.cpp)

# Client executable
add_executable(main-client.out main-client.c)
