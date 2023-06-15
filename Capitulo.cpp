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







std::ostream &operator<<(std::ostream &os, Capitulo capitulo) {
    os << capitulo.toString();
    return os;
}

Capitulo::Capitulo(const std::string &id, const std::string &nombre, int duracion, const std::string &genero,
                   std::string nombreSerie, int numero) : Video(id, nombre, duracion, genero),
                                                                 nombreSerie(std::move(nombreSerie)), numero(numero) {}
