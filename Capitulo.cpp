//
// Created by fredi on 2023-06-14.
//

#include "Capitulo.h"

#include <utility>



std::string Capitulo::toString() {
    return Video::toString() + "[Serie]: "+nombreSerie + "\n"+
                               "[#]: " + std::to_string(numero) + "\n" +
                               "---------------\n";
}



Capitulo::Capitulo(std::string id, const std::string &nombre, int duracion, const std::string &genero,
                   int calificacion, std::string serie, int numero) : Video(std::move(id), nombre, duracion, genero,
                                                                                   calificacion), nombreSerie(std::move(serie)),
                                                                                   numero(numero) {}



std::ostream &operator<<(std::ostream &os, Capitulo capitulo) {
    os << capitulo.toString();
    return os;
}
