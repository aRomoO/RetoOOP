//
// Created by fredi on 13/06/2023.
//

#include "Video.h"


//CONSTRUCTORS
Video::Video(int id, char tipo, std::string nombre, int duracion, std::string genero, int calificacion) :
id(id),
tipo(tipo),
nombre(std::move(nombre)),
duracion(duracion),
genero(std::move(genero)),
calificacion(calificacion){}


//GETTERS & SETTERS
int Video::getId() const {
    return id;
}
void Video::setId(int id) {
    Video::id = id;
}
char Video::getTipo() const {
    return tipo;
}
void Video::setTipo(char tipo) {
    Video::tipo = tipo;
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
int Video::getCalificacion() const {
    return calificacion;
}
void Video::setCalificacion(int calificacion) {
    Video::calificacion = calificacion;
}

//METHODS

//VIRTUAL METHODS
std::string Video::toString() {
     return std::to_string(id)+","+nombre+","+ std::to_string(duracion)+","+genero+","+ std::to_string(calificacion);
}


