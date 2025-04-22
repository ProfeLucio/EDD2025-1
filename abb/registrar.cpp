#include <iostream>
using namespace std;

struct nodo {
    int value;
    struct nodo *izq;
    struct nodo *der;
};

struct nodo *raiz, *aux;

void posicionarNodo(struct nodo *nuevaRaiz){
    if(aux->value<nuevaRaiz->value){
        if(nuevaRaiz->izq == NULL) {
            nuevaRaiz->izq = aux;
        } else {
            posicionarNodo(nuevaRaiz->izq);
        }
    } else {
        if(nuevaRaiz->der == NULL) {
            nuevaRaiz->der = aux;
        } else {
            posicionarNodo(nuevaRaiz->der);
        }
    }
    
}
void adicionarNodo(){
    aux = (struct nodo *) malloc(sizeof(struct nodo));
    aux->izq = aux->der = NULL;
    cout<<"Digite el valor del nodo:";
    cin>>aux->value;
    if(raiz==NULL){
        raiz = aux;
        aux = NULL;
        free(aux);
    }
    else {
        posicionarNodo(raiz);
    }
}

int mostrarNodo(struct nodo *nuevaRaiz){
    
    if(nuevaRaiz->izq!=NULL){
        mostrarNodo(nuevaRaiz->izq);
    }
    cout<<"Valor nodo: "<<nuevaRaiz->value<<endl;
    if(nuevaRaiz->der!=NULL){
        mostrarNodo(nuevaRaiz->der);  
    }
}

int main(){
    int opcion=0;
    do {
        cout<<"1. Registrar"<<endl;
        cout<<"2. Mostrar"<<endl;
        cout<<"Digite la opción: ";
        cin>>opcion;
        switch(opcion){
            case 1: adicionarNodo(); break;
            case 2: mostrarNodo(raiz); break;
        }
    }while(opcion!=5);
}
