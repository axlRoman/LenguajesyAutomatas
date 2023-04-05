#include <iostream>
#include "listaenlazadaordena.h"

using namespace std;

// Función para mostrar el menú y obtener la selección del usuario
int menu() {
    int opcion;
    cout << "Seleccione una opcion:\n";
    cout << "1. Insertar un elemento\n";
    cout << "2. Eliminar un elemento\n";
    cout << "3. Mostrar la lista\n";
    cout << "4. Salir\n";
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

int main()
{
    ListaEnlazadaOrdena list;
    int opcion, dato;
    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                cout << "Ingrese un elemento: ";
                cin >> dato;
                list.insert(dato);
                break;
            case 2:
                cout << "Ingrese un elemento a eliminar: ";
                cin >> dato;
                list.remove(dato);
                break;
            case 3:
                cout << "Lista: ";
                list.print();
                break;
            case 4:
                cout << "Adios!\n";
                break;
            default:
                cout << "Opcion inválida\n";
        }
    } while (opcion != 4);
    /*
        int dato;
        // Insertar algunos elementos en orden
        list.insert(5);
        list.insert(2);
        list.insert(7);
        list.insert(1);
        list.insert(8);
        // Imprimir la lista
        cout << "Lista: ";
        list.print();
        // Eliminar algunos elementos
        list.remove(2);
        list.remove(7);
        // Imprimir la lista actualizada
        cout << "Lista actualizada: ";
        list.print();*/
        return 0;
}
