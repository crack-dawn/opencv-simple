mingw-opencv4.10.0 templete c++ with CMakeLists
+ 直接使用在线打包好的opencv4.10.0动态库
+ 使用vscode + cmake tools的方式简单开发
+ [项目已打包好 opencv4.10.0动态库包, 已链接opencv-contrib库](https://github.com/crack-dawn/Windows_MinGW_64_OpenCV/releases)
+ [opencv4.10.0动态库包在线编译,参考](https://github.com/FastTrackOrg/Windows_MinGW_64_OpenCV)
----

opencv 4.10.0 windows mingw64 简单模板
链接了opencv-contrib库包

-----------------
+ 编译所用g++:`Qt/Tools/mingw1310_64/bin/g++`, 详见[仓库:opencv+opencv-contrib动态库编译的.github/workflows](https://github.com/crack-dawn/Windows_MinGW_64_OpenCV/blob/master/.github/workflows/continuous_autoTask.yml)
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
-DOPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules
-DCMAKE_CXX_COMPILER=g++ ..\source

cmake --build . --config Release
cmake --install . 
```



