#ifndef U05_ARBOL_ARBOL_NODOARBOLAVL_H_
#define U05_ARBOL_ARBOL_NODOARBOLAVL_H_
using namespace std;

#include <string.h>
#include "D:\UCC\UNIVERSIDAD 2023\Segundo Semestre\programacion 3-intento2\PROYECTOFINAL\ProyectoProg3-Gomez-Ossana-Caceres\Estructuras\Lista.h"


template<class T,class U >
class NodoArbolAVL {
private:
    T data;
    NodoArbolAVL *left, *right;
    int height;
    Lista<U> lista; // defino que mi nodo tambien tiene una lista



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


// inserta en la lista como siempre lo ha hacho
    void insertarEnListaConDepo(U elemento,U deposito) {
        lista.insertarUltimoDatYdepo(elemento,deposito);
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
