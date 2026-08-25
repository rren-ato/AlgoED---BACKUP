cmake_minimum_required(VERSION 4.0)
project(PreguntaListas)

set(CMAKE_CXX_STANDARD 20)

add_executable(PreguntaListas main.cpp
        Librerias/Estructuras.hpp
        Librerias/Utils.hpp
        Librerias/FuncionesAuxiliares.cpp
        Librerias/FuncionesAuxiliares.hpp)
