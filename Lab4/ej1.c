#include <stdio.h>

// Declaración de funciones
void BuscarValor(int valores[], int cantidad, int valor);


void BuscarValor(int valores[], int cantidad, int valor ) {
    int posicion = -1;
        for (int i = 0; i < cantidad; i++) {
        if (valor == valores[i]) {
            posicion = i;
            printf("El valor  %d se encontró en la posición %d .\n", valor, posicion);
            return; 
        }
    }

    
    if (posicion == -1) {
        printf("El valor %d no se encontró en el arreglo.\n", valor);
  
      }


    
} 

int busquedaBinaria(int array[], int cantidad , int valor) {
    int inicio = 0;
    int fin = cantidad - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (array[medio] == valor) {
            return medio;
        }
        if (array[medio] < valor) {
            inicio = medio + 1; 
        } else {
            fin = medio - 1; 
        }
    } 

    return -1; 
}


int busquedaRecursiva(int array[], int inicio, int fin, int valor) {
    if (inicio > fin) {
        return -1; // El valor no se encontró en el arreglo
    }
    if (array[inicio] == valor) {
        return inicio; // Se encontró el valor en la posición 'inicio'
    }
    return busquedaRecursiva(array, inicio + 1, fin, valor); // Llamada recursiva con el siguiente elemento
}


int main() {
    int valor;
    int valores[] = {2, 4, 6, 23, 56, 79};
    int cantidad = sizeof(valores) / sizeof(valores[0]); 
    printf("ingrese el valor que desea buscar: ");
    scanf("%d",&valor );

    int resultadoRecursivo = busquedaRecursiva(valores, 0, cantidad-1, valor);
    int resultadoBinario = busquedaBinaria(valores, cantidad,valor);

    if (resultadoBinario != -1) {
        printf("El valor %d se encontró en la posición %d.\n", valor, resultadoBinario);
    } else {
        printf("El valor %d no se encontró en el arreglo.\n", valor);
    }
    BuscarValor(valores, cantidad, valor);

    if (resultadoRecursivo != -1) {
        printf("El valor %d se encontró en la posición %d.\n", valor, resultadoBinario);
    } else {
        printf("El valor %d no se encontró en el arreglo.\n", valor);
    }

    return 0;
}
