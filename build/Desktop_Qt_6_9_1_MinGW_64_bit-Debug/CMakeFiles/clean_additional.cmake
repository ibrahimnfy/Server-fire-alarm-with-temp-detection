# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\protobuf_messages_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\protobuf_messages_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\protobuf_messages_qtprotoreg_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\protobuf_messages_qtprotoreg_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\protoc-deneme_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\protoc-deneme_autogen.dir\\ParseCache.txt"
  "protobuf_messages_autogen"
  "protobuf_messages_qtprotoreg_autogen"
  "protoc-deneme_autogen"
  )
endif()
