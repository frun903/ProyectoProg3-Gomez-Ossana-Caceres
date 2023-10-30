#ifndef U02_LISTAS_LISTA_LISTA_H_
#define U02_LISTAS_LISTA_LISTA_H_
#include "nodo.h"
#include <iostream>
/**
 * Clase que implementa una ListaFT Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class ListaFT {
private:
  Nodo<T> *inicio;

public:
  ListaFT();

  ListaFT(const ListaFT<T> &li);

  ~ListaFT();

  bool esVacia();

  int getTamanio();

  void insertar(int pos, T dato, T deposito);

  void insertarPrimero(T dato, T deposito);

  void insertarUltimo(T dato, T deposito);

  void remover(int pos);

  T getDato(int pos);

  T getDeposito(int pos);

  void reemplazar(int pos, T dato);

  void vaciar();

  void print();

  void reversion();

  void ImparaPar();

  void oddLista();

  bool hasCycle();

  bool Palindrome();

  void  Reorder();

  void byJuan_1(int pos);

  void byJuan_2(int pos);

  void byJuan_0(int pos);


};

/**
 * Constructor de la clase ListaFT
 * @tparam T
 */
template <class T> ListaFT<T>::ListaFT() { inicio = nullptr; }

/**
 * Constructor por copia de la clase ListaFT
 * @tparam T
 * @param li
 */
template <class T> ListaFT<T>::ListaFT(const ListaFT<T> &li) { inicio = li.inicio; }

/**
 * Destructor de la clase ListaFT, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T> ListaFT<T>::~ListaFT() { vaciar(); }

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T> bool ListaFT<T>::esVacia() { return inicio == nullptr; }

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template <class T> int ListaFT<T>::getTamanio() {
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
template <class T> void ListaFT<T>::insertar(int pos, T dato, T deposito) {
  int posActual = 0;
  Nodo<T> *aux = inicio, *nuevo;
  nuevo = new Nodo<T>;
  nuevo->setDato(dato);
    nuevo->setDato(deposito);

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
template <class T> void ListaFT<T>::insertarPrimero(T dato, T deposito) { insertar(0, dato, deposito); }

/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void ListaFT<T>::insertarUltimo(T dato, T deposito) {
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

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template <class T> void ListaFT<T>::remover(int pos) {
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
template <class T> T ListaFT<T>::getDato(int pos) {
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

template <class T> T ListaFT<T>::getDeposito(int pos){
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

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template <class T> void ListaFT<T>::reemplazar(int pos, T dato) {
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
template <class T> void ListaFT<T>::vaciar() {
	Nodo<T> *aux = inicio, *aBorrar;

	while( aux != nullptr ){
		aBorrar = aux;
		aux = aux->getSiguiente();
//		delete aBorrar; //Modificacion echa despues?
	}

	inicio = nullptr;

}

template<class T>
void ListaFT<T>::print() {
    Nodo<T> *aux = inicio;

    while (aux != nullptr) {
        std::cout<<"Depisito: "<<aux->getDeposito()<<"   Stok:"<<aux->getDato() << std::endl;
        aux = aux->getSiguiente();
    }
    //std::cout << "NULL" << std::endl;
}


template<class T> void ListaFT<T>::reversion() {
    Nodo<T> *anterior= nullptr;
    Nodo<T> *actual=inicio;
    Nodo<T>*futuro;

    //Si la lista esta vacia da un error
    if (inicio== nullptr) {
        throw 404;
    }

    //Si la lista tiene un solo nodo
    if (inicio->getSiguiente()== nullptr) {
        return;
    }



    while (actual!= nullptr) {

        futuro=actual->getSiguiente();

        actual->setSiguiente(anterior);
        anterior=futuro->getSiguiente();
        futuro->setSiguiente(actual);

        actual=anterior;
        anterior=futuro;

    }

    inicio=anterior;

}


template<class T> void ListaFT<T>::ImparaPar() {


    //Defino los punteros fijos cabezas de linea
    Nodo<T> *inicio_impar = nullptr;
    Nodo<T> *inicio_par = nullptr;
    //punteros de movimiento
    Nodo<T> *puntero_general = inicio;
    Nodo<T> *puntero_a_par = nullptr;
    Nodo<T> *puntero_a_impar = nullptr;


    //Caso extremo un nodo o lista vacia
    if (inicio == nullptr || inicio->getSiguiente() == nullptr) {
        return;
    }

    //el puntero general se ira moviendo a lo largo de la lista
    while (puntero_general != nullptr) {

        //Para los pares
        if (puntero_general->getDato() % 2 == 0) {
            //Si es la primera iteracion
            if (inicio_par == nullptr) {
                inicio_par = puntero_general;
                puntero_a_par = inicio_par;
            } else {
                puntero_a_par->setSiguiente(puntero_general);
                puntero_a_par = puntero_general;
            }
        }

        //Para los impares
        if (puntero_general->getDato() % 2 != 0) {
            //Si es la primera iteracion
            if (inicio_impar == nullptr) {
                inicio_impar = puntero_general;
                puntero_a_impar = inicio_impar;
            } else {
                puntero_a_impar->setSiguiente(puntero_general);
                puntero_a_impar = puntero_general;
            }
        }
    }
    //Como el metodo requiere a los impares primeros
    /*Se que puntero a impar quedo en el ultimo elemento
     * impar y tengo la referencia del inicio par,
     * entonces hago*/
    puntero_a_impar->setSiguiente(inicio_par);

    /*Es importante que recuerde donde queda mis punteros
     * Para no ir desperdiciando recursos*/

}


// Odd Even Linked List

template<class T> void ListaFT<T>::oddLista() {
    //Defino los punteros fijos cabezas de linea
    Nodo<T>*inicio_impar= nullptr;
    Nodo<T>*inicio_par= nullptr;
    
    
    //punteros de movimiento o dinamicos
    Nodo<T> *par= nullptr;
    Nodo<T> *impar= nullptr;

    //Caso extremo un nodo o lista vacia
    if (inicio == nullptr || inicio->getSiguiente() == nullptr) {
        return;
    }

    inicio_impar=inicio;
    impar=inicio_impar;
    inicio_par=inicio_impar->getSiguiente();
    par=inicio_par;

    while (par!= nullptr && par->getSiguiente() != nullptr){
            impar->setSiguiente(par->getSiguiente());
            impar=par->getSiguiente();
            par->setSiguiente(impar->getSiguiente());
            par=impar->getSiguiente();
    }

    impar->setSiguiente(inicio_par);
}


template<class T> bool ListaFT<T>::hasCycle(){
    Nodo<T> *rapido=inicio;
    Nodo<T> *lento=inicio;

    if (inicio== nullptr){
        throw 404;
    }

    if (inicio->getSiguiente()== nullptr){
        return false;
    }

    while (rapido->getSiguiente()!= nullptr || rapido== nullptr){

        if (rapido->getSiguiente()==lento || rapido==lento){
            //hay algun ciclo
            return true;
        }

        lento=lento->getSiguiente();
        rapido=rapido->getSiguiente()->getSiguiente();
    }

    return false;
}



template<class T>
bool ListaFT<T>::Palindrome() {
    // Defino mis punteros dinámicos
    Nodo<T> *lento = inicio;
    Nodo<T> *rapido = inicio;
    Nodo<T> *auxiliar = nullptr;
    Nodo<T> *reversa = nullptr;

    if (inicio == nullptr) {
        throw 404; // ListaFT vacía
    }

    // Mover los punteros lento y rápido para encontrar el punto medio
    while (rapido != nullptr && rapido->getSiguiente() != nullptr) {
        rapido = rapido->getSiguiente()->getSiguiente();
        auxiliar = lento->getSiguiente();
        lento->setSiguiente(reversa);
        reversa = lento;
        lento = auxiliar;
    }

    // Si rapido no es nulo, la lista tiene un número impar de elementos, avanzar lento
    if (rapido != nullptr) {
        lento = lento->getSiguiente();
    }

    // Comparar la primera mitad con la segunda mitad invertida
    while (reversa != nullptr) {
        if (reversa->getDato() != lento->getDato()) {
            return false; // No es un palíndromo
        }
        reversa = reversa->getSiguiente();
        lento = lento->getSiguiente();
    }

    return true; // Es un palíndromo
}




template<class T> void ListaFT<T>::Reorder() {

    if (inicio== nullptr){
        throw 404;
    }

    //Primero a encontrar mi mitad
    Nodo<T> *rapido=inicio;
    Nodo<T> *lento=inicio;
    Nodo<T> *medio= nullptr;
    Nodo<T> *referencia= nullptr;

    while (rapido != nullptr && rapido->getSiguiente() != nullptr){
       rapido=rapido->getSiguiente()->getSiguiente();
       lento=lento->getSiguiente();
    }

    //situacion para lista Par
    if (rapido== nullptr){
        while (referencia->getSiguiente()!=lento){
            referencia=referencia->getSiguiente();
        }
        medio = referencia->getSiguiente();
    }


    //Situacion para ListaFT ImPar
    if (rapido->getSiguiente()== nullptr) {
        referencia = lento;
        medio = referencia->getSiguiente();
    }


    //A dar vuelta la 2da mitad
    Nodo<T> *anterior= nullptr;
    Nodo<T> *actual= medio;
    Nodo<T> *futuro= nullptr;

    while (actual!= nullptr) {

        futuro=actual->getSiguiente();

        actual->setSiguiente(anterior);
        anterior=futuro->getSiguiente();
        futuro->setSiguiente(actual);

        actual=anterior;
        anterior=futuro;

    }

    medio=anterior;



    //Falta unir ambas!
    referencia->setSiguiente(medio);



}


/**
 * Implementar un metodo de la clase lista que reciba como parametro un valor Pos.
 * El metodo debe buscar el nodo en la posicion Pos y moverlo a la ultima posicion.
 * Realizar moviendo conexiones. No creando nodos nuevos
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 *
 */
template <class T> void ListaFT<T>::byJuan_1(int pos) {
    Nodo<T> *referecnia= nullptr;
    Nodo<T> *anterior_ref=inicio;
    Nodo<T> *ultima_posicion=inicio;
    int cont=0;

    if (inicio== nullptr){
        std::cout<<"ListaFT ingresada vacia e invalida"<<std::endl;
        throw 404;
    }

    //Ciclo para llegar a la ultima pocision

    while (ultima_posicion->getSiguiente()!= nullptr){
        ultima_posicion=ultima_posicion->getSiguiente();

    }


    //Ciclo para paunteros referenciados en "pos"

    while (cont<pos-1){
        anterior_ref=anterior_ref->getSiguiente();
        referecnia=anterior_ref->getSiguiente();
        cont++;
    }


    anterior_ref->setSiguiente(referecnia->getSiguiente());
    referecnia->setSiguiente(nullptr);
    ultima_posicion->setSiguiente(referecnia);


}


/**
 * Implementar un metodo de la clase lista que reciba como parametro un valor I.
 * El metodo debe buscar todos los nodos a partir de la posicion I, e invertirlos.
 * Puede utilizar otras estructuras.
 * @tparam T
 * @param I posicion donde se desea reemplazar
 *
 */
template <class T> void ListaFT<T>::byJuan_2(int I){
    int count=0;
    Nodo<T> *pocision_anterior_refereciada=inicio;
    Nodo<T> *inicio_de_reversa= nullptr;

    //Reviso que mi lista no sea nula
    if (inicio==nullptr){
        std::cout<<"ListaFT ingresada vacia"<<std::endl;
        throw 404;
    }

    while (count<(I-1)){
        pocision_anterior_refereciada=pocision_anterior_refereciada->getSiguiente();
        count++;
    }


    //debe buscar todos los nodos a partir de la posicion I, e invertirlos

    inicio_de_reversa=pocision_anterior_refereciada->getSiguiente();


    //Reversa
    Nodo<T> *anterior= nullptr;
    Nodo<T> *actual=inicio_de_reversa;
    Nodo<T>*futuro;


    while (actual!= nullptr) {

        futuro=actual->getSiguiente();

        actual->setSiguiente(anterior);
        anterior=futuro->getSiguiente();
        futuro->setSiguiente(actual);

        actual=anterior;
        anterior=futuro;

    }

    inicio_de_reversa=anterior;


    pocision_anterior_refereciada->setSiguiente(inicio_de_reversa);


}

/**
 * Implementar un metodo de la clase lista que reciba como parametro un valor Pos.
 * El metodo debe buscar el nodo en la posicion Pos y moverlo a la primera posicion.
 * Realizar moviendo conexiones.
 * No creando nodos nuevos
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 */
template <class T> void ListaFT<T>::byJuan_0(int pos) {
    Nodo<T> *referecnia= nullptr;
    Nodo<T> *anterior_ref=inicio;
    int cont=0;

    if (inicio== nullptr){
        std::cout<<"ListaFT ingresada vacia e invalida"<<std::endl;
        throw 404;
    }

    //Ciclo para paunteros referenciados en "pos"

    while (cont<pos-1){
        anterior_ref=anterior_ref->getSiguiente();
        referecnia=anterior_ref->getSiguiente();
        cont++;
    }

    anterior_ref->setSiguiente(referecnia->getSiguiente());
    referecnia->setSiguiente(inicio);
    inicio=referecnia;


}


#endif // U02_LISTAS_LISTA_LISTA_H_
