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
CMAKE_SOURCE_DIR = /home/wuyou/BCI_ROS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wuyou/BCI_ROS/build

# Include any dependencies generated for this target.
include online_analysis/CMakeFiles/test_talker.dir/depend.make

# Include the progress variables for this target.
include online_analysis/CMakeFiles/test_talker.dir/progress.make

# Include the compile flags for this target's objects.
include online_analysis/CMakeFiles/test_talker.dir/flags.make

online_analysis/CMakeFiles/test_talker.dir/src/test_talker.cpp.o: online_analysis/CMakeFiles/test_talker.dir/flags.make
online_analysis/CMakeFiles/test_talker.dir/src/test_talker.cpp.o: /home/wuyou/BCI_ROS/src/online_analysis/src/test_talker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuyou/BCI_ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object online_analysis/CMakeFiles/test_talker.dir/src/test_talker.cpp.o"
	cd /home/wuyou/BCI_ROS/build/online_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_talker.dir/src/test_talker.cpp.o -c /home/wuyou/BCI_ROS/src/online_analysis/src/test_talker.cpp

online_analysis/CMakeFiles/test_talker.dir/src/test_talker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_talker.dir/src/test_talker.cpp.i"
	cd /home/wuyou/BCI_ROS/build/online_analysis && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuyou/BCI_ROS/src/online_analysis/src/test_talker.cpp > CMakeFiles/test_talker.dir/src/test_talker.cpp.i

online_analysis/CMakeFiles/test_talker.dir/src/test_talker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_talker.dir/src/test_talker.cpp.s"
	cd /home/wuyou/BCI_ROS/build/online_analysis && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuyou/BCI_ROS/src/online_analysis/src/test_talker.cpp -o CMakeFiles/test_talker.dir/src/test_talker.cpp.s

# Object files for target test_talker
test_talker_OBJECTS = \
"CMakeFiles/test_talker.dir/src/test_talker.cpp.o"

# External object files for target test_talker
test_talker_EXTERNAL_OBJECTS =

/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: online_analysis/CMakeFiles/test_talker.dir/src/test_talker.cpp.o
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: online_analysis/CMakeFiles/test_talker.dir/build.make
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /opt/ros/noetic/lib/libroscpp.so
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /opt/ros/noetic/lib/librosconsole.so
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /opt/ros/noetic/lib/librostime.so
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /opt/ros/noetic/lib/libcpp_common.so
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker: online_analysis/CMakeFiles/test_talker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wuyou/BCI_ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker"
	cd /home/wuyou/BCI_ROS/build/online_analysis && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_talker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
online_analysis/CMakeFiles/test_talker.dir/build: /home/wuyou/BCI_ROS/devel/lib/online_analysis/test_talker

.PHONY : online_analysis/CMakeFiles/test_talker.dir/build

online_analysis/CMakeFiles/test_talker.dir/clean:
	cd /home/wuyou/BCI_ROS/build/online_analysis && $(CMAKE_COMMAND) -P CMakeFiles/test_talker.dir/cmake_clean.cmake
.PHONY : online_analysis/CMakeFiles/test_talker.dir/clean

online_analysis/CMakeFiles/test_talker.dir/depend:
	cd /home/wuyou/BCI_ROS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wuyou/BCI_ROS/src /home/wuyou/BCI_ROS/src/online_analysis /home/wuyou/BCI_ROS/build /home/wuyou/BCI_ROS/build/online_analysis /home/wuyou/BCI_ROS/build/online_analysis/CMakeFiles/test_talker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : online_analysis/CMakeFiles/test_talker.dir/depend

