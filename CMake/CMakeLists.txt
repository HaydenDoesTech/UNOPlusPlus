cmake_minimum_required(VERSION 3.20)
project(UNOPlusPlus VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Fetch SFML from git and build for any system
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(SFML)

# Create the executable
# List source files here (cpp, c)
add_executable(UNOPlusPlus
        main.cpp
        Menu.cpp
        Player.cpp
)

target_link_libraries(UNOPlusPlus
        SFML::System # Required
        SFML::Window # Required
        SFML::Graphics # Required
        # Drop these two if you use external libraries for Audio or Networking.
        # Only include them if they are part of your project.
        SFML::Audio # Used for audio transactions (playing sound, bg noise, etc.)
        SFML::Network # Used for basic networking
)

# Set assets path for use in project
set(ASSETS_PATH "${CMAKE_SOURCE_DIR}/assets")
target_compile_definitions(UNOPlusPlus PRIVATE ASSETS_PATH="${ASSETS_PATH}")