#include <stdio.h>

// Función para encontrar el valor mínimo en el arreglo
int encontrarMinimo(int arreglo[], int longitud) {
    int minimo = arreglo[0];
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < minimo) {
            minimo = arreglo[i];
        }
    }
    return minimo;
}

// Función para encontrar el valor máximo en el arreglo
int encontrarMaximo(int arreglo[], int longitud) {
    int maximo = arreglo[0];
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] > maximo) {
            maximo = arreglo[i];
        }
    }
    return maximo;
}

// Función para encontrar el valor mínimo y máximo utilizando punteros
void encontrarMinimoMaximo(int arreglo[], int longitud, int *minimo, int *maximo) {
    *minimo = arreglo[0];
    *maximo = arreglo[0];
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < *minimo) {
            *minimo = arreglo[i];
        }
        if (arreglo[i] > *maximo) {
            *maximo = arreglo[i];
        }
    }
}

int main() {
    int arreglo[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);

   
    int minimo = encontrarMinimo(arreglo, longitud);
    int maximo = encontrarMaximo(arreglo, longitud);

    int minimoPtr, maximoPtr;
    encontrarMinimoMaximo(arreglo, longitud, &minimoPtr, &maximoPtr);


    printf("Valor mínimo encontrado: %d\n", minimo);
    printf("Valor máximo encontrado: %d\n", maximo);

    printf("Valor mínimo encontrado con punteros: %d\n", minimoPtr);
    printf("Valor máximo encontrado con punteros: %d\n", maximoPtr);

    return 0;
}
