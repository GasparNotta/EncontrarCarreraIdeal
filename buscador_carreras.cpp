#include "buscador_carreras.h"

Lista<Carrera*>* Buscador_Carreras::sugerir_carreras(Lista<Carrera*>* carreras, int duracion_maxima, Lista<std::string>* materias_predilectas) {
    Lista<Carrera*>* carreras_sugeridas = new Lista<Carrera*>();

    Nodo<Carrera*>* actual = carreras->obtener_primero();
    while (actual != nullptr) {
        int materias_encontradas = 0;
        Nodo<std::string>* actual_materia = actual->dato->obtener_materias()->obtener_primero();
        while (actual_materia != nullptr) {
            Nodo<std::string>* actual_predilecta = materias_predilectas->obtener_primero();
            while (actual_predilecta != nullptr) {
                if (actual_materia->dato == actual_predilecta->dato) {
                    materias_encontradas++;
                    break;
                }
                actual_predilecta = actual_predilecta->siguiente;
            }
            actual_materia = actual_materia->siguiente;
        }
        if (materias_encontradas >= 3 && actual->dato->obtener_duracion() <= duracion_maxima) {
            carreras_sugeridas->alta(actual->dato);
        }
        actual = actual->siguiente;
    }
    
    return carreras_sugeridas;
}