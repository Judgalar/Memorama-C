#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{

 srand(time(NULL));

    int nFilas, nColumnas;
    int num=0;
    int columna =1;
    int fila = 1;
    string celda ="   |";
    string salto ="----";

    cout<<"INTRODUCE TAMAÑO DEL TABLERO (x*x=par)"<<endl;
    cout<<"Filas = "; cin >> nFilas; cout << "Columnas = "; cin >> nColumnas;

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

    
cout<<endl<<"COMPROBACION PAREJAS"<<endl;   //
    for(int i=0;i<(nFilas*nColumnas);i++){
        cout<<cartas[i];
    }
    cout<<endl<<endl;

cout<< "rands"<<endl;   //
    int x;
    for(int i=0; i<(nFilas*nColumnas); i++){
        int aleatorio = rand() % (nFilas*nColumnas);
cout << aleatorio << "-";   //
        x = cartas[aleatorio];
        cartas[aleatorio] = cartas[i];
        cartas[i] = x;
    }


cout<<endl<<"COMPROBACION PAREJAS aleatorias "<<endl; //
    for(int i=0;i<(nFilas*nColumnas);i++){
        cout<<cartas[i];
    }

 // Matriz
    int matriz[nFilas][nColumnas];
    int indCartas = 0;
    for(int i=0; i<nFilas; i++){
        for(int j=0; j<nColumnas; j++){
            matriz[i][j] = cartas[indCartas];
            indCartas++;
        }
    }

cout<<endl<<endl<<"COMPROBACION PASO A MATRIZ"<<endl; //
 for(int i=0; i<nFilas; i++){
        for(int j=0; j<nColumnas; j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }







 // FIN DEL PROGRAMA
 cout<<endl<<endl;
 int fin;
 cin >> fin;
 return 0;
}
