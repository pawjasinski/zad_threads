# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/dev/clion-2021.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dev/clion-2021.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dev/workspace_qt/zadanie_radmor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dev/workspace_qt/zadanie_radmor/cmake-build-debug

# Include any dependencies generated for this target.
include libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/depend.make
# Include the progress variables for this target.
include libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/progress.make

# Include the compile flags for this target's objects.
include libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/flags.make

libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/src/thread_pool.cpp.o: libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/flags.make
libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/src/thread_pool.cpp.o: ../libs/thread_pool/src/thread_pool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dev/workspace_qt/zadanie_radmor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/src/thread_pool.cpp.o"
	cd /home/dev/workspace_qt/zadanie_radmor/cmake-build-debug/libs/thread_pool && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LIB_ThreadPool.dir/src/thread_pool.cpp.o -c /home/dev/workspace_qt/zadanie_radmor/libs/thread_pool/src/thread_pool.cpp

libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/src/thread_pool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LIB_ThreadPool.dir/src/thread_pool.cpp.i"
	cd /home/dev/workspace_qt/zadanie_radmor/cmake-build-debug/libs/thread_pool && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dev/workspace_qt/zadanie_radmor/libs/thread_pool/src/thread_pool.cpp > CMakeFiles/LIB_ThreadPool.dir/src/thread_pool.cpp.i

libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/src/thread_pool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LIB_ThreadPool.dir/src/thread_pool.cpp.s"
	cd /home/dev/workspace_qt/zadanie_radmor/cmake-build-debug/libs/thread_pool && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dev/workspace_qt/zadanie_radmor/libs/thread_pool/src/thread_pool.cpp -o CMakeFiles/LIB_ThreadPool.dir/src/thread_pool.cpp.s

# Object files for target LIB_ThreadPool
LIB_ThreadPool_OBJECTS = \
"CMakeFiles/LIB_ThreadPool.dir/src/thread_pool.cpp.o"

# External object files for target LIB_ThreadPool
LIB_ThreadPool_EXTERNAL_OBJECTS =

libs/thread_pool/libLIB_ThreadPool.so: libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/src/thread_pool.cpp.o
libs/thread_pool/libLIB_ThreadPool.so: libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/build.make
libs/thread_pool/libLIB_ThreadPool.so: libs/queue_sync/libLIB_QueueSync.so
libs/thread_pool/libLIB_ThreadPool.so: libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dev/workspace_qt/zadanie_radmor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libLIB_ThreadPool.so"
	cd /home/dev/workspace_qt/zadanie_radmor/cmake-build-debug/libs/thread_pool && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LIB_ThreadPool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/build: libs/thread_pool/libLIB_ThreadPool.so
.PHONY : libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/build

libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/clean:
	cd /home/dev/workspace_qt/zadanie_radmor/cmake-build-debug/libs/thread_pool && $(CMAKE_COMMAND) -P CMakeFiles/LIB_ThreadPool.dir/cmake_clean.cmake
.PHONY : libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/clean

libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/depend:
	cd /home/dev/workspace_qt/zadanie_radmor/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dev/workspace_qt/zadanie_radmor /home/dev/workspace_qt/zadanie_radmor/libs/thread_pool /home/dev/workspace_qt/zadanie_radmor/cmake-build-debug /home/dev/workspace_qt/zadanie_radmor/cmake-build-debug/libs/thread_pool /home/dev/workspace_qt/zadanie_radmor/cmake-build-debug/libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/thread_pool/CMakeFiles/LIB_ThreadPool.dir/depend

