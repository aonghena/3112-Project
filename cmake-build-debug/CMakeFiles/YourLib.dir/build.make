# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alexonghena/Documents/workspace/c++/3112-Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alexonghena/Documents/workspace/c++/3112-Project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/YourLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/YourLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/YourLib.dir/flags.make

CMakeFiles/YourLib.dir/main.cpp.o: CMakeFiles/YourLib.dir/flags.make
CMakeFiles/YourLib.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alexonghena/Documents/workspace/c++/3112-Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/YourLib.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/YourLib.dir/main.cpp.o -c /Users/alexonghena/Documents/workspace/c++/3112-Project/main.cpp

CMakeFiles/YourLib.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/YourLib.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexonghena/Documents/workspace/c++/3112-Project/main.cpp > CMakeFiles/YourLib.dir/main.cpp.i

CMakeFiles/YourLib.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/YourLib.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexonghena/Documents/workspace/c++/3112-Project/main.cpp -o CMakeFiles/YourLib.dir/main.cpp.s

# Object files for target YourLib
YourLib_OBJECTS = \
"CMakeFiles/YourLib.dir/main.cpp.o"

# External object files for target YourLib
YourLib_EXTERNAL_OBJECTS =

libYourLib.a: CMakeFiles/YourLib.dir/main.cpp.o
libYourLib.a: CMakeFiles/YourLib.dir/build.make
libYourLib.a: CMakeFiles/YourLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alexonghena/Documents/workspace/c++/3112-Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libYourLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/YourLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/YourLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/YourLib.dir/build: libYourLib.a

.PHONY : CMakeFiles/YourLib.dir/build

CMakeFiles/YourLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/YourLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/YourLib.dir/clean

CMakeFiles/YourLib.dir/depend:
	cd /Users/alexonghena/Documents/workspace/c++/3112-Project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alexonghena/Documents/workspace/c++/3112-Project /Users/alexonghena/Documents/workspace/c++/3112-Project /Users/alexonghena/Documents/workspace/c++/3112-Project/cmake-build-debug /Users/alexonghena/Documents/workspace/c++/3112-Project/cmake-build-debug /Users/alexonghena/Documents/workspace/c++/3112-Project/cmake-build-debug/CMakeFiles/YourLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/YourLib.dir/depend

