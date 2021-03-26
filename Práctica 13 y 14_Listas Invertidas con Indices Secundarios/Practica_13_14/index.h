#ifndef INDEX_H
#define INDEX_H
#include <iostream>

using namespace std;

class Index
{
private:
    string rfc;
    int address;

public:
    Index();

    string getRfc() const;
    void setRfc(const string &value);
    int getAddress() const;
    void setAddress(int value);

    std::string toString();

    bool operator == (const Index &i);
    bool operator != (const Index &i);
    bool operator <= (const Index &i);
    bool operator >= (const Index &i);
    bool operator < (const Index &i);
    bool operator > (const Index &i);
};

#endif // INDEX_H
