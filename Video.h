//
// Created by fredi on 13/06/2023.
//

#ifndef RETOOOP_VIDEO_H
#define RETOOOP_VIDEO_H

#include "string"

class Video {
protected:
    int id;
    char tipo;
    std::string nombre;
    int duracion;
    std::string genero;
    int calificacion;


public:
    //CONSTRUCTOR
    Video(int id, char tipo, std::string nombre, int duracion, std::string genero, int calificacion);

    //GETTERS & SETTERS
    int getId() const;
    void setId(int id);
    char getTipo() const;
    void setTipo(char tipo);
    const std::string &getNombre() const;
    void setNombre(const std::string &nombre);
    int getDuracion() const;
    void setDuracion(int duracion);
    const std::string &getGenero() const;
    void setGenero(const std::string &genero);
    int getCalificacion() const;
    void setCalificacion(int calificacion);

    //VIRTUAL METHODS
    virtual std::string toString() = 0;

};


#endif //RETOOOP_VIDEO_H
