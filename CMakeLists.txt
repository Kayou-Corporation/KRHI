#---------------------------------------#
#				SETUP					#
#---------------------------------------#
cmake_minimum_required(VERSION 3.30.0 FATAL_ERROR)

project(KRHI VERSION 1.0.0 LANGUAGES CXX)



# --------------------------------------- #
#              FIND PACKAGES              #
# --------------------------------------- #
add_subdirectory(Libs)

find_package(Vulkan 1.4.304 REQUIRED)

# Output directories
set(OUTPUT_DIR_BASE "${CMAKE_SOURCE_DIR}/Builds/${CMAKE_CXX_COMPILER_ID}")

message(STATUS "[${PROJECT_NAME}]: Base output directory: ${OUTPUT_DIR_BASE}")

# Use generator expressions directly in output variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR_BASE}/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR_BASE}/$<CONFIG>/libs")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR_BASE}/$<CONFIG>/libs")


#---------------------------------------#
#				SOURCES					#
#---------------------------------------#
file(GLOB_RECURSE KRHI_SOURCES "Code/Source/*.cpp")



#---------------------------------------#
#				BUILD MODE  			#
#---------------------------------------#
option(KRHI_BUILD_STATIC "Build static libraries" ON)

if(KRHI_BUILD_STATIC)
    add_library(KRHI STATIC ${KRHI_SOURCES})
else()
    add_library(KRHI SHARED ${KRHI_SOURCES})
endif()



#---------------------------------------#
#				INCLUDE					#
#---------------------------------------#
target_include_directories(KRHI PUBLIC "Code/Include/")



#---------------------------------------#
#				COMPILE MODE			#
#---------------------------------------#
target_compile_features(KRHI PUBLIC cxx_std_20)

if(MSVC)
    set(CMAKE_DEBUG_POSTFIX "d")
    target_compile_options(KRHI PUBLIC /W3 /WX)
else()
    target_compile_options(KRHI PUBLIC -Wall -Wextra -Wpedantic -Werror)
endif()

# Build position independent code.
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Disable C and C++ compiler extensions.
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



#---------------------------------------#
#        EXPORTS / IMPORTS FOR DLL      #
#---------------------------------------#
# Disable lib prefix
set_target_properties(KRHI PROPERTIES PREFIX "")

# Set dll name
set_target_properties(KRHI PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${PROJECT_VERSION}")



#---------------------------------------#
#               LINK LIBRARIES          #
#---------------------------------------#
target_link_libraries(KRHI PUBLIC Vulkan::Vulkan glm::glm glfw)



# --------------------------------------- #
#              ENABLE TESTING             #
# --------------------------------------- #
# Enable CTests
enable_testing()

add_subdirectory(Test)