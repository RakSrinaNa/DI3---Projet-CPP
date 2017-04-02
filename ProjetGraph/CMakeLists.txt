cmake_minimum_required(VERSION 3.7)
project(ProjetGraph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ProjetGraph/ProjetGraph.cpp

        ProjetGraph/CException.cpp ProjetGraph/Cexception.h
        ProjetGraph/tests/CExceptionUnit.cpp ProjetGraph/tests/CexceptionUnit.h

        ProjetGraph/CArc.cpp ProjetGraph/CArc.h
        ProjetGraph/tests/CArcUnit.cpp ProjetGraph/tests/CArcUnit.h

        ProjetGraph/CVertex.cpp ProjetGraph/CVertex.h

        ProjetGraph/CGraph.cpp ProjetGraph/Cgraph.h

        ProjetGraph/utils.h
        ProjetGraph/tests/CUnit.cpp ProjetGraph/tests/CUnit.h
        )
add_executable(ProjetGraph ${SOURCE_FILES})
