#include <iostream>
#include <vector>
#include <list>
#include <ctime> 
#include <algorithm>
using namespace std;

struct Juego {

    string nombre;
    string desarrollador;
    int anioLanzamiento;
    string plataforma;
    int cantidadJugadores;
    vector<string> categoriasJuego;
    
    Juego(const string& nombre,const string& desarrollador, int anioLanzamiento,
    const string& plataforma, int cantidadJugadores, const vector<string>& categorias){

        this -> nombre = nombre;
        this -> desarrollador = desarrollador;
        this -> anioLanzamiento = anioLanzamiento;
        this -> plataforma = plataforma;
        this -> cantidadJugadores = cantidadJugadores;
        this -> categoriasJuego = categorias;

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

    vector<Juego> listaJuegos;

    

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

    void agregarJuego(const Juego& juego){
        listaJuegos.push_back(juego);
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

            Juego nuevoJuego("Juego del Ahorcado", "Julio Roberto Garbini", 1978, "Speak & Sell", 1, {"Juego de Palabras", "Juego de Adivinanzas"});
            agregarJuego(nuevoJuego);

        }else if (juego == "Sonar"){
            
            Juego nuevoJuego("Sonar", "Roberto Fraga", 2017, "Manual", 1, {"Juego de Estrategia"});
            agregarJuego(nuevoJuego);
    
        }
    }

    void menu(){

        cout << "Bienvenido a Mattel" << endl;
        cout << "1.Registar Juego" << endl;
        cout << "2.Mostrar videojuegos disponibles para jugar" << endl;
        cout << "3.Crear categorias" << endl;
        cout << "4.Agregar juegos a las categorias" << endl;
        cout << "5.Agregar un juego a la lista de favoritos" << endl;
        cout << "6.Mostrar la lista de favoritos" << endl;
        cout << "7.Lista videojuegos por ordenamientos" << endl;
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
    
    void registrarJuego(){

        string nombre, desarrollador, plataforma, categoria;
        int anioLanzamiento, cantidadJugadores;
        vector<string> categoriasJuego;

        cout << "Ingrese el nombre del juego: " << endl;
        cin >> nombre;
        cout << "Ingrese el desarrollador del juego: " << endl;
        cin >> desarrollador;
        cout << "Ingrese el anio de lanzamiento del juego: " << endl;
        cin >> anioLanzamiento;
        cout << "Ingrese la plataforma donde se juega el juego: " << endl;
        cin >> plataforma;
        cout << "Ingrese la cantidad de jugadores: " << endl;
        cin >> cantidadJugadores;

        cout << "Ingrese las categorias del juego (ingrese 'fin' para terminar): " << endl;
        while (cin >> categoria && categoria != "fin"){
            categoriasJuego.push_back(categoria);
        }

        Juego nuevoJuego(nombre, desarrollador, anioLanzamiento, plataforma, cantidadJugadores, categoriasJuego);
        agregarJuego(nuevoJuego);
        cout << "Juego registrado correctamente" << endl;
    }
};

template <typename T, typename T2>
class Multilista{
private:

    struct NodoP {
        
        T dato;
        Multilista<T,T2>* l;
        NodoP* nextP;

        NodoP(){

            nextP = nullptr;
            l = new Multilista<T,T2>();
        }

        NodoP(T d){

            dato = d;
            nextP = nullptr;
            l = new Multilista<T,T2>();
        }

        void print(){
            NodoP* t = nextP;
            while(t != nullptr){
                cout << t->dato << " -> " << endl;
                t -> l -> print();
                t = t -> nextP;
            }
        }
    };

    NodoP* ptr;
    int size;
    vector<string>juegoFavorito;
    
public:

    void agregarListaFavoritos(const string& videojuego){

        juegoFavorito.push_back(videojuego);
    }
    
    const vector<string>& getjuegoFavorito() const {

        return juegoFavorito;
    }

    Multilista(){

        ptr = nullptr;
        size = 0;
    }
  
    ~Multilista(){

        NodoP* temp = ptr;
        while (temp != nullptr){
            NodoP* next_temp = temp -> nextP;
            delete temp -> l;
            delete temp;
            temp = next_temp;
        }
      
    }
  
    void add(T d){
        NodoP* n = new NodoP(d);

        if (ptr == nullptr){
            ptr =  n;
        } else{
            NodoP* t = ptr;
            while(t -> nextP != nullptr){
                t = t -> nextP;
            }
            t -> nextP = n;
        }
        size++;
    }

    void print(){
        NodoP* t = ptr;
        while(t != nullptr){
            cout << t->dato << " -> " << endl;
            t -> l -> print();
            t = t -> nextP;
        }
    }
  
    void insert(T dato, int pos){

        NodoP* new_nodo = new NodoP(dato);
      
        if (ptr == nullptr || pos <= 0){
            new_nodo -> nextP = ptr;
            ptr = new_nodo;
            size++;
        } else if(pos >= size){
            add(dato);
        } else{
            NodoP* t = ptr;
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

    int getSize() const {
        
        return size;
    }
  
    NodoP* get(int i){
        NodoP* t = ptr;
        int j = 0;
        while (t != nullptr && j < i){
            t = t -> nextP;
            j++;
        }
        return t;
    } 

    void agregarCategoria(){
        
        T categoria;

        cout << "Ingrese el nombre de la categoria: " << endl;
        cin >> categoria;

        add(categoria);
    } 

    void agregarJuegoACategoria(){

        T2 juego;
        int categoria;
        int indice = 0;

        cout << "Ingrese el nombre del juego: " << endl;
        cin >> juego;

        cout << "Categorias disponibles: " << endl;
        NodoP* t = ptr;
        while (t != nullptr){
            cout << indice << ". " << t->dato << endl;
            t = t-> nextP;
            indice++;
        }
        
        cout << "Ingrese el indice de la categoria donde desea agregar el juego: " << endl;
        cin >> categoria;

        if (categoria >=0 && categoria < size){
            NodoP* categoria_nodo = get(categoria);
            if (categoria_nodo != nullptr){
                categoria_nodo -> l -> add(juego);
            } else {
                cout << "El indice especificado no existe" << endl;
            }
        } else {

            cout << "El indice de categoria es invalido" << endl;
        }
    }

    void agregarAFavoritos(){

        string juego;

        cout << "Ingrese el nombre del juego que desea agregar a favoritos: " << endl;
        cin >> juego;

        NodoP* temp = ptr;
        while (temp != nullptr){
            NodoP* listaJuegos = temp -> l -> ptr;
            while (listaJuegos != nullptr){
                if (listaJuegos -> dato == juego){
                    temp ->l -> juegoFavorito.push_back(juego);
                    cout << "Juego agregado exitosamente" << endl;
                    return;
                }
                listaJuegos = listaJuegos->nextP;
            }
            temp = temp -> nextP;
        }

        cout << "El juego no existe en la multilista" << endl;

    }

    void mostrarFavoritos() const{

        cout << "La lista de favoritos es: " << endl;
        for (const string&fav : juegoFavorito){
            cout << fav << endl;
        }
    }
    
};
