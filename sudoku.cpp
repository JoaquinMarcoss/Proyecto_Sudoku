#include<iostream>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

struct jugadores{
        char nombre[20];
        int punto;
    };

struct valores{
        int x;
        int y;
        int n;
    };

void menu(){
    cout<<endl<<endl<<" MODOS DE JUEGO "<<endl;
    cout<<endl<<" Opcion 1: Iniciacion con todas las celdas VACIAS. ";
    cout<<endl<<" Opcion 2: Iniciacion con celdas ya COMPLETADAS. ";
    cout<<endl<<" Opcion 3: Salir del juego. "<<endl;
    cout<<endl<<" Seleccione una opcion: ";
}

void mostrarmatriz(int M[9][9]){
    int i,j;
    for(i=0;i<9;i++){
        if(i%3 == 0){
            for(j=0;j<9;j++){
                if(j%3 == 0){
                    cout<< "+-";
                }
                cout<<"--";
            }
            cout<<"+\n";
        }

        for(j=0;j<9;j++){
            if(j%3 == 0){
                cout<<"| ";
            }
            if(M[i][j] == 0){
                cout<<"0";
            }
            else{
               cout<<M[i][j];
            }
            cout<<" ";
        }
        cout<<"|\n";
    }

    for(j=0;j<9;j++){
        if(j%3==0){
            cout<<"+-";
        }
        cout<<"--";
    }
    cout<<"+\n";
}

valores ingreso(valores v[1]){
    cout<<endl<<" Ingrese la celda que desea modificar ";
    cout<<endl<<" Posicion en X: ";
    cin>>v[1].x;
    cout<<" Posicion en Y: ";
    cin>>v[1].y;
    cout<<" Ingrese un numero para la posion ["<<v[1].x<<"]["<<v[1].y<<"]: ";
    cin>>v[1].n;
    return v[1];
}

bool verificacionPosicion(valores v[1]){
    bool bandera;
    if(v[1].x>0 && v[1].x<10 && v[1].y>0 && v[1].y<10 && v[1].n>0 && v[1].n<10){
        return true;
    }else{
        return false;
        }
    }

int matrizAleatorea(int M[9][9]){
    int x, y, n, i, j, cont=1, i1=0, i2=0, j1=0, j2=0;
    bool filas, columnas, subcuadrilla;

    srand(time(NULL));

    do{
        filas = true;
        columnas = true;
        subcuadrilla = true;

        x = rand()%(9);
        y = rand()%(9);
        n = 1+rand()%(10-1);

        if(x>=0 && x<=2){
            i1=0;
            i2=2;
        }else if( x>2 && x<=5){
            i1=3;
            i2=5;
        }else if(x>5 && x<=8){
            i1=6;
            i2=8;
        }

        if(y>=0 && y<=2){
            j1=0;
            j2=2;
        }else if( y>2 && y<=5){
            j1=3;
            j2=5;
        }else if(y>5 && y<=8){
            j1=6;
            j2=8;
        }

    for(i=i1; i<=i2; i++){
            for(j=j1; j<=j2; j++){
            if(M[i][j] == n){
            subcuadrilla = false;
            break;
            }
        }
    }

        for(i=0;i<9;i++){
            if (M[i][y] == n){
                    filas = false;
                    break;
                }else{
                    filas = true;
                }
        }

        for(j=0;j<9;j++){
                if (M[x][j] == n){
                    columnas = false;
                    break;
                }else{
                    columnas = true;
                }
        }

    if(filas && columnas && subcuadrilla && M[x][y]==0){
            M[x][y] = n;
            cont++;}
    }while(cont<41);

    return M[9][9];
}


int matrizvacia(int M[9][9], valores v[1], jugadores p[2]){
    int i=0, j=0, x, y, n, jugador, g, celdas=0, cont=0, i1=0, i2=0, j1=0, j2=0;
    bool filas, columnas, subcuadrilla, continuar, casilla=true;

    cout<<endl<<endl<<"----------- EMPIEZA EL JUEGO --------------";

    for(jugador=0; jugador<2; jugador++){
        filas = true;
        columnas = true;
        subcuadrilla = true;
        continuar = true;

        if(casilla==true){
        cout<<endl<<" Turno del jugador "<<jugador+1<<":";
        }

    while(continuar==true && celdas<81 && casilla==true){
        filas = true;
        columnas = true;
        subcuadrilla = true;
         do{
                ingreso(v);
                if(verificacionPosicion(v) == false){
                    cout<<endl<<"ERROR: Recuerde que las posiciones y valores van del 1 al 9"<<endl;
                }else{
                    verificacionPosicion(v) == true;
                }
            }while(verificacionPosicion(v) == false);

            x = v[1].x-1;
            y = v[1].y-1;
            n = v[1].n;

        for(i=0;i<9;i++){
            if (M[i][y] == n){
                    filas = false;
                    continuar = false;
                    break;
                }else{
                    filas = true;
                }
        }
        for(j=0;j<9;j++){
                if (M[x][j] == n){
                    columnas = false;
                    continuar = false;
                    break;
                }else{
                    columnas = true;
                }
        }

    int i1=0,i2=0,j1=0,j2=0;
    if(x>=0 && x<=2){
        i1=0;
        i2=2;
    }else if( x>2 && x<=5){
        i1=3;
        i2=5;
    }else if(x>5 && x<=8){
        i1=6;
        i2=8;
    }

    if(y>=0 && y<=2){
        j1=0;
        j2=2;
    }else if( y>2 && y<=5){
        j1=3;
        j2=5;
    }else if(y>5 && y<=8){
        j1=6;
        j2=8;
    }

    for(i=i1; i<=i2; i++){
            for(j=j1; j<=j2; j++){
                if(M[i][j] == n){
                    subcuadrilla = false;
                    continuar = false;
                break;
                }
            }
        }

        if(filas && columnas && subcuadrilla && M[x][y]==0){
            cout<<endl<<" Se pudo ingresar el valor"<<endl;
            M[x][y] = n;
            mostrarmatriz(M);
            p[jugador].punto++;
            celdas++;
            if(celdas==81){
                cout<<endl<<"Todas la celdas fueron completas";
            }

           int c1=0,c2=0;
            if(x>=0 && x<=2){
                c1=0;
            }else if( x>2 && x<=5){
                c1=3;
            }else if(x>5 && x<=8){
                c1=6;
            }

            if(y>=0 && y<=2){
                c2=0;
            }else if( y>2 && y<=5){
                c2=3;
            }else if(y>5 && y<=8){
                c2=6;
            }

         for(i=0; i<9; i++){
                cont=0;
                for(i1=c1; i1<=c1+2; i1++){
                    for(j1=c2; j1<=c2+2; j1++){
                            if(M[i1][j1] != 0){
                                cont++;
                            }
                        }
                    }

            if(cont==9){
            casilla = false;
            break;
            }else{
                c1=c1+2;
            }
        }

        if(casilla==false){
            cout<<endl<<" Se completo una casilla. "<<endl;;
            cout<<endl<<" GANADOR: "<<p[jugador].nombre;
            g = jugador;
            break;
        }else{
        continuar = true;
        casilla = true;
    }
        }else if(M[x][y]!=0){
                cout<<endl<<" ADVERTENCIA: ya hay un numero en esa posicion."<<endl;
                continuar=true;
                casilla=true;
            }else{
            cout<<endl<<" No se puede cargar en esta posicion, el jugador "<<jugador+1<<" pierde su turno."<<endl;
            continuar=false;
            }
        }
    }

    cout<<endl<<endl<<" JUGADOR 1 - puntaje: "<<p[0].punto;
    cout<<endl<<" JUGADOR 2 - puntaje: "<<p[1].punto<<endl;

    if(p[0].punto>p[1].punto && casilla){
        cout<<endl<<" GANADOR: "<<p[0].nombre;
        g = 0;
    }else if(casilla && p[0].punto<p[1].punto){
        cout<<endl<<" GANADOR: "<<p[1].nombre;
        g = 1;
    }else if(p[0].punto == p[1].punto){
        cout<<"        EMPATE     "<<endl;
        g = 2;
    }

    return g;
}

int main(){
    system("COLOR B0");
    int i, j, opcion, cuadricula[9][9], x=0, y=0, num=0, ganador;
    jugadores J[2];
    valores A[3];
    ofstream file;
    file.open("RegistroDeJugadas.txt");

    cout<<endl<<" --------- BIENVENIDOS AL JUEGO DEL SUDOKU ----------"<<endl;
    cout<<endl<<" El juego consiste en completar las posiciones vacias";
    cout<<endl<<" con digitos del 1 al 9 siguiendo algunas reglas:"<<endl;
    cout<<endl<<" 1) No se pueden repetir digitos en la misma columna.";
    cout<<endl<<" 2) No se pueden repetir digitos en la misma fila.";
    cout<<endl<<" 3) No se pueden repetir digitos en la misma subcuadricula."<<endl;
    cout<<endl<<" Presiones ENTER para continuar. "<<endl;

    for(i=0; i<2; i++){
        cin.ignore();
        cout<<"Ingrese el nombre del jugador "<<i+1<<": ";
        cin.getline(J[i].nombre, 20, '\n');
    }

 do{
    menu();
    cin>>opcion;
           if(opcion==1){
            //celdas vacias
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
                    cuadricula[i][j] = 0;
                }
            }
            cout<<endl<<" CUADRICULA: "<<endl;
            mostrarmatriz(cuadricula);
            ganador = matrizvacia(cuadricula,A,J);

            if(ganador != 2){
            file<<"GANADOR: "<<J[ganador].nombre<<"\n";
            file<<"PUNTAJE: "<<J[ganador].punto<<"\n";
            file.close();
            }else{
            file<<" "<<J[0].nombre<<" Y "<<J[1].nombre<<" EMPATARON\n";
            file<<" PUNTAJE DE AMBOS: "<<J[0].punto<<"\n";
            file.close();
            }
            break;
        }else{
            if(opcion==2){
                //celdas completadas
           for(i=0;i<9;i++){
                for(j=0;j<9;j++){
                    cuadricula[i][j] = 0;
                }
            }
            matrizAleatorea(cuadricula);
            cout<<endl<<" CUADRICULA: "<<endl;
            mostrarmatriz(cuadricula);
            ganador = matrizvacia(cuadricula,A,J);
            file<<"GANADOR: "<<J[ganador].nombre<<"\n";
            file<<"PUNTAJE: "<<J[ganador].punto<<"\n";
            file.close();
            break;
            }
            else{
                if(opcion==3){
                    cout<<endl<<" Juego cerrado. ";
                    break;
                }else{
            cout<<endl<<" ERROR: No ha ingresado ninguna de las opciones. ";
                }
            }
        }
 }while(opcion!=1 || opcion!= 2 || opcion!=3);
getch();
}

