# CMakeList.txt : CMake project for Doggo_Game, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Doggo_Game")

# Add source to this project's executable.
add_executable (Doggo_Game "../Source Files/DoggoGame.cpp"  "../Source Files/Controls.cpp"  "../Source Files/Engine.cpp" "../Header Files/Controls.h" "../Header Files/Engine.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Doggo_Game PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
