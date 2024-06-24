#include "inventario.h"

Inventario::Inventario() {}

Inventario::~Inventario() {
    // Liberar la memoria de los ítems almacenados
    for (auto item : items) {
        delete item;
    }
}

void Inventario::cargarItemsDesdeArchivo(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo: " << filename << endl;
        return;
    }

    string line;

    // Leer la primera línea que contiene el nombre de la mascota (se usa en main)
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string token;//aux para pasar de string a int

        int id;
        string tipo;
        string nombre;
        int cantidad;

        getline(ss, token, ';');  // ID
        id = stoi(token);
        getline(ss, tipo, ';');   // Tipo de ítem
        getline(ss, nombre, ';'); // Nombre del ítem
        getline(ss, token, ';');  // Cantidad
        cantidad = stoi(token);

        // Crear un nuevo objeto Item segun su tipo
        if (tipo == "Juguete") {
            items.push_back(new Juguete(id, nombre, cantidad));
        } else if (tipo == "Comida") {
            items.push_back(new Comida(id, nombre, cantidad));
        } else if (tipo == "Medicina") {
            items.push_back(new Medicina(id, nombre, cantidad));
        } else {
            cerr << "Tipo de item desconocido: " << tipo << endl;
        }
    }

    file.close();
}

void Inventario::mostrarInventario() {
    cout << "Inventario:" << endl;
    for (auto item : items) {
        item->mostrarItem();
    }
}

Item* Inventario::seleccionarItem() {
    int idSeleccionado;
    cout << "Seleccione un item del inventario por su ID: ";
    cin >> idSeleccionado;

    for (auto item : items) {
        if (item->getID() == idSeleccionado) {
            return item;
        }
    }

    cout << "ID de ítem no valido." << endl;
    return nullptr;
}
