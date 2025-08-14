Package: abseil:x64-windows@20250127.1#2

**Host Environment**

- Host: x64-windows
- Compiler: MSVC 19.41.34120.0
-    vcpkg-tool version: 2025-07-21-d4b65a2b83ae6c3526acd1c6f3b51aff2a884533
    vcpkg-scripts version: e140b1fde2 2025-07-28 (5 hours ago)

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Using cached abseil-abseil-cpp-20250127.1.tar.gz
-- Cleaning sources at C:/vcpkg/buildtrees/abseil/src/20250127.1-a0a219bf72.clean. Use --editable to skip cleaning for the packages you specify.
-- Extracting source C:/vcpkg/downloads/abseil-abseil-cpp-20250127.1.tar.gz
-- Using source at C:/vcpkg/buildtrees/abseil/src/20250127.1-a0a219bf72.clean
-- Configuring x64-windows-dbg
CMake Error at scripts/cmake/vcpkg_execute_required_process.cmake:127 (message):
    Command failed: C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/bin/cmake.exe C:/vcpkg/buildtrees/abseil/src/20250127.1-a0a219bf72.clean -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=C:/vcpkg/packages/abseil_x64-windows/debug -DFETCHCONTENT_FULLY_DISCONNECTED=ON -DABSL_PROPAGATE_CXX_STD=ON -DCMAKE_MAKE_PROGRAM=C:/vcpkg/downloads/tools/ninja/1.12.1-windows/ninja.exe -DBUILD_SHARED_LIBS=ON -DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=C:/vcpkg/scripts/toolchains/windows.cmake -DVCPKG_TARGET_TRIPLET=x64-windows -DVCPKG_SET_CHARSET_FLAG=ON -DVCPKG_PLATFORM_TOOLSET=v143 -DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON -DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON -DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON -DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE -DCMAKE_VERBOSE_MAKEFILE=ON -DVCPKG_APPLOCAL_DEPS=OFF -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON -DVCPKG_CXX_FLAGS= -DVCPKG_CXX_FLAGS_RELEASE= -DVCPKG_CXX_FLAGS_DEBUG= -DVCPKG_C_FLAGS= -DVCPKG_C_FLAGS_RELEASE= -DVCPKG_C_FLAGS_DEBUG= -DVCPKG_CRT_LINKAGE=dynamic -DVCPKG_LINKER_FLAGS= -DVCPKG_LINKER_FLAGS_RELEASE= -DVCPKG_LINKER_FLAGS_DEBUG= -DVCPKG_TARGET_ARCHITECTURE=x64 -DCMAKE_INSTALL_LIBDIR:STRING=lib -DCMAKE_INSTALL_BINDIR:STRING=bin -D_VCPKG_ROOT_DIR=C:/vcpkg "-D_VCPKG_INSTALLED_DIR=C:/Users/İbrahim F. Yoğurtçu/Documents/protoc-deneme/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/vcpkg_installed" -DVCPKG_MANIFEST_INSTALL=OFF
    Working Directory: C:/vcpkg/buildtrees/abseil/x64-windows-dbg
    Error code: 1
    See logs for more information:
      C:\vcpkg\buildtrees\abseil\config-x64-windows-dbg-CMakeCache.txt.log
      C:\vcpkg\buildtrees\abseil\config-x64-windows-dbg-CMakeConfigureLog.yaml.log
      C:\vcpkg\buildtrees\abseil\config-x64-windows-dbg-out.log
      C:\vcpkg\buildtrees\abseil\config-x64-windows-dbg-err.log

Call Stack (most recent call first):
  C:/Users/İbrahim F. Yoğurtçu/Documents/protoc-deneme/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/vcpkg_installed/x64-windows/share/vcpkg-cmake/vcpkg_cmake_configure.cmake:287 (vcpkg_execute_required_process)
  ports/abseil/portfile.cmake:32 (vcpkg_cmake_configure)
  scripts/ports.cmake:206 (include)



```

<details><summary>C:\vcpkg\buildtrees\abseil\config-x64-windows-dbg-out.log</summary>

```
-- The CXX compiler identification is MSVC 19.41.34120.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - failed
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.41.34120/bin/Hostx64/x64/cl.exe
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.41.34120/bin/Hostx64/x64/cl.exe - broken
-- Configuring incomplete, errors occurred!
```
</details>

<details><summary>C:\vcpkg\buildtrees\abseil\config-x64-windows-dbg-err.log</summary>

```
CMake Error at C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeTestCXXCompiler.cmake:73 (message):
  The C++ compiler

    "C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.41.34120/bin/Hostx64/x64/cl.exe"

  is not able to compile a simple test program.

  It fails with the following output:

    Change Dir: 'C:/vcpkg/buildtrees/abseil/x64-windows-dbg/CMakeFiles/CMakeScratch/TryCompile-57ys28'
    
    Run Build Command(s): C:/vcpkg/downloads/tools/ninja/1.12.1-windows/ninja.exe -v cmTC_14f1f
    [1/2] C:\PROGRA~2\MICROS~2\2022\BUILDT~1\VC\Tools\MSVC\1441~1.341\bin\Hostx64\x64\cl.exe  /nologo /TP   /nologo /DWIN32 /D_WINDOWS /utf-8 /GR /EHsc /MP   /MDd /Z7 /Ob0 /Od /RTC1  -MDd /showIncludes /FoCMakeFiles\cmTC_14f1f.dir\testCXXCompiler.cxx.obj /FdCMakeFiles\cmTC_14f1f.dir\ /FS -c C:\vcpkg\buildtrees\abseil\x64-windows-dbg\CMakeFiles\CMakeScratch\TryCompile-57ys28\testCXXCompiler.cxx
    [2/2] C:\Windows\system32\cmd.exe /C "cd . && C:\vcpkg\downloads\tools\cmake-3.30.1-windows\cmake-3.30.1-windows-i386\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\cmTC_14f1f.dir --rc=rc --mt=CMAKE_MT-NOTFOUND --manifests  -- C:\PROGRA~2\MICROS~2\2022\BUILDT~1\VC\Tools\MSVC\1441~1.341\bin\Hostx64\x64\link.exe /nologo CMakeFiles\cmTC_14f1f.dir\testCXXCompiler.cxx.obj  /out:cmTC_14f1f.exe /implib:cmTC_14f1f.lib /pdb:cmTC_14f1f.pdb /version:0.0 /machine:x64  /nologo    /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib && cd ."
    FAILED: cmTC_14f1f.exe 
    C:\Windows\system32\cmd.exe /C "cd . && C:\vcpkg\downloads\tools\cmake-3.30.1-windows\cmake-3.30.1-windows-i386\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\cmTC_14f1f.dir --rc=rc --mt=CMAKE_MT-NOTFOUND --manifests  -- C:\PROGRA~2\MICROS~2\2022\BUILDT~1\VC\Tools\MSVC\1441~1.341\bin\Hostx64\x64\link.exe /nologo CMakeFiles\cmTC_14f1f.dir\testCXXCompiler.cxx.obj  /out:cmTC_14f1f.exe /implib:cmTC_14f1f.lib /pdb:cmTC_14f1f.pdb /version:0.0 /machine:x64  /nologo    /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib && cd ."
    RC Pass 1: command "rc /fo CMakeFiles\cmTC_14f1f.dir/manifest.res CMakeFiles\cmTC_14f1f.dir/manifest.rc" failed (exit code 0) with the following output:
    no such file or directory
    ninja: build stopped: subcommand failed.
    
    

  

  CMake will not be able to correctly generate this project.
Call Stack (most recent call first):
  CMakeLists.txt:26 (project)
```
</details>

<details><summary>C:\vcpkg\buildtrees\abseil\config-x64-windows-dbg-CMakeConfigureLog.yaml.log</summary>

```

---
events:
  -
    kind: "message-v1"
    backtrace:
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeDetermineSystem.cmake:205 (message)"
      - "CMakeLists.txt:26 (project)"
    message: |
      The system is: Windows - 10.0.19045 - AMD64
  -
    kind: "message-v1"
    backtrace:
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeDetermineCompilerId.cmake:17 (message)"
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeDetermineCompilerId.cmake:64 (__determine_compiler_id_test)"
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeDetermineCXXCompiler.cmake:126 (CMAKE_DETERMINE_COMPILER_ID)"
      - "CMakeLists.txt:26 (project)"
    message: |
      Compiling the CXX compiler identification source file "CMakeCXXCompilerId.cpp" failed.
      Compiler: C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.41.34120/bin/Hostx64/x64/cl.exe 
      Build flags: /nologo;/DWIN32;/D_WINDOWS;/utf-8;/GR;/EHsc;/MP
      Id flags:  
      
      The output was:
      2
      CMakeCXXCompilerId.cpp
      LINK : fatal error LNK1104: 'kernel32.lib' dosyası açılamıyor
      
      
  -
    kind: "message-v1"
    backtrace:
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeDetermineCompilerId.cmake:17 (message)"
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeDetermineCompilerId.cmake:64 (__determine_compiler_id_test)"
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeDetermineCXXCompiler.cmake:126 (CMAKE_DETERMINE_COMPILER_ID)"
      - "CMakeLists.txt:26 (project)"
    message: |
      Compiling the CXX compiler identification source file "CMakeCXXCompilerId.cpp" succeeded.
      Compiler: C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.41.34120/bin/Hostx64/x64/cl.exe 
      Build flags: /nologo;/DWIN32;/D_WINDOWS;/utf-8;/GR;/EHsc;/MP
      Id flags: -c 
      
      The output was:
      0
      CMakeCXXCompilerId.cpp
      
      
      Compilation of the CXX compiler identification source "CMakeCXXCompilerId.cpp" produced "CMakeCXXCompilerId.obj"
      
      The CXX compiler identification is MSVC, found in:
        C:/vcpkg/buildtrees/abseil/x64-windows-dbg/CMakeFiles/3.30.1/CompilerIdCXX/CMakeCXXCompilerId.obj
      
  -
    kind: "message-v1"
    backtrace:
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeDetermineCompilerId.cmake:1243 (message)"
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeDetermineCompilerId.cmake:250 (CMAKE_DETERMINE_MSVC_SHOWINCLUDES_PREFIX)"
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeDetermineCXXCompiler.cmake:126 (CMAKE_DETERMINE_COMPILER_ID)"
      - "CMakeLists.txt:26 (project)"
    message: |
      Detecting CXX compiler /showIncludes prefix:
        main.c
        Not: eklenen dosya:  C:\\vcpkg\\buildtrees\\abseil\\x64-windows-dbg\\CMakeFiles\\ShowIncludes\\foo.h
        
      Found prefix "Not: eklenen dosya:  "
  -
    kind: "try_compile-v1"
    backtrace:
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeDetermineCompilerABI.cmake:74 (try_compile)"
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeTestCXXCompiler.cmake:26 (CMAKE_DETERMINE_COMPILER_ABI)"
      - "CMakeLists.txt:26 (project)"
    checks:
      - "Detecting CXX compiler ABI info"
    directories:
      source: "C:/vcpkg/buildtrees/abseil/x64-windows-dbg/CMakeFiles/CMakeScratch/TryCompile-bef14c"
      binary: "C:/vcpkg/buildtrees/abseil/x64-windows-dbg/CMakeFiles/CMakeScratch/TryCompile-bef14c"
    cmakeVariables:
      CMAKE_CXX_FLAGS: " /nologo /DWIN32 /D_WINDOWS /utf-8 /GR /EHsc /MP "
      CMAKE_CXX_FLAGS_DEBUG: "/MDd /Z7 /Ob0 /Od /RTC1 "
      CMAKE_CXX_SCAN_FOR_MODULES: "OFF"
      CMAKE_EXE_LINKER_FLAGS: "/machine:x64"
      CMAKE_MSVC_DEBUG_INFORMATION_FORMAT: ""
      CMAKE_MSVC_RUNTIME_LIBRARY: "MultiThreaded$<$<CONFIG:Debug>:Debug>$<$<STREQUAL:dynamic,dynamic>:DLL>"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "C:/vcpkg/scripts/toolchains/windows.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "C:/Users/\u0130brahim F. Yo\u011furt\u00e7u/Documents/protoc-deneme/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PLATFORM_TOOLSET: "v143"
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_SET_CHARSET_FLAG: "ON"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-windows"
      Z_VCPKG_ROOT_DIR: "C:/vcpkg"
    buildResult:
      variable: "CMAKE_CXX_ABI_COMPILED"
      cached: true
      stdout: |
        Change Dir: 'C:/vcpkg/buildtrees/abseil/x64-windows-dbg/CMakeFiles/CMakeScratch/TryCompile-bef14c'
        
        Run Build Command(s): C:/vcpkg/downloads/tools/ninja/1.12.1-windows/ninja.exe -v cmTC_041c1
        [1/2] C:\\PROGRA~2\\MICROS~2\\2022\\BUILDT~1\\VC\\Tools\\MSVC\\1441~1.341\\bin\\Hostx64\\x64\\cl.exe  /nologo /TP   /nologo /DWIN32 /D_WINDOWS /utf-8 /GR /EHsc /MP   /MDd /Z7 /Ob0 /Od /RTC1  -MDd /showIncludes /FoCMakeFiles\\cmTC_041c1.dir\\CMakeCXXCompilerABI.cpp.obj /FdCMakeFiles\\cmTC_041c1.dir\\ /FS -c C:\\vcpkg\\downloads\\tools\\cmake-3.30.1-windows\\cmake-3.30.1-windows-i386\\share\\cmake-3.30\\Modules\\CMakeCXXCompilerABI.cpp
        [2/2] C:\\Windows\\system32\\cmd.exe /C "cd . && C:\\vcpkg\\downloads\\tools\\cmake-3.30.1-windows\\cmake-3.30.1-windows-i386\\bin\\cmake.exe -E vs_link_exe --intdir=CMakeFiles\\cmTC_041c1.dir --rc=rc --mt=CMAKE_MT-NOTFOUND --manifests  -- C:\\PROGRA~2\\MICROS~2\\2022\\BUILDT~1\\VC\\Tools\\MSVC\\1441~1.341\\bin\\Hostx64\\x64\\link.exe /nologo CMakeFiles\\cmTC_041c1.dir\\CMakeCXXCompilerABI.cpp.obj  /out:cmTC_041c1.exe /implib:cmTC_041c1.lib /pdb:cmTC_041c1.pdb /version:0.0 /machine:x64  /nologo    /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib && cd ."
        FAILED: cmTC_041c1.exe 
        C:\\Windows\\system32\\cmd.exe /C "cd . && C:\\vcpkg\\downloads\\tools\\cmake-3.30.1-windows\\cmake-3.30.1-windows-i386\\bin\\cmake.exe -E vs_link_exe --intdir=CMakeFiles\\cmTC_041c1.dir --rc=rc --mt=CMAKE_MT-NOTFOUND --manifests  -- C:\\PROGRA~2\\MICROS~2\\2022\\BUILDT~1\\VC\\Tools\\MSVC\\1441~1.341\\bin\\Hostx64\\x64\\link.exe /nologo CMakeFiles\\cmTC_041c1.dir\\CMakeCXXCompilerABI.cpp.obj  /out:cmTC_041c1.exe /implib:cmTC_041c1.lib /pdb:cmTC_041c1.pdb /version:0.0 /machine:x64  /nologo    /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib && cd ."
        RC Pass 1: command "rc /fo CMakeFiles\\cmTC_041c1.dir/manifest.res CMakeFiles\\cmTC_041c1.dir/manifest.rc" failed (exit code 0) with the following output:
        no such file or directory
        ninja: build stopped: subcommand failed.
        
      exitCode: 1
  -
    kind: "try_compile-v1"
    backtrace:
      - "C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30/Modules/CMakeTestCXXCompiler.cmake:56 (try_compile)"
      - "CMakeLists.txt:26 (project)"
    checks:
      - "Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.41.34120/bin/Hostx64/x64/cl.exe"
    directories:
      source: "C:/vcpkg/buildtrees/abseil/x64-windows-dbg/CMakeFiles/CMakeScratch/TryCompile-57ys28"
      binary: "C:/vcpkg/buildtrees/abseil/x64-windows-dbg/CMakeFiles/CMakeScratch/TryCompile-57ys28"
    cmakeVariables:
      CMAKE_CXX_FLAGS: " /nologo /DWIN32 /D_WINDOWS /utf-8 /GR /EHsc /MP "
      CMAKE_CXX_FLAGS_DEBUG: "/MDd /Z7 /Ob0 /Od /RTC1 "
      CMAKE_CXX_SCAN_FOR_MODULES: "OFF"
      CMAKE_EXE_LINKER_FLAGS: "/machine:x64"
      CMAKE_MSVC_DEBUG_INFORMATION_FORMAT: ""
      CMAKE_MSVC_RUNTIME_LIBRARY: "MultiThreaded$<$<CONFIG:Debug>:Debug>$<$<STREQUAL:dynamic,dynamic>:DLL>"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "C:/vcpkg/scripts/toolchains/windows.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "C:/Users/\u0130brahim F. Yo\u011furt\u00e7u/Documents/protoc-deneme/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PLATFORM_TOOLSET: "v143"
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_SET_CHARSET_FLAG: "ON"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-windows"
      Z_VCPKG_ROOT_DIR: "C:/vcpkg"
    buildResult:
      variable: "CMAKE_CXX_COMPILER_WORKS"
      cached: true
      stdout: |
        Change Dir: 'C:/vcpkg/buildtrees/abseil/x64-windows-dbg/CMakeFiles/CMakeScratch/TryCompile-57ys28'
        
        Run Build Command(s): C:/vcpkg/downloads/tools/ninja/1.12.1-windows/ninja.exe -v cmTC_14f1f
        [1/2] C:\\PROGRA~2\\MICROS~2\\2022\\BUILDT~1\\VC\\Tools\\MSVC\\1441~1.341\\bin\\Hostx64\\x64\\cl.exe  /nologo /TP   /nologo /DWIN32 /D_WINDOWS /utf-8 /GR /EHsc /MP   /MDd /Z7 /Ob0 /Od /RTC1  -MDd /showIncludes /FoCMakeFiles\\cmTC_14f1f.dir\\testCXXCompiler.cxx.obj /FdCMakeFiles\\cmTC_14f1f.dir\\ /FS -c C:\\vcpkg\\buildtrees\\abseil\\x64-windows-dbg\\CMakeFiles\\CMakeScratch\\TryCompile-57ys28\\testCXXCompiler.cxx
        [2/2] C:\\Windows\\system32\\cmd.exe /C "cd . && C:\\vcpkg\\downloads\\tools\\cmake-3.30.1-windows\\cmake-3.30.1-windows-i386\\bin\\cmake.exe -E vs_link_exe --intdir=CMakeFiles\\cmTC_14f1f.dir --rc=rc --mt=CMAKE_MT-NOTFOUND --manifests  -- C:\\PROGRA~2\\MICROS~2\\2022\\BUILDT~1\\VC\\Tools\\MSVC\\1441~1.341\\bin\\Hostx64\\x64\\link.exe /nologo CMakeFiles\\cmTC_14f1f.dir\\testCXXCompiler.cxx.obj  /out:cmTC_14f1f.exe /implib:cmTC_14f1f.lib /pdb:cmTC_14f1f.pdb /version:0.0 /machine:x64  /nologo    /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib && cd ."
        FAILED: cmTC_14f1f.exe 
        C:\\Windows\\system32\\cmd.exe /C "cd . && C:\\vcpkg\\downloads\\tools\\cmake-3.30.1-windows\\cmake-3.30.1-windows-i386\\bin\\cmake.exe -E vs_link_exe --intdir=CMakeFiles\\cmTC_14f1f.dir --rc=rc --mt=CMAKE_MT-NOTFOUND --manifests  -- C:\\PROGRA~2\\MICROS~2\\2022\\BUILDT~1\\VC\\Tools\\MSVC\\1441~1.341\\bin\\Hostx64\\x64\\link.exe /nologo CMakeFiles\\cmTC_14f1f.dir\\testCXXCompiler.cxx.obj  /out:cmTC_14f1f.exe /implib:cmTC_14f1f.lib /pdb:cmTC_14f1f.pdb /version:0.0 /machine:x64  /nologo    /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib && cd ."
        RC Pass 1: command "rc /fo CMakeFiles\\cmTC_14f1f.dir/manifest.res CMakeFiles\\cmTC_14f1f.dir/manifest.rc" failed (exit code 0) with the following output:
        no such file or directory
        ninja: build stopped: subcommand failed.
        
      exitCode: 1
...
```
</details>

<details><summary>C:\vcpkg\buildtrees\abseil\config-x64-windows-dbg-CMakeCache.txt.log</summary>

```
# This is the CMakeCache file.
# For build in directory: c:/vcpkg/buildtrees/abseil/x64-windows-dbg
# It was generated by CMake: C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/bin/cmake.exe
# You can edit this file to change values found and used by cmake.
# If you do not want to change any of the values, simply exit the editor.
# If you do want to change a value, simply edit, save, and exit the editor.
# The syntax for the file is as follows:
# KEY:TYPE=VALUE
# KEY is the name of a variable in the cache.
# TYPE is a hint to GUIs for the type of VALUE, DO NOT EDIT TYPE!.
# VALUE is the current value for the KEY.

########################
# EXTERNAL cache entries
########################

//No help, variable specified on the command line.
ABSL_PROPAGATE_CXX_STD:UNINITIALIZED=ON

//No help, variable specified on the command line.
BUILD_SHARED_LIBS:UNINITIALIZED=ON

//Path to a program.
CMAKE_AR:FILEPATH=C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.41.34120/bin/Hostx64/x64/lib.exe

//Choose the type of build, options are: None Debug Release RelWithDebInfo
// MinSizeRel ...
CMAKE_BUILD_TYPE:STRING=Debug

CMAKE_CROSSCOMPILING:STRING=OFF

//CXX compiler
CMAKE_CXX_COMPILER:FILEPATH=C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.41.34120/bin/Hostx64/x64/cl.exe

CMAKE_CXX_FLAGS:STRING=' /nologo /DWIN32 /D_WINDOWS /utf-8 /GR /EHsc /MP '

CMAKE_CXX_FLAGS_DEBUG:STRING='/MDd /Z7 /Ob0 /Od /RTC1 '

//Flags used by the CXX compiler during MINSIZEREL builds.
CMAKE_CXX_FLAGS_MINSIZEREL:STRING=/O1 /Ob1 /DNDEBUG

CMAKE_CXX_FLAGS_RELEASE:STRING='/MD /O2 /Oi /Gy /DNDEBUG /Z7 '

//Flags used by the CXX compiler during RELWITHDEBINFO builds.
CMAKE_CXX_FLAGS_RELWITHDEBINFO:STRING=/O2 /Ob1 /DNDEBUG

//Libraries linked by default with all C++ applications.
CMAKE_CXX_STANDARD_LIBRARIES:STRING=kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib

CMAKE_C_FLAGS:STRING=' /nologo /DWIN32 /D_WINDOWS /utf-8 /MP '

CMAKE_C_FLAGS_DEBUG:STRING='/MDd /Z7 /Ob0 /Od /RTC1 '

CMAKE_C_FLAGS_RELEASE:STRING='/MD /O2 /Oi /Gy /DNDEBUG /Z7 '

//No help, variable specified on the command line.
CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION:UNINITIALIZED=ON

//Flags used by the linker during all build types.
CMAKE_EXE_LINKER_FLAGS:STRING=/machine:x64

//Flags used by the linker during DEBUG builds.
CMAKE_EXE_LINKER_FLAGS_DEBUG:STRING=/nologo    /debug /INCREMENTAL

//Flags used by the linker during MINSIZEREL builds.
CMAKE_EXE_LINKER_FLAGS_MINSIZEREL:STRING=/INCREMENTAL:NO

CMAKE_EXE_LINKER_FLAGS_RELEASE:STRING='/nologo /DEBUG /INCREMENTAL:NO /OPT:REF /OPT:ICF  '

//Flags used by the linker during RELWITHDEBINFO builds.
CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO:STRING=/debug /INCREMENTAL

//Enable/Disable output of compile commands during generation.
CMAKE_EXPORT_COMPILE_COMMANDS:BOOL=

//No help, variable specified on the command line.
CMAKE_EXPORT_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY:UNINITIALIZED=ON

//Value Computed by CMake.
CMAKE_FIND_PACKAGE_REDIRECTS_DIR:STATIC=C:/vcpkg/buildtrees/abseil/x64-windows-dbg/CMakeFiles/pkgRedirects

//No help, variable specified on the command line.
CMAKE_INSTALL_BINDIR:STRING=bin

//No help, variable specified on the command line.
CMAKE_INSTALL_LIBDIR:STRING=lib

//Install path prefix, prepended onto install directories.
CMAKE_INSTALL_PREFIX:PATH=C:/vcpkg/packages/abseil_x64-windows/debug

//No help, variable specified on the command line.
CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP:UNINITIALIZED=TRUE

//Path to a program.
CMAKE_LINKER:FILEPATH=C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.41.34120/bin/Hostx64/x64/link.exe

//No help, variable specified on the command line.
CMAKE_MAKE_PROGRAM:UNINITIALIZED=C:/vcpkg/downloads/tools/ninja/1.12.1-windows/ninja.exe

//Flags used by the linker during the creation of modules during
// all build types.
CMAKE_MODULE_LINKER_FLAGS:STRING=/machine:x64

//Flags used by the linker during the creation of modules during
// DEBUG builds.
CMAKE_MODULE_LINKER_FLAGS_DEBUG:STRING=/nologo    /debug /INCREMENTAL

//Flags used by the linker during the creation of modules during
// MINSIZEREL builds.
CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL:STRING=/INCREMENTAL:NO

CMAKE_MODULE_LINKER_FLAGS_RELEASE:STRING='/nologo /DEBUG /INCREMENTAL:NO /OPT:REF /OPT:ICF  '

//Flags used by the linker during the creation of modules during
// RELWITHDEBINFO builds.
CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO:STRING=/debug /INCREMENTAL

CMAKE_MSVC_RUNTIME_LIBRARY:STRING=MultiThreaded$<$<CONFIG:Debug>:Debug>$<$<STREQUAL:dynamic,dynamic>:DLL>

//Path to a program.
CMAKE_MT:FILEPATH=CMAKE_MT-NOTFOUND

//Value Computed by CMake
CMAKE_PROJECT_DESCRIPTION:STATIC=

//Value Computed by CMake
CMAKE_PROJECT_HOMEPAGE_URL:STATIC=

//Value Computed by CMake
CMAKE_PROJECT_NAME:STATIC=absl

//Value Computed by CMake
CMAKE_PROJECT_VERSION:STATIC=20250127

//Value Computed by CMake
CMAKE_PROJECT_VERSION_MAJOR:STATIC=20250127

//Value Computed by CMake
CMAKE_PROJECT_VERSION_MINOR:STATIC=

//Value Computed by CMake
CMAKE_PROJECT_VERSION_PATCH:STATIC=

//Value Computed by CMake
CMAKE_PROJECT_VERSION_TWEAK:STATIC=

//RC compiler
CMAKE_RC_COMPILER:FILEPATH=rc

CMAKE_RC_FLAGS:STRING=-c65001 /DWIN32

//Flags for Windows Resource Compiler during DEBUG builds.
CMAKE_RC_FLAGS_DEBUG:STRING=-D_DEBUG

//Flags for Windows Resource Compiler during MINSIZEREL builds.
CMAKE_RC_FLAGS_MINSIZEREL:STRING=

//Flags for Windows Resource Compiler during RELEASE builds.
CMAKE_RC_FLAGS_RELEASE:STRING=

//Flags for Windows Resource Compiler during RELWITHDEBINFO builds.
CMAKE_RC_FLAGS_RELWITHDEBINFO:STRING=

//Flags used by the linker during the creation of shared libraries
// during all build types.
CMAKE_SHARED_LINKER_FLAGS:STRING=/machine:x64

//Flags used by the linker during the creation of shared libraries
// during DEBUG builds.
CMAKE_SHARED_LINKER_FLAGS_DEBUG:STRING=/nologo    /debug /INCREMENTAL

//Flags used by the linker during the creation of shared libraries
// during MINSIZEREL builds.
CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL:STRING=/INCREMENTAL:NO

CMAKE_SHARED_LINKER_FLAGS_RELEASE:STRING='/nologo /DEBUG /INCREMENTAL:NO /OPT:REF /OPT:ICF  '

//Flags used by the linker during the creation of shared libraries
// during RELWITHDEBINFO builds.
CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO:STRING=/debug /INCREMENTAL

//If set, runtime paths are not added when installing shared libraries,
// but are added when building.
CMAKE_SKIP_INSTALL_RPATH:BOOL=NO

//If set, runtime paths are not added when using shared libraries.
CMAKE_SKIP_RPATH:BOOL=NO

//Flags used by the linker during the creation of static libraries
// during all build types.
CMAKE_STATIC_LINKER_FLAGS:STRING=/machine:x64

//Flags used by the linker during the creation of static libraries
// during DEBUG builds.
CMAKE_STATIC_LINKER_FLAGS_DEBUG:STRING=/nologo

//Flags used by the linker during the creation of static libraries
// during MINSIZEREL builds.
CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during the creation of static libraries
// during RELEASE builds.
CMAKE_STATIC_LINKER_FLAGS_RELEASE:STRING=/nologo

//Flags used by the linker during the creation of static libraries
// during RELWITHDEBINFO builds.
CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO:STRING=

CMAKE_SYSTEM_NAME:STRING=Windows

CMAKE_SYSTEM_PROCESSOR:STRING=AMD64

CMAKE_SYSTEM_VERSION:STRING=10.0.19045

//The CMake toolchain file
CMAKE_TOOLCHAIN_FILE:FILEPATH=C:/vcpkg/scripts/buildsystems/vcpkg.cmake

//If this value is on, makefiles will be generated without the
// .SILENT directive, and all commands will be echoed to the console
// during the make.  This is useful for debugging only. With Visual
// Studio IDE projects all commands are done without /nologo.
CMAKE_VERBOSE_MAKEFILE:BOOL=ON

//No help, variable specified on the command line.
FETCHCONTENT_FULLY_DISCONNECTED:UNINITIALIZED=ON

//Automatically copy dependencies into the output directory for
// executables.
VCPKG_APPLOCAL_DEPS:BOOL=OFF

//No help, variable specified on the command line.
VCPKG_CHAINLOAD_TOOLCHAIN_FILE:UNINITIALIZED=C:/vcpkg/scripts/toolchains/windows.cmake

//No help, variable specified on the command line.
VCPKG_CRT_LINKAGE:UNINITIALIZED=dynamic

//No help, variable specified on the command line.
VCPKG_CXX_FLAGS:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_CXX_FLAGS_DEBUG:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_CXX_FLAGS_RELEASE:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_C_FLAGS:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_C_FLAGS_DEBUG:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_C_FLAGS_RELEASE:UNINITIALIZED=

//The directory which contains the installed libraries for each
// triplet
VCPKG_INSTALLED_DIR:PATH=C:/Users/İbrahim F. Yoğurtçu/Documents/protoc-deneme/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/vcpkg_installed

//No help, variable specified on the command line.
VCPKG_LINKER_FLAGS:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_LINKER_FLAGS_DEBUG:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_LINKER_FLAGS_RELEASE:UNINITIALIZED=

//The path to the vcpkg manifest directory.
VCPKG_MANIFEST_DIR:PATH=

//Use manifest mode, as opposed to classic mode.
VCPKG_MANIFEST_MODE:BOOL=OFF

//No help, variable specified on the command line.
VCPKG_PLATFORM_TOOLSET:UNINITIALIZED=v143

//Appends the vcpkg paths to CMAKE_PREFIX_PATH, CMAKE_LIBRARY_PATH
// and CMAKE_FIND_ROOT_PATH so that vcpkg libraries/packages are
// found after toolchain/system libraries/packages.
VCPKG_PREFER_SYSTEM_LIBS:BOOL=OFF

//Enable the setup of CMAKE_PROGRAM_PATH to vcpkg paths
VCPKG_SETUP_CMAKE_PROGRAM_PATH:BOOL=ON

//No help, variable specified on the command line.
VCPKG_SET_CHARSET_FLAG:UNINITIALIZED=ON

//No help, variable specified on the command line.
VCPKG_TARGET_ARCHITECTURE:UNINITIALIZED=x64

//Vcpkg target triplet (ex. x86-windows)
VCPKG_TARGET_TRIPLET:STRING=x64-windows

//Trace calls to find_package()
VCPKG_TRACE_FIND_PACKAGE:BOOL=OFF

//Enables messages from the VCPKG toolchain for debugging purposes.
VCPKG_VERBOSE:BOOL=OFF

//(experimental) Automatically copy dependencies into the install
// target directory for executables. Requires CMake 3.14.
X_VCPKG_APPLOCAL_DEPS_INSTALL:BOOL=OFF

//(experimental) Add USES_TERMINAL to VCPKG_APPLOCAL_DEPS to force
// serialization.
X_VCPKG_APPLOCAL_DEPS_SERIALIZED:BOOL=OFF

//The directory which contains the installed libraries for each
// triplet
_VCPKG_INSTALLED_DIR:PATH=C:/Users/İbrahim F. Yoğurtçu/Documents/protoc-deneme/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/vcpkg_installed

//No help, variable specified on the command line.
_VCPKG_ROOT_DIR:UNINITIALIZED=C:/vcpkg

//Value Computed by CMake
absl_BINARY_DIR:STATIC=C:/vcpkg/buildtrees/abseil/x64-windows-dbg

//Value Computed by CMake
absl_IS_TOP_LEVEL:STATIC=ON

//Value Computed by CMake
absl_SOURCE_DIR:STATIC=C:/vcpkg/buildtrees/abseil/src/20250127.1-a0a219bf72.clean


########################
# INTERNAL cache entries
########################

//ADVANCED property for variable: CMAKE_AR
CMAKE_AR-ADVANCED:INTERNAL=1
//This is the directory where this CMakeCache.txt was created
CMAKE_CACHEFILE_DIR:INTERNAL=c:/vcpkg/buildtrees/abseil/x64-windows-dbg
//Major version of cmake used to create the current loaded cache
CMAKE_CACHE_MAJOR_VERSION:INTERNAL=3
//Minor version of cmake used to create the current loaded cache
CMAKE_CACHE_MINOR_VERSION:INTERNAL=30
//Patch version of cmake used to create the current loaded cache
CMAKE_CACHE_PATCH_VERSION:INTERNAL=1
//Path to CMake executable.
CMAKE_COMMAND:INTERNAL=C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/bin/cmake.exe
//Path to cpack program executable.
CMAKE_CPACK_COMMAND:INTERNAL=C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/bin/cpack.exe
//Path to ctest program executable.
CMAKE_CTEST_COMMAND:INTERNAL=C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/bin/ctest.exe
//ADVANCED property for variable: CMAKE_CXX_COMPILER
CMAKE_CXX_COMPILER-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_CXX_FLAGS
CMAKE_CXX_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_CXX_FLAGS_DEBUG
CMAKE_CXX_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_CXX_FLAGS_MINSIZEREL
CMAKE_CXX_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_CXX_FLAGS_RELEASE
CMAKE_CXX_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_CXX_FLAGS_RELWITHDEBINFO
CMAKE_CXX_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_CXX_STANDARD_LIBRARIES
CMAKE_CXX_STANDARD_LIBRARIES-ADVANCED:INTERNAL=1
//Path to cache edit program executable.
CMAKE_EDIT_COMMAND:INTERNAL=C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/bin/cmake-gui.exe
//Executable file format
CMAKE_EXECUTABLE_FORMAT:INTERNAL=Unknown
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS
CMAKE_EXE_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_DEBUG
CMAKE_EXE_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_MINSIZEREL
CMAKE_EXE_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_RELEASE
CMAKE_EXE_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXPORT_COMPILE_COMMANDS
CMAKE_EXPORT_COMPILE_COMMANDS-ADVANCED:INTERNAL=1
//Name of external makefile project generator.
CMAKE_EXTRA_GENERATOR:INTERNAL=
//Name of generator.
CMAKE_GENERATOR:INTERNAL=Ninja
//Generator instance identifier.
CMAKE_GENERATOR_INSTANCE:INTERNAL=
//Name of generator platform.
CMAKE_GENERATOR_PLATFORM:INTERNAL=
//Name of generator toolset.
CMAKE_GENERATOR_TOOLSET:INTERNAL=
//Source directory with the top level CMakeLists.txt file for this
// project
CMAKE_HOME_DIRECTORY:INTERNAL=C:/vcpkg/buildtrees/abseil/src/20250127.1-a0a219bf72.clean
//ADVANCED property for variable: CMAKE_LINKER
CMAKE_LINKER-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS
CMAKE_MODULE_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_DEBUG
CMAKE_MODULE_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL
CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_RELEASE
CMAKE_MODULE_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MT
CMAKE_MT-ADVANCED:INTERNAL=1
//number of local generators
CMAKE_NUMBER_OF_MAKEFILES:INTERNAL=1
//Platform information initialized
CMAKE_PLATFORM_INFO_INITIALIZED:INTERNAL=1
//noop for ranlib
CMAKE_RANLIB:INTERNAL=:
//ADVANCED property for variable: CMAKE_RC_COMPILER
CMAKE_RC_COMPILER-ADVANCED:INTERNAL=1
CMAKE_RC_COMPILER_WORKS:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS
CMAKE_RC_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS_DEBUG
CMAKE_RC_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS_MINSIZEREL
CMAKE_RC_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS_RELEASE
CMAKE_RC_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS_RELWITHDEBINFO
CMAKE_RC_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//Path to CMake installation.
CMAKE_ROOT:INTERNAL=C:/vcpkg/downloads/tools/cmake-3.30.1-windows/cmake-3.30.1-windows-i386/share/cmake-3.30
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS
CMAKE_SHARED_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_DEBUG
CMAKE_SHARED_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL
CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_RELEASE
CMAKE_SHARED_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SKIP_INSTALL_RPATH
CMAKE_SKIP_INSTALL_RPATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SKIP_RPATH
CMAKE_SKIP_RPATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS
CMAKE_STATIC_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_DEBUG
CMAKE_STATIC_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL
CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_RELEASE
CMAKE_STATIC_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_TOOLCHAIN_FILE
CMAKE_TOOLCHAIN_FILE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_VERBOSE_MAKEFILE
CMAKE_VERBOSE_MAKEFILE-ADVANCED:INTERNAL=1
//Install the dependencies listed in your manifest:
//\n    If this is off, you will have to manually install your dependencies.
//\n    See https://github.com/microsoft/vcpkg/tree/master/docs/specifications/manifests.md
// for more info.
//\n
VCPKG_MANIFEST_INSTALL:INTERNAL=OFF
//ADVANCED property for variable: VCPKG_VERBOSE
VCPKG_VERBOSE-ADVANCED:INTERNAL=1
//Making sure VCPKG_MANIFEST_MODE doesn't change
Z_VCPKG_CHECK_MANIFEST_MODE:INTERNAL=OFF
//Vcpkg root directory
Z_VCPKG_ROOT_DIR:INTERNAL=C:/vcpkg

```
</details>

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "$schema": "https://raw.githubusercontent.com/microsoft/vcpkg-tool/main/docs/vcpkg.schema.json",
  "dependencies": [
    "protobuf"
  ],
  "name": "mypackage",
  "version-string": "0.0.1"
}

```
</details>
