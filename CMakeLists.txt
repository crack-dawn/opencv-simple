## 环境信息
# windows11 64bit
# g++/gcc.exe --version (Rev6, Built by MSYS2 project) 13.2.0; Copyright (C) 2023 Free Software Foundation,
### gcc/g++ 请使用msys版本,或是mingw64 stable版本, 某些release版本存在链接失效等问题
# cmake --version 3.30.2; CMake suite maintained and supported by Kitware (kitware.com/cmake).
# OpenCV_4.10.0_Full.zip (github编译包 ):https://github.com/FastTrackOrg/Windows_MinGW_64_OpenCV/releases

# OpenCV_4.10.0_Full.zip 使用 find_package(OpenCV REQUIRED)
cmake_minimum_required(VERSION 3.5)

project(demo_opencv)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/exe-out ) # 设置可執行文件輸出路徑

set(OpenCV_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/OpenCV_4.10.0_MinGW_Install") # OpenCV库包顶层路径

#### 纯手动配置

# set(OpenCV_Hpp_Include_Dirs  # OpenCV hpp头文件路径
#     "${OpenCV_DIR}\\include" 
# )
# include_directories(${OpenCV_Hpp_Include_Dirs})

# set(OpenCV_DLL_Libs  # OpenCV 动态库文件名
#   libopencv_world4100.dll 
#   opencv_videoio_ffmpeg4100_64.dll) 
# link_directories(${OpenCV_DIR}/x64/mingw/bin)  # 库路径
# link_libraries(${OpenCV_DLL_Libs}) # 链接动态库

#### .cmake自动查询      include link 没有target前缀,是默认之后的目标都添加/链接
message("OpenCV_DIR: ${OpenCV_DIR}")
find_package(OpenCV REQUIRED HINTS "${OpenCV_DIR}") 
message(头文件 ${OpenCV_INCLUDE_DIRS} ---完)
include_directories(${OpenCV_INCLUDE_DIRS})
message(库文件 ${OpenCV_LIBS} ---完)
link_libraries(${OpenCV_LIBS})   

add_executable(demo_opencv ./src/main.cpp ) # 指定生成 "可执行文件"
 

# 确保运行时能找到 DLL 文件, 因而添加额外操作;  "将依赖的 DLL 文件复制到目标目录"
# 这里用  cmake.exe -E copy_if_different [original] [destination] ,来复制粘贴文件
# 也可以将 ${OpenCV_DIR}/x64/mingw/bin/ 这个路径加入 环境变量path中
add_custom_command(TARGET demo_opencv POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${OpenCV_DIR}/x64/mingw/bin/libopencv_world4100.dll"
    "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${OpenCV_DIR}/x64/mingw/bin/opencv_videoio_ffmpeg4100_64.dll"
    "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)
 


#---------------------------------------------------

##
# Usage: D:\software\Cmake\bin\cmake.exe -E <command> [arguments...]
# Available commands: 
#   capabilities              - Report capabilities built into cmake in JSON format
#   cat [--] <files>...       - concat the files and print them to the standard output
#   chdir dir cmd [args...]   - run command in a given directory
#   compare_files [--ignore-eol] file1 file2
#                               - check if file1 is same as file2
#   copy <file>... destination  - copy files to destination (either file or directory)
#   copy_directory <dir>... destination   - copy content of <dir>... directories to 'destination' directory
#   copy_directory_if_different <dir>... destination   - copy changed content of <dir>... directories to 'destination' directory
#   copy_if_different <file>... destination  - copy files if it has changed



##### add_custom_command
# 第一种通用形式：
# add_custom_command: 增加客制化的构建规则到生成的构建系统中。对于add_custom_command，有两种使用形式。第一种形式是增加一个客制命令用来产生一个输出。
#  add_custom_command(OUTPUT output1 [output2 ...]
#                      COMMAND command1[ARGS] [args1...]
#                      [COMMAND command2 [ARGS] [args2...] ...]
#                      [MAIN_DEPENDENCYdepend]
#                      [DEPENDS[depends...]]
#                      [IMPLICIT_DEPENDS<lang1> depend1 ...]
#                      [WORKING_DIRECTORYdir]
#                      [COMMENT comment] [VERBATIM] [APPEND])
# 不要同时在多个相互独立的目标中执行上述命令产生相同的文件，主要是为了防止冲突产生。如果有多条命令，它们将会按顺序执行。ARGS是为了向后兼容，使用过程中可以忽略。MAIN_DEPENDENCY完全是可选的，它主要是针对Visual Studio给出的一个建议。在Makefile中，它会产生一个这样的新目标：
#  OUTPUT: MAIN_DEPENDENCY DEPENDS
#           COMMAND


# 第二种形式是为某个目标如库或可执行程序添加一个客制命令。这对于要在构建一个目标之前或之后执行一些操作非常有用。该命令本身会成为目标的一部分，仅在目标本身被构建时才会执行。如果该目标已经构建，命令将不会执行。
# 第二种：标记为在什么时候执行命令：编译前，编译后，链接前
#  add_custom_command(TARGET target
#                      PRE_BUILD | PRE_LINK| POST_BUILD
#                      COMMAND command1[ARGS] [args1...]
#                      [COMMAND command2[ARGS] [args2...] ...]
#                      [WORKING_DIRECTORYdir]
#                      [COMMENT comment][VERBATIM])
# 命令执行的时机由如下参数决定： 
#   PRE_BUILD - 命令将会在其他依赖项执行前执行
#   PRE_LINK - 命令将会在其他依赖项执行完后执行
#   POST_BUILD - 命令将会在目标构建完后执行。
# ————————————————
# 版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。        
# 原文链接：https://blog.csdn.net/gubenpeiyuan/article/details/51096777