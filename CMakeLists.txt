cmake_minimum_required(VERSION 3.5)
project(GUI_LIB)

# set standard:
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Vulkan
find_package(Vulkan REQUIRED)
include_directories(${Vulkan_INCLUDE_DIRS})

# SDL3 
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
include_directories(${SDL3_INCLUDE_DIRS})

# add source files:
set(SOURCES
	src/main.c
	src/gui.c
)

# add headers
set(HEADERS
	src/gui.h

	lib/stb_image.h
)

# add executable:
add_executable(GUI_LIB ${SOURCES} ${HEADERS})

# add libs
target_link_libraries(GUI_LIB PRIVATE Vulkan::Vulkan SDL3::SDL3)

# Specify the output directory for the binary
set_target_properties(GUI_LIB PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


