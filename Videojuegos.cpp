#include <iostream>
#include <vector>
using namespace std;

class Videojuegos {

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

    Videojuegos(){

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
        cout << "4.Agregar un juego a la lista de favoritos" << endl;
        cout << "5.Mostrar la lista de favoritos" << endl;
        cout << "6.Lista videojuegos por ordenamientos" << endl;
        /*cout << "6.Consultar y mostrar la lista de videojuegos ordenados por titulo" << endl;
        cout << "7.Consultar y mostrar la lista de videojuegos ordenados por anio de lanzamiento" << endl;
        cout << "8.Consultar y mostrar la lista de videojuegos filtrados por una plataforma especifica" << endl;
        cout << "9.Consultar y mostrar la lista de videojuegos ordenados por categoria y desarrollador" << endl;*/
        cout << "7.Ordenar por videojuegos mas jugados, con los tiempos c/u y nombre del jugaodr" << endl;
        cout << "8.Salir" << endl;
    }

    void iniciarJuego(){

        startGame = time(nullptr);
    }

    void finJuego(){

        if (startGame != 0){
            time_t endGame = time(nullptr);
            tiempoJugado += difftime(endGame, startGame);
            startGame = 0;
        }
    }

    void agregarVideojuego(){

        Videojuegos newGame;

        string nombre;
        string desarrollador;
        string plataforma;
        int anioLanzamiento;
        int cantidadJugadores;
        int cantidadCategorias;
        vector<string> categorias;

        cout << "Ingrese el nombre del juego: " << endl;
        cin >> nombre;
        cout << "Ingrese el desarrollador del juego: " << endl;
        cin >> desarrollador;
        cout << "Ingrese la plataforma donde se juega normalmente: " << endl;
        cin >> plataforma;
        cout << "Ingrese la cantidad de jugadores: " << endl;
        cin >> cantidadJugadores;
        cout << "Ingrese el anio de lanzamiento del juego: " << endl;
        cin >> anioLanzamiento;
        cout << "Ingrese la cantidad de categorias: " << endl;
        cin >> cantidadCategorias;
        cout << "Ingrese las categorias (separadas por espacio): " << endl;
        for (int i = 0; i < cantidadCategorias; i++){
            string categoria;
            cin >> categoria;
            categorias.push_back(categoria);
        }

        newGame.setnombre(nombre);
        newGame.setdesarrollador(desarrollador);
        newGame.setanioLanzamiento(anioLanzamiento);
        newGame.setplataforma(plataforma);
        newGame.setcantidadJugadores(cantidadJugadores);
        newGame.setCategorias(categorias);

        //listavideosjuegos.push_back(newGame);
    }

    void agregarCategorias(){

        string juego;
        int cantidadCategorias;
        
        cout << "Ingrese el nombre del juego al que desea agregar categorias: " << endl;
        cin >> juego;

        if (juego == nombre){
            cout << "Ingrese la cantidad de categorias a agregar: " << endl;
            cin >> cantidadCategorias;
            cout << "Ingrese las categorias a agregar (separadas por espacio): " << endl;
            for (int i = 0; i < cantidadCategorias; i++){
                string categoria;
                cin >> categoria;
                categorias.push_back(categoria);
            }

            cout << "Categorias agregadas exitosamente al juego" << juego << endl;
        } else {

            cout << "El juego especificado no se encuentra en la lista" << endl;
        }
    }

    


    

   

};