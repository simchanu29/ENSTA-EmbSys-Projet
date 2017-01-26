set(TOOLS
        utility/MorseTools.cpp
        utility/GpioTools.cpp
        utility/CryptoTools.cpp
        utility/NetworkTools.cpp)

set(SOURCE_MAIN
        main.cpp
        ${TOOLS})

# Main
add_executable(out.out ${SOURCE_MAIN})

# Units tests
add_executable(unitTest_tools.out ${TOOLS} tests/unitTest_tools.cpp)

# Units test client
add_executable(client.out  tests/client.c)
# Units test server
add_executable(server.out  tests/server.c)
