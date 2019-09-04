cmake_minimum_required(VERSION 3.14)
project(TxCloud)

set(CMAKE_CXX_STANDARD 14)

include_directories(KR_1_2/TxPaint/TxPaint)

add_executable(TxCloud
        KR_1_2/TxPaint/Debug/TxPaint.exe
        KR_1_2/TxPaint/Debug/TxPaint.ilk
        KR_1_2/TxPaint/Debug/TxPaint.pdb
        KR_1_2/TxPaint/TxPaint/Debug/Project1.tlog/CL.command.1.tlog
        KR_1_2/TxPaint/TxPaint/Debug/Project1.tlog/CL.read.1.tlog
        KR_1_2/TxPaint/TxPaint/Debug/Project1.tlog/CL.write.1.tlog
        KR_1_2/TxPaint/TxPaint/Debug/Project1.tlog/link.command.1.tlog
        KR_1_2/TxPaint/TxPaint/Debug/Project1.tlog/link.read.1.tlog
        KR_1_2/TxPaint/TxPaint/Debug/Project1.tlog/link.write.1.tlog
        KR_1_2/TxPaint/TxPaint/Debug/Project1.tlog/Project1.lastbuildstate
        KR_1_2/TxPaint/TxPaint/Debug/TxPaint.tlog/CL.command.1.tlog
        KR_1_2/TxPaint/TxPaint/Debug/TxPaint.tlog/CL.read.1.tlog
        KR_1_2/TxPaint/TxPaint/Debug/TxPaint.tlog/CL.write.1.tlog
        KR_1_2/TxPaint/TxPaint/Debug/TxPaint.tlog/link.command.1.tlog
        KR_1_2/TxPaint/TxPaint/Debug/TxPaint.tlog/link.read.1.tlog
        KR_1_2/TxPaint/TxPaint/Debug/TxPaint.tlog/link.write.1.tlog
        KR_1_2/TxPaint/TxPaint/Debug/TxPaint.tlog/TxPaint.lastbuildstate
        KR_1_2/TxPaint/TxPaint/Debug/ArrayStack.obj
        KR_1_2/TxPaint/TxPaint/Debug/Control.obj
        KR_1_2/TxPaint/TxPaint/Debug/Project1.log
        KR_1_2/TxPaint/TxPaint/Debug/Source.obj
        KR_1_2/TxPaint/TxPaint/Debug/TxPaint.log
        KR_1_2/TxPaint/TxPaint/Debug/vc141.idb
        KR_1_2/TxPaint/TxPaint/Debug/vc141.pdb
        KR_1_2/TxPaint/TxPaint/ArrayStack.cpp
        KR_1_2/TxPaint/TxPaint/BMPTools.exe
        KR_1_2/TxPaint/TxPaint/BMPTools.h
        KR_1_2/TxPaint/TxPaint/Control.c
        KR_1_2/TxPaint/TxPaint/Control.cpp
        KR_1_2/TxPaint/TxPaint/Control.exe
        KR_1_2/TxPaint/TxPaint/fun.bmp
        KR_1_2/TxPaint/TxPaint/new.bmp
        KR_1_2/TxPaint/TxPaint/SmallPic.bmp
        KR_1_2/TxPaint/TxPaint/test.bmp
        KR_1_2/TxPaint/TxPaint/TxPaint.vcxproj
        KR_1_2/TxPaint/TxPaint/TxPaint.vcxproj.filters
        KR_1_2/TxPaint/TxPaint/TxPaint.vcxproj.user
        KR_1_2/TxPaint/TxPaint.sln)
