# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/florent/openfhe_opt/tfhe/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/florent/openfhe_opt/tfhe/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/equality-spqlios-fma.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/equality-spqlios-fma.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/equality-spqlios-fma.dir/flags.make

examples/CMakeFiles/equality-spqlios-fma.dir/equality.cpp.o: examples/CMakeFiles/equality-spqlios-fma.dir/flags.make
examples/CMakeFiles/equality-spqlios-fma.dir/equality.cpp.o: /home/florent/openfhe_opt/tfhe/src/examples/equality.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/florent/openfhe_opt/tfhe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/equality-spqlios-fma.dir/equality.cpp.o"
	cd /home/florent/openfhe_opt/tfhe/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/equality-spqlios-fma.dir/equality.cpp.o -c /home/florent/openfhe_opt/tfhe/src/examples/equality.cpp

examples/CMakeFiles/equality-spqlios-fma.dir/equality.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/equality-spqlios-fma.dir/equality.cpp.i"
	cd /home/florent/openfhe_opt/tfhe/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/florent/openfhe_opt/tfhe/src/examples/equality.cpp > CMakeFiles/equality-spqlios-fma.dir/equality.cpp.i

examples/CMakeFiles/equality-spqlios-fma.dir/equality.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/equality-spqlios-fma.dir/equality.cpp.s"
	cd /home/florent/openfhe_opt/tfhe/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/florent/openfhe_opt/tfhe/src/examples/equality.cpp -o CMakeFiles/equality-spqlios-fma.dir/equality.cpp.s

# Object files for target equality-spqlios-fma
equality__spqlios__fma_OBJECTS = \
"CMakeFiles/equality-spqlios-fma.dir/equality.cpp.o"

# External object files for target equality-spqlios-fma
equality__spqlios__fma_EXTERNAL_OBJECTS =

examples/equality-spqlios-fma: examples/CMakeFiles/equality-spqlios-fma.dir/equality.cpp.o
examples/equality-spqlios-fma: examples/CMakeFiles/equality-spqlios-fma.dir/build.make
examples/equality-spqlios-fma: libtfhe/libtfhe-spqlios-fma.so
examples/equality-spqlios-fma: examples/CMakeFiles/equality-spqlios-fma.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/florent/openfhe_opt/tfhe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable equality-spqlios-fma"
	cd /home/florent/openfhe_opt/tfhe/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/equality-spqlios-fma.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/equality-spqlios-fma.dir/build: examples/equality-spqlios-fma

.PHONY : examples/CMakeFiles/equality-spqlios-fma.dir/build

examples/CMakeFiles/equality-spqlios-fma.dir/clean:
	cd /home/florent/openfhe_opt/tfhe/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/equality-spqlios-fma.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/equality-spqlios-fma.dir/clean

examples/CMakeFiles/equality-spqlios-fma.dir/depend:
	cd /home/florent/openfhe_opt/tfhe/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/florent/openfhe_opt/tfhe/src /home/florent/openfhe_opt/tfhe/src/examples /home/florent/openfhe_opt/tfhe/build /home/florent/openfhe_opt/tfhe/build/examples /home/florent/openfhe_opt/tfhe/build/examples/CMakeFiles/equality-spqlios-fma.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/equality-spqlios-fma.dir/depend

