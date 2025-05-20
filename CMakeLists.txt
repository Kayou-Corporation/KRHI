#-----------------ROOT----------------------#

cmake_minimum_required(VERSION 3.29.5)

#---------------------------------------#
#				SETUP					#
#---------------------------------------#
project(KRHI)

#set(MY_BIN_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/build/${CMAKE_CXX_COMPILERID}$<CONFIG>")
#message("[${CMAKE_PROJECT_NAME}]: Output directory: ${MY_BIN_OUTPUT_DIR}")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${MY_BIN_OUTPUT_DIR}/libs")
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${MY_BIN_OUTPUT_DIR}/libs")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${MY_BIN_OUTPUT_DIR}")
#
#enable_testing()
#
#
##---------------------------------------#
##			LIBS FETCH					#
##---------------------------------------#
#add_subdirectory(libs)
#
#find_package(Vulkan REQUIRED)
#
##---------------------------------------#
##			SUBDIRECTORY				#
##---------------------------------------#
#add_subdirectory(Engine)
#add_subdirectory(Editor)
#
#
##---------------------------------------#
##			LIBS LINK					#
##---------------------------------------#
#target_link_libraries(Engine PUBLIC stb)
#target_link_libraries(Engine PUBLIC assimp::assimp)
#target_link_libraries(Engine PUBLIC glfw)
#target_link_libraries(Engine PUBLIC Vulkan::Vulkan)
#
#target_link_libraries(Editor PUBLIC Vulkan::Vulkan)
#target_link_libraries(Editor PUBLIC glfw)
#target_link_libraries(Editor PUBLIC imgui)
