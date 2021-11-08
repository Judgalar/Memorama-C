#include <iostream>
#include <string>
using namespace std;

int main()
{
    int tablesize;
    char columna ='A';
    int fila = 1;
    string celda ="   |";
    string salto ="----";

    cout<<"INTRODUCE TAMAÑO DEL TABLERO = ";
    cin >> tablesize;

/*Tablero*/
    cout<<celda;
        for(int j=1; j<=tablesize; j++){
            cout<<" "<<columna<<" |";
            columna++;
        }
        cout<<endl;
        for(int j=1;j<=tablesize+1; j++){
            cout<<salto;
        }
        cout<<endl;
    for(int i=1; i<=tablesize; i++){
        cout<<" "<<fila<<" |";
        fila++;
        for(int j=1; j<tablesize+1; j++){
            cout<<celda;
        }
        cout<<endl;
        for(int j=1;j<=tablesize+1; j++){
            cout<<salto;
        }
        cout<<endl;
    }
    char matriz[4][4];
    matriz[1][1]= 'x';
    cout<< matriz[1][1];


 
}
