//
// Created by fredi on 2023-06-14.
//

#ifndef RETOOOP_PELICULA_H
#define RETOOOP_PELICULA_H

#include <ostream>
#include "Video.h"

class Pelicula : public Video{
public:
    //CONSTRUCTOR
    Pelicula(int id, char tipo, const std::string &nombre, int duracion, const std::string &genero, int calificacion);


    //METHODS
    std::string toString() override;


    friend std::ostream &operator<<(std::ostream &os, Pelicula pelicula);
};


#endif //RETOOOP_PELICULA_H
