#include "teacher.h"

string Teacher::getRfc() const
{
    return rfc;
}

void Teacher::setRfc(const string &value)
{
    rfc = value;
}

string Teacher::getName() const
{
    return name;
}

void Teacher::setName(const string &value)
{
    name = value;
}

string Teacher::getPhone() const
{
    return phone;
}

void Teacher::setPhone(const string &value)
{
    phone = value;
}

string Teacher::getEmail() const
{
    return email;
}

void Teacher::setEmail(const string &value)
{
    email = value;
}

string Teacher::getDepartment() const
{
    return department;
}

void Teacher::setDepartment(const string &value)
{
    department = value;
}

string Teacher::toString()
{
    return rfc + "|" + name + "|" + email + "|" + phone + "|" + department + "\n";
}

Teacher &Teacher::operator =(const Teacher &t)
{
    rfc = t.rfc;
    name = t.name;
    email = t.email;
    phone = t.phone;
    department = t.department;

    return *this;
}

bool Teacher::operator ==(const Teacher &t)
{
    return rfc == t.rfc;
}

bool Teacher::operator !=(const Teacher &t)
{
    return rfc != t.rfc;
}

bool Teacher::operator <=(const Teacher &t)
{
    return rfc <= t.rfc;
}

bool Teacher::operator >=(const Teacher &t)
{
    return rfc >= t.rfc;
}

bool Teacher::operator <(const Teacher &t)
{
    return rfc < t.rfc;
}

bool Teacher::operator >(const Teacher &t)
{
    return rfc > t.rfc;
}

Teacher::Teacher() { }

Teacher::Teacher(const Teacher &t) : rfc(t.rfc), name(t.name), phone(t.phone), email(t.email), department(t.department) { }

Teacher::~Teacher() { }
