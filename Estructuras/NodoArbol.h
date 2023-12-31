#ifndef U05_ARBOL_ARBOL_NODOARBOL_H_
#define U05_ARBOL_ARBOL_NODOARBOL_H_

#include <string.h>
#include "ListaFT.h"
using namespace std;


template <class T>
class NodoArbol
{
private:
  T data;
  int oc=1;
  ListaFT<T> lista;
  NodoArbol *left, *right;

public:
  NodoArbol()
  {
    left = nullptr;
    right = nullptr;
  }

  NodoArbol(T d)
  {
    data = d;
    left = nullptr;
    right = nullptr;
  }

  T getData() const
  {
    return data;
  }

  void setData(T d)
  {
    this->data = d;
  }

  NodoArbol *getRight() const
  {
    return right;
  }

  void setRight(NodoArbol *r)
  {
    this->right = r;
  }
  NodoArbol *getLeft() const
  {
    return left;
  }

  void setLeft(NodoArbol *l)
  {
    this->left = l;
  }

    void insertarEnLista(T elemento)
    {
        lista.insertarUltimo(elemento); // Inserta elemento en la lista del nodo
    }

    void imprimirLista()
    {
        lista.print(); // Imprime la lista de elementos del nodo
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

void ocur(){
      oc++;
  }

  };

#endif // U05_ARBOL_ARBOL_NODOARBOL_H_
