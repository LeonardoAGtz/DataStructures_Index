#ifndef MENU_H
#define MENU_H
#include "profesores.h"
#include "indice.h"
#include "listadoble.h"
#include <regex>
#include <fstream>

using namespace std;

class Menu
{
    ListaDoble<Indice> listaI;
    ListaDoble<Profesores> listaP;
public:
    Menu();

    void addProfesor(Profesores &p);
    void mostrarProfesores();
    void buscarProfesor(const string &rfc);
    void modificarProfesor(const string &rfc);
    void eliminarProfesor(const string &rfc);
    void desactivarProfesor(const string &rfc);
    void activarProfesor(const string &rfc);
    void ordenarProfesoresAscendente();
    void ordenarProfesoresDescendentes();
    void mostrarIndices();

    bool validar_RFC(const string &rfc);
    bool validar_RFC_active(const string &rfc);
    bool validar_Email(const string &mail);
};

#endif // MENU_H
