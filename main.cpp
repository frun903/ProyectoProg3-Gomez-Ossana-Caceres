//
// Created by Tomas Oss on 19/10/2023.
//
#include <iostream>
#include <ctime> //para medir el tiempo
#include <fstream> // abrir archivos
#include <sstream> // trabajar con stream
#include <string>

#include "Estructuras/Cola.h"
#include "Estructuras/Lista.h"
#include "Estructuras/ArbolBinario.h"
#include "Estructuras/ArbolBinarioAVL.h"

using namespace std;

int main() {

    string linea;
    string dato;
    string primerlinea;
    int dato_num, cantidadTotalDeArticulosDiferentes=0, cantidadTotalDeArticulos=0;
    int contadordecolumnas=0;
    ArbolBinario<streambuf> arbol1;
    ArbolBinarioAVL<string,int> arbol2;


    // debemos ver como manejar la definicion de los depositos ya que estos son dinamicos.
    // int deposito1, deposito2, deposito3,deposito4 ,deposito5, ;


    Lista<string> listaDecolunas;
    //Lista<string> listaPrueba;



    char delimitadorDeColumn = ',';


    ifstream inventario; // definimos un archivo
    inventario.open("Inventariado Fisico.csv"); // abrimos el archvo

    //aca despues nesesitamos empezar a medir el tiempo;

    if (!inventario.is_open()) {
        cout << "error al abrir el archivo" << endl;
    }
    // vamos a leer la primera linea para saltar el encabezado.
    // y a la vez contamos la cantidad de columnas que vamos a tener.
    getline(inventario, linea);
    stringstream linea2;

    linea2.str(linea);
    {
        while (getline(linea2, dato, ',')) { // aca contamos la cantida de columans
            listaDecolunas.insertarUltimo(dato); // las guardamos en una lista por ahora.
            contadordecolumnas++; // sabemos que las primeras 3 siempre van a ser de grupo, cod y articulo, lo demas seran depositos.
        }
    };
    cout << "cantidad de columnas son " << contadordecolumnas << endl;


    while (getline(inventario, linea)) { // mientras el archivo este abierto o no sea el final.
        // aca tambien podria decir  while ( !inventario.eof)


        stringstream stream(linea); // Convertir la cadena a un stream


        // con este for, hago que los elementos que estan en la columna 1 me los meta en un arbol
        // podria hacer que me meta lo de otra columna en algun otra estructura.
        for (int i = 0; getline(stream, dato, ','); i++) {

            //0= grupo
            //1= codigo de barras
            //2= articulos
            // todo lo demas deposito.


            if (i == 1) {  // elijo la columa articulos y creo un nuevo nodo con esto
                // arbol2.put(dato);
                arbol2.put(dato);
                cantidadTotalDeArticulosDiferentes++;
            }
            if(i>2 && dato!= ""){
                dato_num= stoi(dato);
                arbol2.agregarAListaUltimoNodo(dato_num, i-2);
                cantidadTotalDeArticulos=cantidadTotalDeArticulos+dato_num;

            }
            //if(i>3){ // si es mas que dos estoy a nivel de los depositos
            // lo que estos contengan los quiero en mi lista, que tiene que corresponder justamente al nodo
            // arbol2.agregarAListaUltimoNodo(dato);}

        }

        // si imprimo deveria ver la lista de los depositos para cada nodo ingresado



    }
    arbol2.imprimirListaNodo("AMLM-VT J02 A");
    if (arbol2.search("AMLM-VT J02 A") ){
        cout<<"se encontro el nodo"<<endl;
        //arbol2.searchAndRemove("AMLM-VT J02 A");
        if(arbol2.search("AMLM-VT J02 A")){
        }cout<<"no se encontro el archvivo";
    }

    cout<<"la cantidad total de articulos diferentes es: "<<cantidadTotalDeArticulosDiferentes<<endl;
    cout<<"la cantidad total de articulos es "<<cantidadTotalDeArticulos<<endl;
    cout<<"el estok del articulo SMFS45 SIN/REG-DERECHA es:"
    cout<< arbol2.getSumaDatosNodo("SMFS45 SIN/REG-DERECHA");
// esto es solo una pruenba se supone que se integra en una funcion mas grande que imprime todos los productos
// con su respectivo stock
 inventario.close();
}






/*
   int main(int argc,char **argv ){
       string archivo= argev[argv-1];
       cout<<"archivo"<<


       for(int i= 1; i<arg -1; i++){
           string arg =argv[i];
           cout<<arg<<endl;
           if(arg=="hola"){
               hola(archivo)
           }
           if(arg==" "){

           }
           if(arg==" "){

           }
       }
   }
*/

