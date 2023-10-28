#ifndef U02_LISTAS_LISTA_LISTA_H_
#define U02_LISTAS_LISTA_LISTA_H_
#include "nodo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Lista {
protected:
  Nodo<T> *inicio;

public:
  Lista();

  Lista(const Lista<T> &li);

  ~Lista();

  bool esVacia();

  int getTamanio();

  void insertar(int pos, T dato , T deposito);

  void insertarPrimero(T dato, T deposito );


  // modificamos insertar ultimo para que tenga mas de un dato mi lista;
  void insertarUltimo(T dato);

    void insertarUltimoDatYdepo(T dato, T deposito);


  void remover(int pos);

  T getDato(int pos);

  // nueva funcion implementada
   T getDeposito(int pos);


    void reemplazar(int pos, T dato);

  void vaciar();

  void print();

  int datosolisitado (std::string datoAingresar );   // compara el numero de ocurrencias de un dato y devuelve el numero de veces que sucede.

};

/**
 * Constructor de la clase Lista
 * @tparam T
 */
template <class T> Lista<T>::Lista() { inicio = nullptr; }

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template <class T> Lista<T>::Lista(const Lista<T> &li) { inicio = li.inicio; }

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T> Lista<T>::~Lista() { vaciar(); }

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T> bool Lista<T>::esVacia() { return inicio == nullptr; }

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template <class T> int Lista<T>::getTamanio() {
  Nodo<T> *aux = inicio;
  int size = 0;

  while (aux != nullptr) {
    aux = aux->getSiguiente();
    size++;
  }

  return size;
}

/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template <class T> void Lista<T>::insertar(int pos, T dato, T deposito) {
  int posActual = 0;
  Nodo<T> *aux = inicio, *nuevo;
  nuevo = new Nodo<T>;
  nuevo->setDato(dato);
  nuevo->seetDato(deposito);

  if (pos == 0) {
    nuevo->setSiguiente(inicio);
    inicio = nuevo;
    return;
  }

  while (aux != nullptr && posActual < pos - 1) {
    aux = aux->getSiguiente();
    posActual++;
  }

  if (aux == nullptr) {
    throw 404;
  }

  nuevo->setSiguiente(aux->getSiguiente());
  aux->setSiguiente(nuevo);
}

/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarPrimero(T dato, T deposito) { insertar(0, dato, deposito); }

/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */

// modificamos para que  acepte el dato de deposito.
template <class T> void Lista<T>::insertarUltimoDatYdepo(T dato, T deposito) {
  Nodo<T> *aux = inicio, *nuevo;
  nuevo = new Nodo<T>;
    nuevo->setDeposito(deposito);
    nuevo->setDato(dato);

  if (aux == nullptr) {
    nuevo->setSiguiente(inicio);
    inicio = nuevo;
    return;
  }

  while (aux->getSiguiente() != nullptr) {
    aux = aux->getSiguiente();
  }

  nuevo->setSiguiente(aux->getSiguiente());
  aux->setSiguiente(nuevo);
}

template <class T> void Lista<T>::insertarUltimo(T dato) {
    Nodo<T> *aux = inicio, *nuevo;
    nuevo = new Nodo<T>;
    nuevo->setDato(dato);

    if (aux == nullptr) {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }

    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template <class T> void Lista<T>::remover(int pos) {
  Nodo<T> *aux = inicio, *aBorrar;
  int posActual = 0;

  if (pos == 0) {
    inicio = inicio->getSiguiente();
    delete aux;
    return;
  }

  while (aux != nullptr && posActual < pos - 1) {
    aux = aux->getSiguiente();
    posActual++;
  }

  if (aux == nullptr) {
    throw 404;
  }

  aBorrar = aux->getSiguiente();
  aux->setSiguiente(aBorrar->getSiguiente());

  delete aBorrar;
}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template <class T> T Lista<T>::getDato(int pos) {
  Nodo<T> *aux = inicio;
  int posActual = 0;

  while (aux != nullptr && posActual < pos) {
    aux = aux->getSiguiente();
    posActual++;
  }

  if (aux == nullptr) {
    throw 404;
  }

  return aux->getDato();
}

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */

// implementada por nosotros:

template <class T> T Lista<T>::getDeposito(int pos){
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    return aux->getDeposito();
}





template <class T> void Lista<T>::reemplazar(int pos, T dato) {
  Nodo<T> *aux = inicio;
  int posActual = 0;

  while (aux != nullptr && posActual < pos) {
    aux = aux->getSiguiente();
    posActual++;
  }

  if (aux == nullptr) {
    throw 404;
  }

  aux->setDato( dato );
}

/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template <class T> void Lista<T>::vaciar() {
	Nodo<T> *aux = inicio, *aBorrar;

	while( aux != nullptr ){
		aBorrar = aux;
		aux = aux->getSiguiente();
		delete aBorrar;
	}

	inicio = nullptr;

}

template<class T>
void Lista<T>::print() {
    Nodo<T> *aux = inicio;

    while (aux != nullptr) {
        std::cout << aux->getDato() << "->";
        aux = aux->getSiguiente();
    }
    std::cout << "NULL" << std::endl;
}


template<class T>
int Lista<T>::datosolisitado(std::string datoAingresar) {

    Nodo<T> *PosicionOcurrencia = inicio; // igualo el nodo en el que me encuentro a inicio
    int repeticiones = 0;
    if (PosicionOcurrencia == nullptr) {
        throw 404;
    }
    if (datoAingresar == " ") {
        throw 400;
    } else {
        while (PosicionOcurrencia != nullptr) {  // mientras que no me encuentre en el final de la lsita que mueva la posicion
            if ( datoAingresar==PosicionOcurrencia->getDato()) {
                repeticiones++;
            }
            PosicionOcurrencia=PosicionOcurrencia ->getSiguiente();
        }
        if (PosicionOcurrencia == nullptr) { // si llega al final de la cola que devuelva el valor de repeticiones de dicha ocurrencia.
            return repeticiones;

        }
     }
  }



#endif // U02_LISTAS_LISTA_LISTA_H_