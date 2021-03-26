#include "index.h"

string Index::getRfc() const
{
    return rfc;
}

void Index::setRfc(const string &value)
{
    rfc = value;
}

int Index::getAddress() const
{
    return address;
}

void Index::setAddress(int value)
{
    address = value;
}

string Index::toString()
{
    char myValue[20];
    sprintf(myValue, "%d", address);
    string value(myValue);

    return rfc + "|" + value + "\n";
}

bool Index::operator ==(const Index &i)
{
    return rfc == i.rfc;
}

bool Index::operator !=(const Index &i)
{
    return rfc != i.rfc;
}

bool Index::operator <=(const Index &i)
{
    return rfc <= i.rfc;
}

bool Index::operator >=(const Index &i)
{
    return rfc >= i.rfc;
}

bool Index::operator <(const Index &i)
{
    return rfc < i.rfc;
}

bool Index::operator >(const Index &i)
{
    return rfc > i.rfc;
}

Index::Index() { }
