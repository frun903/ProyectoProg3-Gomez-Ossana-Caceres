# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Limpio.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Limpio.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Limpio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Limpio.dir/flags.make

CMakeFiles/Limpio.dir/Limpio/Procesador_inventario.cpp.obj: CMakeFiles/Limpio.dir/flags.make
CMakeFiles/Limpio.dir/Limpio/Procesador_inventario.cpp.obj: D:/UCC/UNIVERSIDAD\ 2023/Segundo\ Semestre/programacion\ 3-intento2/PROYECTOFINAL/ProyectoProg3-Gomez-Ossana-Caceres/Limpio/Procesador_inventario.cpp
CMakeFiles/Limpio.dir/Limpio/Procesador_inventario.cpp.obj: CMakeFiles/Limpio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Limpio.dir/Limpio/Procesador_inventario.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Limpio.dir/Limpio/Procesador_inventario.cpp.obj -MF CMakeFiles\Limpio.dir\Limpio\Procesador_inventario.cpp.obj.d -o CMakeFiles\Limpio.dir\Limpio\Procesador_inventario.cpp.obj -c "D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres\Limpio\Procesador_inventario.cpp"

CMakeFiles/Limpio.dir/Limpio/Procesador_inventario.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Limpio.dir/Limpio/Procesador_inventario.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres\Limpio\Procesador_inventario.cpp" > CMakeFiles\Limpio.dir\Limpio\Procesador_inventario.cpp.i

CMakeFiles/Limpio.dir/Limpio/Procesador_inventario.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Limpio.dir/Limpio/Procesador_inventario.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres\Limpio\Procesador_inventario.cpp" -o CMakeFiles\Limpio.dir\Limpio\Procesador_inventario.cpp.s

# Object files for target Limpio
Limpio_OBJECTS = \
"CMakeFiles/Limpio.dir/Limpio/Procesador_inventario.cpp.obj"

# External object files for target Limpio
Limpio_EXTERNAL_OBJECTS =

Limpio.exe: CMakeFiles/Limpio.dir/Limpio/Procesador_inventario.cpp.obj
Limpio.exe: CMakeFiles/Limpio.dir/build.make
Limpio.exe: CMakeFiles/Limpio.dir/linkLibs.rsp
Limpio.exe: CMakeFiles/Limpio.dir/objects1.rsp
Limpio.exe: CMakeFiles/Limpio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Limpio.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Limpio.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Limpio.dir/build: Limpio.exe
.PHONY : CMakeFiles/Limpio.dir/build

CMakeFiles/Limpio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Limpio.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Limpio.dir/clean

CMakeFiles/Limpio.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres" "D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres" "D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres\cmake-build-debug" "D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres\cmake-build-debug" "D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres\cmake-build-debug\CMakeFiles\Limpio.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Limpio.dir/depend

