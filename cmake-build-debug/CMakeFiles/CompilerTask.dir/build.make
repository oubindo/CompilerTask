# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/oubin/c/clion-2016.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/oubin/c/clion-2016.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oubin/c/clion-2016.3/Workplace/CompilerTask

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oubin/c/clion-2016.3/Workplace/CompilerTask/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CompilerTask.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CompilerTask.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CompilerTask.dir/flags.make

CMakeFiles/CompilerTask.dir/main.cpp.o: CMakeFiles/CompilerTask.dir/flags.make
CMakeFiles/CompilerTask.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oubin/c/clion-2016.3/Workplace/CompilerTask/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CompilerTask.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CompilerTask.dir/main.cpp.o -c /home/oubin/c/clion-2016.3/Workplace/CompilerTask/main.cpp

CMakeFiles/CompilerTask.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CompilerTask.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oubin/c/clion-2016.3/Workplace/CompilerTask/main.cpp > CMakeFiles/CompilerTask.dir/main.cpp.i

CMakeFiles/CompilerTask.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CompilerTask.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oubin/c/clion-2016.3/Workplace/CompilerTask/main.cpp -o CMakeFiles/CompilerTask.dir/main.cpp.s

CMakeFiles/CompilerTask.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/CompilerTask.dir/main.cpp.o.requires

CMakeFiles/CompilerTask.dir/main.cpp.o.provides: CMakeFiles/CompilerTask.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CompilerTask.dir/build.make CMakeFiles/CompilerTask.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/CompilerTask.dir/main.cpp.o.provides

CMakeFiles/CompilerTask.dir/main.cpp.o.provides.build: CMakeFiles/CompilerTask.dir/main.cpp.o


CMakeFiles/CompilerTask.dir/scanner.cpp.o: CMakeFiles/CompilerTask.dir/flags.make
CMakeFiles/CompilerTask.dir/scanner.cpp.o: ../scanner.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oubin/c/clion-2016.3/Workplace/CompilerTask/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CompilerTask.dir/scanner.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CompilerTask.dir/scanner.cpp.o -c /home/oubin/c/clion-2016.3/Workplace/CompilerTask/scanner.cpp

CMakeFiles/CompilerTask.dir/scanner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CompilerTask.dir/scanner.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oubin/c/clion-2016.3/Workplace/CompilerTask/scanner.cpp > CMakeFiles/CompilerTask.dir/scanner.cpp.i

CMakeFiles/CompilerTask.dir/scanner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CompilerTask.dir/scanner.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oubin/c/clion-2016.3/Workplace/CompilerTask/scanner.cpp -o CMakeFiles/CompilerTask.dir/scanner.cpp.s

CMakeFiles/CompilerTask.dir/scanner.cpp.o.requires:

.PHONY : CMakeFiles/CompilerTask.dir/scanner.cpp.o.requires

CMakeFiles/CompilerTask.dir/scanner.cpp.o.provides: CMakeFiles/CompilerTask.dir/scanner.cpp.o.requires
	$(MAKE) -f CMakeFiles/CompilerTask.dir/build.make CMakeFiles/CompilerTask.dir/scanner.cpp.o.provides.build
.PHONY : CMakeFiles/CompilerTask.dir/scanner.cpp.o.provides

CMakeFiles/CompilerTask.dir/scanner.cpp.o.provides.build: CMakeFiles/CompilerTask.dir/scanner.cpp.o


CMakeFiles/CompilerTask.dir/analyse.cpp.o: CMakeFiles/CompilerTask.dir/flags.make
CMakeFiles/CompilerTask.dir/analyse.cpp.o: ../analyse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oubin/c/clion-2016.3/Workplace/CompilerTask/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CompilerTask.dir/analyse.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CompilerTask.dir/analyse.cpp.o -c /home/oubin/c/clion-2016.3/Workplace/CompilerTask/analyse.cpp

CMakeFiles/CompilerTask.dir/analyse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CompilerTask.dir/analyse.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oubin/c/clion-2016.3/Workplace/CompilerTask/analyse.cpp > CMakeFiles/CompilerTask.dir/analyse.cpp.i

CMakeFiles/CompilerTask.dir/analyse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CompilerTask.dir/analyse.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oubin/c/clion-2016.3/Workplace/CompilerTask/analyse.cpp -o CMakeFiles/CompilerTask.dir/analyse.cpp.s

CMakeFiles/CompilerTask.dir/analyse.cpp.o.requires:

.PHONY : CMakeFiles/CompilerTask.dir/analyse.cpp.o.requires

CMakeFiles/CompilerTask.dir/analyse.cpp.o.provides: CMakeFiles/CompilerTask.dir/analyse.cpp.o.requires
	$(MAKE) -f CMakeFiles/CompilerTask.dir/build.make CMakeFiles/CompilerTask.dir/analyse.cpp.o.provides.build
.PHONY : CMakeFiles/CompilerTask.dir/analyse.cpp.o.provides

CMakeFiles/CompilerTask.dir/analyse.cpp.o.provides.build: CMakeFiles/CompilerTask.dir/analyse.cpp.o


CMakeFiles/CompilerTask.dir/mean.cpp.o: CMakeFiles/CompilerTask.dir/flags.make
CMakeFiles/CompilerTask.dir/mean.cpp.o: ../mean.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oubin/c/clion-2016.3/Workplace/CompilerTask/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CompilerTask.dir/mean.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CompilerTask.dir/mean.cpp.o -c /home/oubin/c/clion-2016.3/Workplace/CompilerTask/mean.cpp

CMakeFiles/CompilerTask.dir/mean.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CompilerTask.dir/mean.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oubin/c/clion-2016.3/Workplace/CompilerTask/mean.cpp > CMakeFiles/CompilerTask.dir/mean.cpp.i

CMakeFiles/CompilerTask.dir/mean.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CompilerTask.dir/mean.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oubin/c/clion-2016.3/Workplace/CompilerTask/mean.cpp -o CMakeFiles/CompilerTask.dir/mean.cpp.s

CMakeFiles/CompilerTask.dir/mean.cpp.o.requires:

.PHONY : CMakeFiles/CompilerTask.dir/mean.cpp.o.requires

CMakeFiles/CompilerTask.dir/mean.cpp.o.provides: CMakeFiles/CompilerTask.dir/mean.cpp.o.requires
	$(MAKE) -f CMakeFiles/CompilerTask.dir/build.make CMakeFiles/CompilerTask.dir/mean.cpp.o.provides.build
.PHONY : CMakeFiles/CompilerTask.dir/mean.cpp.o.provides

CMakeFiles/CompilerTask.dir/mean.cpp.o.provides.build: CMakeFiles/CompilerTask.dir/mean.cpp.o


CMakeFiles/CompilerTask.dir/recursive.cpp.o: CMakeFiles/CompilerTask.dir/flags.make
CMakeFiles/CompilerTask.dir/recursive.cpp.o: ../recursive.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oubin/c/clion-2016.3/Workplace/CompilerTask/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CompilerTask.dir/recursive.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CompilerTask.dir/recursive.cpp.o -c /home/oubin/c/clion-2016.3/Workplace/CompilerTask/recursive.cpp

CMakeFiles/CompilerTask.dir/recursive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CompilerTask.dir/recursive.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oubin/c/clion-2016.3/Workplace/CompilerTask/recursive.cpp > CMakeFiles/CompilerTask.dir/recursive.cpp.i

CMakeFiles/CompilerTask.dir/recursive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CompilerTask.dir/recursive.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oubin/c/clion-2016.3/Workplace/CompilerTask/recursive.cpp -o CMakeFiles/CompilerTask.dir/recursive.cpp.s

CMakeFiles/CompilerTask.dir/recursive.cpp.o.requires:

.PHONY : CMakeFiles/CompilerTask.dir/recursive.cpp.o.requires

CMakeFiles/CompilerTask.dir/recursive.cpp.o.provides: CMakeFiles/CompilerTask.dir/recursive.cpp.o.requires
	$(MAKE) -f CMakeFiles/CompilerTask.dir/build.make CMakeFiles/CompilerTask.dir/recursive.cpp.o.provides.build
.PHONY : CMakeFiles/CompilerTask.dir/recursive.cpp.o.provides

CMakeFiles/CompilerTask.dir/recursive.cpp.o.provides.build: CMakeFiles/CompilerTask.dir/recursive.cpp.o


# Object files for target CompilerTask
CompilerTask_OBJECTS = \
"CMakeFiles/CompilerTask.dir/main.cpp.o" \
"CMakeFiles/CompilerTask.dir/scanner.cpp.o" \
"CMakeFiles/CompilerTask.dir/analyse.cpp.o" \
"CMakeFiles/CompilerTask.dir/mean.cpp.o" \
"CMakeFiles/CompilerTask.dir/recursive.cpp.o"

# External object files for target CompilerTask
CompilerTask_EXTERNAL_OBJECTS =

CompilerTask: CMakeFiles/CompilerTask.dir/main.cpp.o
CompilerTask: CMakeFiles/CompilerTask.dir/scanner.cpp.o
CompilerTask: CMakeFiles/CompilerTask.dir/analyse.cpp.o
CompilerTask: CMakeFiles/CompilerTask.dir/mean.cpp.o
CompilerTask: CMakeFiles/CompilerTask.dir/recursive.cpp.o
CompilerTask: CMakeFiles/CompilerTask.dir/build.make
CompilerTask: CMakeFiles/CompilerTask.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oubin/c/clion-2016.3/Workplace/CompilerTask/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable CompilerTask"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CompilerTask.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CompilerTask.dir/build: CompilerTask

.PHONY : CMakeFiles/CompilerTask.dir/build

CMakeFiles/CompilerTask.dir/requires: CMakeFiles/CompilerTask.dir/main.cpp.o.requires
CMakeFiles/CompilerTask.dir/requires: CMakeFiles/CompilerTask.dir/scanner.cpp.o.requires
CMakeFiles/CompilerTask.dir/requires: CMakeFiles/CompilerTask.dir/analyse.cpp.o.requires
CMakeFiles/CompilerTask.dir/requires: CMakeFiles/CompilerTask.dir/mean.cpp.o.requires
CMakeFiles/CompilerTask.dir/requires: CMakeFiles/CompilerTask.dir/recursive.cpp.o.requires

.PHONY : CMakeFiles/CompilerTask.dir/requires

CMakeFiles/CompilerTask.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CompilerTask.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CompilerTask.dir/clean

CMakeFiles/CompilerTask.dir/depend:
	cd /home/oubin/c/clion-2016.3/Workplace/CompilerTask/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oubin/c/clion-2016.3/Workplace/CompilerTask /home/oubin/c/clion-2016.3/Workplace/CompilerTask /home/oubin/c/clion-2016.3/Workplace/CompilerTask/cmake-build-debug /home/oubin/c/clion-2016.3/Workplace/CompilerTask/cmake-build-debug /home/oubin/c/clion-2016.3/Workplace/CompilerTask/cmake-build-debug/CMakeFiles/CompilerTask.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CompilerTask.dir/depend

