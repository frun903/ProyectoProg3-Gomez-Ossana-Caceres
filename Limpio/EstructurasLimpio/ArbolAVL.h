#include "NodoArbolAVL_SL.h"
/*
 * Este nodo no contiene la lista de los depositos del producto
 * Solo contiene el nombre y el Stock
 * Aplicacion: -minStock
 *             -minStock por deposito
 *             -maxStock
 * */

template<class T, class U>
class ArbolAVL {
protected:
    NodoArbolAVL_SL<T,U> *root;
public:
    ArbolAVL();


    //nueva funcion put segun stock

    void putStock(T data,U stock);


    // funcion para buscar segun producto:

    void printByStock(U stock);


    bool search(T data);


    // Funciones para buscar por minimo o maximo de Stock
    void searchMinStock(U n);

    void searchMaxStock(U n);



    void preorder();

    void inorder();


    ~ArbolAVL();

    bool esVacio();


    int getBalance() {
        return getBalance(root);
    }



private:

    bool search(T data, NodoArbolAVL_SL<T, U> *r);
    void preorder(NodoArbolAVL_SL<T, U> *r);
    void inorder(NodoArbolAVL_SL<T, U> *r);
    int max(int a, int b);
    int calculateHeight(NodoArbolAVL_SL<T, U> *r);
    int getBalance(NodoArbolAVL_SL<T, U> *r);

    NodoArbolAVL_SL<T, U> *rotacionDerecha(NodoArbolAVL_SL<T, U> *y);
    NodoArbolAVL_SL<T, U> *rotacionIzquierda(NodoArbolAVL_SL<T, U> *x);

    //nuevas funciones
    NodoArbolAVL_SL<T, U> *putStock(T data, U stock, NodoArbolAVL_SL<T, U> *r);
    void searchMinStock(NodoArbolAVL_SL<T, U> *r, U n);
    void searchMaxStock(NodoArbolAVL_SL<T, U> *r, U n);


    void printByStock(U stock, NodoArbolAVL_SL<T, U> *r);
    NodoArbolAVL_SL<T, U> *findMin(NodoArbolAVL_SL<T, U> *r);

};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
// constructor sirve para inicializar cosas:
template<class T, class U>
ArbolAVL<T, U>::ArbolAVL() {
    root = nullptr;

}


/**
 * Destructor del Arbol
 */
template<class T, class U>
ArbolAVL<T, U>::~ArbolAVL() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */


// modificamos search para que sea tipo bool

template<class T, class U>
bool ArbolAVL<T, U>::search(T data) {
    return search(data, root);
}


template<class T, class U>
bool ArbolAVL<T, U>::search(T data, NodoArbolAVL_SL<T, U> *r) {
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



/**
 * Acomoda el Arbol por Stock admitiendo valores repetidos en
 * la rama central
 * @param stock Valor de stock del producto
 * @param data Nombre del producto
 */


template<class T, class U>
void ArbolAVL<T, U>::putStock(T data, U stock) {
    root = putStock(data, stock, root);
}

template<class T, class U>
NodoArbolAVL_SL<T, U> *ArbolAVL<T, U>::putStock(T data, U stock, NodoArbolAVL_SL<T, U> *r) {
    // Realizar la inserción normal
    if (r == nullptr) {
        return new NodoArbolAVL_SL<T, U>(data, stock);
    }
// Comparar por el stock en lugar del nombre
    if (r->getStock()>stock) {
        r->setLeft(putStock(data, stock, r->getLeft()));
    } else if (r->getStock()<stock) {
        r->setRight(putStock(data, stock, r->getRight()));
    } else {
        //En el caso de que Stock sea igual al de algun otro producto
        //es decir tal producto tiene el mismo Stock que otro
        // se ingresa en esta rama del medio. 
        r->setIn(putStock(data,stock,r->getIn()));
    }


    r->setHeight(max(calculateHeight(r->getLeft()), calculateHeight(r->getRight())) + 1);

    // Obtener el factor de balance de este nodo padre
    int balance = getBalance(r);

    // Realizar las rotaciones necesarias según el balance
    if (balance > 1) {
        if (stock < r->getLeft()->getStock()) {
            // Rotación derecha
            return rotacionDerecha(r);
        } else {
            // Rotación izquierda-derecha
            r->setLeft(rotacionIzquierda(r->getLeft()));
            return rotacionDerecha(r);
        }
    }

    if (balance < -1) {
        if (stock > r->getRight()->getStock()) {
            // Rotación izquierda
            return rotacionIzquierda(r);
        } else {
            // Rotación derecha-izquierda
            r->setRight(rotacionDerecha(r->getRight()));
            return rotacionIzquierda(r);
        }
    }

    return r;
}


template<class T, class U>
void ArbolAVL<T, U>::searchMinStock(U n) {
    searchMinStock(root, n);
}

template<class T, class U>
void ArbolAVL<T, U>::searchMinStock(NodoArbolAVL_SL<T, U>* r, U n) {
    if (r == nullptr) {
        return;
    }

    // Explorar los nodos en el subárbol izquierdo
    searchMinStock(r->getLeft(), n);


    if(r->getStock() <= n) {
        // Si el stock del nodo actual es menor o igual a n, imprimirlo
        std::cout << "Articulo: " << r->getData() << ", Stock: " << r->getStock() << std::endl;
    }

    // Explorar los nodos en 'in' que cumplen la condición
    if (r->getStock() <= n) {
        searchMinStock(r->getIn(), n);
    }

    // Explorar los nodos en el subárbol derecho solo si es necesario
    if (r->getStock() <= n) {
        searchMinStock(r->getRight(), n);
    }
}



template<class T, class U>
void ArbolAVL<T, U>::searchMaxStock(U n) {
    searchMaxStock(root, n);
}

template<class T, class U>
void ArbolAVL<T, U>::searchMaxStock(NodoArbolAVL_SL<T, U>* r, U n) {
    if (r == nullptr) {
        return;
    }

    // Explorar los nodos en el subárbol derecho
    searchMaxStock(r->getRight(), n);

    if (r->getStock() >= n) {
        // Si el stock del nodo actual es mayor o igual a n, imprimirlo
        std::cout << "Articulo: " << r->getData() << ", Stock: " << r->getStock() << std::endl;
    }

    // Explorar los nodos en 'in' que cumplen la condición
    if (r->getStock() >= n) {
        searchMaxStock(r->getIn(), n);
    }

    // Explorar los nodos en el subárbol izquierdo solo si es necesario
    if (r->getStock() >= n) {
        searchMaxStock(r->getLeft(), n);
    }
}



template<class T, class U>
void ArbolAVL<T, U>::printByStock(U stock) {
    printByStock(stock, root);
}

template<class T, class U>
void ArbolAVL<T, U>::printByStock(U stock, NodoArbolAVL_SL<T, U> *r) {
    if (r == nullptr) {
        return;
    }

    // Si el stock del nodo actual es menor que el stock deseado, busca en el subárbol derecho.
    if (r->getStock() < stock) {
        printByStock(stock, r->getRight());
    }
        // Si el stock del nodo actual es mayor que el stock deseado, busca en el subárbol izquierdo.
    else if (r->getStock() > stock) {
        printByStock( stock, r->getLeft());
    }
        // Si el stock del nodo actual es igual al stock deseado, imprime el producto y continúa buscando en ambos subárboles.
    else {
        cout << "Producto: " << r->getData() << " - Stock: " << r->getStock() << endl;



        printByStock( stock, r->getLeft());
        printByStock( stock, r->getRight());
    }
}


template<class T, class U>
NodoArbolAVL_SL<T, U> *ArbolAVL<T, U>::findMin(NodoArbolAVL_SL<T, U> *r) {
    {
        NodoArbolAVL_SL<T, U> *ret = r;
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
bool ArbolAVL<T, U>::esVacio() { return root == nullptr; }

/**
 * Recorre un árbol en preorden
 */
template<class T, class U>
void ArbolAVL<T, U>::preorder() {
    preorder(root);
    std::cout << std::endl;
}

template<class T, class U>
void ArbolAVL<T, U>::preorder(NodoArbolAVL_SL<T, U> *r) {
    if (r == nullptr) {
        return;
    }

    std::cout << r->getData() << " "<<r->getStock()<<endl;

    preorder(r->getLeft());
    preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */
template<class T, class U>
void ArbolAVL<T, U>::inorder() {
    inorder(root);
    std::cout << std::endl;
}

template<class T, class U>
void ArbolAVL<T, U>::inorder(NodoArbolAVL_SL<T, U> *r) {
    if (r == nullptr) {
        return;
    }

    inorder(r->getLeft());
    std::cout <<"Producto: " << r->getData() <<"\n El stock es: "<<r->getStock()<<endl;

    //r->getdepositos(); Aqui no hay depositos asi que esta linea no seria aplicable

    inorder(r->getIn());
    inorder(r->getRight());
}


//Sector del Balanceo

template<class T, class U>
int ArbolAVL<T, U>::max(int a, int b) {
    return (a > b) ? a : b;
}

template<class T, class U>
int ArbolAVL<T, U>::calculateHeight(NodoArbolAVL_SL<T, U> *r) {
    if (r == nullptr) {
        return 0;
    } else
        return r->getHeight();
}

template<class T, class U>
int ArbolAVL<T, U>::getBalance(NodoArbolAVL_SL<T, U> *r) {
    if (r == nullptr) {
        return 0;
    }
    return calculateHeight(r->getLeft()) - calculateHeight(r->getRight());
}

template<class T, class U>
NodoArbolAVL_SL<T, U> *ArbolAVL<T, U>::rotacionDerecha(NodoArbolAVL_SL<T, U> *y) {
    NodoArbolAVL_SL<T, U> *x = y->getLeft();
    NodoArbolAVL_SL<T, U> *T2 = x->getRight();

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
NodoArbolAVL_SL<T, U> *ArbolAVL<T, U>::rotacionIzquierda(NodoArbolAVL_SL<T, U> *x) {
    NodoArbolAVL_SL<T, U> *y = x->getRight();
    NodoArbolAVL_SL<T, U> *T2 = y->getLeft();

    //Rotacion
    y->setLeft(x);
    x->setRight(T2);

    //Atualizar alturas
    x->setHeight(max(calculateHeight(x->getLeft()), calculateHeight(x->getRight())) + 1);
    y->setHeight(max(calculateHeight(y->getLeft()), calculateHeight(y->getRight())) + 1);

    //Devolver la nueva raiz
    return y;
}

