set(TOOLS
        utility/MorseTools.cpp
        utility/GpioTools.cpp
        utility/CryptoTools.cpp
        utility/NetworkTools.cpp)

# Units tests
add_executable(server.out ${TOOLS} main-server.cpp)

# Units tests
add_executable(client.out main-client.c)
