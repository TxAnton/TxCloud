cmake_minimum_required(VERSION 3.14)
project()

set(CMAKE_CXX_STANDARD 14)

include_directories("4_Tree/Программы к лекции (бин дер)")

add_executable(
        "4_Tree/Программы к лекции (бин дер)/bt_implementation.cpp"
        "4_Tree/Программы к лекции (бин дер)/Btree.h"
        "4_Tree/Программы к лекции (бин дер)/work_bt.cpp")
