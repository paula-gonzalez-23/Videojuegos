#include <iostream>
#include "Videojuegos.cpp"
#include "Ahorcado.cpp"
using namespace std;

int main (){

    int opcion;

    videojuegos user;
    Ahorcado user1;

    do {

        user.menu();

        cout << "Elija la opcion que quiere realizar el dia de hoy" << endl;
        cin >> opcion;

        switch(opcion){
            case 1:
                
                

        }

        
    } while (opcion != 9);







    return 0;
}