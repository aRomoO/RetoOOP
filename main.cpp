#include <iostream>
#include "Video.h"
#include "Pelicula.h"
#include "Capitulo.h"
#include "string"
using namespace std;
int main() {

    Pelicula p1(01,'p',"Harry Potter",120,"fantasia",90);
    Capitulo c1(01,'s',12,"Episodio  Prueba", 22, "aventura", 100);


    cout << p1;
    //cout << p1.toString()<<endl;
    cout << c1.toString();


    return 0;
}
