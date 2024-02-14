#ifndef BUSCADOR_CARRERAS_H
#define BUSCADOR_CARRERAS_H

#include <string>
#include "lista.h" 
#include "carrera.h"

class Buscador_Carreras {
public:
    /* 
    Pre: agregar las necesarias
    Post: busca en “carreras” aquellas que tienen tres o más materias de 
    la lista “materias_predilectas” y una duración menor o igual que 
    duracion_maxima.
    Devuelve un puntero a una lista con las carreras que cumplen con estas 
    características.
    */
    Lista<Carrera*>* sugerir_carreras(Lista<Carrera*>* carreras, int duracion_maxima, Lista<std::string>* materias_predilectas);
};

#endif // BUSCADOR_CARRERAS_H