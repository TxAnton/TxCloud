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
CMAKE_SOURCE_DIR = "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Code.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Code.dir/flags.make

CMakeFiles/Code.dir/bt_implementation.cpp.o: CMakeFiles/Code.dir/flags.make
CMakeFiles/Code.dir/bt_implementation.cpp.o: ../bt_implementation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Code.dir/bt_implementation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Code.dir/bt_implementation.cpp.o -c "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/bt_implementation.cpp"

CMakeFiles/Code.dir/bt_implementation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Code.dir/bt_implementation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/bt_implementation.cpp" > CMakeFiles/Code.dir/bt_implementation.cpp.i

CMakeFiles/Code.dir/bt_implementation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Code.dir/bt_implementation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/bt_implementation.cpp" -o CMakeFiles/Code.dir/bt_implementation.cpp.s

CMakeFiles/Code.dir/work_bt.cpp.o: CMakeFiles/Code.dir/flags.make
CMakeFiles/Code.dir/work_bt.cpp.o: ../work_bt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Code.dir/work_bt.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Code.dir/work_bt.cpp.o -c "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/work_bt.cpp"

CMakeFiles/Code.dir/work_bt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Code.dir/work_bt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/work_bt.cpp" > CMakeFiles/Code.dir/work_bt.cpp.i

CMakeFiles/Code.dir/work_bt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Code.dir/work_bt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/work_bt.cpp" -o CMakeFiles/Code.dir/work_bt.cpp.s

# Object files for target Code
Code_OBJECTS = \
"CMakeFiles/Code.dir/bt_implementation.cpp.o" \
"CMakeFiles/Code.dir/work_bt.cpp.o"

# External object files for target Code
Code_EXTERNAL_OBJECTS =

Code: CMakeFiles/Code.dir/bt_implementation.cpp.o
Code: CMakeFiles/Code.dir/work_bt.cpp.o
Code: CMakeFiles/Code.dir/build.make
Code: CMakeFiles/Code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Code"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Code.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Code.dir/build: Code

.PHONY : CMakeFiles/Code.dir/build

CMakeFiles/Code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Code.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Code.dir/clean

CMakeFiles/Code.dir/depend:
	cd "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)" "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)" "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/cmake-build-debug" "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/cmake-build-debug" "/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/AiSD/4_Tree/Code (copy)/cmake-build-debug/CMakeFiles/Code.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Code.dir/depend
