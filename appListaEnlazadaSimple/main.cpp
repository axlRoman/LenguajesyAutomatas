#include <iostream>
#include "listaenlazadasimple.h"

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
    ListaEnlazadaSimple list;
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
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.print(); // debería imprimir: 1 2 3 4
    list.remove(2);
    list.print(); // debería imprimir: 1 3 4
*/
    return 0;
}


