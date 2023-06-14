//
// Created by fredi on 2023-06-14.
//

#include "Capitulo.h"

Capitulo::Capitulo(int id, char tipo, int numero ,const std::string &nombre, int duracion, const std::string &genero,
                   int calificacion) : Video(id, tipo, nombre, duracion, genero, calificacion),
                                                   numero(numero) {}

std::string Capitulo::toString() {
    return Video::toString() + "," + std::to_string(numero);
}

std::ostream &operator<<(std::ostream &os, Capitulo capitulo) {
    os << capitulo.toString();
    return os;
}


