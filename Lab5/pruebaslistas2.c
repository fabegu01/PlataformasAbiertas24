#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int dato;
    struct elemento *siguiente;
} Nodo;

Nodo *crearLista() {
    Nodo *lista = NULL;
    return lista;
}

Nodo *crearNodo(int dato) {
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void agregarNodoFinal(Nodo **lista, int dato) {
    Nodo *nuevoNodo = crearNodo(dato);
    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        Nodo *auxiliar = *lista;
        while (auxiliar->siguiente != NULL) {
            auxiliar = auxiliar->siguiente;
        }
        auxiliar->siguiente = nuevoNodo;
    }
}

void agregarNodoInicio(Nodo **lista, int dato) {
    Nodo *nuevoNodo = crearNodo(dato);
    nuevoNodo->siguiente = *lista;
    *lista = nuevoNodo;
}

void agregarNodo(Nodo **lista, int dato, Nodo *anterior) {
    if (*lista == NULL || anterior == NULL) {
        agregarNodoInicio(lista, dato);
    } else {
        Nodo *nuevoNodo = crearNodo(dato);
        nuevoNodo->siguiente = anterior->siguiente;
        anterior->siguiente = nuevoNodo;
    }
}

void imprimirLista(Nodo *lista) {
    Nodo *actual = lista;
    while (actual != NULL) {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}

void eliminarNodo(Nodo **lista, Nodo *anterior, Nodo *dato) {
    if (*lista == NULL) {
        printf("La lista está vacía, no hay nada que eliminar\n");
        return;
    }

    if (anterior == NULL) {  // El nodo a eliminar es el primero
        *lista = dato->siguiente;
    } else {
        anterior->siguiente = dato->siguiente;
    }
    free(dato);
}

int main() {
    Nodo *lista = crearLista();

    // Agregar nodos al inicio
    printf("Agregando nodos al inicio:\n");
    agregarNodoInicio(&lista, 3);
    agregarNodoInicio(&lista, 2);


    // Imprimir lista después de agregar al inicio
    printf("Lista después de agregar nodos al inicio:\n");
    imprimirLista(lista);
    printf("\n");

    // Agregar nodos al final
    printf("Agregando nodos al final:\n");
    agregarNodoFinal(&lista, 4);
    agregarNodoFinal(&lista, 5);
    

    // Imprimir lista después de agregar al final
    printf("Lista después de agregar nodos al final:\n");
    imprimirLista(lista);
    printf("\n");

    // Agregar un nodo después del primer nodo
    printf("Agregando nodo después del primer nodo (con valor 10):\n");
    agregarNodo(&lista, 10, lista);

    // Imprimir lista después de agregar nodo en posición específica
    printf("Lista después de agregar nodo después del primer nodo:\n");
    imprimirLista(lista);
    printf("\n");

    // Eliminar un nodo
    printf("Eliminando el segundo nodo (valor original 2):\n");
    eliminarNodo(&lista, lista, lista->siguiente);

    // Imprimir lista después de eliminar un nodo
    printf("Lista después de eliminar un nodo:\n");
    imprimirLista(lista);
    printf("\n");

    // Liberar memoria de la lista restante
    while (lista != NULL) {
        Nodo *temp = lista;
        lista = lista->siguiente;
        free(temp);
    }

    return 0;
}




