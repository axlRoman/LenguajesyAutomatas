#include <iostream>
#include "tablahash.h"

using namespace std;

int main()
{
    TablaHash tablaHash(10);
        // Insertar algunos elementos en la tabla hash
        tablaHash.insertar(2, 20);
        tablaHash.insertar(3, 30);
        tablaHash.insertar(12, 120);
        tablaHash.insertar(7, 70);
        // Obtener el valor de un elemento de la tabla hash
        cout << "Valor de la clave 12: " << tablaHash.get(12) << endl;
        // Eliminar un elemento de la tabla hash
        tablaHash.eliminar(3);
        // Obtener el valor de un elemento de la tabla hash después de la eliminación
        cout << "Valor de la clave 3: " << tablaHash.get(3) << endl;
        return 0;
}
