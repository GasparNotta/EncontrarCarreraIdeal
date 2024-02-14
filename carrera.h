#ifndef CARRERA_H
#define CARRERA_H

#include "lista.h"
#include <string>


class Carrera {
private:
    std::string nombre;
    int duracion;
    Lista<std::string>* materias;

public:
    // Constructor
    // pre: -
    // pos: Crea una Carrera con su nombre, la duración (en años) y una lista de materias
    Carrera(std::string nombre, int duracion, Lista<std::string>* materias);

    // pre: -
    // pos: devuelve el nombre de la carrera
    std::string obtener_nombre();

    // pre: -
    // pos: devuelve la duracion de la carrera
    int obtener_duracion();

    // pre: -
    // pos: devuelve un puntero a la lista de materias
    Lista<std::string>* obtener_materias();
};

#endif // CARRERA_H