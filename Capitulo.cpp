//
// Created by fredi on 2023-06-14.
//

#include "Capitulo.h"

#include <utility>



std::string Capitulo::toString() {
    return Video::toString() + "," + nombreSerie + "," + std::to_string(numero);
}

std::ostream &operator<<(std::ostream &os, Capitulo capitulo) {
    os << capitulo.toString();
    return os;
}

Capitulo::Capitulo(int id, char tipo, const std::string &nombre, int duracion, const std::string &genero,
                   int calificacion, std::string serie, int numero) : Video(id, tipo, nombre, duracion, genero,
                                                                                   calificacion), nombreSerie(std::move(serie)),
                                                                      numero(numero) {}


