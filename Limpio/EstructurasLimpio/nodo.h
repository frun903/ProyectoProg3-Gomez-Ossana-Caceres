#ifndef NODO_H
#define NODO_H

template<class T>
class Nodo{
    private:
    T deposito;
    T dato;
   // T sumaDatos;
        Nodo<T> *siguiente;
    
    public:
       T getDato(){
           return dato;
       }

       void setDato(T d){
           dato = d;
       }


    T getDeposito(){
        return deposito;
    }

    void setDeposito(T depo){
        deposito = depo;
    }


       Nodo<T> *getSiguiente(){
           return siguiente;
       }

       void setSiguiente(Nodo<T> *siguiente){
           this->siguiente = siguiente;
       }


};

#endif //NODO_H