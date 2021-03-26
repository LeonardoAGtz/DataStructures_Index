#ifndef LISTA_INVERTIDA_H
#define LISTA_INVERTIDA_H
#define TEMP1 "temporal1.txt"
#define TEMP2 "temporal2.txt"
#define TEMP3 "temporal3.txt"
#define TEMP4 "temporal4.txt"
#define INDEX "indice.txt"
#define TEACH "profesores.txt"
#define DEPRT "tda_departamento.txt"
#define LISTI "tda_lista_invertida.txt"
#include <fstream>
#include <regex>
#include "index.h"
#include "teacher.h"

class TDA_List;

class TDA_List
{
public:
    string rfc;
    TDA_List *next_on_list;
    TDA_List *next_on_department;

    friend class Lista_Invertida;
};

class TDA_Department
{
public:
    string department;
    TDA_Department *next_on_list_department;
    TDA_List *first_on_department;

    friend class Lista_Invertida;
};

class Lista_Invertida
{
    TDA_Department *d;
    TDA_List *l;
public:
    Lista_Invertida();
    void inicializate();
    bool emptyD();
    bool emptyL();

    TDA_Department *getDepartment(string &name_of_department);
    TDA_List *getNode(string &name_of_node);

    void createTeacher(Teacher &t);
    void showTeachers();

    void insertDepartment(string &name_of_department);
    void insertNode(TDA_Department *departamento, string &name_of_node);

    void printByDepartment(TDA_Department *departamento);
    void printList();

    void modifyTeacher(string &rfc);
    void deleteTeacher(string &name_of_node);

    void saveData();
    void findTeacher(string &rfc);
    void loadData();

    void deleteAll();

    bool existeProfe(string &rfc);
    bool validar_Email(const string &mail);
};

#endif // LISTA_INVERTIDA_H
