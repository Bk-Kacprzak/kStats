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

add_executable(${PROJECT_NAME} main.mm controller/smc.cpp controller/smc.h controller/generic_device.cpp controller/generic_device.h controller/cpu_device.cpp controller/cpu_device.h controller/Utils/utilsConverter.h controller/Utils/keys.h controller/Utils/utils.h controller/Utils/threadPool.cpp controller/Utils/threadPool.h controller/fan_controller.cpp controller/fan_controller.h controller/battery_controller.cpp controller/battery_controller.h controller/network_controller.cpp controller/network_controller.h  controller/generic_class.h controller/generic_class.cpp controller/network_speed.cpp controller/network_speed.h controller/peripherals_controller.mm controller/peripherals_controller.h controller/generic_peripheral.mm controller/generic_peripheral.h controller/volume_storage_controller.mm controller/volume_storage_controller.h)
target_link_libraries(${PROJECT_NAME} PRIVATE ${EXTRA_LIBS} ${EXPAT_LIBRARIES} ${CURL_LIBRARIES} ${BLUETOOTH_LIBS} ${FOUNDATION_LIBS} ${CORE_LIBS} ${APPKIT_LIBRARY})
