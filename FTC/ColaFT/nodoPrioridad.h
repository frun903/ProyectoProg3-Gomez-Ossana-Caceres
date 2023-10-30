#ifndef INC_2021A2_U04_COLAS_COLAS__NODOPRIORIDAD_H
#define INC_2021A2_U04_COLAS_COLAS__NODOPRIORIDAD_H

template <class T>

class NodoPrioridad {
private:
    T dato;
    NodoPrioridad<T> *siguiente;
    int prioridad;

public:

    T getDato(){ return dato;}
    void setDato(T d){ dato=d;}

    NodoPrioridad<T> *getSiguiente(){ return siguiente;}

    void setSiguiente (NodoPrioridad<T> *s){
        this -> siguiente = s;
    }

    void setPrioridad(int prioriPos){
        prioridad=prioriPos;
    }
    int getPrioridad(){return prioridad;}; 

};
#endif
