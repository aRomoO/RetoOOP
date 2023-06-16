/*
 *          ALFREDO ROMO OSORNO
 *          a01643235@tec.mx
 *          SITUACIÓN PROBLEMA OOP 2DO SEMESTRE:
 *          SIMULACION SISTEMA DE STREAMING
 *
 * */

//C++ Libraries
#include <iostream>
//#include "conio.h"
#include "string"
#include "fstream"
#include "exception"
#include "vector"
#include <windows.h>
//#include <filesystem>
#include <sstream>
//#include <typeinfo>
#include <stdexcept>
#include <limits>

//Header files
#include "Pelicula.h"
#include "Capitulo.h"

using namespace std;

//VARIABLES GLOBALES
string lineStr = "------------------------------------------------------------------------------------------------";
vector<Pelicula*> vectorPeliculas;
vector<Capitulo*> vectorCapitulos;




void clearConsole() {
#ifdef _WIN32
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        SetConsoleCursorPosition(hStdOut, coord);
    }
#else
    std::system("clear");
#endif
}

void pressEnter() {

    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = VK_RETURN;
    input.ki.dwFlags = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    INPUT inputRelease = input;
    inputRelease.ki.dwFlags = KEYEVENTF_KEYUP;

    // Press Enter key
    SendInput(1, &input, sizeof(INPUT));

    // Release Enter key
    SendInput(1, &inputRelease, sizeof(INPUT));
}

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

//SUBMENUS
void SubMenuCalificarVideo()
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
        while (true) {
            if (cin >> cal && (cal >= 1 && cal <= 5)) {
                vectorPeliculas.at(idxPelicula)->addCalificacion(cal);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            else
            {
                cout << "INVALID SCORE, TRY AGAIN (only use 1 to 5)...\nScore : ";
            }
        }

    }
    else
    {
        //CHECK ID IS IN CAPITULOS
        int idxCapitulos = BuscarPorID(reinterpret_cast<vector<struct Video *> *>(&vectorCapitulos), videoId);
        if(idxCapitulos != -1)
        {
            int cal; //Calificacion

            cout << "ENTER SCORE FOR: " << vectorCapitulos.at(idxCapitulos)->getNombre() << "    (Low 1 - 5 High)\n: ";
            //Validadte Calification
            while (true) {
                if (cin >> cal && (cal >= 1 && cal <= 5)) {
                    vectorCapitulos.at(idxCapitulos)->addCalificacion(cal);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                else
                {
                    cout << "INVALID SCORE, TRY AGAIN (only use 1 to 5)...\nScore : ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

        }
        //ID DOESNT EXIST IN CATALOGUE
        else
        {
            cout << "ERROR: ID NOT FOUND IN CATALOGUE..." << endl;
        }

    }

    cout << lineStr << endl;

}

void MostrarPorFiltroCalificacion(int tipo)
{
    cout << "Ingresa la calificacion" << endl;
    double calif;
    while(true)
    {
        if (cin >> calif && (calif >= 1 && calif <=5))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } else
        {
            cout << "Por favor ingresa una calificacion valida: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    switch (tipo) {
        case 1:
            for (auto i : vectorPeliculas)
            {
                if(i->PromedioCalificiones() != "SC" && (stod(i->PromedioCalificiones()) >= calif))
                {
                    cout << i->mostrarFiltradoCalificacion()<<endl;
                }
            }
            break;
        case 2:
            for (auto i : vectorCapitulos)
            {
                if(i->PromedioCalificiones() != "SC" && (stod(i->PromedioCalificiones()) >= calif))
                {
                    cout << i->mostrarFiltradoCalificacion() << endl;
                }
            }
            break;
        case 3:
            for (auto i : vectorPeliculas)
            {
                if(i->PromedioCalificiones() != "SC" && (stod(i->PromedioCalificiones()) >= calif))
                {
                    cout << i->mostrarFiltradoCalificacion()<<endl;
                }
            }
            for (auto i : vectorCapitulos)
            {
                if(i->PromedioCalificiones() != "SC" && (stod(i->PromedioCalificiones()) >= calif))
                {
                    cout << i->mostrarFiltradoCalificacion() << endl;
                }
            }
            break;
    } cout << "[FIN DE LA BUSQUEDA...]"<<endl;
}


void MostrarPorFiltroGenero(int tipo)
{
    cout << "Ingresa el genero (accion | misterio | drama): " << endl;
    string genero;
    cin >> genero;
    while(true)
    {
        if (genero =="drama" || genero =="accion" || genero =="misterio")
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } else
        {
            cout << "Por favor ingresa una genero valido: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    switch (tipo) {
        case 1:
            for (auto i : vectorPeliculas)
            {
                if(i->getGenero() == genero)
                {
                    cout << i->mostrarFiltradoGenero()<<endl;
                }
            }
            break;
        case 2:
            for (auto i : vectorCapitulos)
            {
                if(i->getGenero() == genero)
                {
                    cout << i->mostrarFiltradoGenero()<<endl;
                }
            }
            break;
        case 3:
            for (auto i : vectorPeliculas)
            {
                if(i->getGenero() == genero)
                {
                    cout << i->mostrarFiltradoGenero()<<endl;
                }
            }
            for (auto i : vectorCapitulos)
            {
                if(i->getGenero() == genero)
                {
                    cout << i->mostrarFiltradoGenero()<<endl;
                }
            }
            break;
    }     cout << "[FIN DE LA BUSQUEDA...]"<<endl;

}

void SubMenuFiltrarCalifcacion()
{

    string tipoDeVideo = R"delimiter(
        * 1. Mostrar Peliculas
        * 2. Mostrar Capitulos
        * 3. Mostrar peliculas y capitulos
)delimiter";

    cout << tipoDeVideo<<endl;
    cout << ": " << endl;

    int tipo;
    while(true){

        if(cin >> tipo && (tipo >= 1 && tipo <= 3))
        {
            //MOSTRAS POR CALIFICACION
            cout << "Mostrando por calificacion"<<endl;
            MostrarPorFiltroCalificacion(tipo);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } else
        {
            cout << "Ingresa una opcion valida\n: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

}

void SubMenuFiltrarPorGenero(){

    string tipoDeVideo = R"delimiter(
        * 1. Mostrar Peliculas
        * 2. Mostrar Capitulos
        * 3. Mostrar peliculas y capitulos
)delimiter";

    cout << tipoDeVideo<<endl;
    cout << ": " << endl;

    int tipo;
    while(true){

        if(cin >> tipo && (tipo >= 1 && tipo <= 3))
        {
            //MOSTRAS POR CALIFICACION
            cout << "Mostrando por Genero"<<endl;
            MostrarPorFiltroGenero(tipo);

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } else
        {
            cout << "Ingresa una opcion valida\n: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

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

[[noreturn]] void MainMenu()
{
    //clearConsole();
    //MostrarCatalogoConCalif();
    //cout << BuscarPorID(reinterpret_cast<vector<struct Video *> *>(&vectorCapitulos), "20160150-S02E09");

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
                    SubMenuCalificarVideo();
                    system("pause");
                    break;
                case 3:
                    SubMenuFiltrarCalifcacion();
                    system("pause");
                    break;
                case 4:
                    SubMenuFiltrarPorGenero();
                    system("pause");
                    break;
                case 0:
                    abort();
                case 9:
                    abort();
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
        std::cout <<"CURRENT PATH: " << dir_path << std::endl;
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
            cout << " ** Unable to open catalogue file. File may be in use or path may not be correct **"<<endl;
            return false;
        }

            cout << "File Opened Successfully...\n";
            cout << "loading data..."<<endl;
            LoadFileIntoVectors(&file);
            file.close(); // Close the file
            return true;


}

int main() {

    string welcome = R"delimiter(
----------------------BIENVENIDO AL SIMULADOR DE SISTEMA DE STREAMING----------------------

    *SE INTENTARA BUSCAR EL ARCHIVO {"videos.txt"} EN LA CARPETA ACTUAL
    *EN CASO DE NO ENCONTRARLO, POR FAVOR INGRESA A RUTA Y EL NOMBRE MANUALMENTE

-------------------------------------------------------------------------------------------

)delimiter";

    cout << welcome << endl;
    system("pause");
    //Try to open the file with the current path
    if(OpenTextFile(GetCurrentPath(), "video5s.txt")){
        cout << "Data loaded successsfully\n" ;


        MainMenu();
    }

    //If can´t open file on current path, ask for path and filename
    else
    {

        string dir;
        string filename;
        int salir = 0;

        while(true)
        {
            //clearConsole();
            cout << "ENTER FOLDER DIRECTORY: (without file and extention)\n : ";
            cin >> dir; cout << endl;
            cout << "ENTER FILE NAME AND EXTENTION: (ej. videos.txt)\n : ";
            cin >> filename;
            if(!OpenTextFile(dir,filename))
            {
                while (true)
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
