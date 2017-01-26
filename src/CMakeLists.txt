set(TOOLS
        MorseTools.cpp
        GpioTools.cpp
        CryptoTools.cpp
        NetworkTools.cpp)


# Units tests
add_executable(server.out ${TOOLS} server.cpp)

# Units tests
add_executable(client.out  client.c)
