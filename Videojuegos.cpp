#include <iostream>
#include <vector>
#include <list>
#include <ctime> 
#include <algorithm>
using namespace std;


template <typename T>
class Nodo{
private:
  T dato;
  Nodo* next;
public: 
    
    Nodo(){
        next = NULL;
    }
    
    Nodo(T d){
        dato = d;
        next = NULL;
    }
   
    T get_dato(){
        return dato;
    }
    
    void set_dato(T d){
        dato = d;
    }
    
    Nodo<T>* get_next(){
        return next;
    }
    
    void set_next(Nodo<T>* n){
        next = n;
    }
    
    Nodo<T>& operator=(const Nodo<T>& f) { 
		dato = f.dato;
		next = f.next;
		return *this;
	}
	
	static string to_string(const T& dato){
        stringstream ss;
        ss << dato;
        return ss.str();
    }

	friend std::ostream& operator<<(std::ostream& os, Nodo<T>& b) {
		return os << b.to_string();
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
      if(ptr != NULL){
          Nodo<T>* temp =  ptr;
          Nodo<T>* next_temp =  ptr->get_next();
          
          while(next_temp != NULL){
              delete temp;
              temp = next_temp;
              next_temp =  temp->get_next();
          }
          delete temp;
      }
  }
  
  void add(T d){
      Nodo<T>* n = new Nodo<T>(d);
      if(ptr == NULL){
          ptr =  n;
      }else{
          Nodo<T>* t = ptr;
          while(t->get_next() != NULL){
                t = t->get_next();
          }
          t->set_next(n);
      }
      size++;
  }

  void print(){
      Nodo<T>* t = ptr;
      while(t != NULL){
          cout<<(*t)<<endl;
          t = t->get_next();
      }
  }
  
  void insert(T dato, int pos){
      Nodo<T>* t = ptr;
      Nodo<T>* new_nodo = new Nodo<T>(dato);
      
      if(ptr == NULL || pos <= 0){
          new_nodo->set_next(ptr);
          ptr = new_nodo;
          size++;
      }else if(pos >= size){
          add(dato);
      }else{
          Nodo<T>* t = ptr;
          int i=0;
          while(i < pos-1){
                t = t->get_next();
                i++;
          }
          new_nodo->set_next(t->get_next());
          t->set_next(new_nodo);
          size++;
      }
      
  }
  
    
};

template <typename T, typename T2>
class NodoP{
private:
    T dato;
    NodoP<T,T2>* nextP;
    Lista<T2>* l;
public:
    NodoP(){
        nextP = NULL;
        l = new Lista<T2>();
    }
    
    NodoP(T d){
        dato = d;
        nextP = NULL;
        l = new Lista<T2>();
    }
    
    T get_dato(){
        return dato;
    }
    
    void set_dato(T d){
        dato = d;
    }
    
    NodoP<T,T2>* get_next(){
        return nextP;
    }
    
    void set_next(NodoP<T,T2>* n){
        nextP = n;
    }
    
    Lista<T2>* get_lista(){
        return l;
    }
    
    void add(T2 d){
        l->add(d);
    }
    
    void print(){
        cout<<dato<<" -> "<<endl;
        l->print();
    }
    
};


template <typename T, typename T2>
class NodoP2{
private:
    T dato;
    NodoP<T,T2>* nextP;
    Nodo<T2>* ptr;
    int size;
public:
    NodoP2(){
        nextP = NULL;
        ptr = NULL;
        size = 0;
    }
    
    NodoP2(T d){
        dato = d;
        nextP = NULL;
        ptr = NULL;
        size = 0;
    }
    
    T get_dato(){
        return dato;
    }
    
    Nodo<T2>* get_ptr(){
        return ptr;
    }
    
    void add(T2 d){
      Nodo<T2>* n = new Nodo<T2>(d);
      if(ptr == NULL){
          ptr =  n;
      }else{
          Nodo<T2>* t = ptr;
          while(t->get_next() != NULL){
                t = t->get_next();
          }
          t->set_next(n);
      }
      size++;
  }

  void print(){
      cout<<dato<<" -> "<<endl;
      Nodo<T2>* t = ptr;
      while(t != NULL){
          cout<<(*t)<<endl;
          t = t->get_next();
      }
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
      if(ptr != NULL){
          NodoP<T,T2>* temp =  ptr;
          NodoP<T,T2>* next_temp =  ptr->get_next();
          
          while(next_temp != NULL){
              delete temp;
              temp = next_temp;
              next_temp =  temp->get_next();
          }
          delete temp;
      }
  }
  
  void add(T d){
      NodoP<T,T2>* n = new NodoP<T,T2>(d);
      if(ptr == NULL){
          ptr =  n;
      }else{
          NodoP<T,T2>* t = ptr;
          while(t->get_next() != NULL){
                t = t->get_next();
          }
          t->set_next(n);
      }
      size++;
  }

  void print(){
      NodoP<T,T2>* t = ptr;
      while(t != NULL){
          //cout<<(*t)<<endl;
          t->print();
          t = t->get_next();
      }
  }
  
  void insert(T dato, int pos){
      NodoP<T,T2>* t = ptr;
      NodoP<T,T2>* new_nodo = new NodoP<T,T2>(dato);
      
      if(ptr == NULL || pos <= 0){
          new_nodo->set_next(ptr);
          ptr = new_nodo;
          size++;
      }else if(pos >= size){
          add(dato);
      }else{
          NodoP<T,T2>* t = ptr;
          int i=0;
          while(i < pos-1){
                t = t->get_next();
                i++;
          }
          new_nodo->set_next(t->get_next());
          t->set_next(new_nodo);
          size++;
      }
      
  }
  
  NodoP<T,T2>* get(int i){
          NodoP<T,T2>* t = ptr;
          int j=0;
          while(t != NULL && j<i){
              t = t->get_next();
              j++;
          }
          return t;
      }
    
};

struct RegistroJuego {

    string nombreJuego, nombreJugador;
    int tiempoJugadoSegundos;

    RegistroJuego(string _nombreJuego, string _nombreJugador, int _tiempoJugadoSegundos){

        nombreJuego = _nombreJuego;
        nombreJugador = _nombreJugador;
        tiempoJugadoSegundos = _tiempoJugadoSegundos;
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
    int tiempoJugadoSegundos; 
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
        nombreJugadorActual = nombreJugador;
    }

    void finJuego(){

        if (startGame != 0){
            time_t endGame = time(nullptr);
            tiempoJugadoSegundos += difftime(endGame, startGame);
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
