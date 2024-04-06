#include <iostream>
#include "Videojuegos.cpp"
#include "Ahorcado.cpp"
#include "Sonar.cpp"
using namespace std;

int main() {

    int opcion, opcion1;

    Videojuegos user;
    Ahorcado user1;
    Sonar user2;
    Multilista<string, string> user3;

    do {

        user.menu();

        cout << "Elija la opcion que quiere realizar el dia de hoy" << endl;
        cin >> opcion;

        switch(opcion){
            case 1:

            user.registrarJuego();
            break;

            case 2:

            cout << "Los videojuegos que puede jugar son: " << endl;
            cout << "1.Ahorcado" << endl;
            cout << "2.Sonar" << endl;
            cout << "Ingrese su opcion: " << endl;
            cin >> opcion1;

            switch(opcion1){
                case 1:

                user.verInfo("Ahorcado");
                user.iniciarJuego();
                user1.jugar();
                user.finJuego();
                cout << "Tiempo jugado: " << user.gettiempoJugadoSegundos() << "segundos" << endl;
                break;

                case 2:

                user.verInfo("Sonar");
                user.iniciarJuego();
                user2.jugar();
                user.finJuego();
                cout << "Tiempo jugado: " << user.gettiempoJugadoSegundos() << "segundos" << endl;
                break;

                default:

                cout << "Opcion no valida" << endl;
                break;
            }
            break;

            case 3:

            user3.agregarCategoria();
            break;

            case 4:

            user3.agregarJuegoACategoria();
            break;

            case 5:

            user.agregarAFavoritos();
            break;

            case 6:

            user.mostrarFavoritos();
            break;

            case 7:

            break;

            default:

            cout << "Opcion no valida" << endl;
            break;
        }
            
    } while (opcion != 8);

    return 0;
}

                    
        
