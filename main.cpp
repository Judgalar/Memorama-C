#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;


void limpiarPantalla(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void esperar(int x){
    #ifdef _WIN32
        Sleep(x*1000);
    #else
        sleep(x);
    #endif
}

void mostrarTablero( string **qMatriz , int filas , int columnas , bool **qcartasLevantadas , int zoom ){

    int indiceFila = 1, indiceColumna = 1;
    string salto ="----";
    
    for(int j=1 ; j<zoom ; j++) salto = salto+"-";

    for(int j=1 ; j<zoom ; j++) cout<<" ";
    cout<<"   |";
    for(indiceColumna=1 ; indiceColumna<=columnas ; indiceColumna++){    //INDICE DE COLUMNAS
        cout<<" ";
        for(int j=0 ; j<zoom ; j++) cout<<indiceColumna;
        cout<<" |";
    }
    cout<<endl;

    for(int j=0 ; j<=columnas ; j++){  //------------------
        cout<<salto;
    }
    cout<<endl;


    for(int i=0 ; i<filas ; i++){
        for(int x=0 ; x<zoom ; x++){
            //indice de fila
            cout<<" ";
            for(int z=0 ; z<zoom ; z++) cout<<indiceFila;
            cout<<" |";

            for (int j=0 ; j<columnas ; j++){

                if(qcartasLevantadas[i][j]==1){
                    cout<<" ";
                    for(int z=0 ; z<zoom ; z++) cout<<qMatriz[i][j];
                    cout<< " |";     
                }    
                else{  
                    cout<<" ";
                    for(int z=0 ; z<zoom ; z++) cout<<"?";
                    cout<<" |";
                }

            }

            cout<<endl;
                
        }
        cout<<endl;
        indiceFila++;
    }

}

void pedirCoordenadas(int &i, int &j, char variable , char variable2 , int nFilas , int nColumnas){
    cout << "Introduce fila = ";
    cin >> variable;
    while (  (isdigit(variable) == 0) || (variable-48>nFilas) || (variable-48<1)  ){
        cout<<"Introduce fila valida = ";
        cin>>variable;
    }
    i=variable-48;
    cout << "Introduce columna = ";
    cin >> variable2;
    while(  (isdigit(variable2) == 0) || (variable2-48>nColumnas) || (variable2-48<1)  ){
        cout<<"Introduce columna valida = ";
        cin>>variable2;
    }
    j=variable2-48;
    
    i--;j--;
    
    cout<<i+1<<"-"<<j+1;
    cout<<endl;
}

void pedirRangoNumeros( int &variable , char introducido , int minimo , int maximo , string fallo ){ // Captura perfecta de un numero mayor que el tercer argumento y menor que el cuarto
    cin >> introducido;
    while(  (introducido < minimo+48) || (introducido > maximo +48)  ){
        cout<<fallo;
        cin >> introducido;
    }
    variable=introducido-48;

}


int main(){

 srand(time(NULL));

    char variableAscii = 0;
    int i1, j1, i2, j2;
    int nFilas = 4, nColumnas = 4;
    int num=0;
    int score = 0;
    int turno = 1;
    int puntosJugador = 0;
    int puntosMaquina = 0;
    int dificultad = 3;
    bool dificultad2 = 0;
    bool dificultad4 = 0;
    int zoom = 2;
    bool erroresActivado = 0;
    int errores = 0;
    int erroresPermitidos = 5;
    int segundos = 3;
    string fallo = "Introduce opcion valida: ";

    int menuIndex=0;
    int menu=1;

    while(menu==1){
        limpiarPantalla();
        cout<<"#############################"<<endl;
        cout<<"#                           #"<<endl;
        cout<<"#         MEMORAMA          #"<<endl;
        cout<<"#                           #"<<endl;
        cout<<"#############################"<<endl;
        cout<<endl;
        cout<<"Numero de Filas: "<<nFilas<<"    Numero de Columnas: "<<nColumnas<<"    Dificultad: "<<dificultad<<"    Zoom: "<<zoom<<endl;
        cout<<"Segundos que se muestra una pareja erronea: "<<segundos<<endl;
        cout<<"Jugar con errores :";
        if(erroresActivado==1) cout<<" Si"; else cout<<" No";
        if(erroresActivado==1) cout<<"  Numero de errores permitidos: "<<erroresPermitidos;
        cout<<endl;
        cout<<endl<<endl;
        cout<<"1. Jugar"<<endl;
        cout<<"2. Configuracion"<<endl;
        cout<<"3. Salir"<<endl<<endl;
        cout<<"Introduce una opcion: ";
        pedirRangoNumeros( menuIndex , variableAscii , 1 , 3 , fallo = "Introduce opcion valida: " );
        //iub
        if(menuIndex==1){
            num=0;
            score = 0;
            turno = 1;
            puntosJugador = 0;
            puntosMaquina = 0;
            limpiarPantalla();
            cout<<"####JUGAR"<<endl;
            //boolean inicializado a 0 para controlar las cartas levantadas
            bool cartasLevantadas[nFilas][nColumnas];
            for(int i=0; i<nFilas; i++){
                for(int j=0; j<nColumnas; j++){
                    cartasLevantadas[i][j]= 0;
                }
            }
         //boolean inicializado a 0 para controlar las parejas levantadas
            bool parejasAcertadas[nFilas][nColumnas];
            for(int i=0; i<nFilas; i++){
                for(int j=0; j<nColumnas; j++){
                    parejasAcertadas[i][j]= 0;
                }
            }
         //boolean inicializado a 0 para controlar las cartas que han sido descubiertas en algun momento
            bool cartasMostradas[nFilas][nColumnas];
            for(int i=0; i<nFilas; i++){
                for(int j=0; j<nColumnas; j++){
                    cartasMostradas[i][j]= 0;
                }
            }

         // Cadena con tamaño filas*columnas con las parejas ordenadas

            char simbolo = 1;
            int cartas[nFilas*nColumnas];

            for(int i=0;i<(nFilas*nColumnas);i=i+2){
                cartas[i]=simbolo;
                cartas[i+1]=simbolo;
                simbolo++;
            }


         // Barajar la cadena
            int x;
            for(int i=0; i<(nFilas*nColumnas); i++){
                int aleatorio = rand() % (nFilas*nColumnas);
                x = cartas[aleatorio];
                cartas[aleatorio] = cartas[i];
                cartas[i] = x;
            }


         // CONVERSIÓN DE LA CADENA A UNA MATRIZ IGUAL AL TABLERO y PASO DE LOS NUMEROS A LETRAS EN LAS CARTAS
            char letra;
            string matriz[nFilas][nColumnas];
            int indCartas = 0;
            for(int i=0; i<nFilas; i++){
                for(int j=0; j<nColumnas; j++){
                    letra = cartas[indCartas]+64;
                    matriz[i][j] = letra;
                    indCartas++;
                }
            }


         //PUNTEROS
            string *pMatriz[nFilas];
            for (int i=0;i<nFilas;i++){
                pMatriz[i]= &matriz[i][0];
            }
            string **qMatriz = pMatriz;


            bool *pcartasLevantadas[nFilas];
            for (int i=0;i<nFilas;i++){
                pcartasLevantadas[i] = &cartasLevantadas[i][0];
            }
            bool **qcartasLevantadas = pcartasLevantadas;

            
            std::time_t start = std::time(nullptr);
            while(score < ((nFilas*nColumnas)/2)){    //MIENTRAS PUNTUACION SEA MENOR AL NUMERO DE PAREJAS

             // COMIENZO DEL JUEGO

                mostrarTablero( qMatriz , nFilas , nColumnas , qcartasLevantadas , zoom );  //Tablero inicial

             // TURNO DEL JUGADOR
                while  (turno == 1) {
                    cout<<"Puntos del Jugador: "<<puntosJugador<<"  ";
                    if( dificultad>0 ) cout<<"Puntos de la maquina: "<<puntosMaquina<<endl;
                    cout<<"<JUEGAS TU>"<<endl<<endl;
                    if(erroresActivado==1) cout<<"Errores: "<<errores<<"/"<<erroresPermitidos<<endl;
                    cout<<"INTRODUCE COORDENADAS DE LA PRIMERA CARTA"<<endl;
                    pedirCoordenadas(i1,j1, variableAscii , variableAscii, nFilas , nColumnas);
                    while( (cartasLevantadas[i1][j1] == 1) || (parejasAcertadas[i1][j1] == 1) ){
                        cout<<"ESA CARTA YA ESTA LEVANTADA"<<endl;
                        pedirCoordenadas(i1,j1, variableAscii, variableAscii , nFilas , nColumnas);
                    }
                    cartasLevantadas[i1][j1] = 1;
                    cartasMostradas[i1][j1] = 1;
                    mostrarTablero( qMatriz , nFilas , nColumnas , qcartasLevantadas , zoom );

                    cout<<"INTRODUCE COORDENADAS DE LA SEGUNDA CARTA"<<endl;
                    pedirCoordenadas(i2,j2 , variableAscii , variableAscii , nFilas , nColumnas);
                    while( (cartasLevantadas[i2][j2] == 1) || (parejasAcertadas[i2][j2] == 1) ){
                        cout<<"ESA CARTA YA ESTA LEVANTADA"<<endl;
                        pedirCoordenadas(i2,j2 , variableAscii , variableAscii , nFilas , nColumnas);
                    }
                    cartasLevantadas[i2][j2] = 1;
                    cartasMostradas[i2][j2] = 1;
                    mostrarTablero( qMatriz , nFilas , nColumnas , qcartasLevantadas , zoom );
                    esperar(segundos);
                    cartasLevantadas[i1][j1] = 0;
                    cartasLevantadas[i2][j2] = 0;
                    limpiarPantalla();
                
                    if( matriz[i1][j1] == matriz[i2][j2] ){ //SI EL JUGADOR ACIERTA UNA PAREJA
                        score++;
                        puntosJugador++;
                        cartasLevantadas[i1][j1] = 1;
                        cartasLevantadas[i2][j2] = 1;
                    }
                    else{ 
                        if(erroresActivado == 1) errores++;
                        if(dificultad>0) turno = 2;
                    }
                    if ( score == ((nFilas*nColumnas)/2) ) turno = 0;
                    
                    mostrarTablero( qMatriz , nFilas , nColumnas , qcartasLevantadas , zoom );
                    esperar(2);
                }

             // TURNO DE LA MAQUINA    
            
                while( turno == 2 ){ 
                    cout<<"Puntos del Jugador: "<<puntosJugador<<"  Puntos de la maquina: "<<puntosMaquina<<endl;
                    cout<<"<JUEGA LA MAQUINA>"<<endl<<endl;

                    if (dificultad > 0){


                        if(dificultad == 4){
                            dificultad4 = 1;
                            if( (puntosJugador >= 0) && ( puntosJugador < (((nFilas*nColumnas)/2)/4) )  ) dificultad = 2;
                            if( (puntosJugador > (((nFilas*nColumnas)/2)/4) ) && ( puntosJugador > (((nFilas*nColumnas)/2)/1.33) )  ) dificultad = 3;
                            
                        }


                        if (dificultad == 2){
                            dificultad2 = 1;
                            if(dificultad4==1) dificultad2=0;
                            int randDificultad;
                            randDificultad = rand() % 3;
                            if(  (randDificultad == 0) || (randDificultad == 1)  ) dificultad = 1;
                            else dificultad = 3;
                            
                        }




                        if (dificultad == 1){
                            i1= rand() % nFilas;
                            j1= rand() % nColumnas;
                            while(cartasLevantadas[i1][j1] == 1){
                                i1= rand() % nFilas;
                                j1= rand() % nColumnas;
                            }
                            cartasLevantadas[i1][j1] = 1;
                            cout<<"TURNO 1 DE LA MAQUINA"<<endl;
                            esperar(1);
                            mostrarTablero( qMatriz , nFilas , nColumnas , qcartasLevantadas , zoom );
                            esperar(segundos);
            

                            i2= rand() % nFilas;
                            j2= rand() % nColumnas;
                            while(cartasLevantadas[i2][j2] == 1){
                                i2= rand() % nFilas;
                                j2= rand() % nColumnas;
                            }
                            cartasLevantadas[i2][j2] = 1;
                            cout<<"TURNO 2 DE LA MAQUINA"<<endl;
                            esperar(1);
                            mostrarTablero( qMatriz , nFilas , nColumnas , qcartasLevantadas , zoom );
                            esperar(segundos);
                            cartasLevantadas[i1][j1] = 0;
                            cartasLevantadas[i2][j2] = 0;
                            limpiarPantalla();
                            
                            if( matriz[i1][j1] == matriz[i2][j2] ){ //SI ACIERTA UNA PAREJA
                                score++;
                                puntosMaquina++;
                                cartasLevantadas[i1][j1] = 1;
                                cartasLevantadas[i2][j2] = 1;
                            }
                            else turno = 1;
                            if ( score == ((nFilas*nColumnas)/2) ) turno = 0;      

                            if(dificultad2 == 1) dificultad = 2;
                            if(dificultad4 == 1) dificultad = 4;
                        }


                        
                        if (dificultad == 3){
                            int indCartaI;
                            int indCartaJ;
                            bool parejaAceptada = 0;

                            
                            for(int i=0 ; i<nFilas ; i++){
                                for(int j=0 ; j<nColumnas ; j++){          // recorre la matriz

                                    if(  ( cartasMostradas[i][j] == 1 ) && ( cartasLevantadas[i][j] == 0 )  ){    //si se encuenta una carta que haya salido y no esté levantada
                                        i1=i;
                                        j1=j;

                                        indCartaI=i;
                                        indCartaJ=j;

                                        for(int k=0 ; k<nFilas ; k++){
                                            for(int n=0 ; n<nColumnas ; n++){   //recorre la matriz
                                                
                                                if(   (matriz[k][n] == matriz[i][j]) && (( (k!=i) || (n!=j) ))  ){   // cuando encuentra su pareja
                                                    if(  (cartasMostradas[k][n] == 1) && (cartasLevantadas[k][n] == 0) ){ //si su pareja ha salido en algun momento
                                                        i2=k;
                                                        j2=n;

                                                        k=nFilas;
                                                        n=nColumnas;

                                                        i=nFilas;
                                                        j=nColumnas;

                                                        parejaAceptada = 1;
                                                    }
                                                    else{
                                                        i=indCartaI;
                                                        j=indCartaJ;
                                                    }   // volver a buscar otra carta que haya salido

                                                }

                            
                                            }
                                        }
                                    }
                                    
                                }
                            }
                            if(parejaAceptada == 0){
                                i1= rand() % nFilas;
                                j1= rand() % nColumnas;
                                while( (cartasLevantadas[i1][j1] == 1) || (cartasMostradas[i1][j1] == 1) ){ // saca random que no haya salido
                                    i1= rand() % nFilas;
                                    j1= rand() % nColumnas;
                                }

                                for(int k=0 ; k<nFilas ; k++){
                                    for(int n=0 ; n<nColumnas ; n++){   //recorre la matriz
                                                
                                        if(   (matriz[k][n] == matriz[i1][j1]) && ( (k!=i1) || (n!=j1) )  ){   // cuando encuentra su pareja
                                            if(  (cartasMostradas[k][n] == 1) && (cartasLevantadas[k][n] == 0) ){ //si su pareja ha salido en algun momento
                                                i2=k;
                                                j2=n;

                                                k=nFilas;
                                                n=nColumnas;

                                                parejaAceptada = 1;
                                            }
                                            else{
                                                i2= rand() % nFilas;
                                                j2= rand() % nColumnas;
                                                while( (cartasLevantadas[i2][j2] == 1) || (cartasMostradas[i2][j2] == 1) ){ // saca random que no haya salido
                                                    i2= rand() % nFilas;
                                                    j2= rand() % nColumnas;
                                                }  

                                            }
                                        }
                                    }



                                }
                            }
                            cartasLevantadas[i1][j1] = 1;
                            cartasMostradas[i1][j1] =1;
                            cout<<"-TURNO 1 DE LA MAQUINA"<<endl;
                            esperar(1);
                            cout<<matriz[i1][j1]<<endl;
                            mostrarTablero( qMatriz , nFilas , nColumnas , qcartasLevantadas , zoom );

                            cartasLevantadas[i2][j2] = 1;
                            cartasMostradas[i2][j2] = 1;

                            cout<<"-TURNO 2 DE LA MAQUINA"<<endl;
                            esperar(1);
                            cout<<matriz[i2][j2]<<endl;
                            mostrarTablero( qMatriz , nFilas , nColumnas , qcartasLevantadas , zoom );
                            esperar(segundos);

                            cartasLevantadas[i1][j1] = 0;
                            cartasLevantadas[i2][j2] = 0;
                            limpiarPantalla();
                            

                            if( matriz[i1][j1] == matriz[i2][j2] ){ //SI ACIERTA UNA PAREJA
                                score++;
                                puntosMaquina++;
                                cartasLevantadas[i1][j1] = 1;
                                cartasLevantadas[i2][j2] = 1;
                            }
                            else turno = 1;  // turno del jugador
                            if ( score == ((nFilas*nColumnas)/2) ) turno = 0; //sale del bucle

                            if(dificultad2 == 1) dificultad = 2; // Si el boolean dificultad2 está activado, vuelve a su dificultad original
                            if(dificultad4 == 1) dificultad = 4;
                        }





                    }
                }
                

                



            }

            cout<<endl<<endl;
            cout<<"FIN DE LA PARTIDA"<<endl;
            std::cout << "Tiempo transcurrido: "<< std::difftime(std::time(nullptr), start) << " s.\n";
                    
            if(dificultad>0){
                cout<<"NIVEL DE DIFICULTAD: "<<dificultad<<endl;
                cout<<"PUNTOS DEL JUGADOR: "<<puntosJugador << "    Puntos de la maquina: "<<puntosMaquina<<endl<<endl;
                if(puntosMaquina>puntosJugador) cout<<"GANA LA MAQUINA"<<endl;
                if(puntosJugador>puntosMaquina) cout<<"HAS GANADO"<<endl;
                if(puntosMaquina==puntosJugador) cout<< "EMPATE"<<endl;
            }
            esperar(10);
            score=0;
        }
        while(menuIndex==2){
            int configurar = 0;
            limpiarPantalla();
            cout<<"####CONFIGURAR"<<endl<<endl; 
            cout<<"1. Configurar tablero"<<endl;
            cout<<"2. Configurar dificultad"<<endl;
            cout<<"3. Configurar zoom"<<endl;
            cout<<"4. Configurar errores permitidos"<<endl;
            cout<<"5. Configurar tiempo que se muestra una pareja erronea"<<endl;
            cout<<"6. Atras"<<endl<<endl;
            cout<<"Introduce numero: "<<endl;

           pedirRangoNumeros( configurar , variableAscii , 1 , 6 , fallo = "Introduce opcion valida: " );

            if(configurar==1){
                limpiarPantalla();
                cout<<"INTRODUCE TAMANO DEL TABLERO (x*x=par)"<<endl;
                cout<<"Filas = "; cin >> nFilas; cout << "Columnas = "; cin >> nColumnas;

                while( (nFilas*nColumnas)%2 != 0 ){
                    cout<<"INTRODUCE TAMANO DEL TABLERO (x*x=par) = ";
                    cout<<"Filas = "; cin >> nFilas; cout << " Columnas = "; cin >> nColumnas;
                }
            }
            if(configurar==2){
                limpiarPantalla();
                cout<<"CONFIGURAR DIFICULTAD"<<endl<<endl; 
                cout<<"0. Sin bot"<<endl;
                cout<<"1. Nivel facil"<<endl;
                cout<<"2. Nivel medio"<<endl;
                cout<<"3. Nivel dificil"<<endl;
                cout<<"4. Dificultad variable"<<endl<<endl;
                cout<<"Introduce numero: "<<endl;

                pedirRangoNumeros( dificultad , variableAscii , 0 , 4 , fallo = "Introduce opcion valida: " );
            }
            if(configurar==3){
                limpiarPantalla();
                cout<<"CONFIGURAR ZOOM"<<endl<<endl; 
                cout<<"1. Sin zoom"<<endl;
                cout<<"2. Zoom x2"<<endl;
                cout<<"3. Zoom x3"<<endl;
                cout<<"4. Zoom x4"<<endl<<endl;
                cout<<"Introduce numero: "<<endl;

                pedirRangoNumeros( zoom , variableAscii , 1 , 4 , fallo = "Introduce opcion valida: " );
            }
            if(configurar==4){
                limpiarPantalla();
                cout<<"NUMERO DE ERRORES PERMITIDOS"<<endl<<endl;
                cout<<"0. Sin limite de errores"<<endl;
                cout<<"X. El limite de errores es X"<<endl<<endl;
                cout<<"Introduce numero: "<<endl;

                int erroresPermitidosAscii;
                cin>>erroresPermitidos;
                
                if(erroresPermitidos == 0) erroresActivado = 0;
                else erroresActivado = 1;
            }
            if(configurar==5){
                limpiarPantalla();
                cout<<"TIEMPO QUE SE MUESTRA UNA PAREJA ERRONEA"<<endl<<endl;
                cout<<"Introduce segundos: "<<endl;
                pedirRangoNumeros( segundos , variableAscii , 1 , 9, fallo);
            }
            if(configurar==6) menuIndex=0;


        }
        if(menuIndex==3) menu=0;
    }








         

 




 return 0;
}
