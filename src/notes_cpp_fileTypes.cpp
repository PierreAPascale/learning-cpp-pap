/*
File Types:

.cpp
IMPLEMENTATION files. This is where the logic of your code resides. It is never included by other implementation files.
Must be compiled (into Assembly then Object files)

.h
HEADER files. This is where declarations (Classes, members, functions) are written, without implementation. "Just the tokens".

.hpp

JSON
tasks.json : Configuration params for VSCode. In Github, this is what drives compilation. command: g++ compiler.  args: standard, list of source files ("${fileDirName}/*.cpp" means all cpp files it finds in the same FOLDER as source files shown in the editor (when pressing F5). Identical to a "make" file (used by environments to define which files to compile).




*/