#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include "mascota.h"

using namespace std;

class Item {
public:
    Item(int i, string n, int c);
    virtual string getName()=0;
    virtual void mostrarItem()=0;
    virtual void usar(Mascota &mascota)=0;
    virtual int getID()=0;
protected:
    int id;
    string nombre;
    int cantidad;
};

class Comida: public Item{
public:
    Comida(int i, string n, int c);
    virtual string getName() override;
    virtual int getID() override;
    virtual void mostrarItem() override;
    virtual void usar(Mascota &mascota);
};
class Medicina: public Item{
public:
    Medicina(int i, string n, int c);
    virtual string getName();
    virtual int getID() override;
    virtual void mostrarItem();
    virtual void usar(Mascota &mascota);
};

class Juguete: public Item{
public:
    Juguete(int i, string n, int c);
    virtual string getName();
    virtual int getID() override;
    virtual void mostrarItem();
    virtual void usar(Mascota &mascota);
};

#endif // ITEM_H
