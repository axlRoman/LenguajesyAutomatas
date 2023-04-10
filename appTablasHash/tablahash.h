#ifndef TABLAHASH_H
#define TABLAHASH_H
#include <vector>
#include <iostream>
using namespace std;

// Clase para los elementos de la tabla hash
class HashNode {
public:
    int key;
    int value;
    HashNode(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class TablaHash
{
private:
    vector<HashNode*> tabla;
    int capacity;
public:
    TablaHash(int capacity);
    ~TablaHash();
    int hash(int key);
    void insertar(int key, int value);
    int get(int key);
    void eliminar(int key);
};

#endif // TABLAHASH_H
