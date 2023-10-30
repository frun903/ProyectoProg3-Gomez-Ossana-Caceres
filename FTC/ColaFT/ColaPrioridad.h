#ifndef U04_COLAS_COLA_COLAPRIORIDAD_H_
#define U04_COLAS_COLA_COLAPRIODIDAD_H_
#include "nodoPrioridad.h"
#define SIN_PRIORIDAD 1000000

/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class ColaPrioridad{
private:
  NodoPrioridad<T> *tope, *fondo;
public:
  ColaPrioridad();

  ~ColaPrioridad();

  void encolar(T dato);

  T desencolar();

  bool esVacia();

  T peek();

  void encolarPrioridad(T, int);
};

/**
 * Constructor de la clase Cola
 * @tparam T
 */
template <class T> ColaPrioridad<T>::ColaPrioridad() {
  tope = nullptr;
  fondo = nullptr;
}

/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
template <class T> ColaPrioridad<T>::~ColaPrioridad() {
  while(!esVacia()){
    desencolar();
  }
  delete tope;
  delete fondo;
}

/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T> void ColaPrioridad<T>::encolar(T dato) {
  NodoPrioridad<T> *nuevo = new NodoPrioridad<T>();
  nuevo->setDato(dato);
  nuevo->setSiguiente(nullptr);
  nuevo->setPrioridad(SIN_PRIORIDAD);

  if(esVacia()){
    tope = nuevo;
  }else{
    fondo->setSiguiente(nuevo);
  }
  fondo= nuevo;
  //46:=fondo.getdato();
}

/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T> T ColaPrioridad<T>::desencolar() {
  
  /*if(esVacia()){
    throw 400;
  }*/
  //std::cout<<tope->getDato();
  T dato = tope->getDato();
  
  NodoPrioridad<T> *aborrar = tope ;
  tope = tope->getSiguiente();
  if(tope==nullptr){
    fondo=nullptr;
  }
  delete aborrar;
  return dato;
}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T> bool ColaPrioridad<T>::esVacia() {
  return tope == nullptr;
}

template <class T>
T ColaPrioridad<T>::peek(){
  /*if(esVacia()){
    throw 400;
  }*/
  std::cout<<"Hermano tomate el dato "<<std::endl;
  return tope->getDato();

}
template<class T>
void ColaPrioridad<T>::encolarPrioridad(T dato, int prioridad){
    if(prioridad>=SIN_PRIORIDAD){
        encolar(dato);
        return;
    }
    NodoPrioridad<T> *nuevo = new NodoPrioridad<T>();
    nuevo->setDato(dato);
    nuevo->setPrioridad(prioridad);
    if(esVacia()){
      tope=nuevo;
    }else{
      NodoPrioridad<T> *aux = tope;
      if(aux->getPrioridad()> prioridad){
          nuevo->setSiguiente(tope);
          tope = nuevo;
          return;
      }
      while (aux->getSiguiente()->getPrioridad()<= prioridad)
      {
          aux = aux->getSiguiente();
      }
      nuevo->setSiguiente(aux->getSiguiente());
      aux->setSiguiente(nuevo);
    }
    
}

#endif // U04_COLAS_COLA_COLAPRIORIDAD_H_
