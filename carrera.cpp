#include "carrera.h"

Carrera::Carrera(std::string nombre, int duracion, Lista<std::string>* materias) {
    this->nombre = nombre;
    this->duracion = duracion;
    this->materias = materias;
}

std::string Carrera::obtener_nombre() {
    return nombre;
}

int Carrera::obtener_duracion() {
    return duracion;
}

Lista<std::string>* Carrera::obtener_materias() {
    return materias;
}
