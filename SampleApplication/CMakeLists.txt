cmake_minimum_required(VERSION 3.10)
project(SampleApplication)

#find_package(Vulkan REQUIRED)
#find_package(GLM REQUIRED)
#find_package(GLFW REQUIRED)
set(SDL2_INCLUDE_DIR ../libs/SDL2/include)
set(SDL2_DIR ../libs/SDL2)
#set(SDL2_LIBRARY libs/SDL22)
find_package(SDL2 REQUIRED)


MESSAGE(STATUS "SDL2 = ${SDL2_INCLUDE_DIRS}")
MESSAGE(STATUS "SDL2_IMAGE = ${SDL2_IMAGE_INCLUDE_DIRS}")

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

MESSAGE(STATUS "SDL2_LIBRARIES = ${SDL2_LIBRARIES}")

add_executable(SampleApplication src/main.cpp) # src/Application.cpp src/Application.h src/DebugUtils.h

#target_include_directories(SampleApplication PUBLIC ${Vulkan_INCLUDE_DIRS} ../${SDL2_INCLUDE_DIRS})

# target_include_directories(SampleApplication)

#target_link_libraries(SampleApplication Vulkan::Vulkan glm glfw SDL2::Main)

target_link_libraries(SampleApplication ${SDL2_LIBRARIES})
