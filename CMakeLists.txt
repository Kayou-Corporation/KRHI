#-----------------ROOT----------------------#

cmake_minimum_required(VERSION 3.29.5)

#---------------------------------------#
#				SETUP					#
#---------------------------------------#
project(KRHI)

# Output directories
set(OUTPUT_DIR_BASE "${CMAKE_SOURCE_DIR}/build/${CMAKE_CXX_COMPILER_ID}")

message(STATUS "[${PROJECT_NAME}]: Base output directory: ${OUTPUT_DIR_BASE}")

# Use generator expressions directly in output variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR_BASE}/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR_BASE}/$<CONFIG>/libs")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR_BASE}/$<CONFIG>/libs")


#---------------------------------------#
#				SOURCES					#
#---------------------------------------#
file(GLOB_RECURSE KRHI_SOURCES "Source/*.cpp")

#---------------------------------------#
#				EXECUTABLE  			#
#---------------------------------------#
add_executable(KRHI ${KRHI_SOURCES})

#---------------------------------------#
#				INCLUDE					#
#---------------------------------------#
target_include_directories(KRHI PUBLIC "Include/")

#---------------------------------------#
#				COMPILE MODE			#
#---------------------------------------#
target_compile_features(KRHI PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(KRHI PUBLIC /W3 /WX)
else()
    target_compile_options(KRHI PUBLIC -Wall -Wextra -Wpedantic)
endif()