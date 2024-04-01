#include <iostream>
#include <vector>
#include <list>
#include <ctime> 
#include <algorithm>
using namespace std;

struct RegistroJuego {

    string nombreJuego, nombreJugador;
    int tiempoJugado;

    RegistroJuego(string _nombreJuego, string _nombreJugador, int _tiempoJugado){

        nombreJuego = _nombreJuego;
        nombreJugador = _nombreJugador;
        tiempoJugado = _tiempoJugado;
    }
};

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
    vector<RegistroJuego> registrosJuego;

    string nombreJuegoActual;
    string nombreJugadorActual;

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
        cout << "7.Ordenar por videojuegos mas jugados, con los tiempos c/u y nombre del jugador" << endl;
        cout << "8.Salir" << endl;
    }

    void iniciarJuego(const string& nombreJuego, const string& nombreJugador){

        startGame = time(nullptr);
        nombreJuegoActual = nombreJuego;
    }

    void finJuego(){

        if (startGame != 0){
            time_t endGame = time(nullptr);
            tiempoJugado += difftime(endGame, startGame);
            registrosJuego.push_back(RegistroJuego(nombreJuegoActual, nombreJugadorActual, tiempoJugadoSegundos));
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
                if (nodoJuego->get_dato() == nombreJuego->get_dato()){
                    nodoJuego->get_lista()->print();
                    break;
                }

                nodoJuego = nodoJuego->get_next();
            }

            nombreJuego = nombreJuego->get_next();
        }
    }

    void ordenadosPorAnioLanzamiento(Multilista<int, Videojuegos>& multilista){

        Lista<int> aniosLanzamiento;
        NodoP<int, Videojuegos>* nodo = multilista.get(0);

        while (nodo != nullptr){
            aniosLanzamiento.add(nodo->get_dato());
            nodo = nodo ->get_next();
        }

        aniosLanzamiento.sort();

        Nodo<int>* anioLanzamiento = aniosLanzamiento.get_head();

        while (nodoanioLanzamiento != nullptr){
            NodoP<int, Videojuegos>* nodoJuego = multilista.get(0);

            while (nodoJuego->get_dato() == nodoanioLanzamiento->get_dato()){
                nodoJuego->get_lista()->print();
                break;
            }

            nodoJuego = nodoJuego->get_next();
        }

        nodoanioLanzamiento = nodoanioLanzamiento->get_next();
    }

    void mostrarJuegosPorPlataforma(Multilista<string, Videojuegos>& multilista, const string& plataforma){

        NodoP<string, Videojuegos>* nodo = multilista.get(0);
        while (nodo != nullptr){
            if (nodo->get_dato() == plataforma){
                nodo->get_lista()->print();
            }

            nodo = nodo->get_next();
        }
    }

    void ordenarPorTiempoJugado(){

        sort(registrosJuego.begin(), registrosJuego.end(),
            [](const RegistroJuego& a, const RegistroJuego& b){return a.tiempoJugado > b.tiempoJugado; });
        
        for (const auto& registro : registrosJuego){
            cout << "Nombre del juego: " << registro.nombreJuego << ", Nombre del jugador: " << registro.nombreJugador
            << ", Tiempo jugado: " << registro.tiempoJugado << " minutos" << endl;
        }
    }

    void ordenarPorJugador(){

        sort(registrosJuego.begin(), registrosJuego.end(),
            [](const RegistroJuego& a, const RegistroJuego& b){return a.nombreJugador > b.nombreJugador});

        for (const auto& registro : registrosJuego){
            cout << "Nombre del juego: " << registro.nombreJuego << ", Nombre del jugador: " << registro.nombreJugador
            << ", Tiempo jugado: " << registro.tiempoJugado << " minutos" << endl;
        }
    }

    void ordenarPorJuegoMasJugado(){

        sort(registrosJuego.begin(), registrosJuego.end(),
            [](const RegistroJuego& a, const RegistroJuego& b){return a.nombreJuego > b.nombreJuego});

        vector<pair<string, int>> juegosTiempoTotal;
        string juegoActual = registrosJuego[0].nombreJuego;
        int tiempoTotal = 0;

        for (const auto& registro : registrosJuego){
            if (registro.nombreJuego == juegoActual){
                tiempoTotal += registro.tiempoJugado;
            } else {
                juegosTiempoTotal.push_back({juegoActual, tiempoTotal});
                juegoActual = registro.nombreJuego;
                tiempoTotal = registro.tiempoJugado;
            }
        }

        juegosTiempoTotal.push_back({juegoActual, tiempoTotal});

        sort(juegosTiempoTotal.begin(), juegosTiempoTotal.end(),
            [](const pair<string, int>& a, const pair<string, int>& b){return a.second > b.second;});
        
        cout << "Juegos mas jugados: " << endl;
        for (const auto& juegoTiempo : juegosTiempoTotal){
            cout << "Nombre del juego: " << juegoTiempo.first << ", Tiempo jugado: " << juegoTiempo.second << " segundos" << endl;
        }

    }


};
