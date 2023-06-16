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
    void setId(std::string id);

    const std::string &getNombre() const;
    void setNombre(const std::string &nombre);
    int getDuracion() const;
    void setDuracion(int duracion);
    const std::string &getGenero() const;
    void setGenero(const std::string &genero);


    //METHODS
    std::string PromedioCalificiones();
    bool addCalificacion(int cal);

    //VIRTUAL METHODS
    virtual std::string toString() = 0;

};


#endif //RETOOOP_VIDEO_H
