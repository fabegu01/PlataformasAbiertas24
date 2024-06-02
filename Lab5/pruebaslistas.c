#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    char *nombre;
    struct nodo *siguiente;

}Libro;


Libro *listalibro(Libro *lista){
    lista = NULL;
    return lista;
}

Libro *agregarlibro(Libro *lista, char *nombre){

    Libro *agregarLibro;
    agregarLibro = malloc(sizeof(Libro));   
    agregarLibro->nombre = nombre;
    agregarLibro->siguiente = NULL;

    if (lista == NULL) {

        lista = agregarLibro;
    }
    else{

    }
    return lista;
    
   
}

int main(){

  
Libro *lista = listalibro(lista);
lista = agregarlibro(lista, "hola");
printf( "%s\n",lista->nombre);

return 0;


}