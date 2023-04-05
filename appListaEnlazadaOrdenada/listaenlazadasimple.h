#ifndef LISTAENLAZADASIMPLE_H
#define LISTAENLAZADASIMPLE_H
#include <iostream>


// Clase para los nodos de la lista enlazada
class Node {
public:
    int data;
    Node* next;
};


//Clase para la Lista Enlazada
class ListaEnlazadaSimple
{
private:
    Node* head;
public:
    ListaEnlazadaSimple();
    ~ListaEnlazadaSimple();
    void insert(int );
    void remove(int );
    void print();
};

#endif // LISTAENLAZADASIMPLE_H
