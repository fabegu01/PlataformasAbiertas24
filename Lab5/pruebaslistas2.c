#include <stdio.h>
#include <stdlib.h>



typedef struct elemento{
    int dato;
    struct elemento *siguiente
}Nodo;


Nodo *crearlista(){
    Nodo *lista = NULL;
    return lista;
}


Nodo *CrearNodo( int dato){

    Nodo *nuevoNodo;
    nuevoNodo = malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;

    }   

void *agregarNodoFinal(Nodo **lista, int dato){//agregar nodo al final

    Nodo *auxiliar;
    auxiliar = *lista;
    Nodo *nuevoNodo = CrearNodo(dato);
    if (lista == NULL){//significa que la lista esta vacia entonces
        *lista = nuevoNodo;
    }
    else{// la lista no esta vacia
        while(auxiliar->siguiente != NULL);//mientras no encontremos un espacio vacio pasamos a la siguiente variable
        auxiliar= auxiliar->siguiente;
    }// si se sale del while es porque encontro un espacio NULL
        auxiliar->siguiente=nuevoNodo;

}

void *agregarNodoinicio( Nodo **lista, int dato){//agregar nodo al principio

    Nodo *nuevoNodo =CrearNodo(dato), *actual, *anterior;//creamos un nuevo nodo con la funcion crear nodo, y dos variables que nos ayudaran
    actual = *lista;//varaible que apunta al primer valor de la lista de nodos
    anterior = NULL;//valor anterior que apunta a nulo
       if (actual == NULL){//significa que la lista esta vacia entonces
        CrearNodo(dato);
        }
        else{//la lista no esta vacia 
        anterior = nuevoNodo;//ahora la variable anterior sera el nuevo nodo y el principio de la lista
        anterior->siguiente=actual;//actualizamos el valor al que va a apuntar el nuevo inicio que es hacia toda la lista que habia
        *lista = anterior;
        }

}
void *Nodoagregar(Nodo **lista,int dato, Nodo *anterior ){

    Nodo *nuevoNodo = CrearNodo(dato);
    if(*lista==NULL || anterior == NULL){
        agregarNodoinicio(lista , dato); 

    }
    else{
        nuevoNodo->siguiente=anterior->siguiente;
        anterior->siguiente=nuevoNodo;
    }

}


     



