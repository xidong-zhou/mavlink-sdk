# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zxd/mavlink

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zxd/mavlink/build

# Include any dependencies generated for this target.
include CMakeFiles/aimilink_static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aimilink_static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aimilink_static.dir/flags.make

CMakeFiles/aimilink_static.dir/src/linux_serial.cpp.o: CMakeFiles/aimilink_static.dir/flags.make
CMakeFiles/aimilink_static.dir/src/linux_serial.cpp.o: ../src/linux_serial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxd/mavlink/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aimilink_static.dir/src/linux_serial.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aimilink_static.dir/src/linux_serial.cpp.o -c /home/zxd/mavlink/src/linux_serial.cpp

CMakeFiles/aimilink_static.dir/src/linux_serial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aimilink_static.dir/src/linux_serial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxd/mavlink/src/linux_serial.cpp > CMakeFiles/aimilink_static.dir/src/linux_serial.cpp.i

CMakeFiles/aimilink_static.dir/src/linux_serial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aimilink_static.dir/src/linux_serial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxd/mavlink/src/linux_serial.cpp -o CMakeFiles/aimilink_static.dir/src/linux_serial.cpp.s

CMakeFiles/aimilink_static.dir/src/mavlink_interface.cpp.o: CMakeFiles/aimilink_static.dir/flags.make
CMakeFiles/aimilink_static.dir/src/mavlink_interface.cpp.o: ../src/mavlink_interface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxd/mavlink/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/aimilink_static.dir/src/mavlink_interface.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aimilink_static.dir/src/mavlink_interface.cpp.o -c /home/zxd/mavlink/src/mavlink_interface.cpp

CMakeFiles/aimilink_static.dir/src/mavlink_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aimilink_static.dir/src/mavlink_interface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxd/mavlink/src/mavlink_interface.cpp > CMakeFiles/aimilink_static.dir/src/mavlink_interface.cpp.i

CMakeFiles/aimilink_static.dir/src/mavlink_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aimilink_static.dir/src/mavlink_interface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxd/mavlink/src/mavlink_interface.cpp -o CMakeFiles/aimilink_static.dir/src/mavlink_interface.cpp.s

# Object files for target aimilink_static
aimilink_static_OBJECTS = \
"CMakeFiles/aimilink_static.dir/src/linux_serial.cpp.o" \
"CMakeFiles/aimilink_static.dir/src/mavlink_interface.cpp.o"

# External object files for target aimilink_static
aimilink_static_EXTERNAL_OBJECTS =

lib/libaimilink.a: CMakeFiles/aimilink_static.dir/src/linux_serial.cpp.o
lib/libaimilink.a: CMakeFiles/aimilink_static.dir/src/mavlink_interface.cpp.o
lib/libaimilink.a: CMakeFiles/aimilink_static.dir/build.make
lib/libaimilink.a: CMakeFiles/aimilink_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zxd/mavlink/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library lib/libaimilink.a"
	$(CMAKE_COMMAND) -P CMakeFiles/aimilink_static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aimilink_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aimilink_static.dir/build: lib/libaimilink.a

.PHONY : CMakeFiles/aimilink_static.dir/build

CMakeFiles/aimilink_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aimilink_static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aimilink_static.dir/clean

CMakeFiles/aimilink_static.dir/depend:
	cd /home/zxd/mavlink/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zxd/mavlink /home/zxd/mavlink /home/zxd/mavlink/build /home/zxd/mavlink/build /home/zxd/mavlink/build/CMakeFiles/aimilink_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aimilink_static.dir/depend

