#include <iostream>
#include "Videojuegos.cpp"
#include "Ahorcado.cpp"
#include "Sonar.cpp"
using namespace std;

int main (){

    int opcion, opcion1, opcion3, opcion4;
    string plataforma;

    Videojuegos user;
    Ahorcado user1;
    Sonar user2;

    Multilista<string, Videojuegos> multilista;
    Multilista<int, Videojuegos> multilista1;
    Multilista<string, string> multilista2;

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
                        user.iniciarJuego("Ahorcado", "Paula");
                        user1.jugar();
                        user.finJuego();
                        cout << "Tiempo jugado: " << user.gettiempoJugadoSegundos() << "segundos" << endl;
                        break;
                    
                    case 2:
                        user.verInfo("Sonar");
                        user.iniciarJuego("Sonar", "Paula");
                        user2.jugar();
                        user.finJuego();
                        cout << "Tiempo jugado: " << user.gettiempoJugadoSegundos() << "segundos" << endl;
                        break;
                    
                    default:

                        cout << "Opcion no valida" << endl;
                        break;
                }
                break;
            
            case 2:

                user.agregarJuego(multilista2);
                break;
            
            case 3:

                user.agregarCategoria(multilista2);
                break;
            
            case 4:

                user.agregarListaFavoritos();
                break;
            
            case 5:

                user.mostrarListaFavoritos();
                break;
            
            case 6:

                cout << "Elija porque quiere consultar y mostrar la lista de juegos: " << endl;
                cout << "1.Ordenados por titulo" << endl;
                cout << "2.Ordenados por anio de Lanzamiento" << endl;
                cout << "3.Filtrados por una plataforma espeifica" << endl;
                cout << "Elije tu opcion" << endl;
                cin >> opcion3;

                switch(opcion3){
                    case 1:

                        cout << "Lista de videojuegos ordenados por titulo" << endl;
                        user.ordenadosPorTitulo(multilista);
                        break;
                    
                    case 2:
                    
                        cout << "Lista de videojuegos ordenados por anio de lanzamiento" << endl;
                        user.ordenadosPorAnioLanzamiento(multilista1);
                        break;
                    
                    case 3:

                        cout << "Ingrese la plataforma para filtrar los videojuegos: " << endl;
                        cin >> plataforma;

                        cout << "Lista de videjuegos para la plataforma " << plataforma << ":" << endl;
                        user.mostrarJuegosPorPlataforma(multilista,plataforma);
                        break;
                    
                    default:

                        cout << "Opcion no valida" << endl;
                        break;
                }
                break;
            
            case 7:

                cout << "Ingrese la opcion por la quiere ordenar los video juegos: " << endl;
                cout << "1.Por jugador" << endl;
                cout << "2.Por tiempo jugado" << endl;
                cout << "3.Por juego mas jugado" << endl;
                cout << "Elije tu opcion: " << endl;
                cin >> opcion4;

                switch(opcion4){
                    case 1:

                        user.ordenarPorJugador();
                        break;

                    case 2:

                        user.ordenarPorTiempoJugado();
                        break;

                    case 3:

                        user.ordenarPorJuegoMasJugado();
                        break;
                    
                    default:

                        cout << "Opcion no valida" << endl;
                        break;
                }

                break;
            
            default:

                cout << "Opcion no valida" << endl;
                break;

        }

    } while (opcion != 8);


    
    return 0;
}
