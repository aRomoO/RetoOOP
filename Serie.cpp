//
// Created by fredi on 2023-06-14.
//

#include "Serie.h"

Serie::Serie(const std::string &nombre) : nombre(nombre) {}

Serie::Serie(const std::string &nombre, const std::vector<Capitulo *> &capitulos) : nombre(nombre),
                                                                                    Capitulos(capitulos) {}
