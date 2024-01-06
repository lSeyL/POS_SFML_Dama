cmake_minimum_required(VERSION 3.24)
project(POS_SFML_Dama)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML main.cpp
        Classes/Board.cpp
        Classes/Board.h
        Classes/Square.cpp
        Classes/Square.h
        Classes/Player.cpp
        Classes/Player.h
        Classes/Game.cpp
        Classes/Game.h
        Classes/Pawn.cpp
        Classes/Pawn.h
        Classes/DraggedPawn.cpp
        Classes/DraggedPawn.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(SFML sfml-system sfml-window sfml-graphics sfml-audio sfml-network)