#ifndef PILAG_H
#define PILAG_H
//CLASE PANTILLA, SIRVEN PARA UTILIZAR
//DIFERENTES TIPOS DE DATOS INCLUYENDO CLASES PROPIAS
template<class T>
class Pila
{
    T* vec;
    int tam;
    int tope;
    bool vacia;
    bool llena;
public:
    Pila(int n=5);//ARGUMENTO CON VALOR POR DEFECTO
    void push(T valor);
    T pop();
    bool esta_vacia();
    bool esta_llena();
    T Tope();//DEVUELVE EL VALOR QUE ESTA EN EL TOPE DE LA PILA
};

#endif // PILAG_H
