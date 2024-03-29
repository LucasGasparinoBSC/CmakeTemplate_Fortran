project(libfortran)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_LIST_DIR}/*.F90)
set(SOURCES_DIR ${CMAKE_CURRENT_LIST_DIR}/sources)

add_library(${PROJECT_NAME} ${LIBRARY_TYPE} ${SRC_FILES})

add_definitions(-D__BUILD_VERSION__="${TEST_VERSION}")

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${TEST_VERSION} SOVERSION ${TEST_VERSION_MAJOR})
set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

set(${PROJECT_NAME}_INCLUDE_DIRS ${SOURCES_DIR} CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_BINARY_DIR})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${SRC_FILES} DESTINATION include)
