# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/anton/Documents/ummy/clion-2019.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/anton/Documents/ummy/clion-2019.1.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2_Pathfinding.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2_Pathfinding.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2_Pathfinding.dir/flags.make

CMakeFiles/2_Pathfinding.dir/main.cpp.o: CMakeFiles/2_Pathfinding.dir/flags.make
CMakeFiles/2_Pathfinding.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2_Pathfinding.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_Pathfinding.dir/main.cpp.o -c /media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding/main.cpp

CMakeFiles/2_Pathfinding.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_Pathfinding.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding/main.cpp > CMakeFiles/2_Pathfinding.dir/main.cpp.i

CMakeFiles/2_Pathfinding.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_Pathfinding.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding/main.cpp -o CMakeFiles/2_Pathfinding.dir/main.cpp.s

# Object files for target 2_Pathfinding
2_Pathfinding_OBJECTS = \
"CMakeFiles/2_Pathfinding.dir/main.cpp.o"

# External object files for target 2_Pathfinding
2_Pathfinding_EXTERNAL_OBJECTS =

2_Pathfinding: CMakeFiles/2_Pathfinding.dir/main.cpp.o
2_Pathfinding: CMakeFiles/2_Pathfinding.dir/build.make
2_Pathfinding: CMakeFiles/2_Pathfinding.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2_Pathfinding"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2_Pathfinding.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2_Pathfinding.dir/build: 2_Pathfinding

.PHONY : CMakeFiles/2_Pathfinding.dir/build

CMakeFiles/2_Pathfinding.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2_Pathfinding.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2_Pathfinding.dir/clean

CMakeFiles/2_Pathfinding.dir/depend:
	cd /media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding /media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding /media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding/cmake-build-debug /media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding/cmake-build-debug /media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding/cmake-build-debug/CMakeFiles/2_Pathfinding.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2_Pathfinding.dir/depend

