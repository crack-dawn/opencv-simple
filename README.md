opencv4.10.0 templete c++
+ 直接使用在线打包好的opencv4.10.0动态库
+ 使用vscode + cmake tools的方式简单开发
+ 项目已打包好 opencv4.10.0动态库包, 未链接opencv-contrib库

----

opencv 4.10.0 windows mingw64 简单模板
不含opencv contrib库包
-----------------
```
编译配置参数如下:
cmake
-DWITH_OPENMP=ON
-DWITH_OPENCL=ON
-DWITH_OPENGL=ON
-DWITH_TBB=ON
-DWITH_VULKAN=ON
-DWITH_QT=OFF
-DBUILD_WITH_DEBUG_INFO=OFF
-DBUILD_TESTS=OFF
-DBUILD_PERF_TESTS=OFF
-DBUILD_EXAMPLES=OFF
-DBUILD_PROTOBUF=OFF
-DPROTOBUF_UPDATE_FILES=ON
-DINSTALL_C_EXAMPLES=OFF
-DINSTALL_PYTHON_EXAMPLES=ON
-DCPU_BASELINE_DISABLE=SSE3
-DCPU_BASELINE_REQUIRE=SSE2
-DOPENCV_SKIP_PYTHON_LOADER=ON
-DOPENCV_ENABLE_NONFREE=ON
-DBUILD_opencv_world=ON
-G "MinGW Makefiles"
-DCMAKE_CXX_COMPILER=g++ ..\source

cmake --build . --config Release
```
