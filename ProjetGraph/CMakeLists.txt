cmake_minimum_required(VERSION 3.7)
project(ProjetGraph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ProjetGraph/ProjetGraph.cpp

        ProjetGraph/CException.cpp ProjetGraph/CException.h
        ProjetGraph/tests/CExceptionUnit.cpp ProjetGraph/tests/CExceptionUnit.h

        ProjetGraph/CArc.cpp ProjetGraph/CArc.h
        ProjetGraph/tests/CArcUnit.cpp ProjetGraph/tests/CArcUnit.h

        ProjetGraph/CVertex.cpp ProjetGraph/CVertex.h
        ProjetGraph/tests/CVertexUnit.cpp ProjetGraph/tests/CVertexUnit.h

        ProjetGraph/CGraph.cpp ProjetGraph/CGraph.h
        ProjetGraph/tests/CGraphUnit.cpp ProjetGraph/tests/CGraphUnit.h

        ProjetGraph/CGraphParser.cpp ProjetGraph/CGraphParser.h
        ProjetGraph/tests/CGraphParserUnit.cpp ProjetGraph/tests/CGraphParserUnit.h

        ProjetGraph/CHashMap.cpp ProjetGraph/CHashMap.h
        ProjetGraph/tests/CHashMapUnit.cpp ProjetGraph/tests/CHashMapUnit.h

        ProjetGraph/utils.h
        ProjetGraph/tests/CUnit.cpp ProjetGraph/tests/CUnit.h
        )
add_executable(ProjetGraph ${SOURCE_FILES})
