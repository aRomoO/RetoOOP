//
// Created by fredi on 2023-06-14.
//

#include "Pelicula.h"
//CONSTRUCTOR
Pelicula::Pelicula(int id, char tipo, const std::string &nombre, int duracion, const std::string &genero,
                   int calificacion) : Video(id, tipo, nombre, duracion, genero, calificacion) {}

std::string Pelicula::toString() {
    return Video::toString();
}

std::ostream &operator<<(std::ostream &os, Pelicula pelicula) {
    os << pelicula.toString()<<std::endl;
    return os;
}

//GETTERS & SETTERS



//METHODS


