#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "EstructurasLimpio/ListaFT.h"
#include "EstructurasLimpio/ArbolBinarioAVL.h"

using namespace std;

void total_art_dif(string &nombre_archivo) {


    //Apertura del archivo.csv
    ifstream Archivo;

    Archivo.open(nombre_archivo);

    if (Archivo.fail()) {
        std::cout << "Archivo NO  abierto correctamnete" << std::endl;
    } else {
        std::cout << "Archivo funciona correactamente" << std::endl;
    }


    string linea, dato;
    char delimitadorDeColumn = ',';
    int cantidad_Articulos_Diferentes = 0;

    //Ignoramos la primera linea del .csv
    getline(Archivo, linea);
    stringstream linea2;
    linea2.str(linea);

    while (getline(Archivo, linea)) { // mientras el archivo este abierto o no sea el final.
        // aca tambien podria decir  while ( !inventario.eof)

        stringstream stream(linea); // Convertir la cadena a un stream

        for (int i = 0; getline(stream, dato, delimitadorDeColumn); i++) {

            if (i == 2) {  //
                cantidad_Articulos_Diferentes++;
            }
        }
    }

    std::cout << "Cantidad total de artículos diferentes:" << cantidad_Articulos_Diferentes;

}


void total_art() {
    //Apertura del archivo.csv
    ifstream Archivo;
    string linea, dato;
    char delimitadorDeColumn = ',';
    int dato_num = 0, cantidad_Articulos_Totales;


    Archivo.open("Inventariado Fisico.csv");
    if (Archivo.fail()) {
        std::cout << "Archivo NO  abierto correctamnete" << std::endl;
    } else {
        std::cout << "Archivo funciona correactamente" << std::endl;
    }


    while (getline(Archivo, linea)) { // mientras el archivo este abierto o no sea el final.


        stringstream stream(linea); // Convertir la cadena a un stream

        for (int i = 0; getline(stream, dato, delimitadorDeColumn); i++) {
            if (i > 2) {
                if (dato == "" || dato == "\n") {
                    dato = "0";
                }
                dato_num = stoi(dato);
                cantidad_Articulos_Totales = cantidad_Articulos_Totales + dato_num;
            }
        }

    }

    std::cout << "Cantidad total de artículos: " << cantidad_Articulos_Totales;
}


void minStock(string &nombre_archivo, int n) {


    int dato_num, stock = 0;
    string producto;
    string inventario, linea, dato;
    char delimitadorDeColumn = ',';


    ArbolBinarioAVL<string, int, ListaFT<int>> arbolStock;
    ListaFT<int> depositos;


    //Crea conexion a mi archivo de texto
    ifstream Archivo;
    Archivo.open(nombre_archivo);
    if (Archivo.fail()) {
        std::cout << "Archivo NO  abierto correctamnete" << std::endl;
    } else {
        std::cout << "Archivo funciona correactamente" << std::endl;
    }

// vamos a leer la primera linea para saltar el encabezado.
    // y a la vez contamos la cantidad de columnas que vamos a tener.
    getline(Archivo, linea);


    while (getline(Archivo, linea)) { // mientras el archivo este abierto o no sea el final.
        // aca tambien podria decir  while ( !inventario.eof)

        stringstream stream(linea); // Convertir la cadena a un stream

        // con este for, hago que los elementos que estan en la columna 1 me los meta en un arbol
        // podria hacer que me meta lo de otra columna en algun otra estructura.
        for (int i = 0; getline(stream, dato, delimitadorDeColumn); i++) {

            if (i == 2) {  //
                producto = dato;
            }
            if (i > 2) {
                if (dato == "" || dato == "/n") {
                    dato = "0";
                }
                dato_num = stoi(dato);
                stock = stock + dato_num;
                depositos.insertarUltimo(dato_num, i - 2);// Este es para la lista modificada
            }
        }

        arbolStock.putStock(producto, stock, depositos);

        //Aqui el Stock de c/d producto vuelve a cero, ya que esta variable auxilar corresponde solo a un producto
        stock = 0;
        //Vacio esta lista auxiar para poder volver a usarla con el nodo
        depositos.vaciar();
    }

    arbolStock.searchMinStock(n);
}


void minStock(string &nombre_archivo, int n, int NumDepo) {


    int dato_num, stock = 0, depo;
    string producto;
    string inventario, linea, dato;
    char delimitadorDeColumn = ',';


    ArbolBinarioAVL<string, int, ListaFT<int>> arbolStock;
    ListaFT<int> depositos;


    //Crea conexion a mi archivo de texto
    ifstream Archivo;
    Archivo.open(nombre_archivo);
    if (Archivo.fail()) {
        std::cout << "Archivo NO  abierto correctamnete" << std::endl;
    } else {
        std::cout << "Archivo funciona correactamente" << std::endl;
    }

// vamos a leer la primera linea para saltar el encabezado.
    // y a la vez contamos la cantidad de columnas que vamos a tener.
    getline(Archivo, linea);


    while (getline(Archivo, linea)) { // mientras el archivo este abierto o no sea el final.
        // aca tambien podria decir  while ( !inventario.eof)

        stringstream stream(linea); // Convertir la cadena a un stream

        // con este for, hago que los elementos que estan en la columna 1 me los meta en un arbol
        // podria hacer que me meta lo de otra columna en algun otra estructura.
        for (int i = 0; getline(stream, dato, delimitadorDeColumn); i++) {

            if (i == 2) {  //
                producto = dato;
            }
            if (i > 2) {
                if (dato == "" || dato == "/n") {
                    dato = "0";
                }
                dato_num = stoi(dato);
                depo = (i - 2);
                if (depo== NumDepo){
                    stock=dato_num;
                depositos.insertarUltimo(dato_num, i - 2);// Este es para la lista modificada
            }
            }
        }
            arbolStock.putStock(producto, stock, depositos);

        //Aqui el Stock de c/d producto vuelve a cero, ya que esta variable auxilar corresponde solo a un producto
        stock = 0;
        //Vacio esta lista auxiar para poder volver a usarla con el nodo
        depositos.vaciar();
    }

    arbolStock.searchMinStock(n);
}


void stock(string nombreArticulo) {

    int dato_num, stock = 0;
    string producto;
    string inventario, linea, dato;
    char delimitadorDeColumn = ',';


    ArbolBinarioAVL<string, int, ListaFT<int>> arbol1;
    ListaFT<int> depositos;


    //Crea conexion a mi archivo de texto
    ifstream Archivo;
    Archivo.open("Inventariado Fisico.csv");
    if (Archivo.fail()) {
        std::cout << "Archivo NO  abierto correctamnete" << std::endl;
    } else {
        std::cout << "Archivo funciona correactamente" << std::endl;
    }

// vamos a leer la primera linea para saltar el encabezado.
    // y a la vez contamos la cantidad de columnas que vamos a tener.
    getline(Archivo, linea);


    while (getline(Archivo, linea)) { // mientras el archivo este abierto o no sea el final.
        // aca tambien podria decir  while ( !inventario.eof)

        stringstream stream(linea); // Convertir la cadena a un stream

        // con este for, hago que los elementos que estan en la columna 1 me los meta en un arbol
        // podria hacer que me meta lo de otra columna en algun otra estructura.
        for (int i = 0; getline(stream, dato, delimitadorDeColumn); i++) {

            if (i == 2) {  //
                producto = dato;
            }
            if (i > 2) {
                if (dato == "" || dato == "\n") {
                    dato = "0";
                }
                dato_num = stoi(dato);
                stock = stock + dato_num;
                depositos.insertarUltimo(dato_num, i - 2);// Este es para la lista modificada
            }
        }

        arbol1.put(producto, stock, depositos);

        //Aqui el Stock de c/d producto vuelve a cero, ya que esta variable auxilar corresponde solo a un producto
        stock = 0;
        //Vacio esta lista auxiar para poder volver a usarla con el nodo
        depositos.vaciar();
    }

    arbol1.searchAndData(nombreArticulo);
}


void stock2(string nombreArticulo, int deposito) {

    int dato_num, stock = 0;;
    string producto;
    string inventario, linea, dato;
    char delimitadorDeColumn = ',';


    ArbolBinarioAVL<string, int, ListaFT<int>> arbol1;
    ListaFT<int> depositos;


    //Crea conexion a mi archivo de texto
    ifstream Archivo;
    Archivo.open("Inventariado Fisico.csv");
    if (Archivo.fail()) {
        std::cout << "Archivo NO  abierto correctamnete" << std::endl;
    } else {
        std::cout << "Archivo funciona correactamente" << std::endl;
    }

    // vamos a leer la primera linea para saltar el encabezado.
    // y a la vez contamos la cantidad de columnas que vamos a tener.
    getline(Archivo, linea);
    while (getline(Archivo, linea)) { // mientras el archivo este abierto o no sea el final.
        // aca tambien podria decir  while ( !inventario.eof)

        stringstream stream(linea); // Convertir la cadena a un stream

        // con este for, hago que los elementos que estan en la columna 1 me los meta en un arbol
        // podria hacer que me meta lo de otra columna en algun otra estructura.
        for (int i = 0; getline(stream, dato, delimitadorDeColumn); i++) {

            if (i == 2) {  //
                producto = dato;
            }
            if (i > 2) {
                if (dato == "" || dato == "/n") {
                    dato = "0";
                }
                dato_num = stoi(dato);
                stock = stock + dato_num;
                depositos.insertarUltimo(dato_num, i - 2);// Este es para la lista modificada
            }
        }

        arbol1.put(producto, stock, depositos);
        //Aqui el Stock de c/d producto vuelve a cero, ya que esta variable auxilar corresponde solo a un producto
        stock = 0;
        //Vacio esta lista auxiar para poder volver a usarla con el nodo
        depositos.vaciar();
    }

    arbol1.searchAndDataStockDeposito(nombreArticulo, deposito);
}


void maxStock(int n) {


    int dato_num, stock = 0;
    string producto;
    string inventario, linea, dato;
    char delimitadorDeColumn = ',';


    ArbolBinarioAVL<string, int, ListaFT<int>> arbolStock;
    ListaFT<int> depositos;


    //Crea conexion a mi archivo de texto
    ifstream Archivo;
    Archivo.open("Inventariado Fisico.csv");
    if (Archivo.fail()) {
        std::cout << "Archivo NO  abierto correctamnete" << std::endl;
    } else {
        std::cout << "Archivo funciona correactamente" << std::endl;
    }

// vamos a leer la primera linea para saltar el encabezado.
    // y a la vez contamos la cantidad de columnas que vamos a tener.
    getline(Archivo, linea);


    while (getline(Archivo, linea)) { // mientras el archivo este abierto o no sea el final.
        // aca tambien podria decir  while ( !inventario.eof)

        stringstream stream(linea); // Convertir la cadena a un stream

        // con este for, hago que los elementos que estan en la columna 1 me los meta en un arbol
        // podria hacer que me meta lo de otra columna en algun otra estructura.
        for (int i = 0; getline(stream, dato, delimitadorDeColumn); i++) {

            if (i == 2) {  //
                producto = dato;
            }
            if (i > 2) {
                if (dato == "" || dato == "/n") {
                    dato = "0";
                }
                dato_num = stoi(dato);
                stock = stock + dato_num;
                depositos.insertarUltimo(dato_num, i - 2);// Este es para la lista modificada
            }
        }

        arbolStock.putStock(producto, stock, depositos);

        //Aqui el Stock de c/d producto vuelve a cero, ya que esta variable auxilar corresponde solo a un producto
        stock = 0;
        //Vacio esta lista auxiar para poder volver a usarla con el nodo
        depositos.vaciar();
    }

    arbolStock.searchMaxStock(n);
}


int main(int argc, char** argv) {

    int opcion;
    char delimitadorDeColumn = ',';
    string nomArticulo;
    int deposito = -1, n = 0;

    string nombre_archivo = argv[argc - 1];
    // Chequear que archivo sea csv
    // Y cambiar funciones para que tomen nombre_archivo de parametro

    char *arg;
    for (int i = 1; i < argc - 1; i++) {
        arg = argv[i];
        if (strcmp("-tot_art_dif", arg) == 0) {
            total_art_dif(nombre_archivo);
        }


        if (strcmp("-minStock", arg) == 0) {
            try {
                n = stoi(argv[i + 1]);
            } catch (std::invalid_argument &e) {
                cerr << "Leer manual de uso. " << e.what() << endl;
                return 1;
            }

            try {
                deposito = stoi(argv[i + 2]);
            } catch (std::exception &e) {
                cout << "Ejecutando sin deposito..." << endl;
            }

            if (deposito < 0) {
                minStock(nombre_archivo, n);
            } else {
                minStock(nombre_archivo, n, deposito);
            }
        }


//    }
//    switch (opcion) {
//
//        case 2:
//            total_art();
//            break;
//        case 3:
//            cout << "ingrese el valor de stok para obtener los productos con menos igual o menor cantidad" << endl;
//            cin >> n;
//            minStock(n);
//            break;
//        case 4:
//            cout << "ingrese el valor de stok para obtener los productos con menos igual o menor cantidad" << endl;
//            cin >> n;
//            cout << "ingrese el deposito al revisar" << endl;
//            cin >> deposito;
//            minStock2(n, deposito);
//
//
//            break;
//        case 5:
//            cout << "ingrese el nombre del articulo" << endl;
//            cin.ignore();
//            getline(cin, nomArticulo);
//            stock(nomArticulo);
//            break;
//        case 6:
//            cout << "ingrese el nombre del articulo" << endl;
//            cin.ignore();
//            getline(cin, nomArticulo);
//            cout << "ingrese el deposito:" << endl;
//            cin >> deposito;
//            stock2(nomArticulo, deposito);
//            break;
//        case 7:
//            cout << "ingrese el valor de stok para obtener los productos con mayor o igual cantidad" << endl;
//            cin >> n;
//            maxStock(n);
//            break;
//        default:
//            //     funcionError();
//            break;
//    }

        return 0;
    }


/*
    while (!Encola.esVacia()){
        Encola.desencolar();
    }
*/


//cout<<arbol1.search("CTLANIN-330-75");
// arbol1.searchAndData("VASSER CYRANO TOALLERO PERCHA 13/1829");



// esta funcion deberia imprimir todos los productos que se encuentren en el mismo stock
// es decir que tengo un arbol ordenado por stock y busca todos los nodos con este criterio.

//arbol1.preorder();
//arbolStock.inorder2();
//arbolStock.print();
//   arbolStock.printByStock(16);



/*
#include <iostream>
//#include <list>
//#include <vector>
#include "Estructuras/ArbolBinario.h"
#include "Estructuras/ArbolBinarioAVL.h"

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
}
