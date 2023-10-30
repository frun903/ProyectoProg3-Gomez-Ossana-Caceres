//
// Created by frang and Puca on 28/10/23.
//

#ifndef UNTITLED2_NODOES_H
#define UNTITLED2_NODOES_H
#include "string"
#include "../../Estructuras/ListaFT.h"


class NodoES{
private:
    int stock;
    std::string nombre;
    ListaFT<int> depositos;
    NodoES *siguiente;

public:
    int getStock(){
        return stock;
    }

    void setStock(int d){
        stock = d;
    }


    std::string getNombre(){
        return nombre;
    }

    void setNombre(std::string producto){
        nombre = producto;
    }

    void getdepositos(){
        depositos.print();
    }

    void setDepositos(ListaFT<int> depo){
        depositos = depo;
    }


    NodoES *getSiguiente(){
        return siguiente;
    }

    void setSiguiente(NodoES *siguiente){
        this->siguiente = siguiente;
    }


};



#endif //UNTITLED2_NODOES_H
