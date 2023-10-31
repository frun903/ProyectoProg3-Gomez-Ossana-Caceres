#ifndef U05_ARBOL_ARBOL_NODOARBOLAVL_H_
#define U05_ARBOL_ARBOL_NODOARBOLAVL_H_
using namespace std;

#include <string.h>
#include "ListaFT.h"


template<class T,class U,class V >
class NodoArbolAVL {
private:
    T data;
    NodoArbolAVL *left, *right;
    int height;
    // defino que mi nodo tambien tiene una lista
    ListaFT<int> lista; // lista es depositos en el codigo de fran.
    int stock;


public:


    NodoArbolAVL(T d,U s, V l) {
        data = d;
        left = nullptr;
        right = nullptr;
        height = 1;
        //sumaDatoslista=0;
        stock=s;
        lista =l;


    }
// esto seria get nombre en el codigo de fran.
    T getData() const {
        return data;
    }


    void setData(T d) {
        this->data = d;
    }

    NodoArbolAVL *getRight() const {
        return right;
    }

    void setRight(NodoArbolAVL *r) {
        this->right = r;
    }

    NodoArbolAVL *getLeft() const {
        return left;
    }

    void setLeft(NodoArbolAVL *l) {
        this->left = l;
    }

    int getHeight() {
        return height;
    }

    void setHeight(int h) {
        height = h;
    }
/*
    int getSumaDatosLista(){
        return sumaDatoslista;
    }
*/
    int getStock(){
        return stock;
    }

    void setSdepositos(ListaFT<int> listaFt){
        lista = listaFt;
    }

    void getdepositos(){
        lista.print();
    }

    void setstock(){

    }


    int getStockPorDeposito(int n){
        return lista.getDato(n-1);
    }

/*
// inserta en la lista como siempre lo ha hacho
    void insertarEnListaConDepo(U elemento,U deposito) {
        lista.insertarUltimoDatYdepo(elemento,deposito);
        sumaDatoslista=sumaDatoslista+elemento; // sumo los datos totales de la lista
    }

// funcion para imprimir las listas de cada nodo como siempre
    void imprimirLista() {
        lista.print();
    }
*/


    void print(bool esDerecho, string identacion) {
        if (right != NULL) {
            right->print(true, identacion + (esDerecho ? "     " : "|    "));
        }
        cout << identacion;
        if (esDerecho) {
            cout << " /";
        } else {
            cout << " \\";
        }
        cout << "-- ";
        cout << data << endl;
        if (left != NULL) {
            left->print(false, identacion + (esDerecho ? "|    " : "     "));
        }
    }

};

#endif // U05_ARBOL_ARBOL_NODOARBOLAVL_H_


/* #ifndef U05_ARBOL_ARBOL_NODOARBOLAVL_H_


#define U05_ARBOL_ARBOL_NODOARBOLAVL_H_
using namespace std;

#include <string.h>
#include "Lista.h"


template<class T,class U >
class NodoArbolAVL {
private:
    T data;
    NodoArbolAVL *left, *right;

    int height;
    Lista<U> lista; // defino que mi nodo tambien tiene una lista
    int sumaDatoslista;

public:
    NodoArbolAVL() {
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    NodoArbolAVL(T d) {
        data = d;
        left = nullptr;
        right = nullptr;
        height = 1;
        sumaDatoslista=0;
    }

    T getData() const {
        return data;
    }

    void setData(T d) {
        this->data = d;
    }

    NodoArbolAVL *getRight() const {
        return right;
    }

    void setRight(NodoArbolAVL *r) {
        this->right = r;
    }

    NodoArbolAVL *getLeft() const {
        return left;
    }

    void setLeft(NodoArbolAVL *l) {
        this->left = l;
    }

    int getHeight() {
        return height;
    }

    void setHeight(int h) {
        height = h;
    }

    int getSumaDatosLista(){
        return sumaDatoslista;
    }



// inserta en la lista como siempre lo ha hacho
    void insertarEnListaConDepo(U elemento,U deposito) {
        lista.insertarUltimoDatYdepo(elemento,deposito);
        sumaDatoslista=sumaDatoslista+elemento; // sumo los datos totales de la lista
    }

// funcion para imprimir las listas de cada nodo como siempre
    void imprimirLista() {
        lista.print();
    }



    void print(bool esDerecho, string identacion) {
        if (right != NULL) {
            right->print(true, identacion + (esDerecho ? "     " : "|    "));
        }
        cout << identacion;
        if (esDerecho) {
            cout << " /";
        } else {
            cout << " \\";
        }
        cout << "-- ";
        cout << data << endl;
        if (left != NULL) {
            left->print(false, identacion + (esDerecho ? "|    " : "     "));
        }
    }

};

#endif // U05_ARBOL_ARBOL_NODOARBOLAVL_H_
*/