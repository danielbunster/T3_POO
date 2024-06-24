#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "item.h"

using namespace std;

class Inventario {
public:
    Inventario();
    ~Inventario();

    void cargarItemsDesdeArchivo(const string& filename);
    void mostrarInventario();
    Item* seleccionarItem();

private:
    vector<Item*> items;
};

#endif // INVENTARIO_H