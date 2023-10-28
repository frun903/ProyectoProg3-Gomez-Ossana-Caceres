#ifndef U05_ARBOL_ARBOL_ARBOLBINARIOAVL_H_
#define U05_ARBOL_ARBOL_ARBOLBINARIOAVL_H_

#include "NodoArbolAVL.h"

template<class T, class U>
class ArbolBinarioAVL {
protected:
    NodoArbolAVL<T, U> *root;

public:
    ArbolBinarioAVL();

    void put(T data);

    bool search(T data);

    // implementamos buscar y remover;
    bool searchAndRemove(T data);

    void remove(T data);

    void preorder();

    void inorder();

    void postorder();

    ~ArbolBinarioAVL();

    bool esVacio();

    void print();

    int getBalance() {
        return getBalance(root);
    }

    // nuevas funciones para trabajar con listas:

    void insertarEnLista(T data, U elemento, U depositos);

    void imprimirListaNodo(T data);

    void agregarAListaUltimoNodo(U elemento,U deposito);  // funcion que agrega elementos a lista en el ultimo nodo que ingreso.


   U getSumaDatosNodo(T data);


private:

    bool search(T data, NodoArbolAVL<T, U> *r);

    bool searchAndRemove(T data, NodoArbolAVL<T, U> *r);
    void preorder(NodoArbolAVL<T, U> *r);
    void inorder(NodoArbolAVL<T, U> *r);
    void postorder(NodoArbolAVL<T, U> *r);
    int max(int a, int b);
    int calculateHeight(NodoArbolAVL<T, U> *r);
    int getBalance(NodoArbolAVL<T, U> *r);

    NodoArbolAVL<T, U> *rotacionDerecha(NodoArbolAVL<T, U> *y);
    NodoArbolAVL<T, U> *rotacionIzquierda(NodoArbolAVL<T, U> *x);
    NodoArbolAVL<T, U> *put(T data, NodoArbolAVL<T, U> *r); // modifico el put para el ultimo nodo ingresado.
    NodoArbolAVL<T, U> *remove(T data, NodoArbolAVL<T, U> *r);
    NodoArbolAVL<T, U> *findMin(NodoArbolAVL<T, U> *r);
    NodoArbolAVL<T, U> *ultimoNodoInsertado; // declaramos un puntero al ultimo nodo ingresado;
    NodoArbolAVL<T, U> *
    findUltimoNodoInsertado(NodoArbolAVL<T, U> *r);  // funcion para encontrar el ultimo nodo ingresado
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
// constructor sirve para inicializar cosas:
template<class T, class U>
ArbolBinarioAVL<T, U>::ArbolBinarioAVL() {
    root = nullptr;
    ultimoNodoInsertado = nullptr;  // Inicializa el puntero al último nodo ingresado

}


/**
 * Destructor del Arbol
 */
template<class T, class U>
ArbolBinarioAVL<T, U>::~ArbolBinarioAVL() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */


// modificamos search para que sea tipo bool

template<class T, class U>
bool ArbolBinarioAVL<T, U>::search(T data) {
    return search(data, root);
}


template<class T, class U>
bool ArbolBinarioAVL<T, U>::search(T data, NodoArbolAVL<T, U> *r) {
    if (r == nullptr) {
        return false; // El valor no se encontró, retorna false.
    }

    if (r->getData() == data) {
        return true; // El valor se encontró, retorna true.
    }

    if (r->getData() > data) {
        return search(data, r->getLeft());
    } else {
        return search(data, r->getRight());
    }
}


template<class T, class U>
bool ArbolBinarioAVL<T, U>::searchAndRemove(T data) {
    return searchAndRemove(data, root);
}


// implementamos una funcion que busca y elimina
template<class T, class U>
bool ArbolBinarioAVL<T, U>::searchAndRemove(T data, NodoArbolAVL<T, U> *r) {
    if (r == nullptr) {
        return false; // El valor no se encontró, retorna false.
    }

    if (r->getData() == data) {
        root = remove(data, root); // Elimina el nodo encontrado y ajusta el árbol.
        return true; // El valor se encontró y se eliminó, retorna true.
    }

    if (r->getData() > data) {
        return searchAndRemove(data, r->getLeft());
    } else {
        return searchAndRemove(data, r->getRight());
    }
}


/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template<class T, class U>
void ArbolBinarioAVL<T, U>::put(T data) {
    root = put(data, root);
    ultimoNodoInsertado = findUltimoNodoInsertado(root); // ultimo nodo ingresado= al resultado de esta funcion;
}

template<class T, class U>
NodoArbolAVL<T, U> *ArbolBinarioAVL<T, U>::findUltimoNodoInsertado(NodoArbolAVL<T, U> *r) {
    if (r == nullptr) {
        return nullptr;
    }
    while (r->getRight() != nullptr) {
        r = r->getRight();
    }
    return r;
}


template<class T, class U>
NodoArbolAVL<T, U> *ArbolBinarioAVL<T, U>::put(T data, NodoArbolAVL<T, U> *r) {
    //1. Realizar Insercion normal
    if (r == nullptr) {
        return new NodoArbolAVL<T, U>(data);
    }

    if (r->getData() == data) {
        throw 200;
    }

    if (r->getData() > data) {
        r->setLeft(put(data, r->getLeft()));
    } else {
        r->setRight(put(data, r->getRight()));
    }

    //2. Actualizar altura de este nodo padre
    r->setHeight(max(calculateHeight(r->getLeft()), calculateHeight(r->getRight())) + 1);

    //3. Obtener el factor de balance de este nodo padre
    // y chequear si este nodo se desbalanceo
    int balance = getBalance(r);

    //Quedo desbalanceado II: corresponde una rot Der
    if (balance > 1 && data < r->getLeft()->getData()) {
        return rotacionDerecha(r);
    }

    //Quedo desbalanceado ID: corresponde una rot Izq Der
    if (balance > 1 && data > r->getLeft()->getData()) {
        r->setLeft(rotacionIzquierda(r->getLeft()));
        return rotacionDerecha(r);
    }

    //Quedo desbalanceado DD: corresponde una rot Izq
    if (balance < -1 && data > r->getRight()->getData()) {
        return rotacionIzquierda(r);
    }

    //Quedo desbalanceado DI: corresponde una rot Der Izq
    if (balance < -1 && data < r->getRight()->getData()) {
        r->setRight(rotacionDerecha(r->getRight()));
        return rotacionIzquierda(r);
    }

    return r;
}


/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template<class T, class U>
void ArbolBinarioAVL<T, U>::remove(T data) {
    root = remove(data, root);
}

template<class T, class U>
NodoArbolAVL<T, U> *ArbolBinarioAVL<T, U>::remove(T data, NodoArbolAVL<T, U> *r) {
    if (r == nullptr)
        return r;

    // Si el valor data es menor al valor almacenado
    // en r, entonces debe estar en el subarbol
    // izquierdo
    if (data < r->getData())
        r->setLeft(remove(data, r->getLeft()));

        // Si el valor data es mayor al valor almacenado
        // en r, entonces debe estar en el subarbol
        // derecho
    else if (data > r->getData())
        r->setRight(remove(data, r->getRight()));

        // Si data es el mismo valor que esta almacenado
        // en r, entonces es el nodo que hay que eliminar
    else {
        // Si r no tiene sub nodos, o si tiene uno solo
        if ((r->getLeft() == nullptr) || (r->getRight() == nullptr)) {
            NodoArbolAVL<T, U> *temp = r->getLeft() ? r->getLeft() : r->getRight();

            // En caso de que no tenga
            if (temp == nullptr) {
                temp = r;
                r = nullptr;
            } else          // Caso con un solo sub nodo
                *r = *temp; // Se copian los valores del
            // sub nodo no vacio
            delete temp;
        } else {

            // Nodo r con dos sub nodos: Se debe obtener el
            // sucesor inorder (el mas chico en el subarbol derecho)
            NodoArbolAVL<T, U> *temp = findMin(r->getRight());

            // Copiar la data del sucesor inorder en r
            r->setData(temp->getData());

            // Eliminar el sucesor inorder
            r->setRight(remove(temp->getData(), r->getRight()));
        }
    }

    // Si el arbol tuviera un solo nodo, return
    if (r == nullptr)
        return r;

    // 2. Actualizar la altura del nodo r
    r->setHeight(1 + max(calculateHeight(r->getLeft()),
                         calculateHeight(r->getRight())));

    // 3. Obtener el factor de balance del nodo r
    // para determinar si r se desbalanceo o no
    // luego de la eliminacion
    int balance = getBalance(r);

    //Quedo desbalanceado II: corresponde una rot Der
    if (balance > 1 && getBalance(r->getLeft()) >= 0)
        return rotacionDerecha(r);

    //Quedo desbalanceado ID: corresponde una rot Der Izq
    if (balance > 1 && getBalance(r->getLeft()) < 0) {
        r->setLeft(rotacionIzquierda(r->getLeft()));
        return rotacionDerecha(r);
    }

    //Quedo desbalanceado DD: corresponde una rot Izq
    if (balance < -1 && getBalance(r->getRight()) <= 0)
        return rotacionIzquierda(r);

    //Quedo desbalanceado DI: corresponde una rot Izq Der
    if (balance < -1 && getBalance(r->getRight()) > 0) {
        r->setRight(rotacionDerecha(r->getRight()));
        return rotacionIzquierda(r);
    }

    return r;
}

template<class T, class U>
NodoArbolAVL<T, U> *ArbolBinarioAVL<T, U>::findMin(NodoArbolAVL<T, U> *r) {
    {
        NodoArbolAVL<T, U> *ret = r;
        while (ret->getLeft() != nullptr)
            ret = ret->getLeft();

        return ret;
    }
}

/**
 * Informa si un árbol esta vacío
 * @return
 */
template<class T, class U>
bool ArbolBinarioAVL<T, U>::esVacio() { return root == nullptr; }

/**
 * Recorre un árbol en preorden
 */
template<class T, class U>
void ArbolBinarioAVL<T, U>::preorder() {
    preorder(root);
    std::cout << std::endl;
}

template<class T, class U>
void ArbolBinarioAVL<T, U>::preorder(NodoArbolAVL<T, U> *r) {
    if (r == nullptr) {
        return;
    }

    std::cout << r->getData() << " ";
    preorder(r->getLeft());
    preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */
template<class T, class U>
void ArbolBinarioAVL<T, U>::inorder() {
    inorder(root);
    std::cout << std::endl;
}

template<class T, class U>
void ArbolBinarioAVL<T, U>::inorder(NodoArbolAVL<T, U> *r) {
    if (r == nullptr) {
        return;
    }

    inorder(r->getLeft());
    std::cout << r->getData() << " " << endl;
    inorder(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */
template<class T, class U>
void ArbolBinarioAVL<T, U>::postorder() {
    postorder(root);
    std::cout << std::endl;
}

template<class T, class U>
void ArbolBinarioAVL<T, U>::postorder(NodoArbolAVL<T, U> *r) {
    if (r == nullptr) {
        return;
    }

    postorder(r->getLeft());
    postorder(r->getRight());
    std::cout << r->getData() << " ";
}

/**
 * Muestra un árbol por consola
 */
template<class T, class U>
void ArbolBinarioAVL<T, U>::print() {
    if (root != NULL)
        root->print(false, "");
}

template<class T, class U>
int ArbolBinarioAVL<T, U>::max(int a, int b) {
    return (a > b) ? a : b;
}

template<class T, class U>
int ArbolBinarioAVL<T, U>::calculateHeight(NodoArbolAVL<T, U> *r) {
    if (r == nullptr) {
        return 0;
    } else
        return r->getHeight();
}

template<class T, class U>
int ArbolBinarioAVL<T, U>::getBalance(NodoArbolAVL<T, U> *r) {
    if (r == nullptr) {
        return 0;
    }
    return calculateHeight(r->getLeft()) - calculateHeight(r->getRight());
}

template<class T, class U>
NodoArbolAVL<T, U> *ArbolBinarioAVL<T, U>::rotacionDerecha(NodoArbolAVL<T, U> *y) {
    NodoArbolAVL<T, U> *x = y->getLeft();
    NodoArbolAVL<T, U> *T2 = x->getRight();

    //Rotacion
    x->setRight(y);
    y->setLeft(T2);

    //Actualizar alturas
    y->setHeight(max(calculateHeight(y->getLeft()), calculateHeight(y->getRight())) + 1);
    x->setHeight(max(calculateHeight(x->getLeft()), calculateHeight(x->getRight())) + 1);

    //Devolver la nueva raiz;
    return x;
}

template<class T, class U>
NodoArbolAVL<T, U> *ArbolBinarioAVL<T, U>::rotacionIzquierda(NodoArbolAVL<T, U> *x) {
    NodoArbolAVL<T, U> *y = x->getRight();
    NodoArbolAVL<T, U> *T2 = y->getLeft();

    //Rotacion
    y->setLeft(x);
    x->setRight(T2);

    //Atualizar alturas
    x->setHeight(max(calculateHeight(x->getLeft()), calculateHeight(x->getRight())) + 1);
    y->setHeight(max(calculateHeight(y->getLeft()), calculateHeight(y->getRight())) + 1);

    //Devolver la nueva raiz
    return y;
}

// nuevas funciones para inseratar en lista, inserta en el nodo del arbol
// que contiene un dato, un elemento en la lista

template<class T, class U>
void ArbolBinarioAVL<T, U>::insertarEnLista(T data, U elemento, U deposito) {
    NodoArbolAVL<T, U> *nodo = root;
    while (nodo != nullptr) {
        if (data == nodo->getData()) // si encuentra el nodo con el dato
        {
            nodo->insertarEnLista(elemento, deposito);  // lo inserta en la lista
            return;
        } else if (data < nodo->getData()) // sino sigue buscando por derecha e izquierda recursivamente.
        {
            nodo = nodo->getLeft();
        } else {
            nodo = nodo->getRight();
        }
    }
}

// Nueva función para imprimir la lista de un nodo específico que yo paso por paramtro,
// podria implementar una que busque un dato espesifico en los nodos de las listas.
template<class T, class U>
void ArbolBinarioAVL<T, U>::imprimirListaNodo(T data) {
    NodoArbolAVL<T, U> *nodo = root;
    while (nodo != nullptr) {
        if (data == nodo->getData()) // si es el nodo que busco:
        {
            nodo->imprimirLista(); // Llama a la función pública de imprimirLista en el nodo

            return;
        } else if (data < nodo->getData())  // sino sigo buscando por derecha o izquierda.
        {
            nodo = nodo->getLeft();
        } else {
            nodo = nodo->getRight();
        }
    }
}

//funcio que agrega datos a la lista de el ultimo nodo que se agrego;
template<class T, class U>
void ArbolBinarioAVL<T, U>::agregarAListaUltimoNodo(U elemento, U deposito) {
    if (ultimoNodoInsertado != nullptr) {
        ultimoNodoInsertado->insertarEnListaConDepo(elemento, deposito);
    }
}
template<class T, class U>
U ArbolBinarioAVL<T,U>::getSumaDatosNodo(T data) {
    NodoArbolAVL<T, U> *nodo = root;
    while (nodo != nullptr) {
        if (data == nodo->getData()) {
            return nodo->getSumaDatosLista();
        } else if (data < nodo->getData()) {
            nodo = nodo->getLeft();
        } else {
            nodo = nodo->getRight();
        }
    }
    // Si no se encuentra el nodo con el valor especificado, puedes manejar el caso como desees, como lanzar una excepción o devolver un valor predeterminado.
    // Aquí, simplemente devolvemos 0 en caso de que el nodo no se encuentre.
    return 0;
}





#endif // U05_ARBOL_ARBOL_ARBOLBINARIOAVL_H_
