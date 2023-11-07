#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Estructuras/ListaFT.h"
#include "Estructuras/ArbolBinarioAVL.h"
#include "Limpio/EstructurasLimpio/ArbolAVL.h"
using namespace std;

//Ante la funcionalidad de Argumentos
void total_art_dif();
void total_art();



int main() {

    ListaFT<int> depositos;

    int dato_num;
    int stock=0;
    string producto;
    int cantidad_Articulos_Totales=0;
    // ArbolBinarioAVL<string,int,ListaFT<int>> arbol1;
    ArbolAVL<string,int> arbol1;


    ArbolBinarioAVL<string ,int,ListaFT<int>> arbolStock;
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

// vamos a leer la primera linea para saltar el encabezado.
    // y a la vez contamos la cantidad de columnas que vamos a tener.
    getline(Archivo, linea);
    stringstream linea2;
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

            if (i>2){
                if(dato == "" || dato == "/n"){
                    dato= "0";
                }
                dato_num= stoi(dato);
                cantidad_Articulos_Totales=cantidad_Articulos_Totales+dato_num;
                stock=stock+dato_num;
                depositos.insertarUltimo(dato_num, i-2);// Este es para la lista modificada
            }
        }


        // arbolStock.putStock(producto,stock,depositos);
        //A este punto las variables ya deberian estar lista para ir a la estrucutra
        //arbol1.put(producto,stock,depositos);
        arbol1.putStock(producto,stock);
        //arbolStock.insertarEnLista(producto,stock,depositos);
        //depositos.print();
        //Aqui el Stock de c/d producto vuelve a cero, ya que esta variable auxilar corresponde solo a un producto
        stock=0;
        //Vacio esta lista auxiar para poder volver a usarla con el nodo
        depositos.vaciar();
    }

    cout<<std::endl;
    cout<<std::endl;
    cout<<"La cantidad de articulos diferentes es "<<cantidad_Articulos_Diferentes<<endl;
    cout<<"La cantidad de Articulos totales es "<<cantidad_Articulos_Totales<<endl;

    //arbol1.inorder();


    //cout<<arbol1.search("CTLANIN-330-75");
// arbol1.searchAndData("VASSER CYRANO TOALLERO PERCHA 13/1829");
//arbol1.searchAndDataStockDeposito("GUIAS FIXSYSTEM  DE 120 CM",1);
    cout<<"    "<<endl;
    //arbol1.searchMinStock(3); // este funciona;
    cout<<" "<<endl;
    arbol1.searchMaxStock(3);

// esta funcion deberia imprimir todos los productos que se encuentren en el mismo stock
// es decir que tengo un arbol ordenado por stock y busca todos los nodos con este criterio.

//arbol1.preorder();
//arbolStock.inorder2();
//arbolStock.print();
    //arbolStock.printByStock(16);


    return 0;
}
