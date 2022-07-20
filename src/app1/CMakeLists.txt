project(app1)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
set(HEADER_DIR ${CMAKE_CURRENT_LIST_DIR}/headers)
file(GLOB HEADER_FILES ${HEADER_DIR}/*.h)

include_directories(${HEADER_DIR} ${lib1_INCLUDE_DIRS})

add_definitions(-D__BUILD_VERSION__="${TEST_VERSION}")

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})

set_mpi()

target_link_libraries(${PROJECT_NAME} lib1)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "app" VERSION ${TEST_VERSION} SOVERSION ${TEST_VERSION_MAJOR})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)