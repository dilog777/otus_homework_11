project(join_server_lib VERSION ${PROJECT_VERSION})

file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_library(${PROJECT_NAME} STATIC ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

# PUBLIC to usage StringConverter.hpp
target_include_directories(${PROJECT_NAME} PUBLIC
	${Boost_INCLUDE_DIR}
)
