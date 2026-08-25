//
// Created by erasmo on 7/3/26.
//

#include "FuncionesAuxiliares.hpp"

void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

void calcularPrioridad(struct ElementoArbolBinarioBusqueda &elemento) {
    elemento.prioridad = elemento.sintomas.size();
}

bool vaAntes(const struct ElementoArbolBinarioBusqueda &nuevo,
             const struct ElementoArbolBinarioBusqueda &actual) {
    if (nuevo.prioridad < actual.prioridad) return true; // el nuevo es menor, inserto izq
    if (nuevo.prioridad > actual.prioridad) return false; // el nuevo es mayor, inserto der
    //Si llego aqui, entonces nuevo y actual son IGUALES
    //return nuevo.codigoPaciente < actual.codigoPaciente; // el nuevo codigo de paciente es menor, inserto izq caso contrario inerto der
    return false; // por orden de llegada, implica insertar der, ose return False
}

struct NodoArbolBinarioBusqueda *crearNodo(struct ElementoArbolBinarioBusqueda elemento) {
    struct NodoArbolBinarioBusqueda *nuevoNodo;
    nuevoNodo = new struct NodoArbolBinarioBusqueda;

    nuevoNodo->elemento = elemento;
    nuevoNodo->izquierda = nullptr;
    nuevoNodo->derecha = nullptr;

    return nuevoNodo;
}

/*
 * El caso base de insercion se produce en 2 tiempos.
 * 1. Cuando el arbol esta vacio.
 * 2. Cuando el nodo se cae del arbol.
 */
void insertarOrdenado(struct NodoArbolBinarioBusqueda *&raiz,
                      struct ElementoArbolBinarioBusqueda elemento) {
    //Caso Base
    if (raiz == nullptr) {
        raiz = crearNodo(elemento); //Plantar
        return;
    }

    //Caso recursivo
    if (vaAntes(elemento, raiz->elemento)) {
        insertarOrdenado(raiz->izquierda, elemento);
    } else {
        insertarOrdenado(raiz->derecha, elemento);
    }
}

struct ElementoArbolBinarioBusqueda leerElemento(ifstream &archivo) {
    struct ElementoArbolBinarioBusqueda elemento;
    int cantidadSintomas;
    int sintoma;
    // 1023 Ana Cardiologia 3 10 20 30
    archivo >> elemento.codigoPaciente;
    archivo >> elemento.nombre;
    archivo >> elemento.especialidad;
    archivo >> cantidadSintomas;

    for (int i = 0; i < cantidadSintomas; i++) {
        archivo >> sintoma;
        elemento.sintomas.push_back(sintoma);
    }

    calcularPrioridad(elemento);

    return elemento;
}

void cargarPacientes(struct ArbolBinarioBusqueda &arbol,
                     const char *nombreArchivo) {
    ifstream input;
    apertura_archivo_lectura(input, nombreArchivo);

    while (true) {
        struct ElementoArbolBinarioBusqueda elemento;

        elemento = leerElemento(input);

        if (input.eof()) break;
        //Tiene que tener un criterio de orden
        insertarOrdenado(arbol.raiz, elemento); // Si la funcion va a ser recursiva, debo usar nodo en vez de arbol
    }

    input.close();
}

void imprimirSintomas(const vector<int> &sintomas) {
    cout << "[";
    for (int i = 0; i < sintomas.size(); i++) {
        cout << sintomas[i];
        if (i + 1 < sintomas.size()) cout << ", ";
    }
    // for (int i: sintomas) {
    //     cout<<sintomas[i];
    //     if (i + 1 < sintomas.size()) cout << ", ";
    // }
    cout << "]";
}

void imprimirElemento(const struct ElementoArbolBinarioBusqueda &elemento) {
    cout << left << setw(8) << elemento.codigoPaciente;
    cout << left << setw(12) << elemento.nombre;
    cout << left << setw(18) << elemento.especialidad;
    cout << left << setw(10) << elemento.prioridad;
    imprimirSintomas(elemento.sintomas);
    cout << endl;
}

void imprimirEnOrden(struct NodoArbolBinarioBusqueda *raiz) {
    if (raiz == nullptr) return;

    imprimirEnOrden(raiz->izquierda); // Hijo IZQ
    imprimirElemento(raiz->elemento); // PADRE
    imprimirEnOrden(raiz->derecha); // Hijo DER
}

void imprimirReporte(struct ArbolBinarioBusqueda arbol) {
    cout << left << setw(8) << "Codigo";
    cout << left << setw(12) << "Nombre";
    cout << left << setw(18) << "Especialidad";
    cout << left << setw(10) << "Prioridad";
    cout << "Sintomas" << endl;

    cout << "------------------------------------------------------------" << endl;

    imprimirEnOrden(arbol.raiz); //Como es recursiva le paso solo la raiz
}

void destruirArbol(struct NodoArbolBinarioBusqueda *raiz) {
    if (raiz == nullptr) return; // CB

    destruirArbol(raiz->izquierda); //IZQ
    destruirArbol(raiz->derecha);   //DER

    delete raiz; //Padre
}
