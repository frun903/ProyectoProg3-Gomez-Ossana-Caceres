#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include "EstructurasLimpio/ListaFT.h"
#include "EstructurasLimpio/ArbolBinarioAVL.h"
#include "EstructurasLimpio/ArbolAVL.h"

using namespace std;

void total_art_dif(string &nombre_archivo) {

    //comenzando a medir el tiempo.
    std::clock_t start_time = std::clock();

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


    while (getline(Archivo, linea)) {


        stringstream stream(linea); // Convertir la cadena a un stream

        for (int i = 0; getline(stream, dato, delimitadorDeColumn); i++) {

            if (i == 2) {
                cantidad_Articulos_Diferentes++;
            }
        }
    }

    std::cout << "Cantidad total de articulos diferentes:" << cantidad_Articulos_Diferentes<<endl;

    cout<<" "<<endl;
    std::clock_t end_time = std::clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    cout<<" "<<endl;
    std::cout << "Tiempo de ejecucion: " << elapsed_time << " segundos" << std::endl;


}








//Listo
void total_art(string &nombre_archivo) {


    //comenzando a medir el tiempo.
    std::clock_t start_time = std::clock();

    //Apertura del archivo.csv
    ifstream Archivo;
    string linea, dato;
    char delimitadorDeColumn = ',';
    int dato_num = 0, cantidad_Articulos_Totales=0;


    Archivo.open(nombre_archivo);
    if (Archivo.fail()) {
        std::cout << "Archivo NO  abierto correctamnete" << std::endl;
    } else {
        std::cout << "Archivo funciona correactamente" << std::endl;
    }


    //Ignoramos la primera linea del .csv
    getline(Archivo, linea);




    while (getline(Archivo, linea)) { // mientras el archivo este abierto o no sea el final.


        stringstream stream(linea); // Convertir la cadena a un stream


        for (int i = 0; getline(stream, dato, delimitadorDeColumn); i++) {
            if (i > 2) {
                if (dato == "") {
                    dato="0";
                }
                dato_num = stoi(dato);
                cantidad_Articulos_Totales = cantidad_Articulos_Totales + dato_num;
            }
        }

    }

    std::cout << "Cantidad total de articulos: " << cantidad_Articulos_Totales<<endl;


    std::clock_t end_time = std::clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    cout<<" "<<endl;
    std::cout << "Tiempo de ejecucion: " << elapsed_time << " segundos" << std::endl;


}







//Listo
void minStock(string &nombre_archivo, int n) {

    //comenzando a medir el tiempo.
    std::clock_t start_time = std::clock();


//Declaracion de Varibales
    int dato_num, stock = 0;
    string producto;
    string inventario, linea, dato;
    char delimitadorDeColumn = ',';

//Declaracion del Arbol
    ArbolAVL<string, int> arbolStock;


    //Crea conexion a mi archivo de texto .csv
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

        // con este for, hago que los elementos que estan en la columna  me los meta en un arbol
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
            }
        }

        arbolStock.putStock(producto, stock);

        //Aqui el Stock de c/d producto vuelve a cero, ya que esta variable auxilar corresponde solo a un producto
        stock = 0;
    }

    std::cout<<"Articulos con Stock menor a "<< n<<std::endl;

    arbolStock.searchMinStock(n);

    std::clock_t end_time = std::clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    cout<<" "<<endl;
    std::cout << "Tiempo de ejecucion: " << elapsed_time << " segundos" << std::endl;





}

//Listo
void minStock(string &nombre_archivo, int n, int NumDepo) {

    //comenzando a medir el tiempo.
    std::clock_t start_time = std::clock();



    int dato_num, stock = 0, depo;
    string producto;
    string inventario, linea, dato;
    char delimitadorDeColumn = ',';


    ArbolAVL<string, int> arbolStock;

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

            }
            }
        }
            arbolStock.putStock(producto, stock);

        //Aqui el Stock de c/d producto vuelve a cero, ya que esta variable auxilar corresponde solo a un producto
        stock = 0;

    }

    std::cout<<"Articulos en Deposito "<<NumDepo<<" con Stock menor a "<< n<<std::endl;

    arbolStock.searchMinStock(n);


    std::clock_t end_time = std::clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    cout<<" "<<endl;
    std::cout << "Tiempo de ejecucion: " << elapsed_time << " segundos" << std::endl;



}







//Listo
void maxStock(string &nombre_archivo,int n) {

//comenzando a medir el tiempo.
    std::clock_t start_time = std::clock();


    int dato_num, stock = 0;
    string producto;
    string inventario, linea, dato;
    char delimitadorDeColumn = ',';


    ArbolAVL<string, int> arbolStock;

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
            }
        }

        arbolStock.putStock(producto,stock);

        //Aqui el Stock de c/d producto vuelve a cero, ya que esta variable auxilar corresponde solo a un producto
        stock = 0;
    }

    std::cout<<"Articulos con Stock Mayor que "<< n<<std::endl;

    arbolStock.searchMaxStock(n);


    std::clock_t end_time = std::clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    cout<<" "<<endl;
    std::cout << "Tiempo de ejecucion: " << elapsed_time << " segundos" << std::endl;


}




//Listo
void stock(string &nombre_archivo,string nombreArticulo) {

    //comenzando a medir el tiempo.
    std::clock_t start_time = std::clock();


    int dato_num, stock = 0;
    string producto;
    string inventario, linea, dato;
    char delimitadorDeColumn = ',';


    ArbolBinarioAVL<string, int, ListaFT<int>> arbol1;
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


    while (getline(Archivo, linea)) {

        stringstream stream(linea); // Convertir la cadena a un stream


        for (int i = 0; getline(stream, dato, delimitadorDeColumn); i++) {

            if (i == 2) {
                //Aqui guardo el "Articulo" del producto es decir el nombre
                producto = dato;
            }
            if (i > 2) {
                if (dato == "" || dato == "\n") {
                    dato = "0";
                }
                dato_num = stoi(dato);
                stock = stock + dato_num;
                //Para guardar el deposito con la cantidad de elementos del deposito y el numero del mismo
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



    std::clock_t end_time = std::clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    cout<<" "<<endl;
    std::cout << "Tiempo de ejecucion: " << elapsed_time << " segundos" << std::endl;

}










//Listo
void stock2(string &nombre_archivo,string nombreArticulo, int deposito) {

    //comenzando a medir el tiempo.
    std::clock_t start_time = std::clock();


    int dato_num, stock = 0;;
    string producto;
    string inventario, linea, dato;
    char delimitadorDeColumn = ',';


    ArbolBinarioAVL<string, int, ListaFT<int>> arbol1;
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

        arbol1.put(producto, stock, depositos);
        //Aqui el Stock de c/d producto vuelve a cero, ya que esta variable auxilar corresponde solo a un producto
        stock = 0;
        //Vacio esta lista auxiar para poder volver a usarla con el nodo
        depositos.vaciar();
    }

    arbol1.searchAndDataStockDeposito(nombreArticulo, deposito);


    std::clock_t end_time = std::clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    cout<<" "<<endl;
    std::cout << "Tiempo de ejecucion: " << elapsed_time << " segundos" << std::endl;


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
        if (strcmp("-total_art_dif", arg) == 0) {
            total_art_dif(nombre_archivo);
        }

        if (strcmp("-total_art", arg) == 0) {
            total_art(nombre_archivo);
        }


        if (strcmp("-min_Stock", arg) == 0) {
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


        if (strcmp("-max_Stock", arg) == 0) {

            try {
                n = stoi(argv[i + 1]);
            } catch (std::invalid_argument &e) {
                cerr << "Leer manual de uso. " << e.what() << endl;
                return 1;
            }

            if (deposito < 0) {
                maxStock(nombre_archivo, n);
            } else {
                minStock(nombre_archivo, n, deposito);
            }
        }

        if (strcmp("-stock", arg) == 0) {

            try {
                nomArticulo = (argv[i + 1]);
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
                stock(nombre_archivo,nomArticulo);
            } else {
                stock2(nombre_archivo, nomArticulo, deposito);
            }
        }

        return 0;
    }
}
