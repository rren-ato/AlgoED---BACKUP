//
// Created by erasmo on 6/15/26.
//

#ifndef AVL_FUNCIONESAVL_HPP
#define AVL_FUNCIONESAVL_HPP
#include "../ABB/ArbolBinarioBusqueda.h"

int factor_balance(NodoArbolBinarioBusqueda *nodo);

void rotar_derecha(NodoArbolBinarioBusqueda * &raiz);

void rotar_izquierda(NodoArbolBinarioBusqueda * &raiz);

void balancear_avl(NodoArbolBinarioBusqueda * &raiz);

void insertar_avl_recursivo(NodoArbolBinarioBusqueda *&raiz,
                            ElementoArbolBinarioBusqueda elemento);

void eliminar_avl_recursivo(NodoArbolBinarioBusqueda *&raiz,
                            ElementoArbolBinarioBusqueda elemento);

bool es_completo(ArbolBinarioBusqueda &arbol);

bool es_degenerado(ArbolBinarioBusqueda &arbol);

bool es_balanceado_avl(ArbolBinarioBusqueda &arbol);

void construir_desde_arreglo(ArbolBinarioBusqueda &arbol,
                             int *arr_datos,
                             int cantidad_datos);

void insertar_avl(
    ArbolBinarioBusqueda &arbol,
    ElementoArbolBinarioBusqueda elemento);

void eliminar_avl(
    ArbolBinarioBusqueda &arbol,
    ElementoArbolBinarioBusqueda elemento);

#endif //AVL_FUNCIONESAVL_HPP
