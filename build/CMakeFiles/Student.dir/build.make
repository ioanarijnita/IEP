# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/IEP/IEP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/IEP/IEP/build

# Include any dependencies generated for this target.
include CMakeFiles/Student.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Student.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Student.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Student.dir/flags.make

CMakeFiles/Student.dir/Student.cpp.obj: CMakeFiles/Student.dir/flags.make
CMakeFiles/Student.dir/Student.cpp.obj: C:/IEP/IEP/Student.cpp
CMakeFiles/Student.dir/Student.cpp.obj: CMakeFiles/Student.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/IEP/IEP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Student.dir/Student.cpp.obj"
	C:/msys64/mingw64/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Student.dir/Student.cpp.obj -MF CMakeFiles/Student.dir/Student.cpp.obj.d -o CMakeFiles/Student.dir/Student.cpp.obj -c C:/IEP/IEP/Student.cpp

CMakeFiles/Student.dir/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Student.dir/Student.cpp.i"
	C:/msys64/mingw64/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/IEP/IEP/Student.cpp > CMakeFiles/Student.dir/Student.cpp.i

CMakeFiles/Student.dir/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Student.dir/Student.cpp.s"
	C:/msys64/mingw64/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/IEP/IEP/Student.cpp -o CMakeFiles/Student.dir/Student.cpp.s

# Object files for target Student
Student_OBJECTS = \
"CMakeFiles/Student.dir/Student.cpp.obj"

# External object files for target Student
Student_EXTERNAL_OBJECTS =

Student.exe: CMakeFiles/Student.dir/Student.cpp.obj
Student.exe: CMakeFiles/Student.dir/build.make
Student.exe: CMakeFiles/Student.dir/linkLibs.rsp
Student.exe: CMakeFiles/Student.dir/objects1
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/IEP/IEP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Student.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/Student.dir/objects.a
	C:/msys64/mingw64/bin/ar.exe qc CMakeFiles/Student.dir/objects.a @CMakeFiles/Student.dir/objects1
	C:/msys64/mingw64/bin/g++ -g -Wl,--whole-archive CMakeFiles/Student.dir/objects.a -Wl,--no-whole-archive -o Student.exe -Wl,--out-implib,libStudent.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/Student.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/Student.dir/build: Student.exe
.PHONY : CMakeFiles/Student.dir/build

CMakeFiles/Student.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Student.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Student.dir/clean

CMakeFiles/Student.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/IEP/IEP C:/IEP/IEP C:/IEP/IEP/build C:/IEP/IEP/build C:/IEP/IEP/build/CMakeFiles/Student.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Student.dir/depend

