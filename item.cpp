#include "item.h"
#include <iostream>
#include <string>

using namespace std;

Item::Item(int i, string n, int c):
    id(i), nombre(n), cantidad(c){}

Comida::Comida(int i, string n, int c):
    Item(i,n,c){}

string Comida::getName(){
    return nombre;
}
int Comida::getID(){
    return id;
}

void Comida::mostrarItem(){
    cout << " " << endl;
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Cantidad: " << cantidad << endl;
}

void Comida::usar(Mascota &mascota){
    cout << " " << endl;
    cout << "Usando comida: " << nombre << " en la mascota" << endl;
    mascota.setEnergia(mascota.getEnergia()+20);
    if(mascota.getEnergia()>=100){mascota.setEnergia(100);}
    mascota.setSalud(mascota.getSalud()+20);
    if(mascota.getSalud()>=100){mascota.setSalud(100);}
    this->cantidad-=1;
    mascota.mostrarEstado();
}

Medicina::Medicina(int i, string n, int c):
    Item(i, n, c) {}

string Medicina::getName(){
    return nombre;
}
int Medicina::getID(){
    return id;
}
void Medicina::mostrarItem(){
    cout << " " << endl;
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Cantidad: " << cantidad << endl;
}
void Medicina::usar(Mascota &mascota){
    cout << " " << endl;
    cout << "Usando medicina: " << nombre << " en la mascota" << endl;
    mascota.setSalud(mascota.getSalud()+40);
    if(mascota.getSalud()>=100){mascota.setSalud(100);}
    this->cantidad-=1;
}


Juguete::Juguete(int i, string n, int c):
    Item(i, n, c) {}

string Juguete::getName(){
    return nombre;
}
int Juguete::getID(){
    return id;
}
void Juguete::mostrarItem(){
    cout << " " << endl;
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Cantidad: " << cantidad << endl;
}

void Juguete::usar(Mascota &mascota){
    cout << " " << endl;
    cout << "Usando juguete: " << nombre << " en la mascota" << endl;
    mascota.setFelicidad(mascota.getFelicidad()+30);
    if(mascota.getFelicidad()>=100){mascota.setFelicidad(100);}
    this->cantidad-=1;
    
}

