#include<iostream>

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
	
	string to_string() {
		return dato;
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


int main()
{
    Multilista<string, string> m;
    
    int opcion;
    int indice;
    string juego = "";
    
    cout << "Bienvenido a la multilista de juegos" << endl;
    m.add("1. Accion");
    m.add("2. Carreras");
    m.add("3. Lucha");
    
    m.print();
    
    while(true){
        cout << "Desea Agregar juegos a las listas? ó Desea mirar los juegos almacenados en las listas?" << endl << "1. Agregar // 2. Mirar // 3. salir" << endl;
        cin >> opcion;
        
        switch (opcion){
            case 1:
                
                cout << "A que genero de juego pertenece el juego que desea agregar" << endl;
                cin >> indice;
                indice -= 1;
                cout << "Ingrese el nombre del juego que desea agregar: " << endl;
                cin >> juego;
                
                m.get(indice) -> add(juego);
                
            
                break;
            case 2:
            
                cout << "Estos son los juegos actualmente agregados." << endl;
                m.print();
            
                break;
            
            case 3:
            
                cout << "Gracias por usar la multilista" << endl;
                break;
            
            
            default:
                cout << "Ingrese una opcion valida" << endl;
        }
        if(opcion == 3){
            break;
        }
    }
   
    
    return 0;
}