#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int nFilas, nColumnas;

void datosInicio(){

 
}

void desordenar(int *cartas, int filas, int columnas){

    
}

int main()
{

 srand(time(NULL));

    int num=0;
    int columna =1;
    int fila = 1;
    string celda ="   |";
    string salto ="----";

    cout<<"INTRODUCE TAMAÑO DEL TABLERO (x*x=par)"<<endl;
    cout<<"Filas = "; cin >> nFilas; cout << " Columnas = "; cin >> nColumnas;

    while( (nFilas*nColumnas)%2 != 0 ){
        cout<<"INTRODUCE TAMAÑO DEL TABLERO (x*x=par) = ";
        cout<<"Filas = "; cin >> nFilas; cout << " Columnas = "; cin >> nColumnas;
    }

 //Tablero inicial
    cout<<celda;
        for(int j=1; j<=nColumnas; j++){
            cout<<" "<<columna<<" |";
            columna++;
        }
        cout<<endl;
        for(int j=1;j<=nColumnas+1; j++){
            cout<<salto;
        }
        cout<<endl;
    for(int i=1; i<=nFilas; i++){
        cout<<" "<<fila<<" |";
        fila++;
        for(int j=1; j<nColumnas+1; j++){
            cout<<celda;
        }
        cout<<endl;
        for(int j=1;j<=nColumnas+1; j++){
            cout<<salto;
        }
        cout<<endl;
    }

// array parejas

    int simbolo=0;
    int cartas[nFilas*nColumnas];

    for(int i=0;i<(nFilas*nColumnas);i=i+2){
        cartas[i]=simbolo;
        cartas[i+1]=simbolo;
        simbolo++;
    }

    
cout<<endl<<"COMPROBACION PAREJAS"<<endl;
    for(int i=0;i<(nFilas*nColumnas);i++){
        cout<<cartas[i];
    }
  







 // FIN DEL PROGRAMA
 cout<<endl<<endl;
 int salida;
 cin >> salida;
 return 0;
}