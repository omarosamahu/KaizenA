cmake_minimum_required(VERSION 3.10.2)
project(KaizenA C CXX)
set(CMAKE_CXX_STANDARD 14)



INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
# 
# 
add_executable(game 
                src/main.cpp
                src/Game.cpp 
                src/GameObject.cpp
                src/TextureManager.cpp
               )
target_include_directories(game 
                           PUBLIC 
                           ${SDL2_INCLUDE_DIRS}
                           ${SDL2IMAGE_INCLUDE_DIRS}
                           ${CMAKE_CURRENT_SOURCE_DIR}/include) 
target_link_libraries(game  ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})  

