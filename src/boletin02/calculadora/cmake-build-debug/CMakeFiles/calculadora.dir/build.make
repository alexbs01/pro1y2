# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\alexb\CLionProjects\boletin2\calculadora

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\alexb\CLionProjects\boletin2\calculadora\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/calculadora.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/calculadora.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calculadora.dir/flags.make

CMakeFiles/calculadora.dir/main.c.obj: CMakeFiles/calculadora.dir/flags.make
CMakeFiles/calculadora.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexb\CLionProjects\boletin2\calculadora\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/calculadora.dir/main.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\calculadora.dir\main.c.obj -c C:\Users\alexb\CLionProjects\boletin2\calculadora\main.c

CMakeFiles/calculadora.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/calculadora.dir/main.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexb\CLionProjects\boletin2\calculadora\main.c > CMakeFiles\calculadora.dir\main.c.i

CMakeFiles/calculadora.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/calculadora.dir/main.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexb\CLionProjects\boletin2\calculadora\main.c -o CMakeFiles\calculadora.dir\main.c.s

# Object files for target calculadora
calculadora_OBJECTS = \
"CMakeFiles/calculadora.dir/main.c.obj"

# External object files for target calculadora
calculadora_EXTERNAL_OBJECTS =

calculadora.exe: CMakeFiles/calculadora.dir/main.c.obj
calculadora.exe: CMakeFiles/calculadora.dir/build.make
calculadora.exe: CMakeFiles/calculadora.dir/linklibs.rsp
calculadora.exe: CMakeFiles/calculadora.dir/objects1.rsp
calculadora.exe: CMakeFiles/calculadora.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\alexb\CLionProjects\boletin2\calculadora\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable calculadora.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\calculadora.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calculadora.dir/build: calculadora.exe
.PHONY : CMakeFiles/calculadora.dir/build

CMakeFiles/calculadora.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\calculadora.dir\cmake_clean.cmake
.PHONY : CMakeFiles/calculadora.dir/clean

CMakeFiles/calculadora.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\alexb\CLionProjects\boletin2\calculadora C:\Users\alexb\CLionProjects\boletin2\calculadora C:\Users\alexb\CLionProjects\boletin2\calculadora\cmake-build-debug C:\Users\alexb\CLionProjects\boletin2\calculadora\cmake-build-debug C:\Users\alexb\CLionProjects\boletin2\calculadora\cmake-build-debug\CMakeFiles\calculadora.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/calculadora.dir/depend

