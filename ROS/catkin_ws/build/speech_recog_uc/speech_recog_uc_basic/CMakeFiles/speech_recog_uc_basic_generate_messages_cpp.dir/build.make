# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alf/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alf/catkin_ws/build

# Utility rule file for speech_recog_uc_basic_generate_messages_cpp.

# Include the progress variables for this target.
include speech_recog_uc/speech_recog_uc_basic/CMakeFiles/speech_recog_uc_basic_generate_messages_cpp.dir/progress.make

speech_recog_uc/speech_recog_uc_basic/CMakeFiles/speech_recog_uc_basic_generate_messages_cpp: /home/alf/catkin_ws/devel/include/speech_recog_uc_basic/SpeechResult.h


/home/alf/catkin_ws/devel/include/speech_recog_uc_basic/SpeechResult.h: /opt/ros/kinetic/lib/gencpp/gen_cpp.py
/home/alf/catkin_ws/devel/include/speech_recog_uc_basic/SpeechResult.h: /home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc_basic/msg/SpeechResult.msg
/home/alf/catkin_ws/devel/include/speech_recog_uc_basic/SpeechResult.h: /opt/ros/kinetic/share/gencpp/msg.h.template
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/alf/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating C++ code from speech_recog_uc_basic/SpeechResult.msg"
	cd /home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc_basic && /home/alf/catkin_ws/build/catkin_generated/env_cached.sh /usr/bin/python2 /opt/ros/kinetic/share/gencpp/cmake/../../../lib/gencpp/gen_cpp.py /home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc_basic/msg/SpeechResult.msg -Ispeech_recog_uc_basic:/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc_basic/msg -Iactionlib_msgs:/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg -Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg -p speech_recog_uc_basic -o /home/alf/catkin_ws/devel/include/speech_recog_uc_basic -e /opt/ros/kinetic/share/gencpp/cmake/..

speech_recog_uc_basic_generate_messages_cpp: speech_recog_uc/speech_recog_uc_basic/CMakeFiles/speech_recog_uc_basic_generate_messages_cpp
speech_recog_uc_basic_generate_messages_cpp: /home/alf/catkin_ws/devel/include/speech_recog_uc_basic/SpeechResult.h
speech_recog_uc_basic_generate_messages_cpp: speech_recog_uc/speech_recog_uc_basic/CMakeFiles/speech_recog_uc_basic_generate_messages_cpp.dir/build.make

.PHONY : speech_recog_uc_basic_generate_messages_cpp

# Rule to build all files generated by this target.
speech_recog_uc/speech_recog_uc_basic/CMakeFiles/speech_recog_uc_basic_generate_messages_cpp.dir/build: speech_recog_uc_basic_generate_messages_cpp

.PHONY : speech_recog_uc/speech_recog_uc_basic/CMakeFiles/speech_recog_uc_basic_generate_messages_cpp.dir/build

speech_recog_uc/speech_recog_uc_basic/CMakeFiles/speech_recog_uc_basic_generate_messages_cpp.dir/clean:
	cd /home/alf/catkin_ws/build/speech_recog_uc/speech_recog_uc_basic && $(CMAKE_COMMAND) -P CMakeFiles/speech_recog_uc_basic_generate_messages_cpp.dir/cmake_clean.cmake
.PHONY : speech_recog_uc/speech_recog_uc_basic/CMakeFiles/speech_recog_uc_basic_generate_messages_cpp.dir/clean

speech_recog_uc/speech_recog_uc_basic/CMakeFiles/speech_recog_uc_basic_generate_messages_cpp.dir/depend:
	cd /home/alf/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alf/catkin_ws/src /home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc_basic /home/alf/catkin_ws/build /home/alf/catkin_ws/build/speech_recog_uc/speech_recog_uc_basic /home/alf/catkin_ws/build/speech_recog_uc/speech_recog_uc_basic/CMakeFiles/speech_recog_uc_basic_generate_messages_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : speech_recog_uc/speech_recog_uc_basic/CMakeFiles/speech_recog_uc_basic_generate_messages_cpp.dir/depend
