//
// Created by fredi on 2023-06-14.
//

#ifndef RETOOOP_CAPITULO_H
#define RETOOOP_CAPITULO_H
#include "Video.h"

class Capitulo : Video{
private:
    int numero;
public:
    Capitulo(int id, char tipo, int numero,const std::string &nombre, int duracion, const std::string &genero, int calificacion);

    std::string toString() override;
};


#endif //RETOOOP_CAPITULO_H
