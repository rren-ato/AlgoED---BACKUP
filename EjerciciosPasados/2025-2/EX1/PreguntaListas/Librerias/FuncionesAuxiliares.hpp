//
// Created by erasmo on 5/22/26.
//

#ifndef PREGUNTALISTAS_FUNCIONESAUXILIARES_HPP
#define PREGUNTALISTAS_FUNCIONESAUXILIARES_HPP
#include "Utils.hpp"
#include "Estructuras.hpp"

void inicializar(ColaPrioridad &cola);

Nodo *crearNodo(int codigo, Prioridad p);

void llegada(ColaPrioridad &cola, int codigo, Prioridad p);

bool atender(ColaPrioridad &cola);

void imprimir(ColaPrioridad cola);

Prioridad convertir(char* texto);

void simular_banco_alg(const char* nombre_archivo);
#endif //PREGUNTALISTAS_FUNCIONESAUXILIARES_HPP
