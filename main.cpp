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
    string Grupo, codigoBarras, articulo;
    // debemos ver como manejar la definicion de los depositos ya que estos son dinamicos.
    int deposito1, deposito2, deposito3,deposito4 ,deposito5;
    ArbolBinarioAVL<string> arbol1;

    char delimitadorDeColumn = ',';
    cout << "hola mundo funciona el cmake" << endl;


    ifstream inventario; // definimos un archivo
    inventario.open("Inventariado Fisico.csv"); // abrimos el archvo

    //aca despues nesesitamos empezar a medir el tiempo;

    if (!inventario.is_open()) {
        cout << "error al abrir el archivo" << endl;
    }

    // vamos a leer la primera linea para saltar el encabezado.
    getline(inventario,linea);
    while (getline(inventario,linea)){ // mientras el archivo este abierto o no sea el final.
        // aca tambien podria decir  while ( !inventario.eof)

        stringstream stream(linea); // Convertir la cadena a un stream


        // con este for, hago que los elementos que estan en la columna 1 me los meta en un arbol
        // podria hacer que me meta lo de otra columna en algun otra estructura.
        for(int i=0; getline(stream,dato,delimitadorDeColumn); i++ ){
            if(i==1){
                arbol1.put(dato);
            }
        }

/*
        getline(stream, Grupo,',');
        getline(stream, codigoBarras, ',');
        getline(stream, articulo, ',');
        getline(stream, deposito1, ',');
        getline(stream, deposito2, ',');
        getline(stream, deposito3, ',');
        getline(stream,deposito4,',');
*/

    }
  arbol1.inorder();
}