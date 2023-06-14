//
// Created by fredi on 2023-06-14.
//

#ifndef RETOOOP_SERIE_H
#define RETOOOP_SERIE_H
#include "Capitulo.h"
#include "vector"
#include "string"

class Serie{
public:
    explicit Serie(const std::string &nombre);

    Serie(const std::string &nombre, const std::vector<Capitulo *> &capitulos);

private:
    std::string nombre;
    std::vector<Capitulo*> Capitulos;


};


#endif //RETOOOP_SERIE_H
