# --------------------------------------- #
#               CMAKE CONFIG              #
# --------------------------------------- #

# Define minimum CMake version required
cmake_minimum_required(VERSION 3.29.0)



project(Renderer
        VERSION 1.0.0
        LANGUAGES CXX)



#---------------------------------------#
#            BUILD MODE                 #
#---------------------------------------#

add_executable(KRHI_TEST_RENDERER "Main.cpp")



#---------------------------------------#
#                COMPILE MODE           #
#---------------------------------------#
target_compile_features(KRHI_TEST_RENDERER PUBLIC cxx_std_20)

if(MSVC)
    set(CMAKE_DEBUG_POSTFIX "d")
    target_compile_options(KRHI_TEST_RENDERER PUBLIC /W3 /WX)
else()
    target_compile_options(KRHI_TEST_RENDERER PUBLIC -Wall -Wextra -Wpedantic -Werror)
endif()



# Build position independent code.
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Disable C and C++ compiler extensions.
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)



target_link_libraries(KRHI_TEST_RENDERER PRIVATE KRHI)
