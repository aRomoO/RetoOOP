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
void Video::setId(std::string id) {
    Video::id = std::move(id);
}
const std::string &Video::getNombre() const {
    return nombre;
}
void Video::setNombre(const std::string &nombre) {
    Video::nombre = nombre;
}
int Video::getDuracion() const {
    return duracion;
}
void Video::setDuracion(int duracion) {
    Video::duracion = duracion;
}
const std::string &Video::getGenero() const {
    return genero;
}
void Video::setGenero(const std::string &genero) {
    Video::genero = genero;
}


//METHODS
const std::vector<int> &Video::getCalificacion() const {
    return calificacion;
}
void Video::setCalificacion(const std::vector<int> &calificacion) {
    Video::calificacion = calificacion;
}

//VIRTUAL METHODS
std::string Video::toString() {
    return  "\n---------------\n[ID]:"        +id+"\n"+
            "[Nombre]: "       + nombre+"\n"+
            "[Duracion]: "     +std::to_string(duracion)+"\n"+
            "[Genero]: "       + genero+"\n";
            //"[Calificacion]: " + std::to_string(calificacion)+ "\n";

}

std::string Video::PromedioCalificaion() {
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


