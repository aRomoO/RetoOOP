//
// Created by fredi on 2023-06-14.
//

#ifndef RETOOOP_CAPITULO_H
#define RETOOOP_CAPITULO_H

#include <ostream>
#include "Video.h"

class Capitulo : public Video{
private:
    std::string nombreSerie;
    int numero;
public:
    Capitulo(const std::string &id, const std::string &nombre, int duracion, const std::string &genero,
             std::string nombreSerie, int numero);

    std::string toString() override;

    friend std::ostream &operator<<(std::ostream &os, Capitulo capitulo);
};


#endif //RETOOOP_CAPITULO_H
