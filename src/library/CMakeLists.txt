project(join_server_lib VERSION ${PROJECT_VERSION})

file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

file(GLOB_RECURSE SQLITE_SRC "${sqlite3_SOURCE_DIR}/sqlite3.c")

add_library(${PROJECT_NAME} STATIC ${SRC} ${SQLITE_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE
	"${sqlite3_SOURCE_DIR}"
)

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${Boost_INCLUDE_DIR}
)
