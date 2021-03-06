cmake_minimum_required(VERSION 2.8)

find_package(SWIG REQUIRED)
find_package(Java REQUIRED)
find_package(JNI REQUIRED)
include(UseJava)
include(UseSWIG)
include_directories(${JNI_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_LIST_DIR})

set( CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR} )

set( CMAKE_SWIG_FLAGS -Wall -debug-typemap -debug-tmsearch -debug-tmused)
# Build the C++ code into a dynamic library: example.dll (on Windows) or libexample.so (on Linux)
swig_add_library(
    example 
    LANGUAGE java 
    SOURCES example.i 
    example.h
    example.cpp
)
set(  ${SWIG_MODULE_example_EXTRA_DEPS} 
  ${CMAKE_CURRENT_LIST_DIR}/example.i 
  ${CMAKE_CURRENT_LIST_DIR}/example.cpp 
  ${CMAKE_CURRENT_LIST_DIR}/example.h )
#  ${CMAKE_SWIG_OUTDIR}/exampleJAVA_wrap.c 

# For convenience we copy the dynamic library to the current build folder
add_custom_command(
    TARGET example 
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:example> ${CMAKE_CURRENT_BINARY_DIR}
)

# Build the Java code into ExampleJNI.jar
add_jar(
    ExampleJNI
    SOURCES
    ${CMAKE_SWIG_OUTDIR}/example.java
    ${CMAKE_SWIG_OUTDIR}/exampleJNI.java
)
add_dependencies( ExampleJNI example )

# Finally build the demonstration code into Main.jar

set(CMAKE_JAVA_JAR_ENTRY_POINT main) 
add_jar(
    Main 
    SOURCES main.java
    ENTRY_POINT main
)
add_dependencies( Main ExampleJNI )

enable_testing()

add_test(
    NAME TestReturnValue
    COMMAND ${JAVA_HOME}/bin/java -jar Main.jar
)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIG>
                  DEPENDS Main)

