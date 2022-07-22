project(appfortran)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_LIST_DIR}/*.F90)

include_directories(${libfortran_INCLUDE_DIRS})

add_definitions(-D__BUILD_VERSION__="${TEST_VERSION}")

add_executable(${PROJECT_NAME} ${SRC_FILES})

set_mpi()

target_link_libraries(${PROJECT_NAME} libfortran)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "app_F90" VERSION ${TEST_VERSION} SOVERSION ${TEST_VERSION_MAJOR})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)