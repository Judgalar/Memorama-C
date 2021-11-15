#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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
    int carta=1;
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
    int parejasAleatorias[tablesize*tablesize];
    bool cadena[tablesize*tablesize]; for(int i=0; i<(tablesize*tablesize); i++) cadena[i]=0; // cadena booleana con todos los números establecidos a 0

    for(int i=0; i<(tablesize*tablesize)/2; i++){ //HACER PAREJAS
        num=rand() % (tablesize*tablesize);
        cout<<num; // cmprobacion
        if(cadena[num]=0){
            parejasAleatorias[num]=carta;
            cadena[num]=1;
            carta++;
        }
    }
//comprobacion
for(int i=0; i<(tablesize*tablesize);i++) cout<<parejasAleatorias[i]<<",";
cout<<endl;
for(int i=0; i<(tablesize*tablesize);i++) cout<<cadena[i]<<",";

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





 // FIN DEL PROGRAMA
 cout<<endl<<endl;
 system("pause");
 return 0;
}
