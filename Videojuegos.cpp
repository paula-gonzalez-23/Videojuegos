#include <iostream>
#include <vector>
#include <list>
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

    list<string>juegoFavorito;

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

    void agregarListaFavoritos(const string& videojuego){

        juegoFavorito.push_back(videojuego);
    }
    
    const list<string>& getjuegoFavorito() const {

        return juegoFavorito;
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

    void agregarJuego(Multilista<string, string>& multilista){

        int opcion;
        string juego;

        cout << "Seleccione a que genero de juego desea agregar el nuevo juego: " << endl;
        multilista.print();

        cin >> opcion;
        opcion --;

        cout << "Ingrese el nombre del nuevo juego: " << endl;
        cin >> juego;

        multilista.get(opcion)->add(juego);

    }

    void agregarCategoria(Multilista<string, string>& multilista){

        int genero, juego, cantidadCategorias;
        string categoria;

        cout << "Seleccione el genero del juego al que desea agregar categorias: " << endl;
        multilista.print();
        cin >> genero;
        genero --;

        cout << "Seleccione el juego al que desea agregar categorias: " << endl;
        multilista.get(genero)->print();
        cin >> juego;
        juego --;

        cout << "Ingrese la cantidad de categorias que desea agregar: " << endl;
        cin >> cantidadCategorias;

        cout << "Ingrese las cantegorias (una por una): " << endl;
        for (int i = 0; i < cantidadCategorias; i++){
            cin >> categoria;
            multilista.get(genero)->get_lista()->insert(categoria,juego);
        }
    }

    void agregarListaFavoritos(){

        string juego;

        cout << "Ingrese el nombre del juego que desea agregar a su lista de favoritos (0 para salir): " << endl;
        

        while (true){
            cin >> juego;

            if(juego == "0"){
                break;
            }

            juegoFavorito.push_back(juego);
        }
    }

    void mostrarListaFavoritos(){

        cout << "La lista de juegos favoritos es: " << endl;
        for (const auto& videojuego : juegoFavorito){
            cout << videojuego << ", ";
        }

        cout << endl;

    }

    void ordenadosPorTitulo(Multilista<string, Videojuegos>& multilista){

        Lista<string> nombresJuegos;
        NodoP<string, Videojuegos>* nodo = multilista.get(0);
        while (nodo != nullptr){
            nombreJuegos.add(nodo->get_dato());
            nodo = nodo->get_next();
        }

        nombresJuegos.sort();

        Nodo<string>* nombreJuego = nombresJuegos.get_head();
        while (nombreJuego != nullptr){
            NodoP<string, Videojuegos>* nodoJuego = multilista.get(0);
            while (nodoJuego != nullptr){
                if 
            }
        }
    }


    

   

};