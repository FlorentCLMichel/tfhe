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
include libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/depend.make

# Include the progress variables for this target.
include libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/progress.make

# Include the compile flags for this target's objects.
include libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/flags.make

libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/fft_processor_graphec.cpp.o: libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/flags.make
libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/fft_processor_graphec.cpp.o: /home/florent/openfhe_opt/tfhe/src/libtfhe/fft_processors/optalysys_graphec/fft_processor_graphec.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/florent/openfhe_opt/tfhe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/fft_processor_graphec.cpp.o"
	cd /home/florent/openfhe_opt/tfhe/build/libtfhe/fft_processors/optalysys_graphec && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tfhe-fft-graphec.dir/fft_processor_graphec.cpp.o -c /home/florent/openfhe_opt/tfhe/src/libtfhe/fft_processors/optalysys_graphec/fft_processor_graphec.cpp

libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/fft_processor_graphec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tfhe-fft-graphec.dir/fft_processor_graphec.cpp.i"
	cd /home/florent/openfhe_opt/tfhe/build/libtfhe/fft_processors/optalysys_graphec && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/florent/openfhe_opt/tfhe/src/libtfhe/fft_processors/optalysys_graphec/fft_processor_graphec.cpp > CMakeFiles/tfhe-fft-graphec.dir/fft_processor_graphec.cpp.i

libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/fft_processor_graphec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tfhe-fft-graphec.dir/fft_processor_graphec.cpp.s"
	cd /home/florent/openfhe_opt/tfhe/build/libtfhe/fft_processors/optalysys_graphec && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/florent/openfhe_opt/tfhe/src/libtfhe/fft_processors/optalysys_graphec/fft_processor_graphec.cpp -o CMakeFiles/tfhe-fft-graphec.dir/fft_processor_graphec.cpp.s

libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/lagrangehalfc_impl.cpp.o: libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/flags.make
libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/lagrangehalfc_impl.cpp.o: /home/florent/openfhe_opt/tfhe/src/libtfhe/fft_processors/optalysys_graphec/lagrangehalfc_impl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/florent/openfhe_opt/tfhe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/lagrangehalfc_impl.cpp.o"
	cd /home/florent/openfhe_opt/tfhe/build/libtfhe/fft_processors/optalysys_graphec && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tfhe-fft-graphec.dir/lagrangehalfc_impl.cpp.o -c /home/florent/openfhe_opt/tfhe/src/libtfhe/fft_processors/optalysys_graphec/lagrangehalfc_impl.cpp

libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/lagrangehalfc_impl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tfhe-fft-graphec.dir/lagrangehalfc_impl.cpp.i"
	cd /home/florent/openfhe_opt/tfhe/build/libtfhe/fft_processors/optalysys_graphec && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/florent/openfhe_opt/tfhe/src/libtfhe/fft_processors/optalysys_graphec/lagrangehalfc_impl.cpp > CMakeFiles/tfhe-fft-graphec.dir/lagrangehalfc_impl.cpp.i

libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/lagrangehalfc_impl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tfhe-fft-graphec.dir/lagrangehalfc_impl.cpp.s"
	cd /home/florent/openfhe_opt/tfhe/build/libtfhe/fft_processors/optalysys_graphec && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/florent/openfhe_opt/tfhe/src/libtfhe/fft_processors/optalysys_graphec/lagrangehalfc_impl.cpp -o CMakeFiles/tfhe-fft-graphec.dir/lagrangehalfc_impl.cpp.s

tfhe-fft-graphec: libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/fft_processor_graphec.cpp.o
tfhe-fft-graphec: libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/lagrangehalfc_impl.cpp.o
tfhe-fft-graphec: libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/build.make

.PHONY : tfhe-fft-graphec

# Rule to build all files generated by this target.
libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/build: tfhe-fft-graphec

.PHONY : libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/build

libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/clean:
	cd /home/florent/openfhe_opt/tfhe/build/libtfhe/fft_processors/optalysys_graphec && $(CMAKE_COMMAND) -P CMakeFiles/tfhe-fft-graphec.dir/cmake_clean.cmake
.PHONY : libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/clean

libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/depend:
	cd /home/florent/openfhe_opt/tfhe/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/florent/openfhe_opt/tfhe/src /home/florent/openfhe_opt/tfhe/src/libtfhe/fft_processors/optalysys_graphec /home/florent/openfhe_opt/tfhe/build /home/florent/openfhe_opt/tfhe/build/libtfhe/fft_processors/optalysys_graphec /home/florent/openfhe_opt/tfhe/build/libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libtfhe/fft_processors/optalysys_graphec/CMakeFiles/tfhe-fft-graphec.dir/depend

