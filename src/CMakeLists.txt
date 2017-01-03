set(TOOLS
        utility/MorseTools.cpp
        utility/GpioTools.cpp
        utility/CryptoTools.cpp
        utility/NetworkTools.cpp)

set(SOURCE_MAIN
        main.cpp
        ${TOOLS})

# Main
add_executable(out.o ${SOURCE_MAIN})

# Units tests
add_executable(unitTest_tools.o ${TOOLS} tests/unitTest_tools.cpp)