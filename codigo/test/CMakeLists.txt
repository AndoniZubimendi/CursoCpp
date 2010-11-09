cmake_minimum_required(VERSION 2.6)

Project ( base )

FILE(GLOB_RECURSE SOURCES
	src/*.cpp
#	src/*.c
)

FILE(GLOB_RECURSE TEST_SOURCES
	test/*.cpp
#	test/*.c
	src/sample1.cpp
)

add_executable (
   base
   WIN32 # Only if you don't want the DOS prompt to appear in the background in Windows
   MACOSX_BUNDLE
   ${SOURCES} # We could've listed the source files here directly instead of using a variable to store them
)


link_libraries (
    gtest
    gtest_main
)

include_directories (
    include
)

add_executable (
   test
   WIN32 # Only if you don't want the DOS prompt to appear in the background in Windows
   MACOSX_BUNDLE
   ${TEST_SOURCES} # We could've listed the source files here directly instead of using a variable to store them
   ${}
)
