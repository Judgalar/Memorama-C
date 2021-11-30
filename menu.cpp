#include <iostream>
#include <stdlib.h>

using namespace std;

int menu(){
    int menuIndex=0;
    while(menuIndex==0){
        cout<<"#############################"<<endl;
        cout<<"#                           #"<<endl;
        cout<<"#         MEMORIÓN          #"<<endl;
        cout<<"#                           #"<<endl;
        cout<<"#############################"<<endl;
        cout<<endl;
        cout<<"1. Jugar"<<endl;
        cout<<"2. Configuración"<<endl;
        cout<<"3. Salir"<<endl<<endl;
        cout<<"Introduce una opción: ";
        cin>>menuIndex;
        
        while( (menuIndex!=1) && (menuIndex!=2) && (menuIndex!=3)){
            cout<<"Introduce opción válida: ";
            cin>>menuIndex;
        }
        if(menuIndex==1){
            cout<<"####JUGAR"<<endl;
        }
        else
        if(menuIndex==2){
            cout<<"####CONFIGURAR"<<endl;  
        }
    }
    
return 0;
}