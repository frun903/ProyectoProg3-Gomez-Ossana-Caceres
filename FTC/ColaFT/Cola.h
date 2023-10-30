#ifndef U04_COLAS_COLA_COLA_H_
#define U04_COLAS_COLA_COLA_H_
#include "/home/frang/untitled2/Lista/nodoES.h"
#include "Cliente.h"
#include <string>
#include <iostream>
/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T,V
 * @tparam T cualquier tipo de dato
 * @tparam T cualquier tipo de dato
 */
class Cola {
private:
NodoES *fondo, *tope; //fin inicio
public:
  Cola();

  ~Cola();

  void encolar(int, std::string, ListaFT<int>);

   void desencolar();

  bool esVacia();

  //void prioricemos();
};

/**
 * Constructor de la clase Cola
 * @tparam T
 * @tparam V
 */
Cola::Cola() {
    tope= nullptr;
    fondo= nullptr;
}

/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
Cola::~Cola() {
    while (!esVacia()){
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
void Cola::encolar(int dato, std::string nombre, ListaFT<int> lista) {
    NodoES *nuevo= new NodoES();
    nuevo=new NodoES();
    nuevo->setStock(dato);
    nuevo->setNombre(nombre);
    nuevo->setDepositos(lista);



    //Hasta aca caso donde ya tengo nodos.

    if (esVacia()){
        tope=nuevo;
    } else{
        fondo->setSiguiente(nuevo);
    }

    fondo= nuevo;

}

/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
void Cola::desencolar() {
    if (esVacia()){
        throw 404;
    }
    std::cout<<"El Producto es: "<<tope->getNombre()<<std::endl;
    std::cout<<"El Stock del produto es: "<<tope->getStock()<<std::endl;
    tope->getdepositos();


    //std::string dato=tope->getDato();

    NodoES *aBorrar=tope;
    tope=tope->getSiguiente();

    if (tope== nullptr){
        fondo= nullptr;
    }

   delete aBorrar;
    //return dato;
}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
 bool Cola::esVacia() {
    return tope== nullptr;
}

/*template <class T> void Cola<T>::prioricemos() {
    Cliente dato;
    std::cout<<"Ingrese Nombre, cantidad de productos, monto total, y si esta embarazado (Si (1) o No (0) "<<std::endl;
    std::string nombre;
    int cant;
    int precioT;
    bool embarazada;
    std::cin>>nombre;
    std::cin>>cant;
    std::cin>>precioT;
    std::cout<<"HOLA CLIENTE Estas embarazado/a Si(1) o No(0)"<<std::endl;
    std::cin>>embarazada;

    dato.Set_Datos(nombre,cant,precioT,embarazada);

    bool prioridad= true;
    Nodo<T> *nuevo = new Nodo<T>();
    nuevo = new Nodo<T>();
    nuevo->setDato(dato);

    if (dato.embarazado_get()==prioridad){

        if (esVacia()){
            tope=nuevo;

        }

            nuevo->setSiguiente(tope);
            tope = nuevo;

}else{
        if (esVacia()){
            tope=nuevo;
        } else{
            fondo->setSiguiente(nuevo);
        }

        fondo= nuevo;
    }
}
*/

#endif // U04_COLAS_COLA_COLA_H_
