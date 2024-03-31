#include <iostream>
#include "Videojuegos.cpp"
#include "Ahorcado.cpp"
using namespace std;

int main (){

    int opcion, opcion1;

    Videojuegos user;
    Ahorcado user1;

    do {

        user.menu();

        cout << "Elija la opcion que quiere realizar el dia de hoy" << endl;
        cin >> opcion;

        switch(opcion){
            case 1:
                
                cout << "Los videojuegos que estan disponibles son: " << endl;
                cout << "1.Ahorcado" << endl;
                cout << "2.Sonar" << endl;
                cout << "Elije tu opcion: " << endl;
                cin >> opcion1;

                switch(opcion1){
                    case 1: 
                        user.verInfo("Ahorcado");
                        user.iniciarJuego();
                        user1.jugar();
                        user.finJuego();
                        cout << "Tiempo jugado: " << user.gettiempoJugado() << "segundos" << endl;
                        break;
                    
                    case 2:
                        user.verInfo("Sonar");
                        user.iniciarJuego();
                        //llamar la funcion del juego sonar
                        user.finJuego();
                        cout << "Tiempo jugado: " << user.gettiempoJugado() << "segundos" << endl;
                        break;
                    
                    default:

                        cout << "Opcion no valida" << endl;
                        break;
                }
                break;
            
            case 2:

                user.agregarVideojuego();
                cout << "El juego se ha agregado con exito" << endl;
                break;
            
            case 3:
            






                

        }

        
    } while (opcion != 8);







    return 0;
}