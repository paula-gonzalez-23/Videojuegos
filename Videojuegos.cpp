#include <iostream>
#include <vector>
#include <list>
#include <ctime> 
#include <algorithm>
using namespace std;


template <typename T>
struct Nodo {

    T dato;
    Nodo* next:

    Nodo(){

        next = nullptr;
    }

    Nodo(T d){

        dato = d;
        next = nullptr;
    }
};

template <typename T>

class Lista{

private:
    Nodo<T>* ptr;
    int size;
         
public:
    Lista(){
        ptr = NULL;
        size = 0;
    }
  
    ~Lista(){
        Nodo<T>* temp = ptr;
        while (temp != nullptr){
            Nodo<T>* next_temp = temp -> next;
            delete temp;
            temp = next_temp;
        }
    }

    void add(T d){
        Nodo<T>* n = new Nodo<T>(d);
        if (ptr == NULL){
            ptr =  n;
        } else{
            Nodo<T>* t = ptr;
            while(t -> next != nullptr){
                t = t-> next;
            }
            t -> next = n;
        }
        size++;
    }

    void print(){
        Nodo<T>* t = ptr;
        while(t != NULL){
            cout << t -> dato <<endl;
            t = t -> next;
        }
    }
  
    void insert(T dato, int pos){
        Nodo<T>* new_nodo = new Nodo<T>(dato);
      
        if (ptr == NULL || pos <= 0){
            new_nodo -> next = ptr;
            ptr = new_nodo;
            size++;
        } else if(pos >= size){
            add(dato);
        } else{
            Nodo<T>* t = ptr;
            int i = 0;
            while(i < pos-1){
                t = t -> next;
                i++;
            }
            new_nodo -> next = t -> next;
            t -> next = new_nodo;
            size++;
        }
  
    }
};

template <typename T, typename T2>

struct NodoP{
    T dato;
    NodoP<T, T2>* nextP;
    Lista<T2>* l;

    NodoP() {

        nextP = nullptr;
        l = new Lista<T2>();
    }

    NodoP(T d) {

        dato = d;
        nextP = nullptr;
        l = new Lista<T2>();
    }

    void add(T2 d){

        l -> add(d);
    }

    void print(){
        
        cout << dato << " -> " << endl;
        l -> print();
    }
};

template <typename T, typename T2>

class Multilista{

private:
    NodoP<T,T2>* ptr;
    int size;

public:
    Multilista(){

        ptr = NULL;
        size = 0;
    }
  
    ~Multilista(){

        NodoP<T, T2>* temp = ptr;
        while (temp != nullptr){
            NodoP<T, T2>* next_temp = temp -> nextP;
            delete temp;
            temp = next_temp;
        }
      
    }
  
    void add(T d){
        NodoP<T,T2>* n = new NodoP<T,T2>(d);

        if (ptr == NULL){
            ptr =  n;
        } else{
            NodoP<T,T2>* t = ptr;
            while(t -> nextP != nullptr){
                t = t -> nextP;
            }
            t -> nextP = n;
        }
        size++;
    }

    void print(){
        NodoP<T,T2>* t = ptr;
        while(t != nullptr){
            t -> print();
            t = t -> nextP;
        }
    }
  
    void insert(T dato, int pos){

        NodoP<T,T2>* new_nodo = new NodoP<T,T2>(dato);
      
        if (ptr == nullptr || pos <= 0){
            new_nodo -> nextP = ptr;
            ptr = new_nodo;
            size++;
        } else if(pos >= size){
            add(dato);
        } else{
            NodoP<T,T2>* t = ptr;
            int i = 0;
            while (i < pos-1){
                t = t -> nextP;
                i++;
            }
            new_nodo -> nextP = t -> nextP;
            t -> nextP = new_nodo;
            size++;
        }  
    }
  
    NodoP<T,T2>* get(int i){
        NodoP<T,T2>* t = ptr;
        int j = 0;
        while (t != nullptr && j < i){
            t = t -> nextP;
            j++;
        }
        return t;
    }  
};

class Videojuegos {

    private:

    string nombre;
    string desarrollador;
    int anioLanzamiento;
    string plataforma;
    int cantidadJugadores;
    vector<string> categoriasJuego;

    int tiempoJugadoSegundos; 
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

    void setCategoriasJuego(const vector<string>& _categorias){

        categoriasJuego = _categorias;
    }

    vector<string> getCategoriasJuego() const{

        return categoriasJuego;
    }

    void settiempoJugadoSegundos(int _tiempoJugadoSegundos){

        tiempoJugadoSegundos = _tiempoJugadoSegundos;
    }

    int gettiempoJugadoSegundos() const {

        return tiempoJugadoSegundos;
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
        for (const auto& categoria : categoriasJuego){
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
            setCategoriasJuego({"Juego de Palabras", "Juego de adivinanzaz"});

        }else if (juego == "Sonar"){
            
            setnombre("Sonar");
            setdesarrollador("Roberto Fraga");
            setanioLanzamiento(2017);
            setplataforma("Manual");
            setcantidadJugadores(1);
            setCategoriasJuego({"Juego de Estrategia"});
    
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

    void iniciarJuego(){

        startGame = time(nullptr);

    }

    void finJuego(){

        if (startGame != 0){
            time_t endGame = time(nullptr);
            tiempoJugadoSegundos += difftime(endGame, startGame);
            startGame = 0;
        }
    }

    void agregarJuegoACategoria(Multilista<string, string>& multilista){

        int categoriaIndex;
        string categoria, juego;

        cout << "Seleccione la categoria a la que desea agregar un juego: " << endl;
        multilista.print();

        cout << "Ingrese el indice de la categoria: "<< endl;
        cin >> categoriaIndex;

        NodoP<string, string>* nodoCategoria = multilista.get(categoriaIndex);
        if (nodoCategoria == nullptr){
            cout << "El indice de categoria ingresado no es valido" << endl;
            return;
        }

        cout << "Ingrese el nombre del juego que desea agregar a la categoria " << nodoCategoria -> dato() << ":" << endl;
        cin >> juego;

        nodoCategoria -> add(juego);

        cout << "Juego " << juego << " agregado a la categoria " << nodoCategoria -> dato() << " exitosamente" << endl;
    }

    void crearCategoria(Multilista<string, string>& multilista){

        string categoria;

        cout << "Ingrese el nombre de la categoria que desea crear: " << endl;
        cin >> categoria;

        multilista.add(categoria);

        cout << "Categoria " << categoria << " creada exitosamente" << endl;
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

        int n = multilista.size();
        
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

        while (anioLanzamiento != nullptr){
            NodoP<int, Videojuegos>* nodoJuego = multilista.get(0);

            while (nodoJuego->get_dato() == anioLanzamiento->get_dato()){
                nodoJuego->get_lista()->print();
                break;
            }

            nodoJuego = nodoJuego->get_next();
        }

        anioLanzamiento = anioLanzamiento->get_next();
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
            [](const RegistroJuego& a, const RegistroJuego& b){return a.tiempoJugadoSegundos > b.tiempoJugadoSegundos; });
        
        for (const auto& registro : registrosJuego){
            cout << "Nombre del juego: " << registro.nombreJuego << ", Nombre del jugador: " << registro.nombreJugador
            << ", Tiempo jugado: " << registro.tiempoJugadoSegundos << " minutos" << endl;
        }
    }

    void ordenarPorJugador(){

        sort(registrosJuego.begin(), registrosJuego.end(),
            [](const RegistroJuego& a, const RegistroJuego& b){return a.nombreJugador > b.nombreJugador;});

        for (const auto& registro : registrosJuego){
            cout << "Nombre del juego: " << registro.nombreJuego << ", Nombre del jugador: " << registro.nombreJugador
            << ", Tiempo jugado: " << registro.tiempoJugadoSegundos << " minutos" << endl;
        }
    }

    void ordenarPorJuegoMasJugado(){

        sort(registrosJuego.begin(), registrosJuego.end(),
            [](const RegistroJuego& a, const RegistroJuego& b){return a.nombreJuego > b.nombreJuego;});

        vector<pair<string, int>> juegosTiempoTotal;
        string juegoActual = registrosJuego[0].nombreJuego;
        int tiempoTotal = 0;

        for (const auto& registro : registrosJuego){
            if (registro.nombreJuego == juegoActual){
                tiempoTotal += registro.tiempoJugadoSegundos;
            } else {
                juegosTiempoTotal.push_back({juegoActual, tiempoTotal});
                juegoActual = registro.nombreJuego;
                tiempoTotal = registro.tiempoJugadoSegundos;
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
