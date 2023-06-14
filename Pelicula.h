//
// Created by fredi on 2023-06-14.
//

#ifndef RETOOOP_PELICULA_H
#define RETOOOP_PELICULA_H
#include "Video.h"

class Pelicula : public Video{
public:
    //CONSTRUCTOR
    Pelicula(int id, char tipo, const std::string &nombre, int duracion, const std::string &genero, int calificacion);

    //METHODS
    std::string toString() override;
};


#endif //RETOOOP_PELICULA_H
