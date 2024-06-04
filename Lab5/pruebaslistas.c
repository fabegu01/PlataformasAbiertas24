#include <stdio.h>
#include <stdlib.h>

//primero se realiza la variable de estructura
typedef struct nodo{
    char *nombre;
    struct nodo *siguiente;//recursividad, por que con esta funcion se apunta al siguiente elemento que tambien es del tipo variable de estructura

}Libro;//en este caso van a ser libros

// hacemos una funcion para crear la lista de "libros"
Libro *listalibro(Libro *lista){// variable tipo libro, funcion que recibe una variable tipo libro que se llama lista, y que va a comenzar como nula
    lista = NULL;// la lista se inicia vacia
    return lista;
}
//funcion de agregar, variable tipo libro 
Libro *agregarlibro(Libro *lista, char *nombre){//funcion que recibe lista de tipo libro y el nombre que se le va a asignar al libro nuevo

    Libro *nuevoLibro, *auxiliar;// nuevoLibro tipo libro, auxiliar tipo libro para poder agregar nuevos elementos a la lista
    nuevoLibro = malloc(sizeof(Libro));// reservamos el espacio en memoria para almacenar lo que queremos, cuyo tama;o debe ser el mismo que la variable estructural   
    nuevoLibro->nombre = nombre;//le asignamos nombre al puntero nombre de la variable nuevoLibro e tipolibro
    nuevoLibro->siguiente = NULL;//le asignamos el nulo a la siguiente varible de tipo libro que tenemos en la lista
    auxiliar=lista;// variable auxiliar para revisar los campos de la lista
    if (lista == NULL) { //en el caso de que la lista este vacia

        lista = nuevoLibro; //le agregamos a la lista nuestro nuevo libro 
    }
    else{ // en el caso de que la lista no este vacia
        while(auxiliar->siguiente != NULL){//mientras la variable siguiente sea nula
        auxiliar->siguiente;//pasamos a la siguiente variable de la lista para revisar si esta vacia o no
    }// cuando se encuentre el espacio vacio dejamos de buscar, entonces procedemos a asignarle a auxiliar->siguiente=nuevoLibro, porque nuevoLibrocontiene, nuevoLibro->nombre=nombre y nuevoLibro->siguiente=NULL
    auxiliar->siguiente= nuevoLibro;// cuando se encuentre el espacio vacio se le asigna a siguiente la varible nuevoLibro de tipo libro
       

    }
    return lista;//retonarmos la lista
    
   
}
Libro *quitarlibro(Libro *lista, char *nombre){//funcion para quitar libro, que recibe la lista de libros y el nombre del libro que se quiere eliminar

    Libro *actual = lista;//nombramos una variable que contenga el inicio de la lista, llamada lista.
    Libro *anterior = NULL;//hacemos una varaible que apunte a null inicialmente porque el anterior a la inicial no apunta a nada y vamos actualizando su valor segun vayamos avanzando en la lista

    while((actual != NULL) && (actual->nombre != nombre)){//mientras el actual sea diferente de lo nulo y mientras no encontremos el dato que estamos buscando

        anterior = actual;//actualizamos la variable anterior como la siguiente para ir revisando todos los valores de la lista
        actual = actual->siguiente;//actualizamos el valor de actual como el siguiente al actual para revisar todos los valores de la lista
    }//si salimos del while sera por que

    if (actual == NULL){ // llegamos al final de la lista y no encontramos nunca el valor
            printf("No se encontro el dato buscado ");
            return lista;
    }
    if (anterior == NULL){// si anterior es nulo significa que el valor que se quiere eliminar es la cabeza de la lista entonces
         lista= actual->siguiente;//actualizamos el primer valor de la lista como la siguiente variable a la cabeza
         free(actual);//liberamos el espacio que estaba ocupando la variable
       
    }else{// si no es nignuno de los casos anteriores y salimos del while porque encontramos el nombre en la lista entonces
        anterior->siguiente = actual->siguiente;//hacemos que la variable anterior actual apunte hacia la variable siguiente de la varaible actual para relacionarlas entre si.
        
    }
    free(actual);//liberamos el espacio que estba ocupando la variable actual
    return lista;
}
void imprimirLista(Libro *lista) {
    Libro *auxiliar = lista;
    while (auxiliar != NULL) {
        printf("%s\n", auxiliar->nombre);
        auxiliar = auxiliar->siguiente;
    }
}


int main(){

    Libro *lista = listalibro(lista);
    lista = agregarlibro(lista, "HOLA");
    lista = agregarlibro(lista, "Hello");
    lista = agregarlibro(lista, "HALO");
    printf("la lista es: \n");
    imprimirLista(lista);

    lista= quitarlibro(lista, "Hello");
    printf("la lista despues de eliminar a Hello: \n");
    imprimirLista(lista);

   
    while (lista != NULL) {
        Libro *temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
    return 0;


}