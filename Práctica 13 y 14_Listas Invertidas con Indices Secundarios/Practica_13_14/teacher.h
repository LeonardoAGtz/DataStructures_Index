#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>

using namespace std;

class Teacher
{
private:

    string rfc;
    string name;
    string phone;
    string email;
    string department;

public:
    Teacher();
    Teacher(const Teacher &t);
    ~Teacher();


    string getRfc() const;
    void setRfc(const string &value);
    string getName() const;
    void setName(const string &value);
    string getPhone() const;
    void setPhone(const string &value);
    string getEmail() const;
    void setEmail(const string &value);
    string getDepartment() const;
    void setDepartment(const string &value);

    std::string toString();

    Teacher &operator = (const Teacher &t);

    bool operator == (const Teacher &t);
    bool operator != (const Teacher &t);
    bool operator <= (const Teacher &t);
    bool operator >= (const Teacher &t);
    bool operator <  (const Teacher &t);
    bool operator >  (const Teacher &t);
};

#endif // TEACHER_H
