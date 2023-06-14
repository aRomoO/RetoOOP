//
// Created by fredi on 2023-06-14.
//

#ifndef RETOOOP_SERIE_H
#define RETOOOP_SERIE_H
#include "Temporada.h"
#include "vector"
#include "string"

class Serie{
public:
    explicit Serie(const std::string &nombre);
             Serie(const std::string &nombre, const std::vector<Temporada *> &temporadas);

private:
    std::string nombre;
    std::vector<Temporada*> temporadas;


};


#endif //RETOOOP_SERIE_H
