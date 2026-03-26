cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME hero)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
        app/robot_config.h
        phoenix_embedded_base_code/Bsp/Log/SEGGER_RTT.c
        phoenix_embedded_base_code/Bsp/Log/SEGGER_RTT.h
        phoenix_embedded_base_code/Bsp/Log/SEGGER_RTT_Conf.h
        phoenix_embedded_base_code/Bsp/Log/SEGGER_RTT_printf.c
        phoenix_embedded_base_code/Bsp/Log/bsp_log.c
        phoenix_embedded_base_code/Bsp/Log/bsp_log.h
        phoenix_embedded_base_code/Bsp/Fdcan/bsp_fdcan.c
        phoenix_embedded_base_code/Bsp/Fdcan/bsp_fdcan.h
        phoenix_embedded_base_code/Module/Motor/Dji/dev_motor_dji.c
        phoenix_embedded_base_code/Module/Motor/Dji/dev_motor_dji.h
        phoenix_embedded_base_code/Module/Motor/Dm/dev_motor_dm.c
        phoenix_embedded_base_code/Module/Motor/Dm/dev_motor_dm.h
        phoenix_embedded_base_code/Algorithm/Pid/alg_pid.c
        phoenix_embedded_base_code/Algorithm/Pid/alg_pid.h
        app/task/shoot_task.c
        app/task/shoot_task.h
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
        app
        phoenix_embedded_base_code/Bsp/Log
        phoenix_embedded_base_code/Bsp/Fdcan
        phoenix_embedded_base_code/Module/Motor/Dji
        phoenix_embedded_base_code/Module/Motor/Dm
        phoenix_embedded_base_code/Algorithm/Pid
        app/task
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
