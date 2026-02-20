cmake_minimum_required(VERSION 3.21)
project(PTree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Window System)

add_executable(${PROJECT_NAME} 
    main.cpp Pythagorean.cpp Pythagorean.hpp)

if(EXISTS ${CMAKE_SOURCE_DIR}/assets)
    file(COPY ${CMAKE_SOURCE_DIR}/assets
         DESTINATION ${CMAKE_BINARY_DIR})
endif()

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        SFML::Graphics
        SFML::Audio
        SFML::Window
        SFML::System
)