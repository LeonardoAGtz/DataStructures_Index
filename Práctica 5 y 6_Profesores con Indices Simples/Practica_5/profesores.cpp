#include "profesores.h"

string Profesores::getRfc() const
{
    return rfc;
}

void Profesores::setRfc(const string &value)
{
    rfc = value;
}

string Profesores::getName() const
{
    return name;
}

void Profesores::setName(const string &value)
{
    name = value;
}

string Profesores::getPhone() const
{
    return phone;
}

void Profesores::setPhone(const string &value)
{
    phone = value;
}

string Profesores::getEmail() const
{
    return email;
}

void Profesores::setEmail(const string &value)
{
    email = value;
}

string Profesores::getArea() const
{
    return area;
}

void Profesores::setArea(const string &value)
{
    area = value;
}

string Profesores::getStatus() const
{
    return status;
}

void Profesores::setStatus(const string &value)
{
    status = value;
}

string Profesores::toString()
{
    return rfc + " | " + name + " | " + email + " | " + phone + " | " + area + " | " + status + "\n";
}

Profesores &Profesores::operator =(const Profesores &p)
{
    rfc = p.rfc;
    name = p.name;
    email = p.email;
    phone = p.phone;
    area = p.area;
    status = p.status;

    return *this;
}

bool Profesores::operator ==(const Profesores &p)
{
    return rfc == p.rfc;
}

bool Profesores::operator !=(const Profesores &p)
{
    return rfc != p.rfc;
}

bool Profesores::operator <=(const Profesores &p)
{
    return rfc <= p.rfc;
}

bool Profesores::operator >=(const Profesores &p)
{
    return rfc >= p.rfc;
}

bool Profesores::operator <(const Profesores &p)
{
    return rfc < p.rfc;
}

bool Profesores::operator >(const Profesores &p)
{
    return rfc > p.rfc;
}

Profesores::Profesores() {}

Profesores::Profesores(const Profesores &p) : rfc(p.rfc), name(p.rfc), phone(p.phone), email(p.email), area(p.area), status(p.status) {}

Profesores::~Profesores() {}
