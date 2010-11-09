cmake_minimum_required(VERSION 2.6)

Project ( tinyXML )

FILE(GLOB_RECURSE SOURCES
	src/*.cpp
#	src/*.c
)

link_libraries (
)

add_executable (
   tinyXML
   WIN32 # Only if you don't want the DOS prompt to appear in the background in Windows
   MACOSX_BUNDLE
   ${SOURCES} # We could've listed the source files here directly instead of using a variable to store them
)
