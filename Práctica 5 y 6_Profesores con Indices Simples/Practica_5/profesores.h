#ifndef PROFESORES_H
#define PROFESORES_H
#include <iostream>

using namespace std;

class Profesores
{
private:

    string rfc;
    string name;
    string phone;
    string email;
    string area;
    string status;

public:
    Profesores();
    Profesores(const Profesores &p);
    ~Profesores();

    string getRfc() const;
    void setRfc(const string &value);
    string getName() const;
    void setName(const string &value);
    string getPhone() const;
    void setPhone(const string &value);
    string getEmail() const;
    void setEmail(const string &value);
    string getArea() const;
    void setArea(const string &value);
    string getStatus() const;
    void setStatus(const string &value);

    /////Sobrecarga de Operadores

    std::string toString();

    Profesores &operator = (const Profesores &p);

    bool operator == (const Profesores &p);
    bool operator != (const Profesores &p);
    bool operator <= (const Profesores &p);
    bool operator >= (const Profesores &p);
    bool operator < (const Profesores &p);
    bool operator > (const Profesores &p);


};

#endif // PROFESORES_H
