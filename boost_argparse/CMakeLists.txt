cmake_minimum_required(VERSION 3.28)
project(BoostApp)

# Use C++17 or newer
set(CMAKE_CXX_STANDARD 20) # C++ standard comes after 3 years, 17, 20, 23 are the valid standards
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost with program options
find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(boost_app main.cpp)

# Link boost libraries
target_link_libraries(boost_app PRIVATE Boost::program_options)