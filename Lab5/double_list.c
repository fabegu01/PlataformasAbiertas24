#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

Nodo* CrearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo != NULL) {
        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = NULL;
        nuevoNodo->anterior = NULL;
    }
    return nuevoNodo;
}

Nodo* CrearLista() {
    return NULL;
}

void agregarNodoinicio(Nodo** lista, int dato) {
    Nodo* nuevoNodo = CrearNodo(dato);
    if (nuevoNodo != NULL) {
        if (*lista == NULL) {
            *lista = nuevoNodo;
        } else {
            nuevoNodo->siguiente = *lista;
            (*lista)->anterior = nuevoNodo;
            *lista = nuevoNodo;
        }
    }
}

void agregarNodoFinal(Nodo** lista, int dato) {
    Nodo* nuevoNodo = CrearNodo(dato);
    if (nuevoNodo != NULL) {
        if (*lista == NULL) {
            *lista = nuevoNodo;
        } else {
            Nodo* auxiliar = *lista;
            while (auxiliar->siguiente != NULL) {
                auxiliar = auxiliar->siguiente;
            }
            auxiliar->siguiente = nuevoNodo;
            nuevoNodo->anterior = auxiliar;
        }
    }
}

void agregarConIndice(Nodo** lista, int dato, int indice) {
    Nodo* nuevoNodo = CrearNodo(dato);
    if (nuevoNodo != NULL) {
        if (*lista == NULL || indice <= 0) {
            agregarNodoinicio(lista, dato);
        } else {
            Nodo* auxiliar = *lista;
            for (int i = 0; i < indice - 1 && auxiliar->siguiente != NULL; i++) {
                auxiliar = auxiliar->siguiente;
            }
            nuevoNodo->siguiente = auxiliar->siguiente;
            nuevoNodo->anterior = auxiliar;
            if (auxiliar->siguiente != NULL) {
                auxiliar->siguiente->anterior = nuevoNodo;
            }
            auxiliar->siguiente = nuevoNodo;
        }
    }
}

void eliminarNodo(Nodo** lista, int dato) {
    if (*lista != NULL) {
        Nodo* auxiliar = *lista;
        while (auxiliar != NULL && auxiliar->dato != dato) {
            auxiliar = auxiliar->siguiente;
        }
        if (auxiliar != NULL) {
            if (auxiliar->anterior != NULL) {
                auxiliar->anterior->siguiente = auxiliar->siguiente;
            } else {
                *lista = auxiliar->siguiente;
            }
            if (auxiliar->siguiente != NULL) {
                auxiliar->siguiente->anterior = auxiliar->anterior;
            }
            free(auxiliar);
        }
    }
}

Nodo* BuscarNodo(Nodo* lista, int dato) {
    Nodo* auxiliar = lista;
    while (auxiliar != NULL && auxiliar->dato != dato) {
        auxiliar = auxiliar->siguiente;
    }
    return auxiliar;
}

void imprimirListaAdelante(Nodo* lista) {
    Nodo* auxiliar = lista;
    while (auxiliar != NULL) {
        printf("%d ", auxiliar->dato);
        auxiliar = auxiliar->siguiente;
    }
    printf("\n");
}

void imprimirListaAtras(Nodo* lista) {
    Nodo* auxiliar = lista;
    if (auxiliar != NULL) {
        while (auxiliar->siguiente != NULL) {
            auxiliar = auxiliar->siguiente;
        }
        while (auxiliar != NULL) {
            printf("%d ", auxiliar->dato);
            auxiliar = auxiliar->anterior;
        }
    }
    printf("\n");
}
