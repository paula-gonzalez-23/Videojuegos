#include <iostream>
#include <vector>
using namespace std;

class videojuegos {

    private:

    string nombre;
    string desarrollador;
    int anioLanzamiento;
    string plataforma;
    int cantidadJugadores;
    vector<string> categorias;
    int tiempoJugado; 
    time_t startGame; //Tiempo de inicio del juego

    public:

    videojuegos(){

    }

    void setnombre(string _nombre){

        nombre = _nombre;
    }

    string getnombre(){

        return nombre;
    }

    void setdesarrollador(string _desarrollador){

        desarrollador = _desarrollador;
    }

    string getdesarrollador(){

        return desarrollador;
    }

    void setanioLanzamiento(int _anioLanzamiento){

        anioLanzamiento = _anioLanzamiento;
    }

    int getanioLanzamiento(){

        return anioLanzamiento;
    }

    void setplataforma(string _plataforma){

        plataforma = _plataforma;
    }

    string getplataforma(){

        return plataforma;
    }

    void setcantidadJugadores(int _cantidadJugadores){

        cantidadJugadores = _cantidadJugadores;
    }

    int getcantidadJugadores(){

        return cantidadJugadores;
    }

    void setCategorias(const vector<string>& _categorias){

        categorias = _categorias;
    }

    vector<string> getCategorias() const{

        return categorias;
    }

    void settiempoJugado(int _tiempoJugado){

        tiempoJugado = _tiempoJugado;
    }

    int gettiempoJugado() const {

        return tiempoJugado;
    }

    void verInfo(string juego) {

        cout << "Nombre: " << nombre << endl;
        cout << "Desarrollador: " << desarrollador << endl;
        cout << "Anio de Lanzamiento: " << anioLanzamiento << endl;
        cout << "Plataforma: " << plataforma << endl;
        cout << "Categorias: ";
        for (const auto& categoria : categorias){
            cout << categoria << ", ";
        }
        cout << endl;
        cout << "Cantidad de Jugadores: " << cantidadJugadores << endl;

        if(juego == "Ahorcado"){

            setnombre("Juego del Ahorcado");
            setdesarrollador("Julio Roberto Garbini");
            setanioLanzamiento(1978);
            setplataforma("Speak & Sell");
            setcantidadJugadores(1);
            setCategorias({"Juego de Palabras", "Juego de adivinanzaz"});

        }else if (juego == "Sonar"){
            
            setnombre("Sonar");
            setdesarrollador("Roberto Fraga");
            setanioLanzamiento(2017);
            setplataforma("Manual");
            setcantidadJugadores(1);
            setCategorias({"Juego de Estrategia"});
    
        }
    }

    void menu(){

        cout << "Bienvenido a Mattel" << endl;
        cout << "1.Mostrar videojuegos disponibles para jugar" << endl;
        cout << "2.Agregar un videojuego" << endl;
        cout << "3.Asignar categorias a un videojuego" << endl;
        cout << "4.Consultar y mostrar la lista de videojuegos ordenados por titulo" << endl;
        cout << "5.Consultar y mostrar la lista de videojuegos ordenados por anio de lanzamiento" << endl;
        cout << "6.Consultar y mostrar la lista de videojuegos filtrados por una plataforma especifica" << endl;
        cout << "7.Consultar y mostrar la lista de videojuegos ordenados por categoria y desarrollador" << endl;
        cout << "8.Ordenar por videojuegos mas jugados, con los tiempos c/u y nombre del jugaodr" << endl;
        cout << "9.Salir" << endl;
    }

    void iniciarJuego(){

        startGame = time(nullptr);
    }

    void finjuego(){

        if (startGame != 0){
            time_t endGame = time(nullptr);
            tiempoJugado += difftime(endGame, startGame);
            startGame = 0;
        }
    }

    

   

};