//
// Created by fredi on 13/06/2023.
//

#include "Video.h"

#include <utility>


//CONSTRUCTORS
Video::Video(std::string id, std::string nombre, int duracion, std::string genero) :
id(std::move(id)),
nombre(std::move(nombre)),
duracion(duracion),
genero(std::move(genero)){}


//GETTERS & SETTERS
std::string Video::getId() const {
    return id;
}

const std::string &Video::getNombre() const {
    return nombre;
}

const std::string &Video::getGenero() const {
    return genero;
}



//METHODS


std::string Video::PromedioCalificiones() {
    int n = calificacion.size();
    int sum = 0;
    //avoid 0/0
    if (n==0) return "SC";
    else
    {

        for (int i : calificacion)
        {
            sum += i;
        }
    }
    return std::to_string(float(sum) / n);

}

//VIRTUAL METHODS
std::string Video::toString() {
    return  "\n---------------\n[ID]:"        +id+"\n"+
            "[Nombre]: "       + nombre+"\n"+
            "[Duracion]: "     +std::to_string(duracion)+"\n"+
            "[Genero]: "       + genero+"\n"+
            "[Calificacion]: " + PromedioCalificiones()+ "\n";

}

bool Video::addCalificacion(int cal) {
    if (!(cal >= 1 && cal <= 5))
    {
        return false;
    }
    else
    {
        calificacion.push_back(cal);
        return true;
    }

}

std::string Video::mostrarFiltradoCalificacion() {
    return  "\n---------------\n[ID]:"        +id+"\n"+
            "[Nombre]: "       + nombre+"\n"+
            "[Calificacion]: " + PromedioCalificiones()+ "\n";
}

std::string Video::mostrarFiltradoGenero() {
    return  "\n---------------\n[ID]:"        +id+"\n"+
            "[Nombre]: "       + nombre+"\n"+
            "[Genero]: "       + genero+"\n"+
            "[Calificacion]: " + PromedioCalificiones()+ "\n";
}


