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
CMAKE_SOURCE_DIR = /home/ubuntu/data_struct

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/data_struct/build

# Include any dependencies generated for this target.
include CMakeFiles/data_struct.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/data_struct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/data_struct.dir/flags.make

CMakeFiles/data_struct.dir/InsertSort.c.o: CMakeFiles/data_struct.dir/flags.make
CMakeFiles/data_struct.dir/InsertSort.c.o: ../InsertSort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/data_struct/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/data_struct.dir/InsertSort.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/data_struct.dir/InsertSort.c.o   -c /home/ubuntu/data_struct/InsertSort.c

CMakeFiles/data_struct.dir/InsertSort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_struct.dir/InsertSort.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/data_struct/InsertSort.c > CMakeFiles/data_struct.dir/InsertSort.c.i

CMakeFiles/data_struct.dir/InsertSort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_struct.dir/InsertSort.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/data_struct/InsertSort.c -o CMakeFiles/data_struct.dir/InsertSort.c.s

# Object files for target data_struct
data_struct_OBJECTS = \
"CMakeFiles/data_struct.dir/InsertSort.c.o"

# External object files for target data_struct
data_struct_EXTERNAL_OBJECTS =

data_struct: CMakeFiles/data_struct.dir/InsertSort.c.o
data_struct: CMakeFiles/data_struct.dir/build.make
data_struct: CMakeFiles/data_struct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/data_struct/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable data_struct"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/data_struct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/data_struct.dir/build: data_struct

.PHONY : CMakeFiles/data_struct.dir/build

CMakeFiles/data_struct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/data_struct.dir/cmake_clean.cmake
.PHONY : CMakeFiles/data_struct.dir/clean

CMakeFiles/data_struct.dir/depend:
	cd /home/ubuntu/data_struct/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/data_struct /home/ubuntu/data_struct /home/ubuntu/data_struct/build /home/ubuntu/data_struct/build /home/ubuntu/data_struct/build/CMakeFiles/data_struct.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/data_struct.dir/depend

