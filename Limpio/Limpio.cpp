#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "EstructurasLimpio//ListaFT.h"
#include "EstructurasLimpio//ArbolBinarioAVL.h"
using namespace std;




void total_art_dif(){


    //Apertura del archivo.csv
    ifstream Archivo;

    Archivo.open("Inventariado Fisico.csv");

    if (Archivo.fail())
    {
        std::cout<<"Archivo NO  abierto correctamnete" <<std:: endl;
    }else
    {
        std::cout<<"Archivo funciona correactamente"<<std::endl;
    }


    string  linea,dato;
    char delimitadorDeColumn=',';
    int cantidad_Articulos_Diferentes=0;

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

    std::cout<<"Cantidad total de artículos diferentes:"<<cantidad_Articulos_Diferentes;

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

    std::cout<<"Cantidad total de artículos: "<< cantidad_Articulos_Totales;
}







int main() {


int opcion;
    char delimitadorDeColumn=',';
    cout << "Elije una opción (1-7): ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            funcion1();
            break;
        case 2:
            funcion2();
            break;
        case 3:
            funcion3();
            break;
        case 4:
            funcion4();
            break;
        case 5:
            funcion5();
            break;
        case 6:
            funcion6();
            break;
        case 7:
            funcion7();
            break;
        default:
            funcionError();
            break;
    }

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

void total_art_dif(){


    //Apertura del archivo.csv
    ifstream Archivo;

    Archivo.open("Inventariado Fisico.csv");

    if (Archivo.fail())
    {
        std::cout<<"Archivo NO  abierto correctamnete" <<std:: endl;
    }else
    {
        std::cout<<"Archivo funciona correactamente"<<std::endl;
    }


    string  linea,dato;
    char delimitadorDeColumn=',';
    int cantidad_Articulos_Diferentes=0;

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

    std::cout<<"Cantidad total de artículos diferentes:"<<cantidad_Articulos_Diferentes;

}


