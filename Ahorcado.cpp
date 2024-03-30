#include <iostream>
#include <random>
using namespace std;

class Ahorcado {

    private:

    const vector<string> Ahorcado = {
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

    vector<string> listaNivel1 = {"agua", "cielo", "mar", "tierra", "aire", "fuego", "electricidad"};
    vector<string> listaNivel2 = {"camiseta", "jean", "zapatos", "medias", "boxers", "esqueleto", "camisa", "gafas", "labial", "manilla"};
    vector<string> listaNivel3 = {"futbol", "leer", "tejer", "videojuegos", "patinar", "cocinar", "tenis", "gimnasia", "yoga", "pintar"};
    vector<string> listaNivel4 = {"bosa", "kennedy", "fontibon", "chapinero", "teusaquillo", "engativa", "martires", "suba", "tunjuelito", "usme", "sumapaz"};
    vector<string> listaNivel5 = {"meximo", "guatemala", "colombia", "brazil", "chile", "ecuador", "argentina", "bolivia", "peru", "honduras", "uruguay", "cuba"};
    vector<string> listaNivel6 = {"arquitectura", "jurisprudencia", "biologia", "macc", "filosofia", "medicina", "finanzas", "economia", "fisioterapia", "emprendimiento"};

    int nivel = 1;
    int intentosRestantes = Ahorcado.size() -1;
    string palabra;
    string letrasIncorrectas;
    string letrasCorrectas;


};
