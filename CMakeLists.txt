cmake_minimum_required(VERSION 3.17)
project(cpuStats)

set(CMAKE_CXX_STANDARD 17)
find_library(IOKIT_LIBRARY IOKit)
#find_library(FOUNDATION_LIBRARY CoreFoundation)
#find_library(IOBLUETOOTH_LIBRARY IOBluetooth)
find_library(CPU_LIB cpuid)
find_library(FOUNDATION_LIBRARY Foundation)
find_library(CORE_FOUNDATION CoreFoundation)
find_library(BLUETOOTH_LIBRARY IOBluetooth)
find_library(APPKIT_LIBRARY AppKit)
find_library(METAL_LIBRARY Metal)



find_package(CURL REQUIRED)
find_package(EXPAT REQUIRED)
include_directories(${EXPAT_INCLUDE_DIRS})

IF(CURL_FOUND)
    INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${CURL_LIBRARIES} )
ELSE(CURL_FOUND)
    MESSAGE(FATAL_ERROR "Could not find the CURL library and development files.")
ENDIF(CURL_FOUND)

mark_as_advanced(IOKIT_LIBRARY)
set(EXTRA_LIBS ${IOKIT_LIBRARY})
set(BLUETOOTH_LIBS ${BLUETOOTH_LIBRARY})
set(FOUNDATION_LIBS ${FOUNDATION_LIBRARY})
set(CORE_LIBS ${CORE_FOUNDATION})

add_executable(${PROJECT_NAME} main.mm controller/smc.cpp controller/smc.h controller/Generic/generic_device.cpp controller/Generic/generic_device.h controller/CPU/cpu_device.cpp controller/CPU/cpu_device.h controller/Utils/utilsConverter.h controller/Utils/keys.h controller/Utils/utils.h controller/Utils/threadPool.cpp controller/Utils/threadPool.h controller/Fan/fan_controller.cpp controller/Fan/fan_controller.h controller/Battery/battery_controller.cpp controller/Battery/battery_controller.h controller/Network/network_controller.cpp controller/Network/network_controller.h controller/Generic/generic_class.h controller/Generic/generic_class.cpp controller/Network/network_speed.cpp controller/Network/network_speed.h controller/Peripherals/peripherals_controller.mm controller/Peripherals/peripherals_controller.h controller/Peripherals/generic_peripheral.mm controller/Peripherals/generic_peripheral.h controller/Peripherals/volume_storage_controller.mm controller/Peripherals/volume_storage_controller.h controller/kStat_controller.mm controller/kStat_controller.h controller/Peripherals/iokit_libraries.h controller/GPU/gpu_device.mm controller/GPU/gpu_device.h)
target_link_libraries(${PROJECT_NAME} PRIVATE ${EXTRA_LIBS} ${EXPAT_LIBRARIES} ${CURL_LIBRARIES} ${BLUETOOTH_LIBS} ${FOUNDATION_LIBS} ${CORE_LIBS} ${APPKIT_LIBRARY} ${METAL_LIBRARY})
