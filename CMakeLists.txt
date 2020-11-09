cmake_minimum_required(VERSION 3.10)
project(VulkanProject)

set(CMAKE_CXX_STANDARD 20)

# Add modules path dir
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake;${CMAKE_MODULE_PATH}")

add_subdirectory(libs/glm)
set(GLM_ROOT_DIR libs/gml)
set(GLM_INCLUDE_DIR libs/gml)


add_subdirectory(libs/glfw)
set(GLFW_INCLUDE_DIR libs/glfw/include)
set(GLFW_LIBRARY libs/glfw)

#set(SDL2_PATH libs/SDL2)
#set(SDL2_INCLUDE_DIR libs/SDL2/include)
#set(SDL2_LIBRARY libs/SDL2)

add_definitions(-DDEBUG_STATUS=1)

add_subdirectory(SampleApplication)

# add_executable(VulkanProject main.cpp)

# target_include_directories(VulkanProject PUBLIC ${Vulkan_INCLUDE_DIRS})

# target_link_libraries(VulkanProject PRIVATE Vulkan::Vulkan glm glfw)