#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int num;
    int num2;
    int casillaRandom;
    int tablesize;
    int filaJugador1, columnaJugador1,filaJugador2, columnaJugador2;
    int columna =1;
    int fila = 1;
    char letra='A';
    string celda ="   |";
    string salto ="----";

    cout<<"INTRODUCE TAMAÑO DEL TABLERO (x*x=par) = ";
    cin >> tablesize;
    while( (tablesize*tablesize)%2 != 0 ){
     cout<<"INTRODUCE TAMAÑO DEL TABLERO (x*x=par) = ";
     cin>>tablesize; 
    }
   
    
//Tablero inicial
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

    int matriz[tablesize][tablesize];
    char parejasAleatorias[tablesize*tablesize];
    bool cadena[tablesize*tablesize]; for(int i=0; i<(tablesize*tablesize); i++) cadena[i]=0; // cadena booleana con todos los números establecidos a 0

    for(int i=0; i<(tablesize*tablesize)/2; i++){ //HACER UNA FUNCION
        num=rand() % (tablesize*tablesize);
        num2=rand() % (tablesize*tablesize);
        parejasAleatorias[num]=letra; cadena[num]=1;
        while(num==num2) num2=rand() % (tablesize*tablesize);
        parejasAleatorias[num2]=letra; cadena[num2]=1;
    }

    cout<<"Introduce fila = ";
    cin>>filaJugador1;
    cout<<"Introduce columna = ";
    cin>>columnaJugador1;
    cout<<matriz[filaJugador1][columnaJugador1];
    cout<<"Introduce fila = ";
    cin>>filaJugador2;
    cout<<"Introduce columna = ";
    cin>>columnaJugador2;
    cout<<matriz[filaJugador2][columnaJugador2];
    
    if(matriz[filaJugador1][columnaJugador1]==matriz[filaJugador2][columnaJugador2]) cout<<"has acertado";

 

 // FIN DEL PROGRAMA
 cout<<endl<<endl;
 system("pause");
 return 0;
}
