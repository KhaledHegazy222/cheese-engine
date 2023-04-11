project(CHEESE_ENGINE)
cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

file(GLOB_RECURSE SRCs src/*.cpp)
add_executable(${PROJECT_NAME} ${SRCs})
target_include_directories(${PROJECT_NAME} PUBLIC include)

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::Main)

find_package(SDL2_image REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image)

find_package(SDL2_ttf REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::TTF)

if(SDL2_FOUND)
    message("Found SDL2")
else()
    message("SDL2 is missing")
endif()

if(SDL2_IMAGE_FOUND)
    message("Found SDL2_IMAGE")
else()
    message("SDL2_IMAGE is missing")
endif()
