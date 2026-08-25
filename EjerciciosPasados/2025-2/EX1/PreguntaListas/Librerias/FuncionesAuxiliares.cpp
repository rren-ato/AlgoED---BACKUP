//
// Created by erasmo on 5/22/26.
//

#include "FuncionesAuxiliares.hpp"

void inicializar(ColaPrioridad &cola) {
    cola.head = nullptr;
    cola.tail = nullptr;
    cola.last1 = nullptr;
}

Nodo *crearNodo(int codigo, Prioridad p) {
    Nodo *nuevo = new Nodo;
    nuevo->codigo = codigo;
    nuevo->prioridad = p;
    nuevo->sig = nullptr;
    return nuevo;
}

/* ENCOLAR O(1) */
void llegada(ColaPrioridad &cola, int codigo, Prioridad p) {

    Nodo *nuevo = crearNodo(codigo, p);

    /* CASO 1: cola vacia */
    if (cola.head == nullptr) {
        cola.head = cola.tail = nuevo;

        if (p == PREFERENTE)
            cola.last1 = nuevo;

        return;
    }

    /* CLIENTE REGULAR -> insertar al final */
    if (p == REGULAR) {
        cola.tail->sig = nuevo;
        cola.tail = nuevo;
        return;
    }

    /* CLIENTE PREFERENTE */

    /* si no existe segmento P1 */
    if (cola.last1 == nullptr) {
        nuevo->sig = cola.head;
        cola.head = nuevo;
        cola.last1 = nuevo;
    }
    else {
        nuevo->sig = cola.last1->sig;
        cola.last1->sig = nuevo;
        cola.last1 = nuevo;

        if (nuevo->sig == nullptr)
            cola.tail = nuevo;
    }
}

/* DESENCOLAR O(1) */
bool atender(ColaPrioridad &cola) {

    if (cola.head == nullptr)
        return false;

    Nodo *elim = cola.head;

    cout << "Atendido: "
         << elim->codigo
         << " ("
         << (elim->prioridad == PREFERENTE ? "P1" : "P2")
         << ")"
         << endl;

    cola.head = cola.head->sig;

    /* si se elimina el ultimo P1 */
    if (elim == cola.last1)
        cola.last1 = nullptr;

    /* cola vacia */
    if (cola.head == nullptr) {
        cola.tail = nullptr;
        cola.last1 = nullptr;
    }

    delete elim;

    return true;
}

void imprimir(ColaPrioridad cola) {

    cout << "Estado: ";

    cout << "[P1: ";

    Nodo *rec = cola.head;

    while (rec != nullptr &&
           rec->prioridad == PREFERENTE) {

        cout << rec->codigo;

        if (rec != cola.last1)
            cout << ", ";

        rec = rec->sig;
    }

    cout << "]";

    cout << "[P2: ";

    while (rec != nullptr) {
        cout << rec->codigo;

        if (rec->sig != nullptr)
            cout << ", ";

        rec = rec->sig;
    }

    cout << "]" << endl;
}

Prioridad convertir(char* texto) {

    if (strcmp(texto, "preferente") == 0)
        return PREFERENTE;

    return REGULAR;
}

void simular_banco_alg(const char* nombre_archivo) {
    ifstream arch(nombre_archivo, ios::in);

    ColaPrioridad cola;
    inicializar(cola);

    string comando;

    while (arch >> comando) {

        if (comando == "llegada") {

            int codigo;
            char tipo[20];

            arch >> codigo >> tipo;

            llegada(cola, codigo, convertir(tipo));
        }

        else if (comando == "atender") {

            int k;
            arch >> k;

            for (int i = 0; i < k; i++) {

                if (not atender(cola))
                    break;
            }
        }

        else if (comando == "imprimir") {
            imprimir(cola);
        }
    }
}
