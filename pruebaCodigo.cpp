#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Estructuras/ListaFT.h"
#include "Estructuras/ArbolBinarioAVL.h"
using namespace std;

int main() {

    ListaFT<int> depositos;

    int dato_num;
    int stock=0;
    string producto;
    int cantidad_Articulos_Totales=0;
      ArbolBinarioAVL<string,int,ListaFT<int>> arbol1;
    //Crea conexion a mi archivo de texto
    ifstream Archivo;
    char renglon[100];
    string  inventario,linea,dato;
    char delimitadorDeColumn=',';
    int contadordecolumnas;
    int cantidad_Articulos_Diferentes=0;

    Archivo.open("Inventariado Fisico.csv");


    if (Archivo.fail())
    {
        std::cout<<"Archivo NO  abierto correctamnete" <<std:: endl;
    }else
    {
        std::cout<<"Archivo funciona correactamente"<<std::endl;
    }


    /* while (!Archivo.eof()){
         Archivo.getline(renglon,100);
         cout<<renglon<<endl;
     }*/

// vamos a leer la primera linea para saltar el encabezado.
    // y a la vez contamos la cantidad de columnas que vamos a tener.
    getline(Archivo, linea);
    stringstream linea2;
    // cout<<linea<<endl;
    linea2.str(linea);



    while (getline(Archivo, linea)) { // mientras el archivo este abierto o no sea el final.
        // aca tambien podria decir  while ( !inventario.eof)

        stringstream stream(linea); // Convertir la cadena a un stream



        // con este for, hago que los elementos que estan en la columna 1 me los meta en un arbol
        // podria hacer que me meta lo de otra columna en algun otra estructura.
        for (int i = 0; getline(stream, dato, delimitadorDeColumn); i++) {



            //0= grupo
            //1= codigo de barras
            //2= articulos

            if (i == 2) {  //
                cantidad_Articulos_Diferentes++;
                producto=dato;
                //cout<<dato<<endl;

            }

            if (i>2 && dato!= ""){
                dato_num= stoi(dato);
                cantidad_Articulos_Totales=cantidad_Articulos_Totales+dato_num;
                stock=stock+dato_num;
                depositos.insertarUltimo(dato_num, i-2);// Este es para la lista modificada
            }
        }


        //A este punto las variables ya deberian estar lista para ir a la estrucutra
        arbol1.put(producto,stock,depositos);

        //depositos.print();




        //Aqui el Stock de c/d producto vuelve a cero, ya que esta variable auxilar corresponde solo a un producto
        stock=0;
        //Vacio esta lista auxiar para poder volver a usarla con el nodo
        depositos.vaciar();
    }

/*
    while (!Encola.esVacia()){
        Encola.desencolar();
    }
*/
    cout<<std::endl;
    cout<<std::endl;
    cout<<"La cantidad de articulos diferentes es "<<cantidad_Articulos_Diferentes<<endl;
    cout<<"La cantidad de Articulos totales es "<<cantidad_Articulos_Totales<<endl;

  arbol1.inorder();

    return 0;
}





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
