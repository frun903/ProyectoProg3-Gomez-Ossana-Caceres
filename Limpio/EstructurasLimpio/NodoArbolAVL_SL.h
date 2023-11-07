using namespace std;
#include <string.h>

/*
 * Este nodo no contiene la lista de los depositos del producto
 * Solo contiene el nombre y el Stock
 * Aplicacion: -minStock
 *             -minStock por deposito
 *             -max
 * */

template<class T,class U >
class NodoArbolAVL_SL {
private:
    T data;
    int stock;
    NodoArbolAVL_SL *left, *right, *in;
    int height;



public:


    NodoArbolAVL_SL(T d,U s ) {
        data = d;
        left = nullptr;
        right = nullptr;
        in= nullptr;
        height = 1;
        //sumaDatoslista=0;
        stock=s;



    }
// esto seria get nombre en el codigo de fran.
    T getData() const {
        return data;
    }


    void setData(T d) {
        this->data = d;
    }

    NodoArbolAVL_SL *getRight()  {
        return right;
    }

    void setRight(NodoArbolAVL_SL *r) {
        this->right = r;
    }


    NodoArbolAVL_SL *getIn()  {
        return in;
    }

    void setIn(NodoArbolAVL_SL *i) {
        this->in = i;
    }

    NodoArbolAVL_SL *getLeft() {
        return left;
    }

    void setLeft(NodoArbolAVL_SL *l) {
        this->left = l;
    }


    int getHeight() {
        return height;
    }

    void setHeight(int h) {
        height = h;
    }
/*
    int getSumaDatosLista(){
        return sumaDatoslista;
    }
*/
    int getStock(){
        return stock;
    }

    void setStock(int s){
        this->stock=s;
    }


    void setstock(){

    }



    void print(bool esDerecho, string identacion) {
        if (right != NULL) {
            right->print(true, identacion + (esDerecho ? "     " : "|    "));
        }
        cout << identacion;
        if (esDerecho) {
            cout << " /";
        } else {
            cout << " \\";
        }
        cout << "-- ";
        cout << data << endl;
        if (left != NULL) {
            left->print(false, identacion + (esDerecho ? "|    " : "     "));
        }
    }

    void insertarEnLista(U u) {

    }
};
