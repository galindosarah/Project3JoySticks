# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/CHESS101/CLionProjects/Project3JoySticks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/CHESS101/CLionProjects/Project3JoySticks/build

# Include any dependencies generated for this target.
include CMakeFiles/MyCppProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyCppProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyCppProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyCppProject.dir/flags.make

CMakeFiles/MyCppProject.dir/codegen:
.PHONY : CMakeFiles/MyCppProject.dir/codegen

CMakeFiles/MyCppProject.dir/main.cpp.o: CMakeFiles/MyCppProject.dir/flags.make
CMakeFiles/MyCppProject.dir/main.cpp.o: /Users/CHESS101/CLionProjects/Project3JoySticks/main.cpp
CMakeFiles/MyCppProject.dir/main.cpp.o: CMakeFiles/MyCppProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/CHESS101/CLionProjects/Project3JoySticks/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyCppProject.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyCppProject.dir/main.cpp.o -MF CMakeFiles/MyCppProject.dir/main.cpp.o.d -o CMakeFiles/MyCppProject.dir/main.cpp.o -c /Users/CHESS101/CLionProjects/Project3JoySticks/main.cpp

CMakeFiles/MyCppProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyCppProject.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/CHESS101/CLionProjects/Project3JoySticks/main.cpp > CMakeFiles/MyCppProject.dir/main.cpp.i

CMakeFiles/MyCppProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyCppProject.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/CHESS101/CLionProjects/Project3JoySticks/main.cpp -o CMakeFiles/MyCppProject.dir/main.cpp.s

# Object files for target MyCppProject
MyCppProject_OBJECTS = \
"CMakeFiles/MyCppProject.dir/main.cpp.o"

# External object files for target MyCppProject
MyCppProject_EXTERNAL_OBJECTS =

MyCppProject: CMakeFiles/MyCppProject.dir/main.cpp.o
MyCppProject: CMakeFiles/MyCppProject.dir/build.make
MyCppProject: CMakeFiles/MyCppProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/CHESS101/CLionProjects/Project3JoySticks/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MyCppProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyCppProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyCppProject.dir/build: MyCppProject
.PHONY : CMakeFiles/MyCppProject.dir/build

CMakeFiles/MyCppProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyCppProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyCppProject.dir/clean

CMakeFiles/MyCppProject.dir/depend:
	cd /Users/CHESS101/CLionProjects/Project3JoySticks/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/CHESS101/CLionProjects/Project3JoySticks /Users/CHESS101/CLionProjects/Project3JoySticks /Users/CHESS101/CLionProjects/Project3JoySticks/build /Users/CHESS101/CLionProjects/Project3JoySticks/build /Users/CHESS101/CLionProjects/Project3JoySticks/build/CMakeFiles/MyCppProject.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MyCppProject.dir/depend

