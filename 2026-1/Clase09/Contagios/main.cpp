#include "src/Funciones.hpp"

int main() {
    int arreglo[]{10, 20, 15, 10, 12, 10, 13, 18};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int cuenta = cuentaIncrementos(arreglo, 0, n - 1);
    cout << "Intervalo maximo de incrementos: " << cuenta <<
         ", con indice " << (cuenta * 1.0) / n << endl;
    return 0;
}

/*/
O(log n) // Partiendo nuestro espacio en mitades
    - Busqueda Binaria
    - La parte inicial del algoritmo merge sort

O(nlogn) // Proceso adicional luego de partir
    - Mergesort > solo la parte del mergrega ese N
        logn * n


Si aplico Busqueda binaria en una matriz o en un arreglo de arrelgos.
    For( i =0: i<M; i++){
        //ya me agrega un M
        busqueda_binaria(matriz[i]) // log n
    }
    //Resulta en un m log n

Si aplico Merge en una matriz o un arrreglo de arreglos
    For( i =0: i<M; i++){
        //ya me agrega un M
        merge_sort(matriz[i]) // n log n
    }
    //Resulta en un m * n log n
 */

