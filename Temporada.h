//
// Created by fredi on 2023-06-14.
//

#ifndef RETOOOP_TEMPORADA_H
#define RETOOOP_TEMPORADA_H
#include "Capitulo.h"
#include "vector"


class Temporada {
private:
    int numero;
    std::vector <Capitulo*> capitulos;

public:

    //CONSTRUCTOR
    explicit Temporada(int numero);
             Temporada(int numero, std::vector<Capitulo *> capitulos);

    //SETTERS & GETTERS
    int getNumero() const;
    void setNumero(int numero);

    //METHODS
    void addCapitulo(Capitulo*capitulo);

};


#endif //RETOOOP_TEMPORADA_H
