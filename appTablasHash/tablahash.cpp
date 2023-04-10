#include "tablahash.h"

TablaHash::TablaHash(int capacity)
{
    this->capacity = capacity;
    tabla.resize(capacity);
    for (int i = 0; i < capacity; i++) {
        tabla[i] = NULL;
    }
}

TablaHash::~TablaHash()
{
    for (int i = 0; i < capacity; i++) {
        if (tabla[i] != NULL) {
            delete tabla[i];
        }
    }
}

int TablaHash::hash(int key)
{
    return key % capacity;
}

void TablaHash::insertar(int key, int value)
{
    int index = hash(key);
    while (tabla[index] != NULL && tabla[index]->key != key) {
        index = hash(index + 1);
    }
    if (tabla[index] != NULL) {
        delete tabla[index];
    }
    tabla[index] = new HashNode(key, value);
}

int TablaHash::get(int key)
{
    int index = hash(key);
            while (tabla[index] != NULL && tabla[index]->key != key) {
                index = hash(index + 1);
            }
            if (tabla[index] == NULL) {
                return -1;
            }
            return tabla[index]->value;
}

void TablaHash::eliminar(int key)
{
    int index = hash(key);
    while (tabla[index] != NULL) {
        if (tabla[index]->key == key) {
            break;
        }
        index = hash(index + 1);
    }
    if (tabla[index] == NULL) {
        return;
    }
    delete tabla[index];
    tabla[index] = NULL;
    // Reorganizar la tabla hash después de la eliminación
    index = hash(index + 1);
    while (tabla[index] != NULL) {
        int new_index = hash(tabla[index]->key);
        if (new_index != index) {
            swap(tabla[index], tabla[new_index]);
            index = new_index;
        }
        index = hash(index + 1);
    }
}
