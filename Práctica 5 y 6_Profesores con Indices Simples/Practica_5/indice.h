#ifndef INDICE_H
#define INDICE_H
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Indice
{
private:

    string rfc;
    string status;
    long int direccion;

public:
    Indice();

    string getRfc() const;
    void setRfc(const string &value);
    string getStatus() const;
    void setStatus(const string &value);
    long getDireccion() const;
    void setDireccion(long value);

    ////Sobrecarga de Operadores

    std::string toString();

    bool operator == (const Indice &i);
    bool operator != (const Indice &i);
    bool operator <= (const Indice &i);
    bool operator >= (const Indice &i);
    bool operator < (const Indice &i);
    bool operator > (const Indice &i);
};

#endif // INDICE_H
