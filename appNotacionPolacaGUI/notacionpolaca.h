#ifndef NOTACIONPOLACA_H
#define NOTACIONPOLACA_H
#include <string>
#include "pilag.h"
#include "pilag.cpp"
//cuando se usan templates se agregan ambos archivos para evitar problemas con el compilador
//incluimos el .h (clase/encabesado y prototipos) y el .cpp(implementacion)

using namespace std;

enum Simbolo{OPERANDO, PIZQ, PDER, SUMRES, MULTDIV, POW};

class notacionpolaca
{
public:
    //notacionpolaca();
    //string, qstring
    string ConvertiraNotacionPostfijaString(string Expinfija);
    //QString ConvertiraNotacionPostfijaQString(string Expinfija);
    char * ConvertiraNotacionPostfija(string Expinfija);
    Simbolo tipoYPrecedenacia(char c);
    double solucionarExpresionPostfija (string expPos);
    bool expresionNumerica (string expresion);
};

#endif // NOTACIONPOLACA_H
