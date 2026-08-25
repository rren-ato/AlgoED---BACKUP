cmake_minimum_required(VERSION 4.0)
project(AVL)

set(CMAKE_CXX_STANDARD 20)

add_executable(AVL main.cpp
        Bibliotecas/ABB/funcionesArbolBinarioBusqueda.cpp
        Bibliotecas/AVL/FuncionesAVL.cpp
        Bibliotecas/AVL/FuncionesAVL.hpp
)
