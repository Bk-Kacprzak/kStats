cmake_minimum_required(VERSION 3.17)
project(kStats)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_MACOS_BUNDLE ON)
set(CMAKE_MACOSX_RPATH ON)
set(CMAKE_CXX_STANDARD 20)

set(CUR_TARGET ${PROJECT_NAME})
find_library(IOKIT_LIBRARY IOKit)
find_library(CPU_LIB cpuid)
find_library(FOUNDATION_LIBRARY Foundation)
find_library(CORE_FOUNDATION CoreFoundation)
find_library(BLUETOOTH_LIBRARY IOBluetooth)
find_library(APPKIT_LIBRARY AppKit)
find_library(METAL_LIBRARY Metal)
find_package(CURL REQUIRED)
find_package(EXPAT REQUIRED)
#find_package(Qt5::Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets Core Gui)

set(REQUIRED_LIBS Core Gui Widgets REQUIRED)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

include_directories(${EXPAT_INCLUDE_DIRS})

IF(CURL_FOUND)
    INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})#
    SET(requiredlibs ${requiredlibs} ${CURL_LIBRARIES} )
ELSE(CURL_FOUND)
    MESSAGE(FATAL_ERROR "Could not find the CURL library and development files.")
ENDIF(CURL_FOUND)

mark_as_advanced(IOKIT_LIBRARY)
set(EXTRA_LIBS ${IOKIT_LIBRARY})
set(BLUETOOTH_LIBS ${BLUETOOTH_LIBRARY})
set(FOUNDATION_LIBS ${FOUNDATION_LIBRARY})
set(CORE_LIBS ${CORE_FOUNDATION})
qt5_add_resources(view/resources.qrc)

add_executable(${PROJECT_NAME} MACOSX_BUNDLE main.mm model/smc.cpp model/smc.h model/Generic/generic_device.cpp model/Generic/generic_device.h model/CPU/cpu_model.cpp model/CPU/cpu_model.h model/Utils/utilsConverter.h model/Utils/keys.h model/Utils/utils.h model/Utils/threadPool.cpp model/Utils/threadPool.h model/Fan/fan_model.cpp model/Fan/fan_model.h model/Battery/battery_model.cpp model/Battery/battery_model.h model/Network/network_model.cpp model/Network/network_model.h model/Generic/generic_class.h model/Generic/generic_class.cpp model/Network/network_speed.cpp model/Network/network_speed.h model/Peripherals/peripherals_model.mm model/Peripherals/peripherals_model.h model/Peripherals/generic_peripheral.mm model/Peripherals/generic_peripheral.h model/Peripherals/volume_storage_model.mm model/Peripherals/volume_storage_model.h model/kStats_model.mm model/kStats_model.h model/Peripherals/iokit_libraries.h model/GPU/gpu_device.mm model/GPU/gpu_device.h view/kStats_view.h view/kStats_view.mm view/resources.qrc global.h controller/kStatsController.mm controller/kStatsController.h view/qt_libraries.h view/animation.h "model/Main Device/MainDeviceModel.cpp" "model/Main Device/MainDeviceModel.h" model/Processor/generic_processor.cpp model/Processor/generic_processor.h model/RAM/ram_model.cpp model/RAM/ram_model.h global_headers.h)
target_link_libraries(${PROJECT_NAME} PRIVATE ${EXTRA_LIBS} ${EXPAT_LIBRARIES} ${CURL_LIBRARIES} ${BLUETOOTH_LIBS} ${FOUNDATION_LIBS} ${CORE_LIBS} ${APPKIT_LIBRARY} ${METAL_LIBRARY} ${REQUIRED_LIBS_QUALIFIED})

set_target_properties(${CUR_TARGET} PROPERTIES
        BUNDLE True
        MACOSX_BUNDLE_GUI_IDENTIFIER my.domain.style.identifier.${CUR_TARGET}
        MACOSX_BUNDLE_BUNDLE_NAME ${CUR_TARGET}
        MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1"
        )

