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
CMAKE_SOURCE_DIR = /home/sunlee/my-linux-c-app/230627_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sunlee/my-linux-c-app/230627_1

# Include any dependencies generated for this target.
include CMakeFiles/e2000-test-1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/e2000-test-1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/e2000-test-1.dir/flags.make

CMakeFiles/e2000-test-1.dir/main.c.o: CMakeFiles/e2000-test-1.dir/flags.make
CMakeFiles/e2000-test-1.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunlee/my-linux-c-app/230627_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/e2000-test-1.dir/main.c.o"
	aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/e2000-test-1.dir/main.c.o   -c /home/sunlee/my-linux-c-app/230627_1/main.c

CMakeFiles/e2000-test-1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/e2000-test-1.dir/main.c.i"
	aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sunlee/my-linux-c-app/230627_1/main.c > CMakeFiles/e2000-test-1.dir/main.c.i

CMakeFiles/e2000-test-1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/e2000-test-1.dir/main.c.s"
	aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sunlee/my-linux-c-app/230627_1/main.c -o CMakeFiles/e2000-test-1.dir/main.c.s

# Object files for target e2000-test-1
e2000__test__1_OBJECTS = \
"CMakeFiles/e2000-test-1.dir/main.c.o"

# External object files for target e2000-test-1
e2000__test__1_EXTERNAL_OBJECTS =

e2000-test-1: CMakeFiles/e2000-test-1.dir/main.c.o
e2000-test-1: CMakeFiles/e2000-test-1.dir/build.make
e2000-test-1: CMakeFiles/e2000-test-1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sunlee/my-linux-c-app/230627_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable e2000-test-1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/e2000-test-1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/e2000-test-1.dir/build: e2000-test-1

.PHONY : CMakeFiles/e2000-test-1.dir/build

CMakeFiles/e2000-test-1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/e2000-test-1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/e2000-test-1.dir/clean

CMakeFiles/e2000-test-1.dir/depend:
	cd /home/sunlee/my-linux-c-app/230627_1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sunlee/my-linux-c-app/230627_1 /home/sunlee/my-linux-c-app/230627_1 /home/sunlee/my-linux-c-app/230627_1 /home/sunlee/my-linux-c-app/230627_1 /home/sunlee/my-linux-c-app/230627_1/CMakeFiles/e2000-test-1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/e2000-test-1.dir/depend
