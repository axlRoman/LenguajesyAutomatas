#include "listaenlazadasimple.h"
using namespace std;

ListaEnlazadaSimple::ListaEnlazadaSimple()
{
    head = NULL;
}

ListaEnlazadaSimple::~ListaEnlazadaSimple()
{
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}
// Insertar un nodo al final de la lista
void ListaEnlazadaSimple::insert(int dato)
{
    Node* newNode = new Node;
    newNode->data = dato;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Eliminar un nodo de la lista
void ListaEnlazadaSimple::remove(int dato)
{
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL && current->data != dato) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (previous == NULL) {
        head = current->next;
    }
    else {
        previous->next = current->next;
    }
    delete current;
}
// Imprimir los elementos de la lista
void ListaEnlazadaSimple::print()
{
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
