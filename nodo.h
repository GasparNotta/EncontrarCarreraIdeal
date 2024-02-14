#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;
    
    // constructor
    // pre: -
    // pos: crea un nodo con el dato dado
    Nodo(const T& dato) : dato(dato), siguiente(nullptr) {}

    // pre: -
    // pos: devuelve el dato que contiene el nodo
    T obtener_dato() {
        return dato;
    }

    // pre: -
    // pos: devuelve el puntero al siguiente nodo
    Nodo<T>* obtener_siguiente() {
        return siguiente;
    }

    // pre: -
    // pos: cambia el dato que contiene el nodo
    void cambiar_dato(T d) {
        dato = d;
    }

    // pre: -
    // pos: cambia el puntero al siguiente nodo
    void cambiar_siguiente(Nodo<T>* pn) {
        siguiente = pn;
    }
};

#endif // NODO_H