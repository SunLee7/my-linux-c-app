# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/sunlee/C/i2c_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sunlee/C/i2c_test

# Include any dependencies generated for this target.
include CMakeFiles/i2c_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/i2c_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/i2c_test.dir/flags.make

CMakeFiles/i2c_test.dir/i2c_test.c.o: CMakeFiles/i2c_test.dir/flags.make
CMakeFiles/i2c_test.dir/i2c_test.c.o: i2c_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunlee/C/i2c_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/i2c_test.dir/i2c_test.c.o"
	arm-linux-gnueabihf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/i2c_test.dir/i2c_test.c.o   -c /home/sunlee/C/i2c_test/i2c_test.c

CMakeFiles/i2c_test.dir/i2c_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/i2c_test.dir/i2c_test.c.i"
	arm-linux-gnueabihf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sunlee/C/i2c_test/i2c_test.c > CMakeFiles/i2c_test.dir/i2c_test.c.i

CMakeFiles/i2c_test.dir/i2c_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/i2c_test.dir/i2c_test.c.s"
	arm-linux-gnueabihf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sunlee/C/i2c_test/i2c_test.c -o CMakeFiles/i2c_test.dir/i2c_test.c.s

CMakeFiles/i2c_test.dir/i2c_test.c.o.requires:

.PHONY : CMakeFiles/i2c_test.dir/i2c_test.c.o.requires

CMakeFiles/i2c_test.dir/i2c_test.c.o.provides: CMakeFiles/i2c_test.dir/i2c_test.c.o.requires
	$(MAKE) -f CMakeFiles/i2c_test.dir/build.make CMakeFiles/i2c_test.dir/i2c_test.c.o.provides.build
.PHONY : CMakeFiles/i2c_test.dir/i2c_test.c.o.provides

CMakeFiles/i2c_test.dir/i2c_test.c.o.provides.build: CMakeFiles/i2c_test.dir/i2c_test.c.o


# Object files for target i2c_test
i2c_test_OBJECTS = \
"CMakeFiles/i2c_test.dir/i2c_test.c.o"

# External object files for target i2c_test
i2c_test_EXTERNAL_OBJECTS =

i2c_test: CMakeFiles/i2c_test.dir/i2c_test.c.o
i2c_test: CMakeFiles/i2c_test.dir/build.make
i2c_test: CMakeFiles/i2c_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sunlee/C/i2c_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable i2c_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/i2c_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/i2c_test.dir/build: i2c_test

.PHONY : CMakeFiles/i2c_test.dir/build

CMakeFiles/i2c_test.dir/requires: CMakeFiles/i2c_test.dir/i2c_test.c.o.requires

.PHONY : CMakeFiles/i2c_test.dir/requires

CMakeFiles/i2c_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/i2c_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/i2c_test.dir/clean

CMakeFiles/i2c_test.dir/depend:
	cd /home/sunlee/C/i2c_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sunlee/C/i2c_test /home/sunlee/C/i2c_test /home/sunlee/C/i2c_test /home/sunlee/C/i2c_test /home/sunlee/C/i2c_test/CMakeFiles/i2c_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/i2c_test.dir/depend
