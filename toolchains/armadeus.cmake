##
## toolchain.cmake
##

## ==== Settings Section ====

## ---- Armadeus subsection ----
# set the Armadeus board (comments/uncomment according to your board)
set(ARMADEUS_BOARD            "APF27")
# set(ARMADEUS_BOARD            "APF9328")

# set the uClibc version
set(ARMADEUS_UCLIBC_VERSION   "0.9.29")

# set the Armadeus root path
set(ARMADEUS_ROOT             "/path/to/your/armadeus/sdk")

## ---- CMake subsection ----
# this one is important
set(CMAKE_SYSTEM_NAME         "Linux")
# this one not so much
set(CMAKE_SYSTEM_VERSION      "1")


## ==== CMake Variables ====

if(ARMADEUS_BOARD STREQUAL "APF27")
    set(ARMADEUS_MARCH          "armv5te")
elseif(ARMADEUS_BOARD STREQUAL "APF9328")
    set(ARMADEUS_MARCH          "armv4t")
else(ARMADEUS_BOARD STREQUAL "APF27")
    message("\n"
            "===========================================================\n"
            "= Cannot determine the target                             =\n"
            "===========================================================\n"
            )
endif(ARMADEUS_BOARD STREQUAL "APF27")

set(ARMADEUS_ROOT_BR          ${ARMADEUS_ROOT}/buildroot)
set(ARMADEUS_ROOT_CTC         ${ARMADEUS_ROOT_BR}/build_${ARMADEUS_MARCH}/staging_dir)
set(ARMADEUS_ROOT_CTC_BINDIR  ${ARMADEUS_ROOT_CTC}/usr/bin)
set(ARMADEUS_CTC_PREFIX       "arm-linux-")

# specify the cross-toolchain (compiler, header and library directories)
set(CMAKE_C_COMPILER          ${ARMADEUS_ROOT_CTC_BINDIR}/${ARMADEUS_CTC_PREFIX}gcc)
set(CMAKE_CXX_COMPILER        ${ARMADEUS_ROOT_CTC_BINDIR}/${ARMADEUS_CTC_PREFIX}g++)
set(CMAKE_INCLUDE_PATH        ${ARMADEUS_ROOT_BR}/toolchain_build_${ARMADEUS_MARCH}/uClibc-${ARMADEUS_UCLIBC_VERSION}/include)
set(CMAKE_LIBRARY_PATH        ${ARMADEUS_ROOT_CTC})

set(CMAKE_FIND_ROOT_PATH      ${ARMADEUS_ROOT_CTC} ${CMAKE_INCLUDE_PATH})

# search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM ONLY)
# for libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
