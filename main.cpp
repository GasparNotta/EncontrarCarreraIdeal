#include "lista.h"
#include "carrera.h"
#include "buscador_carreras.h"
#include <iostream>

int main() {
    // Crear una lista de materias predilectas
    Lista<std::string>* materias_predilectas = new Lista<std::string>();
    materias_predilectas->alta("Programación");
    materias_predilectas->alta("Algebra");
    materias_predilectas->alta("Física");

    // Definir la duración máxima deseada
    const int duracion_maxima_deseada = 5;

    // Crear una lista de carreras
    Lista<Carrera*>* carreras = new Lista<Carrera*>();

    // Crear carreras
    Lista<std::string>* materias_carrera1 = new Lista<std::string>();
    materias_carrera1->alta("Algebra");
    materias_carrera1->alta("Analisis Matemático");
    materias_carrera1->alta("Física");
    materias_carrera1->alta("Química");
    materias_carrera1->alta("Programación");
    Carrera* carrera1 = new Carrera("Ingeniería", 5, materias_carrera1);
    carreras->alta(carrera1);

    Lista<std::string>* materias_carrera2 = new Lista<std::string>();
    materias_carrera2->alta("Matemáticas");
    materias_carrera2->alta("Física");
    materias_carrera2->alta("Biología");
    materias_carrera2->alta("Química");
    Carrera* carrera2 = new Carrera("Biología", 4, materias_carrera2);
    carreras->alta(carrera2);

    Lista<std::string>* materias_carrera3 = new Lista<std::string>();
    materias_carrera3->alta("Quimica");
    materias_carrera3->alta("Anatomia");
    materias_carrera3->alta("Biología");
    materias_carrera3->alta("Física");
    Carrera* carrera3 = new Carrera("Medicina", 6, materias_carrera3);
    carreras->alta(carrera3);

    Lista<std::string>* materias_carrera4 = new Lista<std::string>();
    materias_carrera4->alta("Historia");
    materias_carrera4->alta("Literatura");
    materias_carrera4->alta("Filosofía");
    materias_carrera4->alta("Idiomas");
    materias_carrera4->alta("Sociología");
    Carrera* carrera4 = new Carrera("Humanidades", 4, materias_carrera4);
    carreras->alta(carrera4);

    Lista<std::string>* materias_carrera5 = new Lista<std::string>();
    materias_carrera5->alta("Economía");
    materias_carrera5->alta("Estadística");
    materias_carrera5->alta("Finanzas");
    materias_carrera5->alta("Marketing");
    materias_carrera5->alta("Gestión Empresarial");
    Carrera* carrera5 = new Carrera("Administración de Empresas", 5, materias_carrera5);
    carreras->alta(carrera5);

    Lista<std::string>* materias_carrera6 = new Lista<std::string>();
    materias_carrera6->alta("Derecho Constitucional");
    materias_carrera6->alta("Derecho Penal");
    materias_carrera6->alta("Derecho Civil");
    materias_carrera6->alta("Derecho Laboral");
    materias_carrera6->alta("Derecho Internacional");
    Carrera* carrera6 = new Carrera("Derecho", 6, materias_carrera6);
    carreras->alta(carrera6);


    // Usar el buscador de carreras para sugerir carreras
    Buscador_Carreras buscador;
    Lista<Carrera*>* carreras_sugeridas = buscador.sugerir_carreras(carreras, duracion_maxima_deseada, materias_predilectas);

    // Imprimir las carreras sugeridas
    Nodo<Carrera*>* temp = carreras_sugeridas->obtener_primero();
    if (temp == nullptr) {
        std::cout << "No se encontraron carreras sugeridas" << std::endl;
    } else {
        while (temp != nullptr) {
        std::cout << "Carrera sugerida: " << temp->obtener_dato()->obtener_nombre() << std::endl;
        temp = temp->obtener_siguiente();
    }
    }
    
    // Liberar memoria utilizada
    while (!carreras->esta_vacia()) {
        Carrera* temp = carreras->consulta(1);
        delete temp;
        carreras->baja(1);
    }
    delete carreras;
    delete materias_carrera1;
    delete materias_carrera2;
    delete materias_carrera3;
    delete materias_carrera4;
    delete materias_carrera5;
    delete materias_carrera6;
    delete carreras_sugeridas;
    delete materias_predilectas;

    return 0;
}
   