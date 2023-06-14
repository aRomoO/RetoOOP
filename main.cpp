/*
 *          ALFREDO ROMO OSORNO
 *          a01643235@tec.mx
 *          SITUACIÓN PROBLEMA OOP 2DO SEMESTRE:
 *          SIMULACION SISTEMA DE STREAMING
 *
 * */


#include <iostream>
#include "Video.h"
#include "Pelicula.h"
#include "Capitulo.h"
#include "string"
using namespace std;
int main() {

    Pelicula p1(01,'p',"Harry Potter",120,"fantasia",90);
    Capitulo c1(01,'c',"Capitulo1",23,"aventura",100,"HIMYM",01);
    cout << p1;
    cout << c1;


    //TRATAR DE CARGAR ARCHIVO//

    //SI NO SE ENCUENTRA EL ARCHIVO, PEDIR LA RUTA//

    //SI NO SE PUEDE, MARCAR ERROR//



    return 0;
}
