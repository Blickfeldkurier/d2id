cmake_minimum_required (VERSION 3.10)
project (d2id)
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(d2id_SRC 
	"src/main.cpp"
	"src/log.cpp"
	"src/config.cpp"
	"src/curlwrapper.cpp"
	"src/w1wrapper.cpp"
	)
add_executable(d2id ${d2id_SRC})
target_link_libraries(d2id ${CURL_LIBRARIES})

