#include "listaenlazadaordena.h"
using namespace std;

ListaEnlazadaOrdena::ListaEnlazadaOrdena()
{
    head = NULL;
}

ListaEnlazadaOrdena::~ListaEnlazadaOrdena()
{
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

void ListaEnlazadaOrdena::insert(int dato)
{
    Node* newNode = new Node;
    newNode->data = dato;
    newNode->next = NULL;
    if (head == NULL || dato < head->data) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != NULL && current->next->data < dato) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void ListaEnlazadaOrdena::remove(int dato)
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

void ListaEnlazadaOrdena::print()
{
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
