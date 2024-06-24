#ifndef MASCOTA_H
#define MASCOTA_H
#include <iostream>
#include <string>
using namespace std;

enum Estado { Neutro, Feliz, Triste, Hambriento, Enojado, Cansado, Muerto };

class Mascota
{
public:
    Mascota(string n);
    Mascota(string nombre, double edad, int salud, int energia, int felicidad);
    virtual void mostrarEstado();
    string getNombre();
    int getSalud();
    int getEnergia();
    int getFelicidad();
    void setSalud(int a);
    void setEnergia(int a);
    void setFelicidad(int a);
    void setEdad(double ed);
    void actualizarEstado();
private:
    string nombre;
    int edad;
    int salud;
    int energia;
    int felicidad;
    Estado estado;
};

#endif // MASCOTA_H
