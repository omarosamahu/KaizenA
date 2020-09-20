cmake_minimum_required(VERSION 3.10.2)
project(KaizenA C CXX)
set(CMAKE_CXX_STANDARD 17)

# find_package(SDL2 REQUIRED)
# find_package(SDL2_image REQUIRED sdl2_image)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)


add_executable(game 
                src/main.cpp
                src/Game.cpp 
                src/TextureManager.cpp
)
target_include_directories(game 
                           PUBLIC 
                           ${SDL2_INCLUDE_DIR}
                           ${SDL2IMAGE_INCLUDE_DIR}
                           ${CMAKE_CURRENT_SOURCE_DIR}/include) 
target_link_libraries(game ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARY} )  

