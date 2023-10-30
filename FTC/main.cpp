#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Lista/ListaFT.h"
#include "Cola/Cola.h"
using namespace std;

int main() {

    ListaFT<int> depositos;
    Cola Encola;
    int dato_num;
    int stock=0;
    string producto;
    int cantidad_Articulos_Totales=0;

    //Crea conexion a mi archivo de texto
   ifstream Archivo;
   char renglon[100];
   string  inventario,linea,dato;
   char delimitadorDeColumn=',';
   int contadordecolumnas;
   int cantidad_Articulos_Diferentes=0;

   Archivo.open("/home/frang/untitled2/Inventariado Fisico.csv");


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
        Encola.encolar(stock,producto,depositos);

        //depositos.print();




        //Aqui el Stock de c/d producto vuelve a cero, ya que esta variable auxilar corresponde solo a un producto
        stock=0;
        //Vacio esta lista auxiar para poder volver a usarla con el nodo
        depositos.vaciar();
    }


    while (!Encola.esVacia()){
        Encola.desencolar();
    }

    cout<<std::endl;
    cout<<std::endl;
    cout<<"La cantidad de articulos diferentes es "<<cantidad_Articulos_Diferentes<<endl;
    cout<<"La cantidad de Articulos totales es "<<cantidad_Articulos_Totales<<endl;



    return 0;
}
