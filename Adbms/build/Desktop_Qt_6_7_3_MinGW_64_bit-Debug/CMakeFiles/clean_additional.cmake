# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Adbms_autogen"
  "CMakeFiles\\Adbms_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Adbms_autogen.dir\\ParseCache.txt"
  )
endif()
