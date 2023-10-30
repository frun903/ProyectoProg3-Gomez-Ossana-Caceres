//
// Created by frang on 11/09/23.
//

#ifndef U04_COLAS_FRUN903_CLIENTE_H
#define U04_COLAS_FRUN903_CLIENTE_H
#include <string>
class Cliente{
private:
    std::string nombre;
    int cant_productos;
    int aGastar;
    bool embarazado;
public:
    int cant_pro_Get(){
        return cant_productos;
    }

    std::string Nombre_GEt(){
        return nombre;
    }

    int aGastar_Get(){
        return aGastar;
    }

    bool embarazado_get(){
        return embarazado;
    }

    void Set_Datos(std::string N, int A, int B, bool C){
        nombre=N;
        cant_productos=A;
        aGastar=B;
        embarazado=C;
    }

};



#endif //U04_COLAS_FRUN903_CLIENTE_H
