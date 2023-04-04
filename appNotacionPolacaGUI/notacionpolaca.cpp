#include "notacionpolaca.h"
#include <cmath>
#include <string.h>



/*
notacionpolaca::notacionpolaca()
{

}
*/
//IMPLEMENTAR EL METODO QUE RESUELVE LA EXPRESION POSTFIJA
//USAR LOS EJEMPLOS DE INICIO DEL TEMA


//IMPLEMENTAR UN METODO QUE ANALICE LA CADENA DE LA EXP INFIJA
//Y REGRESE SOLO LA CANTIDAD DE LOS CARACTERES NECESARIOS
//PARA ESTABLECER EL TAMAÑO DE DICHA EXPRESION
int tamañoEpos(string exp){
    string expTam = exp;
    int tamaño = expTam.length();
    int cont = 0;
    for(int i=0; i<expTam.length(); i++){
        if(expTam[i] == 40 || expTam[i] == 41)
            cont++;
    }
    tamaño -=cont;

    return tamaño;
}

int cantParentesis(string einfija){
    int cant_Parentesis =0;
    for(int i=0; i<einfija.length(); i++)
        if(einfija.at(i) == '(' || einfija[i] == ')')
            cant_Parentesis++;
    return cant_Parentesis;
}

int tamPila(string exp){
    int cantOperadores = 0;
    for(int i=0; i<exp.length(); i++)
        //if(exp.at(i) == '^' || exp.at(i) == '*' || exp.at(i) == '/' || exp.at(i) == '+' || exp.at(i) == '-' || exp.at(i) == '(')
        if(strchr("(^*/+-",exp.at(i)))
            cantOperadores++;
    return cantOperadores;


}

//Cambiar a regresar en
//String

//QString
string notacionpolaca::ConvertiraNotacionPostfijaString(string Expinfija)
{
    string Eposfija;
    Pila<int> *stack = new Pila<int>(tamPila(Expinfija));

    int i,pos; //Indice i recorre Expinfija, indice pos sirve par ir almacenando en Eposfija
     pos = 0;
    for(i = 0; i<Expinfija.size(); i++){
        char car = Expinfija[i];
        Simbolo actual = tipoYPrecedenacia(car);

        switch (actual) {
        case OPERANDO:
            Eposfija += car;
            break;
        case SUMRES:
        {
            while(!stack->esta_vacia() && tipoYPrecedenacia((char) stack->Tope()) >= actual)
                Eposfija+= (char) stack->pop();
            stack->push(car);
        }
            break;
        case MULTDIV:
        {
            while(!stack->esta_vacia() && tipoYPrecedenacia((char) stack->Tope()) >= actual)
                Eposfija+= (char) stack->pop();
            stack->push(car);
        }
            break;
        case POW:
        {
            while(!stack->esta_vacia() && tipoYPrecedenacia((char) stack->Tope()) >= actual)
                Eposfija+= (char) stack->pop();
            stack->push(car);
        }
            break;
        case PIZQ:
        {
            stack->push(car);
        }
            break;
        case PDER:
        {
            char c = (char) stack->pop();
            while(tipoYPrecedenacia(c) != PIZQ)
            {
                Eposfija+= c;
                c = (char) stack->pop();
            }
        }
            break;
        }
    }

    while(!stack->esta_vacia())
        if(pos < Expinfija.length())
            Eposfija+= (char) stack->pop();
        else
            break;

    Eposfija+='\0';
    return Eposfija;
}
/*
QString notacionpolaca::ConvertiraNotacionPostfijaQString(string Expinfija)
{

    Pila<int> *stack = new Pila<int>(tamPila(Expinfija));

    int i,pos; //Indice i recorre Expinfija, indice pos sirve par ir almacenando en Eposfija
     pos = 0;
    for(i = 0; i<Expinfija.size(); i++){
        char car = Expinfija[i];
        Simbolo actual = tipoYPrecedenacia(car);

        switch (actual) {
        case OPERANDO:
            Eposfija += car;
            break;
        case SUMRES:
        {
            while(!stack->esta_vacia() && tipoYPrecedenacia((char) stack->Tope()) >= actual)
                Eposfija+= (char) stack->pop();
            stack->push(car);
        }
            break;
        case MULTDIV:
        {
            while(!stack->esta_vacia() && tipoYPrecedenacia((char) stack->Tope()) >= actual)
                Eposfija+= (char) stack->pop();
            stack->push(car);
        }
            break;
        case POW:
        {
            while(!stack->esta_vacia() && tipoYPrecedenacia((char) stack->Tope()) >= actual)
                Eposfija+= (char) stack->pop();
            stack->push(car);
        }
            break;
        case PIZQ:
        {
            stack->push(car);
        }
            break;
        case PDER:
        {
            char c = (char) stack->pop();
            while(tipoYPrecedenacia(c) != PIZQ)
            {
                Eposfija+= c;
                c = (char) stack->pop();
            }
        }
            break;
        }
    }

    while(!stack->esta_vacia())
        if(pos < Expinfija.length())
            Eposfija+= (char) stack->pop();
        else
            break;

    Eposfija+='\0';
    return Eposfija;
}
*/
char *notacionpolaca::ConvertiraNotacionPostfija(string Expinfija)
{
    //char *Eposfija = new char[Expinfija.length()];
    //USAR EL TAMAÑO NECESARIO SIN PARENTESIS
    char *Eposfija = new char[Expinfija.length() -cantParentesis(Expinfija)];

    Pila<int> *stack = new Pila<int>(tamPila(Expinfija));

    int i,pos; //Indice i recorre Expinfija, indice pos sirve par ir almacenando en Eposfija
     pos = 0;
    for(i = 0; i<Expinfija.size(); i++){
        char car = Expinfija[i];
        Simbolo actual = tipoYPrecedenacia(car);

        switch (actual) {
        case OPERANDO:
            Eposfija[pos++] = car;
            break;
        case SUMRES:
        {
            while(!stack->esta_vacia() && tipoYPrecedenacia((char) stack->Tope()) >= actual)
                Eposfija[pos++] = (char) stack->pop();
            stack->push(car);
        }
            break;
        case MULTDIV:
        {
            while(!stack->esta_vacia() && tipoYPrecedenacia((char) stack->Tope()) >= actual)
                Eposfija[pos++] = (char) stack->pop();
            stack->push(car);
        }
            break;
        case POW:
        {
            while(!stack->esta_vacia() && tipoYPrecedenacia((char) stack->Tope()) >= actual)
                Eposfija[pos++] = (char) stack->pop();
            stack->push(car);
        }
            break;
        case PIZQ:
        {
            stack->push(car);
        }
            break;
        case PDER:
        {
            char c = (char) stack->pop();
            while(tipoYPrecedenacia(c) != PIZQ)
            {
                Eposfija[pos++] = c;
                c = (char) stack->pop();
            }
        }
            break;
        }
    }

    while(!stack->esta_vacia())
        if(pos < Expinfija.length())
            Eposfija[pos++] = (char) stack->pop();
        else
            break;

    Eposfija[pos]='\0';
    return Eposfija;
}

Simbolo notacionpolaca::tipoYPrecedenacia(char c)
{
    Simbolo simbolo;
    switch (c) {
        case '+':
            case'-':
                simbolo = SUMRES;
        break;

        case '*':
            case'/':
                simbolo = MULTDIV;
        break;

        case '^':
            simbolo = POW;
        break;

        case '(':
            simbolo = PIZQ;
        break;

        case ')':
            simbolo = PDER;
        break;
        default:
            simbolo = OPERANDO;
        break;
    }
    return simbolo;
}

double notacionpolaca::solucionarExpresionPostfija(string expPos)
{
    Pila<double> *stack = new Pila<double>(expPos.size());

    for(char elemento : expPos){
        if(isdigit(elemento))
            stack->push(elemento - '0');
        else
        {
            double operando2 = stack->pop();
            double operando1 = stack->pop();

            double resultado;

            switch (elemento) {
            case '+':
                resultado = operando1 + operando2;
                break;
            case '-':
                resultado = operando1 - operando2;
                break;
            case '*':
                resultado = operando1 * operando2;
                break;
            case '/':
                resultado = operando1 / operando2;
                break;
            case '^':
                resultado = pow(operando1, operando2);
                break;
            }
            stack->push(resultado);
        }
    }
    return stack->pop();
}
















