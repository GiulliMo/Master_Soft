# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "speech_recog_uc: 2 messages, 0 services")

set(MSG_I_FLAGS "-Ispeech_recog_uc:/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg;-Iactionlib_msgs:/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(speech_recog_uc_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/DOAResult.msg" NAME_WE)
add_custom_target(_speech_recog_uc_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "speech_recog_uc" "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/DOAResult.msg" ""
)

get_filename_component(_filename "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/SpeechResult.msg" NAME_WE)
add_custom_target(_speech_recog_uc_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "speech_recog_uc" "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/SpeechResult.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(speech_recog_uc
  "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/DOAResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/speech_recog_uc
)
_generate_msg_cpp(speech_recog_uc
  "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/SpeechResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/speech_recog_uc
)

### Generating Services

### Generating Module File
_generate_module_cpp(speech_recog_uc
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/speech_recog_uc
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(speech_recog_uc_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(speech_recog_uc_generate_messages speech_recog_uc_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/DOAResult.msg" NAME_WE)
add_dependencies(speech_recog_uc_generate_messages_cpp _speech_recog_uc_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/SpeechResult.msg" NAME_WE)
add_dependencies(speech_recog_uc_generate_messages_cpp _speech_recog_uc_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(speech_recog_uc_gencpp)
add_dependencies(speech_recog_uc_gencpp speech_recog_uc_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS speech_recog_uc_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(speech_recog_uc
  "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/DOAResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/speech_recog_uc
)
_generate_msg_eus(speech_recog_uc
  "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/SpeechResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/speech_recog_uc
)

### Generating Services

### Generating Module File
_generate_module_eus(speech_recog_uc
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/speech_recog_uc
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(speech_recog_uc_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(speech_recog_uc_generate_messages speech_recog_uc_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/DOAResult.msg" NAME_WE)
add_dependencies(speech_recog_uc_generate_messages_eus _speech_recog_uc_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/SpeechResult.msg" NAME_WE)
add_dependencies(speech_recog_uc_generate_messages_eus _speech_recog_uc_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(speech_recog_uc_geneus)
add_dependencies(speech_recog_uc_geneus speech_recog_uc_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS speech_recog_uc_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(speech_recog_uc
  "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/DOAResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/speech_recog_uc
)
_generate_msg_lisp(speech_recog_uc
  "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/SpeechResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/speech_recog_uc
)

### Generating Services

### Generating Module File
_generate_module_lisp(speech_recog_uc
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/speech_recog_uc
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(speech_recog_uc_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(speech_recog_uc_generate_messages speech_recog_uc_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/DOAResult.msg" NAME_WE)
add_dependencies(speech_recog_uc_generate_messages_lisp _speech_recog_uc_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/SpeechResult.msg" NAME_WE)
add_dependencies(speech_recog_uc_generate_messages_lisp _speech_recog_uc_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(speech_recog_uc_genlisp)
add_dependencies(speech_recog_uc_genlisp speech_recog_uc_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS speech_recog_uc_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(speech_recog_uc
  "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/DOAResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/speech_recog_uc
)
_generate_msg_nodejs(speech_recog_uc
  "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/SpeechResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/speech_recog_uc
)

### Generating Services

### Generating Module File
_generate_module_nodejs(speech_recog_uc
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/speech_recog_uc
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(speech_recog_uc_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(speech_recog_uc_generate_messages speech_recog_uc_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/DOAResult.msg" NAME_WE)
add_dependencies(speech_recog_uc_generate_messages_nodejs _speech_recog_uc_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/SpeechResult.msg" NAME_WE)
add_dependencies(speech_recog_uc_generate_messages_nodejs _speech_recog_uc_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(speech_recog_uc_gennodejs)
add_dependencies(speech_recog_uc_gennodejs speech_recog_uc_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS speech_recog_uc_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(speech_recog_uc
  "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/DOAResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/speech_recog_uc
)
_generate_msg_py(speech_recog_uc
  "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/SpeechResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/speech_recog_uc
)

### Generating Services

### Generating Module File
_generate_module_py(speech_recog_uc
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/speech_recog_uc
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(speech_recog_uc_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(speech_recog_uc_generate_messages speech_recog_uc_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/DOAResult.msg" NAME_WE)
add_dependencies(speech_recog_uc_generate_messages_py _speech_recog_uc_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc/msg/SpeechResult.msg" NAME_WE)
add_dependencies(speech_recog_uc_generate_messages_py _speech_recog_uc_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(speech_recog_uc_genpy)
add_dependencies(speech_recog_uc_genpy speech_recog_uc_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS speech_recog_uc_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/speech_recog_uc)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/speech_recog_uc
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_cpp)
  add_dependencies(speech_recog_uc_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(speech_recog_uc_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/speech_recog_uc)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/speech_recog_uc
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_eus)
  add_dependencies(speech_recog_uc_generate_messages_eus actionlib_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(speech_recog_uc_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/speech_recog_uc)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/speech_recog_uc
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_lisp)
  add_dependencies(speech_recog_uc_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(speech_recog_uc_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/speech_recog_uc)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/speech_recog_uc
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_nodejs)
  add_dependencies(speech_recog_uc_generate_messages_nodejs actionlib_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(speech_recog_uc_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/speech_recog_uc)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/speech_recog_uc\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/speech_recog_uc
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_py)
  add_dependencies(speech_recog_uc_generate_messages_py actionlib_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(speech_recog_uc_generate_messages_py std_msgs_generate_messages_py)
endif()
