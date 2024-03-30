#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Videojuegos.cpp"
using namespace std;

class Ahorcado {

    private:

    const vector<string> AHORCADO = {
        R"(
          +---+
          |   |
              |
              |
              |
              |
        =========)",
        R"(
          +---+
          |   |
          O   |
              |
              |
              |
        =========)",
        R"(
          +---+
          |   |
          O   |
          |   |
              | 
              |
        =========)",
        R"(
          +---+
          |   |
          O   |
         /|   |
              |
              |
        =========)",
        R"(
          +---+
          |   |
          O   |
         /|\  |
              |
              |
        =========)",
        R"(
          +---+
          |   |
          O   |
         /|\  |
         /    |
              |
        =========)",
        R"(
          +---+
          |   |
          O   |
         /|\  |
         / \  |
              |
        =========)"
    };

    vector<vector<string>> palabrasNiveles = {
      {"agua", "cielo", "mar", "tierra", "aire", "fuego", "electricidad"},
      {"camiseta", "jean", "zapatos", "medias", "boxers", "esqueleto", "camisa", "gafas", "labial", "manilla"},
      {"futbol", "leer", "tejer", "videojuegos", "patinar", "cocinar", "tenis", "gimnasia", "yoga", "pintar"},
      {"bosa", "kennedy", "fontibon", "chapinero", "teusaquillo", "engativa", "martires", "suba", "tunjuelito", "usme", "sumapaz"},
      {"meximo", "guatemala", "colombia", "brazil", "chile", "ecuador", "argentina", "bolivia", "peru", "honduras", "uruguay", "cuba"},
      {"arquitectura", "jurisprudencia", "biologia", "macc", "filosofia", "medicina", "finanzas", "economia", "fisioterapia", "emprendimiento"}
    };

    int nivel = 0;
    int intentosRestantes = AHORCADO.size() -1;
    string palabra;
    string letrasIncorrectas;
    string letrasCorrectas;

  public:

    Ahorcado(){

      srand(time(nullptr));
    }

    void elegirPalabra(){
      int indice = rand () % palabrasNiveles[nivel].size();
      palabra = palabrasNiveles[nivel][indice];
    }

    void tableroDeJuego(){
      
      cout << AHORCADO[AHORCADO.size() - intentosRestantes] << endl;
      cout << "Nivel: " << nivel + 1 << endl;
      cout << endl;

      cout << "Las letras incorrectas son: " << endl;
      for (char letra : letrasIncorrectas){
        cout << letra << " ";
      }
      cout << endl;

      for (char letra : palabra){
        if (letrasCorrectas.find(letra) != string :: npos){
          cout << letra << " ";
        } else {
          cout << "_ ";
        }
      }
      cout << endl << endl;
    }

    char elegirLetra(){
      
      char letra;
      cout << "Adivina una letra: " << endl;
      cin >> letra;
      return letra;
    }

    bool inicioJuego(){

      char respuesta;
      cout << "¿Quieres jugar de nuevo? (s/n): ";
      cin >> respuesta;
      return respuesta == 's' || respuesta == 'S';
    }

    bool letraCorrecta(char letra){

      if(palabra.find(letra) != string :: npos){
        letrasCorrectas += letra;
        return true;
      }else {
        letrasIncorrectas += letra;
        return false;
      }
    }

    void jugar() {

      bool finJuego = false;

      cout << "*****A H O R C A D O*****" << endl;

      while (!finJuego) {
        elegirPalabra();
        intentosRestantes = AHORCADO.size() - 1;
        letrasCorrectas.clear();
        letrasIncorrectas.clear();

        while (intentosRestantes > 0){
          tableroDeJuego();

          char letra = elegirLetra();

          if (palabra.find(letra) != string :: npos){
            letrasCorrectas += letra;
          } else {
            letrasIncorrectas += letra;
            intentosRestantes --;
          }

          if (letrasCorrectas.size() == palabra.size()){
            cout << "¡Haz adivinado la palabra! La palabra era: " << palabra << endl;
            break;
          }
        }

        if (intentosRestantes == 0){
          cout << "¡Te has quedado sin intentos! La palabra era: " << palabra << endl;
        }

        if (!inicioJuego()){
          finJuego = true;
        }
      }
    }
};