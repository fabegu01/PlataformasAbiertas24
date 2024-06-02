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


int main ()
{    
Libro *lista = listalibro(lista);

printf( "%p", lista);

return 0;


}