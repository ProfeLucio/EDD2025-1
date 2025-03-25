#include <iostream>
using namespace std;

// Estructura del nodo
struct nodo {
    int valor;         // Valor que almacena el nodo
    struct nodo *sig;  // Puntero al siguiente nodo
};

// Punteros globales para manipular la lista
struct nodo *top = NULL, *aux = NULL, *aux2 = NULL;

int addNodo(){
    aux = ((struct nodo *) malloc(sizeof(struct nodo)));
    cout<<"Digite Nodo: ";
    cin>>aux->valor;
    if(top==NULL){
        top = aux;
        top->sig = NULL;
    }
    else {
        aux->sig = top;
        top = aux;
    }
    aux = NULL;
    free(aux);    
}


void viewNodos() {    
    for (aux = top; aux != NULL; aux = aux->sig) {
        cout << "El valor del nodo es: " << aux->valor << endl;
    }
}

// Función para buscar un valor en la lista
int searchNodo() {
    int seed;
    cout << "Digite el numero a buscar: ";
    cin >> seed;

    // Recorre la lista comparando el valor
    for (aux = top; aux != NULL; aux = aux->sig) {
        if (aux->valor == seed) {
            aux =  NULL; // Se limpian los punteros auxiliares
            free(aux);          // Se libera la memoria de aux
            return 1;  // Valor encontrado
        }
    }
    aux =  NULL; // Se limpian los punteros auxiliares
    free(aux);          // Se libera la memoria de aux
    return 0; // Valor no encontrado
}


int main(){
    int band, opc;

    do {
        // Muestra menú al usuario
        cout << "\n==== MENÚ LIFO ====\n";
        cout << "1. Adicionar nodo\n";
        cout << "2. Mostrar\n";
        cout << "3. Buscar nodo\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opc;

        switch(opc) {
            case 1:
                addNodo();
                break;
            case 2:
                viewNodos();
                break;
            case 3:
                band = searchNodo();
                if (band)
                    cout << "Nodo encontrado.\n";
                else
                    cout << "No encontrado.\n";
                break;
        }

    } while(opc != 5);
}