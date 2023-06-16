/*
 *          ALFREDO ROMO OSORNO
 *          a01643235@tec.mx
 *          SITUACIÓN PROBLEMA OOP 2DO SEMESTRE:
 *          SIMULACION SISTEMA DE STREAMING
 *
 * */

//C++ Libraries
#include <iostream>
#include "conio.h"
#include "string"
#include "fstream"
#include "exception"
#include "vector"
#include <windows.h>
#include <filesystem>
#include <sstream>
#include <typeinfo>
#include <stdexcept>
#include <limits>

//Header files
#include "Video.h"
#include "Pelicula.h"
#include "Capitulo.h"

using namespace std;

//VARIABLES GLOBALES
string lineStr = "------------------------------------------------------------------------------------------------";
vector<Pelicula*> vectorPeliculas;
vector<Capitulo*> vectorCapitulos;

//Busca y regresa el index de en donde se encuentra la película con ID _
int BuscarPorID(vector <Video*> * v,const string& id){
    for (int i = 0; i < v->size(); i++)
    {
        if (v->at(i)->getId() == id )
        {
            return i;
        }
    }
    return -1;
}

void subMenuCalificarVideo()
{
    string videoId;
    cout << endl << lineStr << endl;
    cout << "Enter video ID: ";

    cin >> videoId;

    int idxPelicula = BuscarPorID(reinterpret_cast<vector<struct Video *> *>(&vectorPeliculas), videoId);
    if(idxPelicula != -1) //CHECK IF ID IS IN MOVIES
    {
        //cout << "INDICE EN PELICULAS: " << idxPelicula << endl;;

        int cal; //Calificacion

        cout << "ENTER SCORE FOR: " << vectorPeliculas.at(idxPelicula)->getNombre() << "    (Low 1 - 5 High)\n: ";
        //Validadte Calification
        while (1) {
            if (cin >> cal && (cal >= 1 && cal <= 5)) {
                vectorPeliculas.at(idxPelicula)->addCalificacion(cal);
                break;
            }
            else
            {
                cout << "INVALID SCORE, TRY AGAIN (only use 1 to 5)...\n";
            }
        }

    }
    else
    {
        //CHECK ID IS IN CAPITULOS
        int idxCapitulos = BuscarPorID(reinterpret_cast<vector<struct Video *> *>(&vectorCapitulos), videoId);
        if(idxCapitulos != -1)
        {
            //cout << "INDICE EN CAPITULOS: " << idxCapitulos << endl;

        }
        //ID DOESNT EXIST IN CATALOGUE
        else
        {
            cout << "ERROR: ID NOT FOUND IN CATALOGUE..." << endl;
        }

    }

    cout << lineStr << endl;

}

void MostrarCatalogoConCalif()
{
    for(auto i : vectorPeliculas)
    {
        cout << *i;
    }

    for(auto i : vectorCapitulos)
    {
        cout << *i;
    }


}

void CalificarVideo(const string& id)
{

}


void clearConsole() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = {0, 0};
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(hConsole, &screen);
    FillConsoleOutputCharacter(hConsole, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(hConsole, topLeft);
}

[[noreturn]] void MainMenu()
{
    //clearConsole();
    //MostrarCatalogoConCalif();
    //cout << BuscarPorID(reinterpret_cast<vector<struct Video *> *>(&vectorCapitulos), "20160150-S02E09");

    clearConsole();
    string mainMenutxt =
(R"delimiter(
                                    --------MENU--------
------------------------------------------------------------------------------------------------

        * 1. Mostrar todo el catalogo con calificaciones.
        * 2. Calificar un video
        * 3. Mostrar peliculas o capitulos con una calificacion minima determinada
        * 4. Mostrar peliculas o capitulos de un cierto genero.
        * 9/0. Salir

------------------------------------------------------------------------------------------------

-Ingrese una opcion: )delimiter");

    int opcionMainMenu;

    while (true) {
        cout << mainMenutxt;

        //Validate input is int and (1->4 or 0/9)
        if (cin >> opcionMainMenu && ((opcionMainMenu >=1 && opcionMainMenu <=4) || opcionMainMenu==0) || opcionMainMenu==9) {

            switch (opcionMainMenu) {
                case 1:
                    MostrarCatalogoConCalif();
                    system("pause");
                    break;
                case 2:
                    subMenuCalificarVideo();
                    system("pause");
                    break;
                case 3:
                    system("pause");
                    break;
                case 4:
                    system("pause");
                    break;
                case 0:
                    abort();
                    break;
                case 9:
                    abort();
                    break;
            }


            // Reset the error state and ignore any remaining invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Input is not a valid number


            // Reset the error state and ignore the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingresa una opción valida\n" << endl;
        }
    }



}


string GetCurrentPath()
{
    try
    {
        string file {__FILE__};
        string path {file.substr(0, file.rfind('/\\'))};
        ///FORMAT WITH DOUBLE backslash

        string dir_path;
        for (char c : path) {
            if (c == '\\') {
                dir_path += "\\\\";
            } else {
                dir_path += c;
            }
        }
        std::cout << dir_path << std::endl;
        return dir_path;


    } catch (...){} throw runtime_error("Can't get Current Directory");

}

void LoadFileIntoVectors(ifstream * file) {
    string dataLine;


        while (getline(*file, dataLine))
        {

            stringstream ss(dataLine);
            string tipo;
            getline(ss, tipo, ',');

            //VARIABLES PARA LUEGO METER DATOS A OBJETOS
            string  id,
                    titulo,
                    duracion_str,
                    genero,
                    nombreSerie,
                    numero_str;

            int duracion,
                    numeroEpisodio;

            //STREAMSTREAM PARA SEPARAR EN BASE A LAS COMAS LOS VALOES
            getline(ss, id, ',');
            getline(ss, titulo, ',');
            getline(ss, duracion_str, ',');
            duracion = stoi(duracion_str);
            getline(ss, genero, ',');
            //CAPITULO TIENE EXTRA ESTOS DATOS, POR LO QUE SOLO ESTOS VAN DENTRO DEL IF

            //CHECAMOS SI ES PELICULA O CAPITULO Y CREAMOS UN OBJETO EN EL VECTOR CORRESPONDIENTE
            if (tipo == "c")
            {
                getline(ss, nombreSerie, ',');
                getline(ss, numero_str);

                numeroEpisodio = stoi(numero_str);

                vectorCapitulos.push_back(new Capitulo(id, titulo, duracion, genero, nombreSerie, numeroEpisodio));

            }
            else
            {
                if (tipo == "p")
                {

                    vectorPeliculas.push_back(new Pelicula(id, titulo, duracion, genero));
                    //cout << *vectorPeliculas.at(0);
                }
                else
                {
                    cout << "CAN'T PARSE DATA FROM: " << dataLine << endl
                         << "PLEASE VERIFY INFO..."<<endl;
                }
            }


        }




}

bool OpenTextFile(const string& CurrentPath, const string& filename) {
    ifstream file(CurrentPath+"\\"+filename); // Open the file
    string firstLine;


        if (!file.is_open()) {
            cout << "Unable to open catalogue file. File may be in use or path may not be correct "<<endl;
            return false;
        }

            cout << "File Opened Successfully...\n";
            cout << "loading data..."<<endl;
            LoadFileIntoVectors(&file);
            file.close(); // Close the file
            return true;


}

int main() {

    cout << "Looking for { videos.txt } file in current dir: \n";

    //Try to open the file with the current path
    if(OpenTextFile(GetCurrentPath(), "videos.txt")){
        cout << "Data loaded successsfully\n" ;
        MainMenu();
    }

    //If can´t open file on current path, ask for path and filename
    else
    {

        string dir;
        string filename;
        int salir = 0;

        while(1)
        {
            //clearConsole();
            cout << "ENTER FOLDER DIRECTORY: (without file and extention)\n : ";
            cin >> dir; cout << endl;
            cout << "ENTER FILE NAME AND EXTENTION: (ej. videos.txt)\n : ";
            cin >> filename;
            if(!OpenTextFile(dir,filename))
            {
                while (1)
                {
                    cin.clear();  // Clear the error flag
                    cout << "CAN'T OPEN DOCUMENT, TRY AGAIN?\n0 : exit\nanything else : continue" <<endl;
                    cin >> salir;
                    if (salir==0)
                    {
                        abort();
                    }

                    else
                    {
                        //clearConsole();
                        break;
                    }

                }

            }
            else
            {
                break;


            }

        }

        MainMenu();


    }









    return 0;
}
