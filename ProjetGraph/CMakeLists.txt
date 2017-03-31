cmake_minimum_required(VERSION 3.7)
project(ProjetGraph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ProjetGraph/ProjetGraph.cpp

        ProjetGraph/utils.h
        ProjetGraph/CUnit.cpp ProjetGraph/CUnit.h
        )
add_executable(ProjetGraph ${SOURCE_FILES})
