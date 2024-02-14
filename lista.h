#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "nodo.h"

template <class T>
class Lista {
private:
    Nodo<T>* primero;
    int cantidad;

public:
    // Constructor 
    // pre: -
    // pos: crea una lista vacía
    Lista() {
        primero = nullptr;
        cantidad = 0;
    }

    // pre: -
    // pos: devuelve el nodo en la posición pos
    Nodo<T>* obtener_nodo(int pos) {
        Nodo<T>* pn = primero;
        for (int i = 1; i < pos; i++)
            pn = pn->obtener_siguiente();
        return pn;
    }

    // pre: -
    // pos: agrega un dato al final de la lista
    void alta(T d) {
        Nodo<T>* nuevo = new Nodo<T>(d);
        if (primero == nullptr) {
            primero = nuevo;
        } else {
            Nodo<T>* temp = primero;
            while (temp->obtener_siguiente() != nullptr) {
                temp = temp->obtener_siguiente();
            }
            temp->cambiar_siguiente(nuevo);
        }
        cantidad++;
    }

    // pre: 1 <= pos <= cantidad + 1
    // pos: agrega un dato en la posición pos
    void baja(int pos) {
        Nodo<T>* borrar = primero;
        if (pos == 1) {
            primero = borrar->obtener_siguiente();
        } else {
            Nodo<T>* anterior = obtener_nodo(pos - 1);
            borrar = anterior->obtener_siguiente();
            Nodo<T>* siguiente = borrar->obtener_siguiente();
            anterior->cambiar_siguiente(siguiente);
        }
        delete borrar;
        cantidad--;
    }

    // pre: 1 <= pos <= cantidad
    // pos: devuelve el dato en la posición pos
    T consulta(int pos) {
        Nodo<T>* pn = obtener_nodo(pos);
        return pn->obtener_dato();
    }

    // pre: 1 <= pos <= cantidad
    // pos: cambia el dato en la posición pos
    bool esta_vacia() {
        return (cantidad == 0);
    }

    // pre: -
    // pos: devuelve la cantidad de elementos en la lista
    int obtener_cantidad() {
        return cantidad;
    }

    // pre: -
    // pos: devuelve el primer nodo de la lista
    Nodo<T>* obtener_primero() {
        return primero;
    }

    // pre: -
    // pos: devuelve true si el nodo con el dato d se encuentra en la lista
    bool buscar(T d) {
        Nodo<T>* temp = primero;
        while (temp != nullptr) {
            if (temp->obtener_dato() == d) {
                return true;
            }
            temp = temp->obtener_siguiente();
        }
        return false;
    }

    // Destructor
    // pre: -
    // pos: libera la memoria utilizada por la lista
    ~Lista() {
        while (!esta_vacia())
            baja(1);
    }
};

#endif // LISTA_H
