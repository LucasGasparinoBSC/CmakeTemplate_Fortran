function(init_metis)
  if (USE_METIS)
    set(ASSERT OFF CACHE INTERNAL "")
    set(ASSERT2 OFF CACHE INTERNAL "")
    set(DEBUG OFF CACHE INTERNAL "")
    set(GDB OFF CACHE INTERNAL "")
    set(GKRAND OFF CACHE INTERNAL "")
    set(GKREGEX OFF CACHE INTERNAL "")
    set(GPROF OFF CACHE INTERNAL "")
    set(METIS_REAL "64" CACHE INTERNAL "")
    set(OPENMP OFF CACHE INTERNAL "")
    set(METIS_INTEGER "64" CACHE INTERNAL "")
  endif()
endfunction()

function(set_metis)
  if (USE_METIS)
    add_definitions(-DIDXTYPEWIDTH=${METIS_INTEGER})
    add_definitions(-DREALTYPEWIDTH=${METIS_REAL})
    include_directories(${METIS_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} metis)
  else()
    message("  -- Not using METIS...")
    add_definitions(-DNO_METIS)
  endif()
endfunction()