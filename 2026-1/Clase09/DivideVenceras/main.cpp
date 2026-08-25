#include "src/Funciones.hpp"

int buscar_solo(int *arr_p1, int inicio, int fin) {
    //Caso Base: Inicio == Fin, encontramos con el elemento unico
    if (inicio == fin) return arr_p1[inicio];

    int medio = (inicio + fin) / 2; // Lanzar la piedrita

    // Asegurarmos q medio sea par para comparar con su siguiente
    if (medio % 2 == 1) medio--;

    // Si el par esta completo
    if (arr_p1[medio] == arr_p1[medio + 1])
        return buscar_solo(arr_p1, medio + 2, fin); // Asumiendo q en la parte izq solo hay pares
    else
        return buscar_solo(arr_p1, inicio, medio); // Asumiendo q en la parte derecha solo hay pares
}

int buscar_pico(int *arr_p5, int inicio, int fin) {
    //CB
    if (inicio == fin) return arr_p5[inicio];
    int med = (inicio + fin) / 2;
    if (arr_p5[med] < arr_p5[med + 1])
        return buscar_pico(arr_p5, med + 1, fin);
    else
        return buscar_pico(arr_p5, inicio, med);
}

//{3, 8, 4, 2, 1}
int merge_inversiones(int *arr, int inicio, int med, int fin) {
    // {3, 8, 4, 2, 1}
    int izq = 0, der = 0;
    for (int i = med; i > inicio; i--) {
        if (arr[i] < arr[i - 1]) izq++;
    }

    for (int i = med + 1; i < fin; i++) {
        if (arr[i] > arr[i + 1]) der++;
    }
    return izq + der;
}

//{3, 8, 4, 2, 1}
//98 95 92 89 91 92 89 89 92 93 94 92 91 90 88 88 88 89 90 91 88 88 90 90 92 89 90 88 90 91

//int entrada = 88;
// cantidad de repetido de la entrada
// indice del primer elemmento
int contar_inversiones(int *arr, int inicio, int fin) {
    //CB
    //cout<<inicio<<"    "<<fin<<"    "<<arr[inicio]<<endl;
    if (inicio >= fin) return 0; //CB
    int med = (inicio + fin) / 2;
    //Rec
    int contador_izq = contar_inversiones(arr, inicio, med);
    int contador_der = contar_inversiones(arr, med+1 , fin);
    //Merge
    // {3, 8, 4, 2, 1}
    int contador_centro = merge_inversiones(arr, inicio, med, fin);
    return contador_izq + contador_der + contador_centro;
}

int main() {
    //Primer Problema
    // int arr_p1[]{1, 1, 3, 3, 4, 4, 5, 7, 7, 8, 8};
    // int n = sizeof(arr_p1) / sizeof(arr_p1[0]);
    // int inicio = 0, fin = n - 1, indice;
    // indice = buscar_solo(arr_p1, inicio, fin);
    // cout << indice << endl;

    //Problema 5

    // int arr_p5[]{8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    // int n = sizeof(arr_p5) / sizeof(arr_p5[0]);
    // int inicio = 0, fin = n - 1, valor;
    // valor = buscar_pico(arr_p5, inicio, fin);
    // cout<<valor<<endl;

    //Problema 6
    int arr_p6[]{3, 8, 4, 2, 1};
    //i = 0
    //j = 3
    // i<j si cumple
    //a[i]>a[j] 3>2 si se cumple
    int n = sizeof(arr_p6) / sizeof(arr_p6[0]);
    int inicio = 0, fin = n - 1, valor;
    valor = contar_inversiones(arr_p6, inicio, fin);
    cout<<valor<<endl;
    return 0;
}
