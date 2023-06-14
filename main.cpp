/*
 *          ALFREDO ROMO OSORNO
 *          a01643235@tec.mx
 *          SITUACIÓN PROBLEMA OOP 2DO SEMESTRE:
 *          SIMULACION SISTEMA DE STREAMING
 *
 * */

//C++ Libraries
#include <iostream>
#include "string"
#include "fstream"
#include "exception"
#include "vector"


//Header files
#include "Video.h"
#include "Pelicula.h"
#include "Capitulo.h"

using namespace std;

//VARIABLES GLOBALES
vector<Pelicula*> vectorPeliculas;
vector<Capitulo*> vectorCapitulos;


string getSingleLine() {
    std::ifstream file(R"(G:\My Drive\2DO SEMESTRE\OOP2\RetoOOP\videos.txt)"); // Open the file
    std::string firstLine;

    try {
        if (file.is_open()) {
            getline(file, firstLine); // Read the first line






            file.close(); // Close the file
        } else {
            throw runtime_error("Unable to open the file. check the path:");
        }
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << std::endl;
    }

    return firstLine;
}

int main() {

/*
    Pelicula p1(01,'p',"Harry Potter",120,"fantasia",90);
    Capitulo c1(01,'c',"Capitulo1",23,"aventura",100,"HIMYM",01);
    cout << p1;
    cout << c1;
*/


    //TRATAR DE CARGAR ARCHIVO//
    string firstLine = getSingleLine();
    cout << firstLine;


    //SI NO SE ENCUENTRA EL ARCHIVO, PEDIR LA RUTA//

    //SI NO SE PUEDE, MARCAR ERROR//



    return 0;
}
