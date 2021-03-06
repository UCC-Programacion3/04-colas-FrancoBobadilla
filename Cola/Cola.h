#ifndef COLA_H
#define COLA_H


#include "Nodo.h"

template<class T>
class Cola {
private:
    Nodo<T> *frente;
    Nodo<T> *fondo;

public:
    Cola();

    ~Cola();

    void encolar(T dato);

    T desencolar();

    bool esVacia();

    void vaciar();

    T verFrente();
};

template<class T>
Cola<T>::Cola() {
    fondo = frente = NULL;
}

template<class T>
Cola<T>::~Cola() {
    vaciar();
}

template<class T>
void Cola<T>::encolar(T dato) {
    if (fondo == NULL && frente == NULL) {
        frente = fondo = new Nodo<T>(dato);
    } else {
        fondo->setNext(new Nodo<T>(dato));
    }
}

template<class T>
T Cola<T>::desencolar() {
    if (esVacia()) throw 1;
    T tmp;
    Nodo<T> *aux = frente;
    frente = frente->getNext();
    tmp = aux->getDato();
    delete aux;
    /*if (frente == NULL)
        fondo = NULL;*/
    return tmp;
}

template<class T>
bool Cola<T>::esVacia() {
    return frente == NULL;
}

template<class T>
void Cola<T>::vaciar() {

    while (frente != NULL)
        desencolar();

}

template<class T>
T Cola<T>::verFrente() {
    if (esVacia()) throw 1;
    return frente->getDato();
}


#endif //LISTA_H