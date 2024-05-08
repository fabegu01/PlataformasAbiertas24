#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos de funciones
void llenarMatriz(int dim, int matriz[dim][dim]);
void imprimirMatriz(int dim, int matriz[dim][dim]);
int encontrarCuadrado(int dim, int matriz[dim][dim]);

int main() {
    srand(time(NULL));
    int dim;
    printf("Ingrese la dimensión de la matriz (máximo 10): ");
    scanf("%d", &dim);

    if (dim < 1 || dim > 10) {
        printf("Número de dimensión no válido. Se utilizará un valor por defecto.\n");
        dim = 5; // Valor por defecto
    }

    int matriz[10][10]; // El tamaño máximo de la matriz será de 10x10

    llenarMatriz(dim, matriz);

    printf("La matriz generada es:\n");
    imprimirMatriz(dim, matriz);

    int maximo = encontrarCuadrado(dim, matriz);

    printf("El tamaño del cuadrado más grande es: %d x %d.\n", maximo, maximo);

    return 0;
}

void llenarMatriz(int dim, int matriz[dim][dim]) {
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            matriz[i][j] = rand() % 2;
        }
    }
}

void imprimirMatriz(int dim, int matriz[dim][dim]) {
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int encontrarCuadrado(int dim, int matriz[dim][dim]) {
    int maximo = 0;
    int i, j, k, l;
    int tam;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            // Verificar si el cuadrado de lado 'tam' es homogéneo
            for (tam = 1; tam <= dim - i && tam <= dim - j; tam++) {
                int esHomogeneo = 1;

                // Verificar si todos los elementos del cuadrado son iguales
                for (k = i; k < i + tam; k++) {
                    for (l = j; l < j + tam; l++) {
                        if (matriz[k][l] != matriz[i][j]) {
                            esHomogeneo = 0;
                            break;
                        }
                    }
                    if (!esHomogeneo) break;
                }

                if (esHomogeneo && tam > maximo) {
                    maximo = tam;
                }
            }
        }
    }

    return maximo;
}


            
    
            


    

    




