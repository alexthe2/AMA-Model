cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(ama_model VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(ama_model
    main.cpp

    config/SystemConfig.cpp

    memory/LocalMemory.cpp
    memory/RemoteMemory.cpp

    prefetcher/AccuracyPrefetcher.cpp

    system/System.cpp
)

# If there are other directories that the compiler should look in for include files
# you can use the following line:
# target_include_directories(ama_model PUBLIC ${PROJECT_SOURCE_DIR}/path_to_directory)

