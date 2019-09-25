cmake_minimum_required (VERSION 3.10)
project (d2id)
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
add_executable(d2id src/main.cpp)
target_link_libraries(d2id ${CURL_LIBRARIES})

