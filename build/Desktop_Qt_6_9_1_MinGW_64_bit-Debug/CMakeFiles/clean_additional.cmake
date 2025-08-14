# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
<<<<<<< HEAD
=======
  "CMakeFiles\\Client_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Client_autogen.dir\\ParseCache.txt"
>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a
  "CMakeFiles\\protobuf_messages_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\protobuf_messages_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\protobuf_messages_qtprotoreg_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\protobuf_messages_qtprotoreg_autogen.dir\\ParseCache.txt"
<<<<<<< HEAD
  "CMakeFiles\\protoc-deneme_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\protoc-deneme_autogen.dir\\ParseCache.txt"
  "protobuf_messages_autogen"
  "protobuf_messages_qtprotoreg_autogen"
  "protoc-deneme_autogen"
=======
  "Client_autogen"
  "protobuf_messages_autogen"
  "protobuf_messages_qtprotoreg_autogen"
>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a
  )
endif()
