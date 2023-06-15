//
// Created by fredi on 2023-06-14.
//

#include "Pelicula.h"

#include <utility>
//CONSTRUCTOR
Pelicula::Pelicula(std::string id, const std::string &nombre, int duracion, const std::string &genero,
                   int calificacion) : Video(std::move(id), nombre, duracion, genero, calificacion) {}

std::string Pelicula::toString() {
    return Video::toString();
}

std::ostream &operator<<(std::ostream &os, Pelicula pelicula) {
    os << pelicula.toString() << "---------------"<<std::endl;
    return os ;
}

//GETTERS & SETTERS



//METHODS


