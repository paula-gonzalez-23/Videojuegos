#include <iostream>
#include <vector>
#include <list>
#include <ctime> 
#include <algorithm>
using namespace std;

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
        cout << "2.Agregar un videojuego a la categoria deseada" << endl;
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

    void agregarAFavoritos(const Multilista<string, string>& multilista){

        string juego;

        cout << "Ingrese el nombre del juego que desea agregar a favoritos: " << endl;
        cin >> juego;

        bool juegoExiste = false;
        for (int i = 0; i < multilista.getSize(); ++i){
            Multilista<string, string>::NodoP * categoria = multilista.get(i);
            if (categoria != nullptr){
                Multilista<string, string>* listaJuegos = categoria -> l;
                for (Multilista<string, string>::NodoP * juegoNode = listaJuegos ->ptr; juegoNode != nullptr; juegoNode = juegoNode->nextP){
                    if (juegoNode -> dato == juego){
                        juegoExiste = true;
                        break;
                    }
                }
            }

            if (juegoExiste) break;
        }

        if (juegoExiste){

            bool juegoYaEnFavoritos = false;
            for (const string& fav : juegoFavorito){
                if (fav == juego){
                    juegoYaEnFavoritos = true;
                    break;
                }
            }

            if (!juegoYaEnFavoritos){
                juegoFavorito.push_back(juego);
                cout << "Juego agregado a la lista de favoritos" << endl;
            } else {
                cout << "El juego ya existe en la lista de favoritos" << endl;
            }

        } else{
            cout << "El juego no existe en la multilista" << endl;
        }
 
    }

    void mostrarFavoritos() const{

        cout << "La lista de favoritos es: " << endl;
        for (const string&fav : juegoFavorito){
            cout << fav << endl;
        }
    }
    
};
