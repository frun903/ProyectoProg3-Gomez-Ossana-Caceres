#ifndef U05_ARBOL_ARBOL_ARBOLBINARIOAVL_H_
#define U05_ARBOL_ARBOL_ARBOLBINARIOAVL_H_

#include "NodoArbolAVL.h"

template<class T, class U, class V>
class ArbolBinarioAVL {
protected:
    NodoArbolAVL<T,U,V> *root;
    NodoArbolAVL<T,U,V> *ultimoNodoInsertado;
public:
    ArbolBinarioAVL();

    void put(T data,U stock, V lista );

    //nueva funcion put segun stock

    void putStock(T data,U stock, V lista );

    // funcion para buscar segun producto:

    void printByStock(U stock);


    bool search(T data);

    // implementamos buscar y remover;
    bool searchAndRemove(T data);

    bool searchAndData(T Data);

    bool searchAndDataStockDeposito (T data, U deposito);

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

    void insertarEnLista( T data, U elemento, V lista) ;

    void imprimirListaNodo(T data);

    void agregarAListaUltimoNodo(U elemento,U deposito);  // funcion que agrega elementos a lista en el ultimo nodo que ingreso.


   U getSumaDatosNodo(T data);


private:

    bool search(T data, NodoArbolAVL<T, U,V> *r);
    bool searchAndData(T data, NodoArbolAVL<T, U,V> *r);
    bool searchAndRemove(T data, NodoArbolAVL<T, U,V> *r);
    bool searchAndDataStockDeposito (T data,U deposito, NodoArbolAVL<T, U,V> *r);
    void preorder(NodoArbolAVL<T, U,V> *r);
    void inorder(NodoArbolAVL<T, U,V> *r);
    void postorder(NodoArbolAVL<T, U,V> *r);
    int max(int a, int b);
    int calculateHeight(NodoArbolAVL<T, U,V> *r);
    int getBalance(NodoArbolAVL<T, U,V> *r);

    NodoArbolAVL<T, U,V> *rotacionDerecha(NodoArbolAVL<T, U,V> *y);
    NodoArbolAVL<T, U,V> *rotacionIzquierda(NodoArbolAVL<T, U,V> *x);
    NodoArbolAVL<T, U, V> *put(T data, U stock, V lista, NodoArbolAVL<T, U, V> *r);
    //nueva funcion
    NodoArbolAVL<T, U, V> *putStock(T data, U stock, V lista, NodoArbolAVL<T, U, V> *r);
    NodoArbolAVL<T, U, V> *insertarEnLista( T data, U elemento, V lista ,NodoArbolAVL<T, U, V> *r);

     void printByStock(U stock, NodoArbolAVL<T, U, V> *r);
    NodoArbolAVL<T, U,V> *remove(T data, NodoArbolAVL<T, U,V> *r);
    NodoArbolAVL<T, U,V> *findMin(NodoArbolAVL<T, U,V> *r);
    // declaramos un puntero al ultimo nodo ingresado;
    NodoArbolAVL<T, U,V> *findUltimoNodoInsertado(NodoArbolAVL<T, U,V> *r);  // funcion para encontrar el ultimo nodo ingresado

};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
// constructor sirve para inicializar cosas:
template<class T, class U, class V>
ArbolBinarioAVL<T, U, V>::ArbolBinarioAVL() {
    root = nullptr;
    ultimoNodoInsertado = nullptr;  // Inicializa el puntero al último nodo ingresado

}


/**
 * Destructor del Arbol
 */
template<class T, class U, class V>
ArbolBinarioAVL<T, U, V>::~ArbolBinarioAVL() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */


// modificamos search para que sea tipo bool

template<class T, class U, class V>
bool ArbolBinarioAVL<T, U, V>::search(T data) {
    return search(data, root);
}


template<class T, class U, class V>
bool ArbolBinarioAVL<T, U, V>::search(T data, NodoArbolAVL<T, U,V> *r) {
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

template<class T, class U, class V>
bool ArbolBinarioAVL<T, U, V>::searchAndData(T data) {
    return searchAndData(data, root);
}

template<class T, class U, class V>
bool ArbolBinarioAVL<T, U, V>::searchAndData(T data, NodoArbolAVL<T, U, V> *r) {
    if (r == nullptr) {
         // Establece el stock en 0 si el valor no se encuentra.
        return false;
    }

    if (r->getData() == data) {
        cout<<"Producto: "<<data<<" "<<endl;
       // r->getdepositos();
        cout<<"stock total del producto: "<< r->getStock()<<endl;
        return true; // El valor se encontró, retorna true.
    }

    if (r->getData() > data) {
        return searchAndData(data, r->getLeft());
    } else {
        return searchAndData(data, r->getRight());
    }
}





template<class T, class U, class V>
bool ArbolBinarioAVL<T, U, V>::searchAndDataStockDeposito(T data, U deposito)  {
    return searchAndDataStockDeposito(data,deposito, root);
}


template<class T, class U, class V>
bool ArbolBinarioAVL<T, U, V>::searchAndDataStockDeposito(T data, U deposito, NodoArbolAVL<T, U, V> *r) {
    if (r == nullptr) {
        return false;
        cout<<"no se encontro el producto"<<endl;
    }

    if (r->getData() == data) {
        cout<<"Producto: "<<data<<" "<<endl;
       cout<<"El stock en el deposito "<<deposito<< " es: "<<r->getStockPorDeposito(deposito)<<endl;
        return true;
    }

    if (r->getData() > data) {
        return searchAndDataStockDeposito(data,deposito, r->getLeft());
    } else {
        return searchAndDataStockDeposito(data,deposito, r->getRight());
    }
}







template<class T, class U, class V>
bool ArbolBinarioAVL<T, U, V>::searchAndRemove(T data) {
    return searchAndRemove(data, root);
}


// implementamos una funcion que busca y elimina
template<class T, class U, class V>
bool ArbolBinarioAVL<T, U, V>::searchAndRemove(T data, NodoArbolAVL<T, U,V> *r) {
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

template<class T, class U, class V>
NodoArbolAVL<T, U,V> *ArbolBinarioAVL<T, U, V>::findUltimoNodoInsertado(NodoArbolAVL<T, U,V> *r) {{
        if (r == nullptr) {
            return nullptr;
        }

        if (r->getRight() != nullptr) {
            return findUltimoNodoInsertado(r->getRight());
        } else {
            return r;
        }
    }
};

template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::put(T data, U stock, V lista) {
    root = put(data, stock, lista, root);

}

template<class T, class U, class V>
NodoArbolAVL<T, U, V> *ArbolBinarioAVL<T, U, V>::put(T data, U stock, V lista, NodoArbolAVL<T, U, V> *r) {
    // Realizar la inserción normal
    if (r == nullptr) {
        return new NodoArbolAVL<T, U, V>(data, stock, lista);
    }

    if (r->getData() == data) {
        throw 200; // Considera cómo manejar casos de datos duplicados.
    }

    if (r->getData() > data) {
        r->setLeft(put(data, stock, lista, r->getLeft()));
    } else {
        r->setRight(put(data, stock, lista, r->getRight()));
    }

    // Actualizar la altura de este nodo padre
    r->setHeight(max(calculateHeight(r->getLeft()), calculateHeight(r->getRight())) + 1);

    // Obtener el factor de balance de este nodo padre
    // y chequear si este nodo se desbalanceó
    int balance = getBalance(r);

    //Quedo desbalanceado II: corresponde una rot Der
    if (balance > 1 && data < r->getLeft()->getData())
    {
        return rotacionDerecha(r);
    }

    //Quedo desbalanceado ID: corresponde una rot Izq Der
    if (balance > 1 && data > r->getLeft()->getData())
    {
        r->setLeft(rotacionIzquierda(r->getLeft()));
        return rotacionDerecha(r);
    }

    //Quedo desbalanceado DD: corresponde una rot Izq
    if (balance < -1 && data > r->getRight()->getData())
    {
        return rotacionIzquierda(r);
    }

    //Quedo desbalanceado DI: corresponde una rot Der Izq
    if (balance < -1 && data < r->getRight()->getData())
    {
        r->setRight(rotacionDerecha(r->getRight()));
        return rotacionIzquierda(r);
    }

    return r;
}

/*
template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::putStock(T data, U stock, V lista) {
    root = putStock(data, stock, lista, root);
}

template<class T, class U, class V>
NodoArbolAVL<T, U, V> *ArbolBinarioAVL<T, U, V>::putStock(T data, U stock, V lista, NodoArbolAVL<T, U, V> *r) {
    // Realizar la inserción normal
        if (r == nullptr) {
            return new NodoArbolAVL<T, U, V>(data, stock, lista);
    }
// Comparar por el stock en lugar del nombre
    if (r->getStock()>stock) {
        r->setLeft(putStock(data, stock, lista, r->getLeft()));
    } else if (r->getStock()<stock) {
        r->setRight(putStock(data, stock, lista, r->getRight()));
    } else {
        // Si el stock es igual, compara por el nombre
        if ( r->getData()>data) {
            r->setLeft(putStock(data, stock, lista, r->getLeft()));
        } else if (r->getData()<data) {
            r->setRight(putStock(data, stock, lista, r->getRight()));
        } else {
            throw 200;
        }
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
*/

template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::printByStock(U stock) {
    printByStock(stock, root);
}

template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::printByStock(U stock, NodoArbolAVL<T, U, V> *r) {
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







/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::remove(T data) {
    root = remove(data, root);
}

template<class T, class U, class V>
NodoArbolAVL<T, U,V> *ArbolBinarioAVL<T, U, V>::remove(T data, NodoArbolAVL<T, U,V> *r) {
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
            NodoArbolAVL<T, U,V> *temp = r->getLeft() ? r->getLeft() : r->getRight();

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
            NodoArbolAVL<T, U,V> *temp = findMin(r->getRight());

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

template<class T, class U, class V>
NodoArbolAVL<T, U,V> *ArbolBinarioAVL<T, U, V>::findMin(NodoArbolAVL<T, U,V> *r) {
    {
        NodoArbolAVL<T, U,V> *ret = r;
        while (ret->getLeft() != nullptr)
            ret = ret->getLeft();

        return ret;
    }
}

/**
 * Informa si un árbol esta vacío
 * @return
 */
template<class T, class U, class V>
bool ArbolBinarioAVL<T, U, V>::esVacio() { return root == nullptr; }

/**
 * Recorre un árbol en preorden
 */
template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::preorder() {
    preorder(root);
    std::cout << std::endl;
}

template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::preorder(NodoArbolAVL<T, U,V> *r) {
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
template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::inorder() {
    inorder(root);
    std::cout << std::endl;
}

template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::inorder(NodoArbolAVL<T, U,V> *r) {
    if (r == nullptr) {
        return;
    }

    inorder(r->getLeft());
    std::cout <<"Producto: " << r->getData() <<endl;

    r->getdepositos();
    inorder(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */
template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::postorder() {
    postorder(root);
    std::cout << std::endl;
}

template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::postorder(NodoArbolAVL<T, U,V> *r) {
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
template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::print() {
    if (root != NULL)
        root->print(false, "");
}

template<class T, class U, class V>
int ArbolBinarioAVL<T, U, V>::max(int a, int b) {
    return (a > b) ? a : b;
}

template<class T, class U, class V>
int ArbolBinarioAVL<T, U, V>::calculateHeight(NodoArbolAVL<T, U,V> *r) {
    if (r == nullptr) {
        return 0;
    } else
        return r->getHeight();
}

template<class T, class U, class V>
int ArbolBinarioAVL<T, U, V>::getBalance(NodoArbolAVL<T, U,V> *r) {
    if (r == nullptr) {
        return 0;
    }
    return calculateHeight(r->getLeft()) - calculateHeight(r->getRight());
}

template<class T, class U, class V>
NodoArbolAVL<T, U,V> *ArbolBinarioAVL<T, U, V>::rotacionDerecha(NodoArbolAVL<T, U,V> *y) {
    NodoArbolAVL<T, U,V> *x = y->getLeft();
    NodoArbolAVL<T, U,V> *T2 = x->getRight();

    //Rotacion
    x->setRight(y);
    y->setLeft(T2);

    //Actualizar alturas
    y->setHeight(max(calculateHeight(y->getLeft()), calculateHeight(y->getRight())) + 1);
    x->setHeight(max(calculateHeight(x->getLeft()), calculateHeight(x->getRight())) + 1);

    //Devolver la nueva raiz;
    return x;
}

template<class T, class U, class V>
NodoArbolAVL<T, U,V> *ArbolBinarioAVL<T, U, V>::rotacionIzquierda(NodoArbolAVL<T, U,V> *x) {
    NodoArbolAVL<T, U,V> *y = x->getRight();
    NodoArbolAVL<T, U,V> *T2 = y->getLeft();

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

/*
template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::insertarEnLista(T data, U elemento, U deposito) {
    NodoArbolAVL<T, U,V> *nodo = root;
     NodoArbol<T> *nodoAnterior = nullptr;
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
}*/

template<class T, class U, class V>
void ArbolBinarioAVL<T,U,V>::insertarEnLista(T data, U elemento, V lista )
{
    NodoArbolAVL<T, U,V> *nodo = root;
    NodoArbolAVL<T, U,V> *nodoAnterior = nullptr;

    // Buscar el nodo adecuado para insertar
    while (nodo != nullptr)
    {
        nodoAnterior = nodo;

        if (elemento == nodo->getStock())
        {
            nodo->insertarEnListain(data,elemento);
            return;
        }
        else if (elemento < nodo->getStock())
        {
            nodo = nodo->getLeft();
        }
        else
        {
            nodo = nodo->getRight();
        }
    }

    // Si llega a ser nullptr, crea un nuevo nodo solo si es necesario
    if (nodoAnterior == nullptr)
    {
        root = new NodoArbolAVL<T,U,V>(data,elemento,lista);
        root->insertarEnListain(data,elemento);
    }
    else if (elemento < nodoAnterior->getStock())
    {
        nodoAnterior->setLeft(new NodoArbolAVL<T,U,V>(data,elemento,lista));
        nodoAnterior->getLeft()->insertarEnListain(data,elemento);
    }
    else
    {
        nodoAnterior->setRight(new NodoArbolAVL<T,U,V>(data,elemento,lista));
        nodoAnterior->getRight()->insertarEnListain(data,elemento);
    }
}




// Nueva función para imprimir la lista de un nodo específico que yo paso por paramtro,
// podria implementar una que busque un dato espesifico en los nodos de las listas.
template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::imprimirListaNodo(T data) {
    NodoArbolAVL<T, U,V> *nodo = root;
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
template<class T, class U, class V>
void ArbolBinarioAVL<T, U, V>::agregarAListaUltimoNodo(U elemento, U deposito) {
    if (ultimoNodoInsertado != nullptr) {
        ultimoNodoInsertado->insertarEnListaConDepo(elemento, deposito);
    }
}
template<class T, class U, class V>
U ArbolBinarioAVL<T,U, V>::getSumaDatosNodo(T data) {
    NodoArbolAVL<T, U,V> *nodo = root;
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
