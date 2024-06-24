#include "mascota.h"
#include <iostream>

Mascota::Mascota(string n) {
    nombre = n;
    edad = 0;
    salud = 50;
    energia = 50;
    felicidad = 50;
    actualizarEstado();
}

Mascota::Mascota(string n, double ed, int s, int en, int f){
    nombre = n;
    edad = ed;
    salud = s;
    energia = en;
    felicidad = f;
    actualizarEstado();
}

void Mascota::actualizarEstado(){
    if (felicidad>=60){estado = Estado::Feliz;}
    else if (felicidad<=20){estado=Estado::Triste;}
    else if ((edad <=5 & salud<=20) || (edad>=5 & edad<=10 & salud<=50)){estado=Estado::Hambriento;}
    else if (edad>5 & salud<=30 & energia<=30){estado=Estado::Enojado;}
    else if (energia<=15){estado=Estado::Cansado;}
    else if ((salud<=0 & energia<=0)||(edad>=15)){estado=Estado::Muerto;}
    else {estado=Estado::Neutro;}
}

string Mascota::getNombre(){
    return nombre;
}

int Mascota::getSalud(){
    return salud;
}

int Mascota::getEnergia(){
    return energia;
}

int Mascota::getFelicidad(){
    return felicidad;
}

void Mascota::setEnergia(int a){
    energia = a;
    actualizarEstado();
}

void Mascota::setFelicidad(int a){
    felicidad = a;
    actualizarEstado();
}

void Mascota::setSalud(int a){
    salud = a;
    actualizarEstado();
}

void Mascota::setEdad(double ed){
    edad=ed;
    actualizarEstado();
}


const char* estadoToString(Estado estado) {
    switch (estado) {
    case Neutro: return "Neutro";
    case Feliz: return "Feliz";
    case Triste: return "Triste";
    case Hambriento: return "Hambriento";
    case Enojado: return "Enojado";
    case Cansado: return "Cansado";
    case Muerto: return "Muerto";
    default: return "Neutro";
    }
}


void Mascota::mostrarEstado(){
    cout << " " << endl;
    cout << "----------------" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Salud: " << salud << endl;
    cout << "Energia: " << energia << endl;
    cout << "Felicidad: " << felicidad << endl;
    cout << "Estado: " << estadoToString(estado) << endl;
}



