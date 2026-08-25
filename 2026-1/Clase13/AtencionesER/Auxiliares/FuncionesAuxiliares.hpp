//
// Created by erasmo on 7/3/26.
//

#ifndef ATENCIONESER_FUNCIONESAUXILIARES_HPP
#define ATENCIONESER_FUNCIONESAUXILIARES_HPP
#include "Utils.hpp"
#include "../BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"

void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo);

void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo);

void cargarPacientes(struct ArbolBinarioBusqueda &arbol, const char *nombreArchivo);

void imprimirReporte(struct ArbolBinarioBusqueda arbol);

void destruirArbol(struct NodoArbolBinarioBusqueda *raiz);
#endif //ATENCIONESER_FUNCIONESAUXILIARES_HPP
