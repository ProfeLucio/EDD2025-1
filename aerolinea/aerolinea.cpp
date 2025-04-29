#include <iostream>
using namespace std;

//Tipo FIFO
struct aerolinea {
    int id;
    char nombre[20];
    struct aerolinea *sig;
};

struct aerolinea *cabAereo = NULL, *auxAereo = NULL, *auxAereo2 = NULL;

struct pasajero {
    int id;
    char nombre[20];
    struct pasajero *sig;
};

struct pasajero *auxpasajero = NULL, *auxpasajero2 = NULL;

struct vuelo {
    int id; 

    struct vuelo *izq;  
    struct vuelo *der;  

    struct aerolinea *mi;
    struct pasajero *cab;
};

struct vuelo *raiz = NULL, *auxvuelo = NULL, *auxvuelo2 = NULL;
