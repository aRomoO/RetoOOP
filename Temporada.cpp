//
// Created by fredi on 2023-06-14.
//

#include "Temporada.h"


//CONSTRUCTOR
Temporada::Temporada(int numero) : numero(numero) {}
Temporada::Temporada(int numero, std::vector<Capitulo *> capitulos) : numero(numero), capitulos(std::move(capitulos)) {}

//SETTERS & GETTERS
int Temporada::getNumero() const {
    return numero;
}
void Temporada::setNumero(int numero) {
    Temporada::numero = numero;
}

void Temporada::addCapitulo(Capitulo * capitulo) {
    capitulos.push_back(capitulo);

}


//METHODS
