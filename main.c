#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TDA-ListaDin.h"

Lista *crearLista(){
	Lista *L;
	L = (Lista *) malloc(sizeof(Lista));
    if (L!=NULL) {
        L->head=NULL;
        L->n=0;
    }else{
        printf("ERROR: MEMORIA LISTA NO ASIGNADA"); 
    }
    return L;

}
void insertarNodoIni(Lista *L, int val){ 
    Nodo  *newN;
	newN = (Nodo *) malloc(sizeof(Nodo));
    if (newN != NULL ) {
    	newN->info = val;//asignar valor del nuevo nodo
    	if (L->head==NULL) {   //INSERTAR LISTA VACIA
    	  newN->sig=NULL;
    	  L->head=newN;
        }else{   //INSERTAR UNA LISTA NO VACIA
          newN->sig = L->head;
    	  L->head=newN;
		}
		L->n++;
    }else{
        printf("ERROR: MEMORIA NUEVO NODO NO ASIGNADA"); 
    }
}
void recorrerLista(Lista *L){
    Nodo *aux;
    aux = L->head;
    printf("\n Valores de la Lista: ");
    while (aux != NULL){
        printf("%d  ", aux->info); 
        aux = aux->sig;
    }
    printf("\n");
	
}

Nodo *ultimo(Lista *L){
    Nodo *aux;
    aux = L->head;
    while (aux->sig != NULL){
        aux = aux->sig;
    }
	return aux; //devuelve la direcciÃ³n de memoria del Ãºltimo nodo
}
Nodo *penultimo(Lista *L){
    Nodo *aux;
    aux = L->head;
    while (aux->sig->sig != NULL){
        aux = aux->sig;
    }
	return aux; //devuelve la direcciÃ³n de memoria del penÃºltimo nodo
}

void insertarNodoFin(Lista *L, int val){ 
    Nodo  *newN, *aux;
	newN = (Nodo *) malloc(sizeof(Nodo));
    if (newN != NULL ) { //se asignÃ³ memoria al nuevo nodo
    	newN->info = val;//asignar valor del nuevo nodo
    	if (L->head==NULL) {   //INSERTAR LISTA VACIA
			newN->sig=NULL;
			L->head=newN;
        }else{   //INSERTAR UNA LISTA NO VACIA
			aux = ultimo(L); 
			aux->sig = newN;
		}
		L->n++;
    }else{
        printf("ERROR: MEMORIA NUEVO NODO NO ASIGNADA"); 
    }
}

int eliminarNodoIni(Lista *L){
    Nodo  *aux;
	int val_elim;
	if (L->head != NULL ) { //Si no es lista vacÃ­a
		aux = L->head;
		L->head = L->head->sig; //la cabeza se mueve al nodo siguiente del inicio
		aux->sig = NULL;
		val_elim = aux->info;
		free(aux);
		L->n--;
		return val_elim;
	}
}


int eliminarNodoFin(Lista *L){
	if (L->head != NULL ) { //Si no es lista vacÃ­a
		int val_elim;
		if (L->head->sig == NULL ) { //lista tiene un solo nodo
			val_elim = L->head->info;
			free(L->head);
		}else{
			Nodo  *aux,*auxE;
			aux = penultimo(L); 
			auxE = aux->sig;
			aux->sig = NULL;
			val_elim = auxE->info;
			free(auxE);
			L->n--;
			return val_elim;
		}
	}
}


void destruirLista(Lista *L){
    Nodo *aux;
    while (L->head != NULL) {
		aux = L->head;
		L->head=L->head->sig;
		free(aux);
    }
    free(L);
}


int main(void) {
    Lista *lis;
    lis = crearLista();
    int index = 0;
    char aux;
    FILE* fp = fopen("1.txt", "r");
    while (aux != EOF){
        index++;
        aux = fgetc(fp);
        if( index == 1){
            printf("%c", aux);
        }
        else{
            insertarNodoFin(lis, aux);
        }
    }
    fclose(fp);
    
    return 0;
}
