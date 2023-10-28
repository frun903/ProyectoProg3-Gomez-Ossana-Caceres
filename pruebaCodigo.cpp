/*
#include <iostream>
//#include <list>
//#include <vector>
#include "Estructuras/ArbolBinario.h"
#include "Estructuras/ArbolBinarioAVL.h"
/*
class MiLista {
public:
    MiLista() {}

    void agregar(int elemento) {
        lista.push_back(elemento);
    }

    void imprimir() {
        for (int elemento : lista) {
            std::cout << elemento << "->";
        }
        std::cout << std::endl;
    }

private:
    std::list<int> lista;
};

#include <iostream>
#include "Estructuras/Lista.h"
//#include <vector>
#include "Estructuras/ArbolBinario.h"

template <class T>
class NodoArbol {
public:
    int valor;
    Lista<T> lista;
    NodoArbol* izquierda;
    NodoArbol* derecha;

    NodoArbol(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};

template <class T>
class ArbolConListas {
private:
    NodoArbol<T>* raiz;

    void insertarEnNodo(NodoArbol<T>* nodo, int valor) {
        if (nodo->valor == valor) {
            nodo->lista.insertarUltimo(valor);
        } else if (valor < nodo->valor) {
            if (nodo->izquierda == nullptr) {
                nodo->izquierda = new NodoArbol<T>(valor);
            } else {
                insertarEnNodo(nodo->izquierda, valor);
            }
        } else {
            if (nodo->derecha == nullptr) {
                nodo->derecha = new NodoArbol<T>(valor);
            } else {
                insertarEnNodo(nodo->derecha, valor);
            }
        }
    }

public:
    ArbolConListas() : raiz(nullptr) {}

    void insertarNuevoNodo(int valor) {
        if (raiz == nullptr) {
            raiz = new NodoArbol<T>(valor);
        } else {
            insertarEnNodo(raiz, valor);
        }
    }

    void insertarElementoEnLista(int valor) {
        if (raiz) {
            insertarEnNodo(raiz, valor);
        }
    }

    void imprimirArbol() {
        imprimirListaNodo(raiz);
    }

    void imprimirListaNodo(NodoArbol<T>* nodo) {
        if (nodo) {
            std::cout << "Nodo " << nodo->valor << ":";
            nodo->lista.print();
            imprimirListaNodo(nodo->izquierda);
            imprimirListaNodo(nodo->derecha);
        }
    }

    void destruir() {
        destruirArbol(raiz);
        raiz = nullptr;
    }

    void destruirArbol(NodoArbol<T>* nodo) {
        if (nodo) {
            destruirArbol(nodo->izquierda);
            destruirArbol(nodo->derecha);
            delete nodo;
        }
    }
};

int main() {
    ArbolConListas<int> arbol; // Puedes especificar el tipo de dato que almacena tu lista aquí

    arbol.insertarNuevoNodo(1);
    arbol.insertarNuevoNodo(2);
    arbol.insertarNuevoNodo(3);
    arbol.insertarNuevoNodo(4);
    arbol.insertarElementoEnLista(1);
    arbol.insertarElementoEnLista(2);
    arbol.insertarElementoEnLista(1);
    arbol.insertarElementoEnLista(4);
    arbol.insertarNuevoNodo(2);
    arbol.insertarNuevoNodo(2);
    arbol.imprimirArbol();

    arbol.destruir(); // Libera la memoria del árbol

    return 0;
}



//#include <list>
//#include <vector>
#include "Estructuras/ArbolBinario.h"
#include "Estructuras/ArbolBinarioAVL.h"
    int main()
    {
        ArbolBinarioAVL<string> arbol;

        // Insertar elementos en el árbol AVL
        arbol.put("1");
        arbol.agregarAListaUltimoNodo("1-a");
        arbol.agregarAListaUltimoNodo("1-b");
        arbol.agregarAListaUltimoNodo("1-c");
        arbol.put("2");
        arbol.agregarAListaUltimoNodo("2-b");
        arbol.put("3");
        arbol.agregarAListaUltimoNodo("3-c");
        arbol.put("4");
        arbol.agregarAListaUltimoNodo("4-d");
        arbol.put("5");
        arbol.agregarAListaUltimoNodo("5-e");
        arbol.put("6");
        arbol.agregarAListaUltimoNodo("6-f");
        arbol.put("7");
        arbol.agregarAListaUltimoNodo("7-g");



        cout<<"arbol numero 1"<<endl;
        arbol.imprimirListaNodo("1");
        cout<<"arbol numero 2"<<endl;
        arbol.imprimirListaNodo("2");
        cout<<"arbol numero 3"<<endl;
        arbol.imprimirListaNodo("3");
        cout<<"arbol numero 4"<<endl;
        arbol.imprimirListaNodo("4");
        cout<<"arbol numero 5"<<endl;
        arbol.imprimirListaNodo("5");
        cout<<"arbol numero 6"<<endl;
        arbol.imprimirListaNodo("6");
        cout<<"arbol numero 7"<<endl;
        arbol.imprimirListaNodo("7");
        cout<<"arbol numero 8"<<endl;
        arbol.imprimirListaNodo("8");
        // Mostrar el árbol AVL
        arbol.print();

        return 0;
    }
*/
