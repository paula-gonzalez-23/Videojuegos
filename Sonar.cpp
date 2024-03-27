#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

class Sonar{

    public:
    int ANCHO = 60, ALTO = 15, random, numCofres = 3, coorX,coorY;
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

    string hacerMovimientos(vector <int> coordCofres,int x ,int y){

        int limite = 100, pos = 0;
        float distancia = 0;

        for(int i = 1; i < 6; i +=2 ){
            distancia = sqrt((coordCofres[i]-x) * (coordCofres[i]-x) + (coordCofres[i+1]-y) * (coordCofres[i+1]-y));

            if (distancia < limite)
            {
                limite = distancia;
            }
    
        }

        
        limite = round(limite);

        if (limite == 0)
        {// posible cambio 
            coordCofres.erase(coordCofres.begin() + x);
            coordCofres.erase(coordCofres.begin() + y);
            return "Has encontrado un tesoro";
        }
        else{
            if (limite < 10){
                tab1[x][y] = to_string(limite);
                return "Has encontrado un tesoro a " + to_string(limite) + "unidades del dispositivo ";
            }
            else{
                tab1[x][y] = "X";
                return "No has encontrado ningun cofre cerca del sonar";
            }
        }
        return "";
        
    }

    vector <int> movimientos(){
        
        vector <int> movimiento;

        while (true){        
        
            cout << "Ingrese una posicion para el eje x: " << endl;
            cin >> coorX;

            cout << "Ingrese una posicion para el eje y: " << endl;
            cin >> coorY;

            if(coorX < 0 || coorX > 60){
                cout << "Ingrese una coordenada valida para el eje x" << endl;
            }
            if(coorY < 0 || coorY > 15){
                cout << "Ingrese una coordenada valida para el eje y" << endl;
            }
            else{
                movimiento.push_back(coorX);
                movimiento.push_back(coorY);
                return movimiento;
            }


        }
    }        

    int jugarOtra(){
        int op;

        cout << "Desea jugar otra vez? 1. Si / 2. No " << endl;
        cin >> op;

        return op;
    }

    void jugar(){

        cout << "S O N A R! " << endl << "Busca los tesoros ocultos en el fondo del océano usando sondas sonar." << endl;
        
        cout << "Para dejar caer un sonar, ingresa las coordenadas \'x\' y \'y\'. El sonar puede detectar la distancia"  << endl;

    }
};