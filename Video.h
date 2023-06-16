//
// Created by fredi on 13/06/2023.
//

#ifndef RETOOOP_VIDEO_H
#define RETOOOP_VIDEO_H

#include "string"
#include "vector"

class Video {
protected:
    std::string id;
    std::string nombre;
    int duracion;
    std::string genero;
    std::vector <int> calificacion = {};



public:
    //CONSTRUCTOR
    Video(std::string id, std::string nombre, int duracion, std::string genero);

    //GETTERS & SETTERS
    std::string getId() const;


    const std::string &getNombre() const;

    const std::string &getGenero() const;



    bool addCalificacion(int cal);

    //METHODS
    std::string PromedioCalificiones();
    std::string mostrarFiltradoCalificacion();
    std::string mostrarFiltradoGenero();

    //VIRTUAL METHODS

    virtual std::string toString() = 0;



};


#endif //RETOOOP_VIDEO_H
