//
// Created by erasmo on 6/15/26.
//

#include "FuncionesAVL.hpp"

#include <cmath>

#include "../ABB/funcionesArbolBinarioBusqueda.h"

int factor_balance(NodoArbolBinarioBusqueda *nodo) {
    if (nodo == nullptr) return 0;

    return alturaRecursivo(nodo->izquierda) -
           alturaRecursivo(nodo->derecha);
}


void rotar_derecha(NodoArbolBinarioBusqueda *&raiz) {
    NodoArbolBinarioBusqueda *nuevo_padre;

    nuevo_padre = raiz->izquierda;

    raiz->izquierda = nuevo_padre->derecha;

    nuevo_padre->derecha = raiz;

    raiz = nuevo_padre;
}

void rotar_izquierda(NodoArbolBinarioBusqueda *&raiz) {
    NodoArbolBinarioBusqueda *nuevo_padre;

    nuevo_padre = raiz->derecha;

    raiz->derecha = nuevo_padre->izquierda;

    nuevo_padre->izquierda = raiz;

    raiz = nuevo_padre;
}

void balancear_avl(NodoArbolBinarioBusqueda *&raiz) {
    int balance;

    if (raiz == nullptr) return;

    balance = factor_balance(raiz);

    if (balance > 1) {
        if (factor_balance(raiz->izquierda) < 0)
            rotar_izquierda(raiz->izquierda);

        rotar_derecha(raiz);
    }

    if (balance < -1) {
        if (factor_balance(raiz->derecha) > 0)
            rotar_derecha(raiz->derecha);

        rotar_izquierda(raiz);
    }
}

void insertar_avl_recursivo(NodoArbolBinarioBusqueda *&raiz, ElementoArbolBinarioBusqueda elemento) {
    if (raiz == nullptr) {
        plantarNodoArbolBinario(raiz, nullptr, elemento, nullptr);
        return;
    }

    if (elemento.numero < raiz->elemento.numero)
        insertar_avl_recursivo(raiz->izquierda, elemento);

    else if (elemento.numero > raiz->elemento.numero)
        insertar_avl_recursivo(raiz->derecha, elemento);

    else
        return;

    balancear_avl(raiz);
}

void insertar_avl(ArbolBinarioBusqueda &arbol, ElementoArbolBinarioBusqueda elemento) {
    insertar_avl_recursivo(arbol.raiz, elemento);
}

void construir_desde_arreglo_recursivo(ArbolBinarioBusqueda &arbol,
                                       int *arr_datos,
                                       int cantidad_datos,
                                       int posicion) {
    ElementoArbolBinarioBusqueda elemento;

    if (posicion == cantidad_datos)
        return;

    elemento.numero = arr_datos[posicion];

    insertar_avl(arbol, elemento);

    construir_desde_arreglo_recursivo(arbol, arr_datos, cantidad_datos, posicion + 1);
}

void construir_desde_arreglo(ArbolBinarioBusqueda &arbol,
                             int *arr_datos,
                             int cantidad_datos) {
    construir(arbol);

    construir_desde_arreglo_recursivo(arbol, arr_datos, cantidad_datos, 0);
}

NodoArbolBinarioBusqueda *obtener_minimo(NodoArbolBinarioBusqueda *raiz) {
    if (raiz == nullptr)
        return nullptr;

    if (raiz->izquierda == nullptr)
        return raiz;

    return obtener_minimo(
        raiz->izquierda);
}

void eliminar_avl_recursivo(NodoArbolBinarioBusqueda *&raiz,
                            ElementoArbolBinarioBusqueda elemento) {
    NodoArbolBinarioBusqueda *hijo;
    NodoArbolBinarioBusqueda *sucesor;

    if (raiz == nullptr)
        return;

    if (elemento.numero < raiz->elemento.numero)

        eliminar_avl_recursivo(
            raiz->izquierda,
            elemento);

    else if (elemento.numero > raiz->elemento.numero)

        eliminar_avl_recursivo(
            raiz->derecha,
            elemento);

    else {
        if (raiz->izquierda == nullptr and
            raiz->derecha == nullptr) {
            delete raiz;
            raiz = nullptr;
        } else if (raiz->izquierda == nullptr or
                   raiz->derecha == nullptr) {
            if (raiz->izquierda != nullptr)
                hijo = raiz->izquierda;
            else
                hijo = raiz->derecha;

            delete raiz;

            raiz = hijo;
        } else {
            sucesor = obtener_minimo(
                raiz->derecha);

            raiz->elemento =
                    sucesor->elemento;

            eliminar_avl_recursivo(
                raiz->derecha,
                sucesor->elemento);
        }
    }

    if (raiz != nullptr)
        balancear_avl(raiz);
}

void eliminar_avl(ArbolBinarioBusqueda &arbol,
                  ElementoArbolBinarioBusqueda elemento) {
    eliminar_avl_recursivo(arbol.raiz, elemento);
}

bool es_degenerado_recursivo(NodoArbolBinarioBusqueda *raiz) {
    if (raiz == nullptr)
        return true;

    if (raiz->izquierda != nullptr and
        raiz->derecha != nullptr)
        return false;

    return es_degenerado_recursivo(raiz->izquierda) and es_degenerado_recursivo(raiz->derecha);
}

bool es_degenerado(ArbolBinarioBusqueda &arbol) {
    return es_degenerado_recursivo(arbol.raiz);
}


bool es_balanceado_avl_recursivo(NodoArbolBinarioBusqueda *raiz) {
    int balance;

    if (raiz == nullptr)
        return true;

    balance = factor_balance(raiz);

    return abs(balance) <= 1 and
           es_balanceado_avl_recursivo(raiz->izquierda) and
           es_balanceado_avl_recursivo(raiz->derecha);
}

bool es_balanceado_avl(ArbolBinarioBusqueda &arbol) {
    return es_balanceado_avl_recursivo(arbol.raiz);
}

bool es_completo_recursivo(NodoArbolBinarioBusqueda *raiz,
                           int posicion,
                           int cantidad_nodos) {
    if (raiz == nullptr)
        return true;

    if (posicion >= cantidad_nodos)
        return false;

    return es_completo_recursivo(raiz->izquierda, 2 * posicion + 1, cantidad_nodos) and
           es_completo_recursivo(raiz->derecha, 2 * posicion + 2, cantidad_nodos);
}

bool es_completo(ArbolBinarioBusqueda &arbol) {
    int cantidad_nodos;

    cantidad_nodos = numeroNodos(arbol);

    return es_completo_recursivo(arbol.raiz, 0, cantidad_nodos);
}
