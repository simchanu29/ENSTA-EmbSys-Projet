set(TOOLS
        utility/MorseTools.cpp
        utility/GpioTools.cpp
        utility/CryptoTools.cpp
        utility/NetworkTools.cpp)

# Units tests
add_executable(server.out ${TOOLS} network/server.cpp)

# Units tests
add_executable(client.out network/client.c)
