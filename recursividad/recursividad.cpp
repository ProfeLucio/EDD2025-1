#include <iostream>
using namespace std;

int factorial(int valor){
    if (valor==0){
        return 1;
    }
    else {
        cout<<"Valor: "<<valor<<endl;
        return valor * factorial(valor - 1);
    }
}

int main(){
    int value;
    cout<<"Valor a calcular: ";
    cin>>value;
    value = factorial(value);
    cout<<endl<<"El Factorial es: "<<value;
    return 0;
}