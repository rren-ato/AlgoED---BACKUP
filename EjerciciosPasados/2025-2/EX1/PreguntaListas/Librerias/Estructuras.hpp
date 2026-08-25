//
// Created by erasmo on 5/22/26.
//

#ifndef PREGUNTALISTAS_ESTRUCTURAS_HPP
#define PREGUNTALISTAS_ESTRUCTURAS_HPP
#include "Utils.hpp"

struct Nodo {
    int codigo;
    Prioridad prioridad;
    Nodo *sig;
};

struct ColaPrioridad {
    Nodo *head;
    Nodo *tail;
    Nodo *last1; // ultimo nodo P1
};
#endif //PREGUNTALISTAS_ESTRUCTURAS_HPP
