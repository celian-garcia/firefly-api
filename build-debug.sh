rm -rf build
mkdir -p build/debug
cd build/debug && cmake \
    -G "MSYS Makefiles" \
    -DCMAKE_CXX_COMPILER="C:/MinGW/bin/g++.exe" \
    -DCMAKE_C_COMPILER="C:/MinGW/bin/gcc.exe" \
    -DFly_DIR="C:/WORK_celian/sublimetext_workspace/fly" \
    ../..
