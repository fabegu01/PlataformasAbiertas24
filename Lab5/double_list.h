#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef struct elemento {
    int dato;
    struct elemento *siguiente;
    struct elemento *anterior;
} Nodo;

Nodo* CrearNodo(int dato);
Nodo* CrearLista();
void agregarNodoinicio(Nodo** lista, int dato);
void agregarNodoFinal(Nodo** lista, int dato);
void agregarConIndice(Nodo** lista, int dato, int indice);
void eliminarNodo(Nodo** lista, int dato);
Nodo* BuscarNodo(Nodo* lista, int dato);
void imprimirListaAdelante(Nodo* lista);
void imprimirListaAtras(Nodo* lista);

#endif
