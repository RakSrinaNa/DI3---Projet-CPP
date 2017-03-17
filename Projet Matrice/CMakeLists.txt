cmake_minimum_required(VERSION 3.7)
project(Preojet3Matrice)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES "Projet Matrice/Projet Matrice.cpp" "Projet Matrice/CException.cpp" "Projet Matrice/CException.h" "Projet Matrice/CMatrix.cpp" "Projet Matrice/CMatrix.h" "Projet Matrice/CMatrixParser.cpp" "Projet Matrice/CMatrixParser.h" "Projet Matrice/CSquareMatrix.cpp" "Projet Matrice/CSquareMatrix.h" "Projet Matrice/utils.h" "Projet Matrice/tests/CExceptionUnit.cpp" "Projet Matrice/tests/CExceptionUnit.h" "Projet Matrice/tests/CUnit.h" "Projet Matrice/tests/CMatrixParserUnit.cpp" "Projet Matrice/tests/CMatrixParserUnit.h" "Projet Matrice/tests/CMatrixUnit.cpp" "Projet Matrice/tests/CMatrixUnit.h" "Projet Matrice/tests/CUnit.cpp")
add_executable(TP1 ${SOURCE_FILES})