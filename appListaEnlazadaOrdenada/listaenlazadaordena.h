#ifndef LISTAENLAZADAORDENA_H
#define LISTAENLAZADAORDENA_H
#include <iostream>

// Clase para los nodos de la lista enlazada
class Node {
public:
    int data;
    Node* next;
};

//Clase para la Lista Enlazada
class ListaEnlazadaOrdena
{
private:
    Node* head;
public:
    ListaEnlazadaOrdena();
    ~ListaEnlazadaOrdena();
    void insert(int );
    void remove(int );
    void print();
};

#endif // LISTAENLAZADAORDENA_H
