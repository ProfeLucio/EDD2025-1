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

// Busca el nodo con su padre; deja el resultado en 'aux' y el padre en 'padre'
nodo* buscarConPadre(nodo *actual, int clave, nodo **padre) {
    *padre = NULL;
    while (actual != NULL) {
        if (actual->value == clave) {
            aux = actual;            // usamos aux como "target"
            return aux;
        }
        *padre = actual;
        if (clave < actual->value)
            actual = actual->izq;
        else
            actual = actual->der;
    }
    aux = NULL;
    return NULL;
}

void eliminarNodo() {
    if (raiz == NULL) {
        cout << "El árbol está vacío.\n";
        return;
    }

    int clave;
    cout << "Digite el valor a eliminar: ";
    cin  >> clave;

    nodo *padre = NULL;
    buscarConPadre(raiz, clave, &padre);
    if (aux == NULL) {
        cout << "Nodo con valor " << clave << " no encontrado.\n";
        return;
    }

    // Caso de dos hijos: no implementado
    if (aux->izq != NULL && aux->der != NULL) {
        cout << "El nodo tiene dos hijos; este caso no está implementado.\n";
        return;
    }

    // Determinar único hijo (o NULL si es hoja)
    nodo *hijo = (aux->izq != NULL) ? aux->izq : aux->der;

    // Ajustar el puntero del padre (o raíz)
    if (padre == NULL) {
        // Eliminando la raíz
        raiz = hijo;
    }
    else if (padre->izq == aux) {
        padre->izq = hijo;
    }
    else {
        padre->der = hijo;
    }

    free(aux);
    aux = NULL;
    cout << "Nodo eliminado correctamente.\n";
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
            case 3: eliminarNodo(); break;
        }
    }while(opcion!=5);
}
