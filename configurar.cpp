#include <iostream>
#include <stdlib.h>

using namespace std;

int configurar(){
    int menuConfig=0;
    while(menuConfig==0){
        cout<<"#############################"<<endl;
        cout<<"#       CONFIGURACIÓN       #"<<endl;
        cout<<"#############################"<<endl;
        cout<<endl;
        cout<<"1. Tamaño del tablero"<<endl;
        cout<<"2. Dificultad"<<endl;
        cout<<"3. Zoom"<<endl<<endl;
        cout<<"4. Atrás"<<endl;
        cout<<"Introduce una opción: ";
        cin>>menuConfig;
        
        while( (menuConfig!=1) && (menuConfig!=2) && (menuConfig!=3) && (menuConfig!=4) ){
            cout<<"Introduce opción válida: ";
            cin>>menuConfig;
        }
        if(menuConfig==1){
            cout<<"####JUGAR"<<endl;
        }
        else
        if(menuConfig==2){
            cout<<"####CONFIGURAR"<<endl;  
        }
        else
        if(menuConfig==3){
            cout<<"####ZOOM"<<endl;
        }
    }
    
return 0;
} 