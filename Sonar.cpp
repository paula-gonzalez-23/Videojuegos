#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class Sonar{

    public:
    int ANCHO = 60, ALTO = 15, random;
    string tab1 [60][15] = {};
    


    Sonar(){

    }
    
    void crearTablero(int ANCHO, int ALTO, string tab1[60][15]){
        
        srand(time(NULL));
        int random;

        for(int i = 0; i < ALTO; i++){
            for (int j = 0; j < ANCHO; j++)
            {   
                random = rand() %2;
                if(random == 0){
                    tab1[j][i] = "~";
                }
                else{
                    tab1[j][i] = "^";
                }
            
            }
        
        }

    }


    void imprimirTablero(string tab1[60][15]){    

        string esp = " ", esp1 = "         ", numbers = "012345678901234567890123456789012345678901234567890123456789";
        
        for (int i = 1; i < 6; i++)
        {
            esp += (esp1)+ to_string(i);
        }
        
        cout << "   " << esp << endl << "    " << numbers << endl;
        cout << endl;
        for(int i = 0; i < 15; i ++){
            if (i < 10){
                cout  << " " << i << "  ";
            }
            else{
                cout  << "" << i << "  ";
            }
            for(int j = 0; j < 60; j ++){
                cout << tab1[j][i]; 
            }
            if (i < 10){
                cout  << "  " << i << endl;
            }
            else{
                cout  << " " << i << endl;
            }

        }
        cout << endl;
        cout << "    " << numbers << endl << "   " << esp << endl ;

    }

    vector <int> cofres(int numCofres){
        vector <int> coordCofres;
        int coordX, coordY;

        for(int i = 0; i < 2*numCofres; i++){
            coordX = rand() %60;
            coordY = rand() %15;

            coordCofres.push_back(coordX);
            coordCofres.push_back(coordY);
        }

        return coordCofres;
    }

    string movimiento(){

    }
};