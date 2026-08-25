#include <iostream>
using namespace std;

#include "Bibliotecas/ABB/funcionesArbolBinarioBusqueda.h"
#include "Bibliotecas/AVL/FuncionesAVL.hpp"

int main() {
    ArbolBinarioBusqueda arbol;

    int arr_datos[] = {
        40, 20, 60,
        10, 30, 50, 70,
        25, 35
    };

    int cantidad_datos = sizeof(arr_datos) / sizeof(arr_datos[0]);

    construir_desde_arreglo(arbol, arr_datos, cantidad_datos);

    cout << "ARBOL INICIAL" << endl;

    cout << "En Orden: ";
    recorrerEnOrden(arbol);
    cout << endl;

    cout << "Pre Orden: ";
    recorrerPreOrden(arbol);
    cout << endl;

    cout << "Post Orden: ";
    recorrerPostOrden(arbol);
    cout << endl;

    cout << endl;

    cout << "Altura: " << altura(arbol) << endl;

    cout << "Numero Nodos: " << numeroNodos(arbol) << endl;

    cout << "Numero Hojas: " << numeroHojas(arbol) << endl;

    cout << endl;

    cout << "Es Completo: " << es_completo(arbol) << endl;

    cout << "Es Degenerado: " << es_degenerado(arbol) << endl;

    cout << "Es Equilibrado: " << esEquilibrado(arbol) << endl;

    cout << "Es AVL: " << es_balanceado_avl(arbol) << endl;

    ElementoArbolBinarioBusqueda elemento;

    cout << endl;
    cout << "INSERTAR 5" << endl;

    elemento.numero = 5;

    insertar_avl(arbol, elemento);

    recorrerEnOrden(arbol);
    cout << endl;

    cout << "Es AVL: " << es_balanceado_avl(arbol) << endl;

    cout << endl;
    cout << "INSERTAR 65" << endl;

    elemento.numero = 65;

    insertar_avl(arbol, elemento);

    recorrerEnOrden(arbol);
    cout << endl;

    cout << "Es AVL: " << es_balanceado_avl(arbol) << endl;

    cout << endl;
    cout << "ELIMINAR 40" << endl;

    elemento.numero = 40;

    eliminar_avl(arbol, elemento);

    recorrerEnOrden(arbol);
    cout << endl;

    cout << "Es AVL: " << es_balanceado_avl(arbol) << endl;

    cout << endl;
    cout << "ELIMINAR 20" << endl;

    elemento.numero = 20;

    eliminar_avl(arbol, elemento);

    recorrerEnOrden(arbol);
    cout << endl;

    cout << "Es AVL: " << es_balanceado_avl(arbol) << endl;

    destruirArbolBinario(arbol);

    return 0;
}
