# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\SupemonAlpha

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\SupemonAlpha\build

# Include any dependencies generated for this target.
include CMakeFiles/SupemonAlpha.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SupemonAlpha.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SupemonAlpha.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SupemonAlpha.dir/flags.make

CMakeFiles/SupemonAlpha.dir/main.c.obj: CMakeFiles/SupemonAlpha.dir/flags.make
CMakeFiles/SupemonAlpha.dir/main.c.obj: F:/SupemonAlpha/main.c
CMakeFiles/SupemonAlpha.dir/main.c.obj: CMakeFiles/SupemonAlpha.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\SupemonAlpha\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SupemonAlpha.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SupemonAlpha.dir/main.c.obj -MF CMakeFiles\SupemonAlpha.dir\main.c.obj.d -o CMakeFiles\SupemonAlpha.dir\main.c.obj -c F:\SupemonAlpha\main.c

CMakeFiles/SupemonAlpha.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SupemonAlpha.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\SupemonAlpha\main.c > CMakeFiles\SupemonAlpha.dir\main.c.i

CMakeFiles/SupemonAlpha.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SupemonAlpha.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\SupemonAlpha\main.c -o CMakeFiles\SupemonAlpha.dir\main.c.s

CMakeFiles/SupemonAlpha.dir/fight.c.obj: CMakeFiles/SupemonAlpha.dir/flags.make
CMakeFiles/SupemonAlpha.dir/fight.c.obj: F:/SupemonAlpha/fight.c
CMakeFiles/SupemonAlpha.dir/fight.c.obj: CMakeFiles/SupemonAlpha.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\SupemonAlpha\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SupemonAlpha.dir/fight.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SupemonAlpha.dir/fight.c.obj -MF CMakeFiles\SupemonAlpha.dir\fight.c.obj.d -o CMakeFiles\SupemonAlpha.dir\fight.c.obj -c F:\SupemonAlpha\fight.c

CMakeFiles/SupemonAlpha.dir/fight.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SupemonAlpha.dir/fight.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\SupemonAlpha\fight.c > CMakeFiles\SupemonAlpha.dir\fight.c.i

CMakeFiles/SupemonAlpha.dir/fight.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SupemonAlpha.dir/fight.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\SupemonAlpha\fight.c -o CMakeFiles\SupemonAlpha.dir\fight.c.s

CMakeFiles/SupemonAlpha.dir/supemon.c.obj: CMakeFiles/SupemonAlpha.dir/flags.make
CMakeFiles/SupemonAlpha.dir/supemon.c.obj: F:/SupemonAlpha/supemon.c
CMakeFiles/SupemonAlpha.dir/supemon.c.obj: CMakeFiles/SupemonAlpha.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\SupemonAlpha\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/SupemonAlpha.dir/supemon.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SupemonAlpha.dir/supemon.c.obj -MF CMakeFiles\SupemonAlpha.dir\supemon.c.obj.d -o CMakeFiles\SupemonAlpha.dir\supemon.c.obj -c F:\SupemonAlpha\supemon.c

CMakeFiles/SupemonAlpha.dir/supemon.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SupemonAlpha.dir/supemon.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\SupemonAlpha\supemon.c > CMakeFiles\SupemonAlpha.dir\supemon.c.i

CMakeFiles/SupemonAlpha.dir/supemon.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SupemonAlpha.dir/supemon.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\SupemonAlpha\supemon.c -o CMakeFiles\SupemonAlpha.dir\supemon.c.s

CMakeFiles/SupemonAlpha.dir/load_and_save.c.obj: CMakeFiles/SupemonAlpha.dir/flags.make
CMakeFiles/SupemonAlpha.dir/load_and_save.c.obj: F:/SupemonAlpha/load_and_save.c
CMakeFiles/SupemonAlpha.dir/load_and_save.c.obj: CMakeFiles/SupemonAlpha.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\SupemonAlpha\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/SupemonAlpha.dir/load_and_save.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SupemonAlpha.dir/load_and_save.c.obj -MF CMakeFiles\SupemonAlpha.dir\load_and_save.c.obj.d -o CMakeFiles\SupemonAlpha.dir\load_and_save.c.obj -c F:\SupemonAlpha\load_and_save.c

CMakeFiles/SupemonAlpha.dir/load_and_save.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SupemonAlpha.dir/load_and_save.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\SupemonAlpha\load_and_save.c > CMakeFiles\SupemonAlpha.dir\load_and_save.c.i

CMakeFiles/SupemonAlpha.dir/load_and_save.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SupemonAlpha.dir/load_and_save.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\SupemonAlpha\load_and_save.c -o CMakeFiles\SupemonAlpha.dir\load_and_save.c.s

CMakeFiles/SupemonAlpha.dir/player.c.obj: CMakeFiles/SupemonAlpha.dir/flags.make
CMakeFiles/SupemonAlpha.dir/player.c.obj: F:/SupemonAlpha/player.c
CMakeFiles/SupemonAlpha.dir/player.c.obj: CMakeFiles/SupemonAlpha.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\SupemonAlpha\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/SupemonAlpha.dir/player.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SupemonAlpha.dir/player.c.obj -MF CMakeFiles\SupemonAlpha.dir\player.c.obj.d -o CMakeFiles\SupemonAlpha.dir\player.c.obj -c F:\SupemonAlpha\player.c

CMakeFiles/SupemonAlpha.dir/player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SupemonAlpha.dir/player.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\SupemonAlpha\player.c > CMakeFiles\SupemonAlpha.dir\player.c.i

CMakeFiles/SupemonAlpha.dir/player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SupemonAlpha.dir/player.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\SupemonAlpha\player.c -o CMakeFiles\SupemonAlpha.dir\player.c.s

CMakeFiles/SupemonAlpha.dir/shop.c.obj: CMakeFiles/SupemonAlpha.dir/flags.make
CMakeFiles/SupemonAlpha.dir/shop.c.obj: F:/SupemonAlpha/shop.c
CMakeFiles/SupemonAlpha.dir/shop.c.obj: CMakeFiles/SupemonAlpha.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\SupemonAlpha\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/SupemonAlpha.dir/shop.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SupemonAlpha.dir/shop.c.obj -MF CMakeFiles\SupemonAlpha.dir\shop.c.obj.d -o CMakeFiles\SupemonAlpha.dir\shop.c.obj -c F:\SupemonAlpha\shop.c

CMakeFiles/SupemonAlpha.dir/shop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SupemonAlpha.dir/shop.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\SupemonAlpha\shop.c > CMakeFiles\SupemonAlpha.dir\shop.c.i

CMakeFiles/SupemonAlpha.dir/shop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SupemonAlpha.dir/shop.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\SupemonAlpha\shop.c -o CMakeFiles\SupemonAlpha.dir\shop.c.s

CMakeFiles/SupemonAlpha.dir/item.c.obj: CMakeFiles/SupemonAlpha.dir/flags.make
CMakeFiles/SupemonAlpha.dir/item.c.obj: F:/SupemonAlpha/item.c
CMakeFiles/SupemonAlpha.dir/item.c.obj: CMakeFiles/SupemonAlpha.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\SupemonAlpha\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/SupemonAlpha.dir/item.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SupemonAlpha.dir/item.c.obj -MF CMakeFiles\SupemonAlpha.dir\item.c.obj.d -o CMakeFiles\SupemonAlpha.dir\item.c.obj -c F:\SupemonAlpha\item.c

CMakeFiles/SupemonAlpha.dir/item.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SupemonAlpha.dir/item.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\SupemonAlpha\item.c > CMakeFiles\SupemonAlpha.dir\item.c.i

CMakeFiles/SupemonAlpha.dir/item.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SupemonAlpha.dir/item.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\SupemonAlpha\item.c -o CMakeFiles\SupemonAlpha.dir\item.c.s

CMakeFiles/SupemonAlpha.dir/utils.c.obj: CMakeFiles/SupemonAlpha.dir/flags.make
CMakeFiles/SupemonAlpha.dir/utils.c.obj: F:/SupemonAlpha/utils.c
CMakeFiles/SupemonAlpha.dir/utils.c.obj: CMakeFiles/SupemonAlpha.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\SupemonAlpha\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/SupemonAlpha.dir/utils.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SupemonAlpha.dir/utils.c.obj -MF CMakeFiles\SupemonAlpha.dir\utils.c.obj.d -o CMakeFiles\SupemonAlpha.dir\utils.c.obj -c F:\SupemonAlpha\utils.c

CMakeFiles/SupemonAlpha.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SupemonAlpha.dir/utils.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\SupemonAlpha\utils.c > CMakeFiles\SupemonAlpha.dir\utils.c.i

CMakeFiles/SupemonAlpha.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SupemonAlpha.dir/utils.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\SupemonAlpha\utils.c -o CMakeFiles\SupemonAlpha.dir\utils.c.s

# Object files for target SupemonAlpha
SupemonAlpha_OBJECTS = \
"CMakeFiles/SupemonAlpha.dir/main.c.obj" \
"CMakeFiles/SupemonAlpha.dir/fight.c.obj" \
"CMakeFiles/SupemonAlpha.dir/supemon.c.obj" \
"CMakeFiles/SupemonAlpha.dir/load_and_save.c.obj" \
"CMakeFiles/SupemonAlpha.dir/player.c.obj" \
"CMakeFiles/SupemonAlpha.dir/shop.c.obj" \
"CMakeFiles/SupemonAlpha.dir/item.c.obj" \
"CMakeFiles/SupemonAlpha.dir/utils.c.obj"

# External object files for target SupemonAlpha
SupemonAlpha_EXTERNAL_OBJECTS =

SupemonAlpha.exe: CMakeFiles/SupemonAlpha.dir/main.c.obj
SupemonAlpha.exe: CMakeFiles/SupemonAlpha.dir/fight.c.obj
SupemonAlpha.exe: CMakeFiles/SupemonAlpha.dir/supemon.c.obj
SupemonAlpha.exe: CMakeFiles/SupemonAlpha.dir/load_and_save.c.obj
SupemonAlpha.exe: CMakeFiles/SupemonAlpha.dir/player.c.obj
SupemonAlpha.exe: CMakeFiles/SupemonAlpha.dir/shop.c.obj
SupemonAlpha.exe: CMakeFiles/SupemonAlpha.dir/item.c.obj
SupemonAlpha.exe: CMakeFiles/SupemonAlpha.dir/utils.c.obj
SupemonAlpha.exe: CMakeFiles/SupemonAlpha.dir/build.make
SupemonAlpha.exe: CMakeFiles/SupemonAlpha.dir/linkLibs.rsp
SupemonAlpha.exe: CMakeFiles/SupemonAlpha.dir/objects1.rsp
SupemonAlpha.exe: CMakeFiles/SupemonAlpha.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=F:\SupemonAlpha\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable SupemonAlpha.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SupemonAlpha.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SupemonAlpha.dir/build: SupemonAlpha.exe
.PHONY : CMakeFiles/SupemonAlpha.dir/build

CMakeFiles/SupemonAlpha.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SupemonAlpha.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SupemonAlpha.dir/clean

CMakeFiles/SupemonAlpha.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\SupemonAlpha F:\SupemonAlpha F:\SupemonAlpha\build F:\SupemonAlpha\build F:\SupemonAlpha\build\CMakeFiles\SupemonAlpha.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SupemonAlpha.dir/depend

