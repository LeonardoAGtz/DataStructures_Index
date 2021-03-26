#include "indice.h"

string Indice::getRfc() const
{
    return rfc;
}

void Indice::setRfc(const string &value)
{
    rfc = value;
}

string Indice::getStatus() const
{
    return status;
}

void Indice::setStatus(const string &value)
{
    status = value;
}

long Indice::getDireccion() const
{
    return direccion;
}

void Indice::setDireccion(long value)
{
    direccion = value;
}

string Indice::toString()
{
    char myVaule[20];
    sprintf(myVaule, "%d", direccion);
    string temp(myVaule);

    return rfc + " | " + status + " | " + temp + "\n";

}

bool Indice::operator ==(const Indice &i)
{
    return rfc == i.rfc;
}

bool Indice::operator !=(const Indice &i)
{
    return rfc != i.rfc;
}

bool Indice::operator <=(const Indice &i)
{
    return rfc <= i.rfc;
}

bool Indice::operator >=(const Indice &i)
{
    return rfc >= i.rfc;
}

bool Indice::operator <(const Indice &i)
{
    return rfc < i.rfc;
}

bool Indice::operator >(const Indice &i)
{
    return rfc > i.rfc;
}

Indice::Indice() {}
