# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Streetplanner_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Streetplanner_autogen.dir/ParseCache.txt"
  "Streetplanner_autogen"
  )
endif()
