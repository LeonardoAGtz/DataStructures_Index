#include <iostream>
#include "lista_invertida.h"

using namespace std;

int main()
{
    Lista_Invertida lista;
    string op;

    lista.inicializate();
    lista.loadData();

    while (true) {
        system("cls");
        cout << "Menu Practica 13,14 by EvoSenpai(Leonardo Aranda 217761528 INNI) " << endl;
        cout << "Menu de Profesores" << endl;
        cout << "   1.- Crear Profesor" << endl;
        cout << "   2.- Mostrar Profesores" << endl;
        cout << "   3.- Imprimir Profesores por Departamento" << endl;
        cout << "   4.- Imprimir Lista invertida(Lista de nodos)" << endl;
        cout << "   5.- Modificar Profesor" << endl;
        cout << "   6.- Eliminar Profesor" << endl;
        cout << "   0.- Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            Teacher t;
            string str;
            cout << "Ingresa el RFC: ";
            getline(cin, str);
            t.setRfc(str);
            cout << "Ingresa el Nombre: ";
            getline(cin, str);
            t.setName(str);
start:
            cout << "Ingresa el Telefono: ";
            getline(cin, str);
            if (str.size() < 10 or str.size() > 10) {
                goto start;
            }
            t.setPhone(str);
start1:
            cout << "Ingresa el Email: ";
            getline(cin, str);
            if (lista.validar_Email(str)==false) {
                goto start1;
            }
            t.setEmail(str);
            cout << "Ingresa el Departamento: ";
            getline(cin, str);
            t.setDepartment(str);
            lista.createTeacher(t);
        } else if (op == "2") { //Listo
            system("cls");
            lista.showTeachers();
            system("pause");
        } else if (op == "3") { //Listo
            string str;
            cout << "Ingresa el Departamento que buscas: ";
            getline(cin, str);

            if (lista.getDepartment(str)==NULL) {
                cout << "El Departamento que buscas no existe... D:" << endl;
                system("pause");
            } else {
                TDA_Department *department;
                department = lista.getDepartment(str);
                lista.printByDepartment(department);
                system("pause");
            }

        } else if (op == "4") { //Listo
            system("cls");
            lista.printList();
            system("pause");
        } else if (op == "5") { //Listo
            string str;
            cout << "Ingresa el RFC del profesor que deseas modificar: ";
            getline(cin, str);

            if (lista.getNode(str)==NULL) {
                cout << "Ese profesor no esta registrado... D:" << endl;
            } else { lista.modifyTeacher(str);}

        } else if (op == "6") { //Listo
            string str;
            cout << "Ingresa el RFC del profesor que deseas eliminar: ";
            getline(cin, str);

            if (lista.getNode(str)==NULL) {
                cout << "Ese profesor no esta registrado... D:" << endl;
            } else { lista.deleteTeacher(str);}

        } else if (op == "0") { //Listo
            remove(LISTI);
            remove(DEPRT);
            lista.saveData();
            lista.deleteAll();
            break;
        }
    }
    return 0;
}
