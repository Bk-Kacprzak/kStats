# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cpuStats.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpuStats.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpuStats.dir/flags.make

CMakeFiles/cpuStats.dir/main.mm.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/main.mm.o: ../main.mm
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpuStats.dir/main.mm.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/main.mm.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/main.mm

CMakeFiles/cpuStats.dir/main.mm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/main.mm.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/main.mm > CMakeFiles/cpuStats.dir/main.mm.i

CMakeFiles/cpuStats.dir/main.mm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/main.mm.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/main.mm -o CMakeFiles/cpuStats.dir/main.mm.s

CMakeFiles/cpuStats.dir/controller/smc.cpp.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/smc.cpp.o: ../controller/smc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpuStats.dir/controller/smc.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/smc.cpp.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/smc.cpp

CMakeFiles/cpuStats.dir/controller/smc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/smc.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/smc.cpp > CMakeFiles/cpuStats.dir/controller/smc.cpp.i

CMakeFiles/cpuStats.dir/controller/smc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/smc.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/smc.cpp -o CMakeFiles/cpuStats.dir/controller/smc.cpp.s

CMakeFiles/cpuStats.dir/controller/Generic/generic_device.cpp.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/Generic/generic_device.cpp.o: ../controller/Generic/generic_device.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cpuStats.dir/controller/Generic/generic_device.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/Generic/generic_device.cpp.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Generic/generic_device.cpp

CMakeFiles/cpuStats.dir/controller/Generic/generic_device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/Generic/generic_device.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Generic/generic_device.cpp > CMakeFiles/cpuStats.dir/controller/Generic/generic_device.cpp.i

CMakeFiles/cpuStats.dir/controller/Generic/generic_device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/Generic/generic_device.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Generic/generic_device.cpp -o CMakeFiles/cpuStats.dir/controller/Generic/generic_device.cpp.s

CMakeFiles/cpuStats.dir/controller/CPU/cpu_device.cpp.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/CPU/cpu_device.cpp.o: ../controller/CPU/cpu_device.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cpuStats.dir/controller/CPU/cpu_device.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/CPU/cpu_device.cpp.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/CPU/cpu_device.cpp

CMakeFiles/cpuStats.dir/controller/CPU/cpu_device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/CPU/cpu_device.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/CPU/cpu_device.cpp > CMakeFiles/cpuStats.dir/controller/CPU/cpu_device.cpp.i

CMakeFiles/cpuStats.dir/controller/CPU/cpu_device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/CPU/cpu_device.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/CPU/cpu_device.cpp -o CMakeFiles/cpuStats.dir/controller/CPU/cpu_device.cpp.s

CMakeFiles/cpuStats.dir/controller/Utils/threadPool.cpp.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/Utils/threadPool.cpp.o: ../controller/Utils/threadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cpuStats.dir/controller/Utils/threadPool.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/Utils/threadPool.cpp.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Utils/threadPool.cpp

CMakeFiles/cpuStats.dir/controller/Utils/threadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/Utils/threadPool.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Utils/threadPool.cpp > CMakeFiles/cpuStats.dir/controller/Utils/threadPool.cpp.i

CMakeFiles/cpuStats.dir/controller/Utils/threadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/Utils/threadPool.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Utils/threadPool.cpp -o CMakeFiles/cpuStats.dir/controller/Utils/threadPool.cpp.s

CMakeFiles/cpuStats.dir/controller/Fan/fan_controller.cpp.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/Fan/fan_controller.cpp.o: ../controller/Fan/fan_controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cpuStats.dir/controller/Fan/fan_controller.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/Fan/fan_controller.cpp.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Fan/fan_controller.cpp

CMakeFiles/cpuStats.dir/controller/Fan/fan_controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/Fan/fan_controller.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Fan/fan_controller.cpp > CMakeFiles/cpuStats.dir/controller/Fan/fan_controller.cpp.i

CMakeFiles/cpuStats.dir/controller/Fan/fan_controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/Fan/fan_controller.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Fan/fan_controller.cpp -o CMakeFiles/cpuStats.dir/controller/Fan/fan_controller.cpp.s

CMakeFiles/cpuStats.dir/controller/Battery/battery_controller.cpp.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/Battery/battery_controller.cpp.o: ../controller/Battery/battery_controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/cpuStats.dir/controller/Battery/battery_controller.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/Battery/battery_controller.cpp.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Battery/battery_controller.cpp

CMakeFiles/cpuStats.dir/controller/Battery/battery_controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/Battery/battery_controller.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Battery/battery_controller.cpp > CMakeFiles/cpuStats.dir/controller/Battery/battery_controller.cpp.i

CMakeFiles/cpuStats.dir/controller/Battery/battery_controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/Battery/battery_controller.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Battery/battery_controller.cpp -o CMakeFiles/cpuStats.dir/controller/Battery/battery_controller.cpp.s

CMakeFiles/cpuStats.dir/controller/Network/network_controller.cpp.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/Network/network_controller.cpp.o: ../controller/Network/network_controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/cpuStats.dir/controller/Network/network_controller.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/Network/network_controller.cpp.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Network/network_controller.cpp

CMakeFiles/cpuStats.dir/controller/Network/network_controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/Network/network_controller.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Network/network_controller.cpp > CMakeFiles/cpuStats.dir/controller/Network/network_controller.cpp.i

CMakeFiles/cpuStats.dir/controller/Network/network_controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/Network/network_controller.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Network/network_controller.cpp -o CMakeFiles/cpuStats.dir/controller/Network/network_controller.cpp.s

CMakeFiles/cpuStats.dir/controller/Generic/generic_class.cpp.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/Generic/generic_class.cpp.o: ../controller/Generic/generic_class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/cpuStats.dir/controller/Generic/generic_class.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/Generic/generic_class.cpp.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Generic/generic_class.cpp

CMakeFiles/cpuStats.dir/controller/Generic/generic_class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/Generic/generic_class.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Generic/generic_class.cpp > CMakeFiles/cpuStats.dir/controller/Generic/generic_class.cpp.i

CMakeFiles/cpuStats.dir/controller/Generic/generic_class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/Generic/generic_class.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Generic/generic_class.cpp -o CMakeFiles/cpuStats.dir/controller/Generic/generic_class.cpp.s

CMakeFiles/cpuStats.dir/controller/Network/network_speed.cpp.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/Network/network_speed.cpp.o: ../controller/Network/network_speed.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/cpuStats.dir/controller/Network/network_speed.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/Network/network_speed.cpp.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Network/network_speed.cpp

CMakeFiles/cpuStats.dir/controller/Network/network_speed.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/Network/network_speed.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Network/network_speed.cpp > CMakeFiles/cpuStats.dir/controller/Network/network_speed.cpp.i

CMakeFiles/cpuStats.dir/controller/Network/network_speed.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/Network/network_speed.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Network/network_speed.cpp -o CMakeFiles/cpuStats.dir/controller/Network/network_speed.cpp.s

CMakeFiles/cpuStats.dir/controller/Peripherals/peripherals_controller.mm.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/Peripherals/peripherals_controller.mm.o: ../controller/Peripherals/peripherals_controller.mm
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/cpuStats.dir/controller/Peripherals/peripherals_controller.mm.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/Peripherals/peripherals_controller.mm.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Peripherals/peripherals_controller.mm

CMakeFiles/cpuStats.dir/controller/Peripherals/peripherals_controller.mm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/Peripherals/peripherals_controller.mm.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Peripherals/peripherals_controller.mm > CMakeFiles/cpuStats.dir/controller/Peripherals/peripherals_controller.mm.i

CMakeFiles/cpuStats.dir/controller/Peripherals/peripherals_controller.mm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/Peripherals/peripherals_controller.mm.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Peripherals/peripherals_controller.mm -o CMakeFiles/cpuStats.dir/controller/Peripherals/peripherals_controller.mm.s

CMakeFiles/cpuStats.dir/controller/Peripherals/generic_peripheral.mm.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/Peripherals/generic_peripheral.mm.o: ../controller/Peripherals/generic_peripheral.mm
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/cpuStats.dir/controller/Peripherals/generic_peripheral.mm.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/Peripherals/generic_peripheral.mm.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Peripherals/generic_peripheral.mm

CMakeFiles/cpuStats.dir/controller/Peripherals/generic_peripheral.mm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/Peripherals/generic_peripheral.mm.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Peripherals/generic_peripheral.mm > CMakeFiles/cpuStats.dir/controller/Peripherals/generic_peripheral.mm.i

CMakeFiles/cpuStats.dir/controller/Peripherals/generic_peripheral.mm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/Peripherals/generic_peripheral.mm.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Peripherals/generic_peripheral.mm -o CMakeFiles/cpuStats.dir/controller/Peripherals/generic_peripheral.mm.s

CMakeFiles/cpuStats.dir/controller/Peripherals/volume_storage_controller.mm.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/Peripherals/volume_storage_controller.mm.o: ../controller/Peripherals/volume_storage_controller.mm
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/cpuStats.dir/controller/Peripherals/volume_storage_controller.mm.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/Peripherals/volume_storage_controller.mm.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Peripherals/volume_storage_controller.mm

CMakeFiles/cpuStats.dir/controller/Peripherals/volume_storage_controller.mm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/Peripherals/volume_storage_controller.mm.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Peripherals/volume_storage_controller.mm > CMakeFiles/cpuStats.dir/controller/Peripherals/volume_storage_controller.mm.i

CMakeFiles/cpuStats.dir/controller/Peripherals/volume_storage_controller.mm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/Peripherals/volume_storage_controller.mm.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/Peripherals/volume_storage_controller.mm -o CMakeFiles/cpuStats.dir/controller/Peripherals/volume_storage_controller.mm.s

CMakeFiles/cpuStats.dir/controller/kStat_controller.mm.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/kStat_controller.mm.o: ../controller/kStat_controller.mm
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/cpuStats.dir/controller/kStat_controller.mm.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/kStat_controller.mm.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/kStat_controller.mm

CMakeFiles/cpuStats.dir/controller/kStat_controller.mm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/kStat_controller.mm.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/kStat_controller.mm > CMakeFiles/cpuStats.dir/controller/kStat_controller.mm.i

CMakeFiles/cpuStats.dir/controller/kStat_controller.mm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/kStat_controller.mm.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/kStat_controller.mm -o CMakeFiles/cpuStats.dir/controller/kStat_controller.mm.s

CMakeFiles/cpuStats.dir/controller/GPU/gpu_device.mm.o: CMakeFiles/cpuStats.dir/flags.make
CMakeFiles/cpuStats.dir/controller/GPU/gpu_device.mm.o: ../controller/GPU/gpu_device.mm
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/cpuStats.dir/controller/GPU/gpu_device.mm.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpuStats.dir/controller/GPU/gpu_device.mm.o -c /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/GPU/gpu_device.mm

CMakeFiles/cpuStats.dir/controller/GPU/gpu_device.mm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuStats.dir/controller/GPU/gpu_device.mm.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/GPU/gpu_device.mm > CMakeFiles/cpuStats.dir/controller/GPU/gpu_device.mm.i

CMakeFiles/cpuStats.dir/controller/GPU/gpu_device.mm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuStats.dir/controller/GPU/gpu_device.mm.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/controller/GPU/gpu_device.mm -o CMakeFiles/cpuStats.dir/controller/GPU/gpu_device.mm.s

# Object files for target cpuStats
cpuStats_OBJECTS = \
"CMakeFiles/cpuStats.dir/main.mm.o" \
"CMakeFiles/cpuStats.dir/controller/smc.cpp.o" \
"CMakeFiles/cpuStats.dir/controller/Generic/generic_device.cpp.o" \
"CMakeFiles/cpuStats.dir/controller/CPU/cpu_device.cpp.o" \
"CMakeFiles/cpuStats.dir/controller/Utils/threadPool.cpp.o" \
"CMakeFiles/cpuStats.dir/controller/Fan/fan_controller.cpp.o" \
"CMakeFiles/cpuStats.dir/controller/Battery/battery_controller.cpp.o" \
"CMakeFiles/cpuStats.dir/controller/Network/network_controller.cpp.o" \
"CMakeFiles/cpuStats.dir/controller/Generic/generic_class.cpp.o" \
"CMakeFiles/cpuStats.dir/controller/Network/network_speed.cpp.o" \
"CMakeFiles/cpuStats.dir/controller/Peripherals/peripherals_controller.mm.o" \
"CMakeFiles/cpuStats.dir/controller/Peripherals/generic_peripheral.mm.o" \
"CMakeFiles/cpuStats.dir/controller/Peripherals/volume_storage_controller.mm.o" \
"CMakeFiles/cpuStats.dir/controller/kStat_controller.mm.o" \
"CMakeFiles/cpuStats.dir/controller/GPU/gpu_device.mm.o"

# External object files for target cpuStats
cpuStats_EXTERNAL_OBJECTS =

cpuStats: CMakeFiles/cpuStats.dir/main.mm.o
cpuStats: CMakeFiles/cpuStats.dir/controller/smc.cpp.o
cpuStats: CMakeFiles/cpuStats.dir/controller/Generic/generic_device.cpp.o
cpuStats: CMakeFiles/cpuStats.dir/controller/CPU/cpu_device.cpp.o
cpuStats: CMakeFiles/cpuStats.dir/controller/Utils/threadPool.cpp.o
cpuStats: CMakeFiles/cpuStats.dir/controller/Fan/fan_controller.cpp.o
cpuStats: CMakeFiles/cpuStats.dir/controller/Battery/battery_controller.cpp.o
cpuStats: CMakeFiles/cpuStats.dir/controller/Network/network_controller.cpp.o
cpuStats: CMakeFiles/cpuStats.dir/controller/Generic/generic_class.cpp.o
cpuStats: CMakeFiles/cpuStats.dir/controller/Network/network_speed.cpp.o
cpuStats: CMakeFiles/cpuStats.dir/controller/Peripherals/peripherals_controller.mm.o
cpuStats: CMakeFiles/cpuStats.dir/controller/Peripherals/generic_peripheral.mm.o
cpuStats: CMakeFiles/cpuStats.dir/controller/Peripherals/volume_storage_controller.mm.o
cpuStats: CMakeFiles/cpuStats.dir/controller/kStat_controller.mm.o
cpuStats: CMakeFiles/cpuStats.dir/controller/GPU/gpu_device.mm.o
cpuStats: CMakeFiles/cpuStats.dir/build.make
cpuStats: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX11.3.sdk/usr/lib/libexpat.tbd
cpuStats: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX11.3.sdk/usr/lib/libcurl.tbd
cpuStats: CMakeFiles/cpuStats.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable cpuStats"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpuStats.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpuStats.dir/build: cpuStats

.PHONY : CMakeFiles/cpuStats.dir/build

CMakeFiles/cpuStats.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpuStats.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpuStats.dir/clean

CMakeFiles/cpuStats.dir/depend:
	cd /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug /Users/bk.kacprzak/Documents/PROGRAMOWANIE/C++/cpuStats/cmake-build-debug/CMakeFiles/cpuStats.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpuStats.dir/depend

