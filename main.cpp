#include <iostream>
#include "mascota.h"
#include "item.h"
#include "inventario.h"

using namespace std;

//Compilar con:
//>g++ main.cpp mascota.cpp inventario.cpp item.cpp -o main.exe
//>./main.exe

//Etapa 2
int main() {
    // Leer nombre de la mascota del archivo config.csv
    ifstream file("config.csv");
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo config.csv" << endl;
        return 1;
    }
    string nombreMascota;
    getline(file, nombreMascota);
    file.close();

    // Crear la mascota y mostrar estado inicial
    Mascota miMascota(nombreMascota);
    miMascota.mostrarEstado();
    cout << endl;

    // Crear inventario y cargar ítems desde config.csv
    Inventario inventario;
    inventario.cargarItemsDesdeArchivo("config.csv");

    // Mostrar estado inicial del inventario
    inventario.mostrarInventario();
    cout << endl;

    // Tiempo de simulación inicial
    double tiempoSimulacion = 0.0;
    const double tiempoMaximo = 15.0;
    const double pasoTiempo = 0.5;


    while (tiempoSimulacion <= tiempoMaximo) {
        // Mostrar tiempo de simulación
        cout << "Tiempo de simulacion: " << tiempoSimulacion << endl;

        // Mostrar estado de la mascota
        miMascota.mostrarEstado();
        cout << endl;

        // Mostrar estado del inventario como menú
        inventario.mostrarInventario();
        cout << endl;

        // Permitir al usuario seleccionar un ítem del inventario
        Item* itemSeleccionado = inventario.seleccionarItem();
        if (itemSeleccionado != nullptr) {
            // Usar el ítem seleccionado en la mascota
            itemSeleccionado->usar(miMascota);
        }

        // Avanzar el tiempo de simulación
        tiempoSimulacion += pasoTiempo;
        miMascota.setEdad(tiempoSimulacion);

    }

    cout << "Fin de la simulacion." << endl;

    return 0;
}
