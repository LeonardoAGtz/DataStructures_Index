#include "menu.h"

Menu::Menu()
{
    string op;
    Profesores profesor;
    Indice indice;

    while (true) {
        system("cls");
        string temp;
        cout << "Menu Practica 5_6 by EvoSenpai(Leonardo Aranda 217761528 INNI)" << endl;
        cout << "Menu de Profesores" << endl;
        cout << "1.- Crear Profesor" << endl;
        cout << "2.- Mostrar Profesores" << endl;
        cout << "3.- Buscar Profesor" << endl;
        cout << "4.- Modificar Profesor" << endl;
        cout << "5.- Eliminar Profesor" << endl;
        cout << "6.- Descativar Profesor" << endl;
        cout << "7.- Activar Profesor" << endl;
        cout << "8.- Ordenar Profesores Ascendente" << endl;
        cout << "9.- Ordenar Profesores Descendente" << endl;
        cout << "10.- Mostrar Indices" << endl;
        cout << "0.- Salir" << endl;
        getline(cin, op);

        if (op == "1") {///listo validado agregar
            system("cls");
            string temp;

start:
            cout << "Ingrese RFC: ";
            getline(cin, temp);

            if (temp.size() < 12 or temp.size() > 12) {
                cout << "Formato RFC invalido..." << endl;
                system("pause");
                goto start;
            }

            if (validar_RFC(temp) == true) {
                cout << "RFC ya existenta..." << endl;
                system("pause");
                goto start;
            }

            profesor.setRfc(temp);

            cout << "Ingresa nombre: ";
            getline(cin, temp);
            profesor.setName(temp);

start2:
            cout << "Ingresa telefono: ";
            getline(cin, temp);

            if (temp.size() < 10 or temp.size() > 10) {
                cout << "Formato movil invalido..." << endl;
                system("pause");
                goto start2;
            }

            profesor.setPhone(temp);

start3:
            cout << "Ingresa email: ";
            getline(cin, temp);

            if (validar_Email(temp) == false) {
                cout << "Formato email invalido" << endl;
                system("pause");
                goto start3;
            }

            profesor.setEmail(temp);

            cout << "Ingresa departamento: ";
            getline(cin, temp);

            profesor.setArea(temp);

            temp = "1";
            profesor.setStatus(temp);

            cout << "Ingresando registro..." << endl;
            addProfesor(profesor);

        }
        else if (op == "2") {///listo validado mostrar prof
            system("cls");
            mostrarProfesores();
            system("pause");
        }
        else if (op == "3") {///listo validado buscar
            system("cls");
start8:
            cout << "Ingrese RFC a buscar: ";
            getline(cin, temp);

            if (temp.size() < 12 or temp.size() > 12) {
                cout << "Formato RFC invalido..." << endl;
                system("pause");
                goto start8;
            }

            if (validar_RFC(temp) == true and validar_RFC_active(temp) == true) {
                buscarProfesor(temp);
                system("pause");
            }
            else {
                cout << "El rfc que buscas no ha sido registrado o no se encuentra activo" << endl;
                system("pause");
            }


        }
        else if (op == "4") {///Listo validado modificar
            system("cls");
            string temp;

start9:
            cout << "Ingrese RFC a modificar: ";
            getline(cin, temp);

            if (temp.size() < 12 or temp.size() > 12) {
                cout << "Formato RFC invalido..." << endl;
                system("pause");
                goto start9;
            }

            if (validar_RFC(temp) == true and validar_RFC_active(temp) == true) {
                modificarProfesor(temp);
            }
            else {
                cout << "El rfc que buscas no ha sido registrado o no se encuentra activo" << endl;
                system("pause");
            }

        }
        else if (op == "5") {///listo validado eliminar
            system("cls");
start10:
            cout << "Ingrese RFC a eliminar: ";
            getline(cin, temp);

            if (temp.size() < 12 or temp.size() > 12) {
                cout << "Formato RFC invalido..." << endl;
                system("pause");
                goto start10;
            }

            if (validar_RFC(temp) == true and validar_RFC_active(temp) == true) {
                eliminarProfesor(temp);
                cout << "Profesor eliminado" << endl;
                system("pause");
            }
            else {
                cout << "El rfc que buscas no ha sido registrado o no está activo" << endl;
                system("pause");
            }

        }
        else if (op == "6") {///listo validado desactivar
            system("cls");
start11:
            cout << "Ingrese RFC a desactivar: ";
            getline(cin, temp);

            if (temp.size() < 12 or temp.size() > 12) {
                cout << "Formato RFC invalido..." << endl;
                system("pause");
                goto start11;
            }

            if (validar_RFC(temp) == true and validar_RFC_active(temp) == true) {
                desactivarProfesor(temp);
                cout << "Profesor desactivado" << endl;
                system("pause");
            }
            else {
                cout << "El rfc que buscas no ha sido registrado o ya esta desactivado" << endl;
                system("pause");
            }
        }
        else if (op == "7") {///listo validado activar
            system("cls");
start12:
            cout << "Ingrese RFC a activar: ";
            getline(cin, temp);

            if (temp.size() < 12 or temp.size() > 12) {
                cout << "Formato RFC invalido..." << endl;
                system("pause");
                goto start12;
            }

            if (validar_RFC(temp) == true) {
                activarProfesor(temp);
                cout << "Profesor activado" << endl;
                system("pause");
            }
            else {
                cout << "El rfc que buscas no ha sido registrado" << endl;
                system("pause");
            }
        }
        else if (op == "8") {///listo validado ordenAsc
            system("cls");
            ordenarProfesoresAscendente();
            system("pause");
        }
        else if (op == "9") {
            system("cls");
            ordenarProfesoresDescendentes();
            system("pause");
        }
        else if (op == "10") {
            system("cls");
            mostrarIndices();
            system("pause");
        }
        else if (op == "0") {
            cout << "Programa creado por: Leonardo Aranda Gtz INNI 217761528" << endl;
            system("pause");
            break;
        }

    }
}

void Menu::addProfesor(Profesores &p) ///listo, verificado
{
    Indice indice;

    indice.setRfc(p.getRfc());
    indice.setStatus(p.getStatus());

    ofstream save("Profesores.txt", ios::app);

    save.seekp(0, ios::end);
    indice.setDireccion(save.tellp()); ///guardo la direccion

    save << p.getRfc();
    save << ",";
    save << p.getName();
    save << ",";
    save << p.getPhone();
    save << ",";
    save << p.getEmail();
    save << ",";
    save << p.getArea();
    save << ",";
    save << p.getStatus();
    save << endl;

    save.close();

    ofstream save1("Indice.txt", ios::app);
    save1 << indice.getRfc();
    save1 << ",";
    save1 << indice.getStatus();
    save1 << ",";
    save1 << indice.getDireccion();
    save1 << endl;

    save1.close();

}

void Menu::mostrarProfesores() ///listo, verificado
{
/*
    fstream load_indices("Indices.txt", ios::in | ios::out);
    fstream load_profesor("Profesores.txt", ios::in | ios::out);

    if (load_indices.is_open()) {
        while (!load_indices.eof()) {
            string linea;
            long int direccionCargada;

            getline(load_indices, linea, ',');
            if (load_indices.eof()) {
                break;
            }
            Indice indice;
            indice.setRfc(linea);

            getline(load_indices, linea, ',');
            indice.setStatus(linea);

            getline(load_indices, linea);
            direccionCargada = stol(linea);
            indice.setDireccion(direccionCargada);

            if (indice.getStatus() == "1") {
                Profesores profesor;
                load_profesor.seekg(direccionCargada);

                string linea2;

                getline(load_profesor, linea2, ',');
                profesor.setRfc(linea2);

                getline(load_profesor, linea2, ',');
                profesor.setName(linea2);

                getline(load_profesor, linea2, ',');
                profesor.setPhone(linea2);

                getline(load_profesor, linea2, ',');
                profesor.setEmail(linea2);

                getline(load_profesor, linea2, ',');
                profesor.setArea(linea2);

                cout << profesor.getRfc() << "|" << profesor.getName() << "|" << profesor.getPhone() << "|" << profesor.getEmail()
                     << "|" << profesor.getArea() << "|" << profesor.getStatus() << endl;

            }
        }
    }
    */
    ifstream load("Profesores.txt", ios::in);

    if (load.is_open()) {
        while (!load.eof()) {
            string linea;

            getline(load, linea, ',');
            if (load.eof()) {
                break;
            }
            Profesores p;
            p.setRfc(linea);

            getline(load, linea, ',');
            p.setName(linea);

            getline(load, linea, ',');
            p.setPhone(linea);

            getline(load, linea, ',');
            p.setEmail(linea);

            getline(load, linea, ',');
            p.setArea(linea);

            getline(load, linea);
            p.setStatus(linea);

            if (p.getStatus() == "0") {
                continue;
            }
            else if (p.getStatus() == "1") {
                cout << p.getRfc() << "|" << p.getName() << "|" << p.getPhone() << "|" << p.getEmail()
                     << "|" << p.getArea() << "|" << p.getStatus() << endl;
            }
        }
    }
    load.close();
}

void Menu::buscarProfesor(const string &rfc)///listo verificado
{
    long int redireccion;

    ifstream load_indice("Indice.txt", ios::in);
    if (load_indice.is_open()) {
        while (!load_indice.eof()) {

            string linea;
            long int direccionCargada;

            getline(load_indice, linea, ',');
            if (load_indice.eof()) {
                break;
            }
            Indice indice;
            indice.setRfc(linea);

            getline(load_indice, linea, ',');
            indice.setStatus(linea);

            getline(load_indice, linea);
            direccionCargada = stol(linea);
            indice.setDireccion(direccionCargada);

            if (indice.getRfc() == rfc) {
                redireccion = direccionCargada;
            }

            if (load_indice.eof()) {
                break;
            }
        }
    }
    load_indice.close();

    ifstream load_profesor("Profesores.txt", ios::in);
    if (load_profesor.is_open()) {
        load_profesor.seekg(redireccion, ios::beg); ///me redirecciono

        string linea;

        getline(load_profesor, linea, ',');
        Profesores p;
        p.setRfc(linea);

        getline(load_profesor, linea, ',');
        p.setName(linea);

        getline(load_profesor, linea, ',');
        p.setPhone(linea);

        getline(load_profesor, linea, ',');
        p.setEmail(linea);

        getline(load_profesor, linea, ',');
        p.setArea(linea);

        getline(load_profesor, linea);
        p.setStatus(linea);

        cout << p.getRfc() << "|" << p.getName() << "|" << p.getPhone() << "|" << p.getEmail()
             << "|" << p.getArea() << "|" << p.getStatus() << endl;
    }
    load_profesor.close();
}

void Menu::modificarProfesor(const string &rfc)///listo verificado
{
    Profesores profesor;
    string temp_;
    Indice indice;


    ifstream load("Profesores.txt", ios::in);

    if (load.is_open()) {
        while (!load.eof()) {
            string linea;

            getline(load, linea, ',');
            if (load.eof()) {
                break;
            }
            profesor.setRfc(linea);

            getline(load, linea, ',');
            profesor.setName(linea);

            getline(load, linea, ',');
            profesor.setPhone(linea);

            getline(load, linea, ',');
            profesor.setEmail(linea);

            getline(load, linea, ',');
            profesor.setArea(linea);

            getline(load, linea);
            profesor.setStatus(linea);

            if (profesor.getRfc() == rfc and profesor.getStatus() == "1") { ///si llego al que necesito moidifcar, guardo las variables

                cout << "Nombre nuevo: ";
                getline(cin, temp_);
                profesor.setName(temp_);
start:
                cout << "Telefono nuevo: ";
                getline(cin, temp_);
                if (temp_.size() < 10 or temp_.size() > 10) {
                    cout << "Formato movil invalido..." << endl;
                    system("pause");
                    goto start;
                }
                profesor.setPhone(temp_);
start1:
                cout << "Email nuevo: ";
                getline(cin, temp_);
                if (validar_Email(temp_) == false) {
                    cout << "Formato email invalido" << endl;
                    system("pause");
                    goto start1;
                }
                profesor.setEmail(temp_);
                cout << "Departamento nuevo: ";
                getline(cin, temp_);
                profesor.setArea(temp_);
            }

            indice.setRfc(profesor.getRfc());
            indice.setStatus(profesor.getStatus());

            ofstream save_pt("PT.txt", ios::app);
            indice.setDireccion(save_pt.tellp());

            save_pt << profesor.getRfc();
            save_pt << ",";
            save_pt << profesor.getName();
            save_pt << ",";
            save_pt << profesor.getPhone();
            save_pt << ",";
            save_pt << profesor.getEmail();
            save_pt << ",";
            save_pt << profesor.getArea();
            save_pt << ",";
            save_pt << profesor.getStatus();
            save_pt << endl;


            ofstream save_it("IT.txt", ios::app);
            save_it << indice.getRfc();
            save_it << ",";
            save_it << indice.getStatus();
            save_it << ",";
            save_it << indice.getDireccion();
            save_it << endl;

            save_it.close();
            save_pt.close();
        }

    }
    load.close();

    remove("Profesores.txt");
    remove("Indice.txt");
    rename("PT.txt", "Profesores.txt");
    rename("IT.txt", "Indice.txt");
}

void Menu::eliminarProfesor(const string &rfc)///listo validado
{
    Profesores profesor;
    Indice indice;


    ifstream load("Profesores.txt", ios::in);

    if (load.is_open()) {
        while (!load.eof()) {
            string linea;

            getline(load, linea, ',');
            if (load.eof()) {
                break;
            }
            profesor.setRfc(linea);

            getline(load, linea, ',');
            profesor.setName(linea);

            getline(load, linea, ',');
            profesor.setPhone(linea);

            getline(load, linea, ',');
            profesor.setEmail(linea);

            getline(load, linea, ',');
            profesor.setArea(linea);

            getline(load, linea);
            profesor.setStatus(linea);

            if (profesor.getRfc() == rfc and profesor.getStatus() == "1") { ///si llego al que necesito moidifcar, guardo las variables
                continue;
            }

            indice.setRfc(profesor.getRfc());
            indice.setStatus(profesor.getStatus());

            ofstream save_pt("PT.txt", ios::app);
            indice.setDireccion(save_pt.tellp());

            save_pt << profesor.getRfc();
            save_pt << ",";
            save_pt << profesor.getName();
            save_pt << ",";
            save_pt << profesor.getPhone();
            save_pt << ",";
            save_pt << profesor.getEmail();
            save_pt << ",";
            save_pt << profesor.getArea();
            save_pt << ",";
            save_pt << profesor.getStatus();
            save_pt << endl;


            ofstream save_it("IT.txt", ios::app);
            save_it << indice.getRfc();
            save_it << ",";
            save_it << indice.getStatus();
            save_it << ",";
            save_it << indice.getDireccion();
            save_it << endl;

            save_it.close();
            save_pt.close();
        }

    }
    load.close();

    remove("Profesores.txt");
    remove("Indice.txt");
    rename("PT.txt", "Profesores.txt");
    rename("IT.txt", "Indice.txt");
}

void Menu::desactivarProfesor(const string &rfc)///listo verificado
{

    Profesores profesor;
    Indice indice;


    ifstream load("Profesores.txt", ios::in);

    if (load.is_open()) {
        while (!load.eof()) {
            string linea;

            getline(load, linea, ',');
            if (load.eof()) {
                break;
            }
            profesor.setRfc(linea);

            getline(load, linea, ',');
            profesor.setName(linea);

            getline(load, linea, ',');
            profesor.setPhone(linea);

            getline(load, linea, ',');
            profesor.setEmail(linea);

            getline(load, linea, ',');
            profesor.setArea(linea);

            getline(load, linea);
            profesor.setStatus(linea);

            if (profesor.getRfc() == rfc and profesor.getStatus() == "1") { ///si llego al que necesito moidifcar, guardo las variables
                string temp = "0";
                profesor.setStatus(temp);
            }

            indice.setRfc(profesor.getRfc());
            indice.setStatus(profesor.getStatus());

            ofstream save_pt("Profesores_Temp.txt", ios::app);
            indice.setDireccion(save_pt.tellp());

            save_pt << profesor.getRfc();
            save_pt << ",";
            save_pt << profesor.getName();
            save_pt << ",";
            save_pt << profesor.getPhone();
            save_pt << ",";
            save_pt << profesor.getEmail();
            save_pt << ",";
            save_pt << profesor.getArea();
            save_pt << ",";
            save_pt << profesor.getStatus();
            save_pt << endl;

            save_pt.close();

            ofstream save_it("Indices_Temp.txt", ios::app);
            save_it << indice.getRfc();
            save_it << ",";
            save_it << indice.getStatus();
            save_it << ",";
            save_it << indice.getDireccion();
            save_it << endl;

            save_it.close();

        }
    }
    load.close();

    remove("Profesores.txt");
    remove("Indice.txt");
    rename("Profesores_Temp.txt", "Profesores.txt");
    rename("Indices_Temp.txt", "Indice.txt");

}

void Menu::activarProfesor(const string &rfc)///listo verificado
{
    Profesores profesor;
    Indice indice;


    ifstream load("Profesores.txt", ios::in);

    if (load.is_open()) {
        while (!load.eof()) {
            string linea;

            getline(load, linea, ',');
            if (load.eof()) {
                break;
            }
            profesor.setRfc(linea);

            getline(load, linea, ',');
            profesor.setName(linea);

            getline(load, linea, ',');
            profesor.setPhone(linea);

            getline(load, linea, ',');
            profesor.setEmail(linea);

            getline(load, linea, ',');
            profesor.setArea(linea);

            getline(load, linea);
            profesor.setStatus(linea);

            if (profesor.getRfc() == rfc and profesor.getStatus() == "0") { ///si llego al que necesito moidifcar, guardo las variables
                string temp = "1";
                profesor.setStatus(temp);
            }

            indice.setRfc(profesor.getRfc());
            indice.setStatus(profesor.getStatus());

            ofstream save_pt("Profesores_Temp.txt", ios::app);
            indice.setDireccion(save_pt.tellp());

            save_pt << profesor.getRfc();
            save_pt << ",";
            save_pt << profesor.getName();
            save_pt << ",";
            save_pt << profesor.getPhone();
            save_pt << ",";
            save_pt << profesor.getEmail();
            save_pt << ",";
            save_pt << profesor.getArea();
            save_pt << ",";
            save_pt << profesor.getStatus();
            save_pt << endl;

            save_pt.close();

            ofstream save_it("Indices_Temp.txt", ios::app);
            save_it << indice.getRfc();
            save_it << ",";
            save_it << indice.getStatus();
            save_it << ",";
            save_it << indice.getDireccion();
            save_it << endl;

            save_it.close();

        }
    }
    load.close();

    remove("Profesores.txt");
    remove("Indice.txt");
    rename("Profesores_Temp.txt", "Profesores.txt");
    rename("Indices_Temp.txt", "Indice.txt");
}

void Menu::ordenarProfesoresDescendentes()
{
    ListaDoble<Indice> myLista;
    ListaDoble<Profesores> myLista2;
    long int direccionCargada;

    cout << "Ordenando Indices..." << endl << endl;

    ifstream load("Indice.txt", ios::in);

    if (load.is_open()) {
        while (!load.eof()) {
            string linea;

            direccionCargada = 0;

            getline(load, linea, ',');
            if (load.eof()) {
                break;
            }
            Indice indice;
            indice.setRfc(linea);

            getline(load, linea, ',');
            indice.setStatus(linea);

            getline(load, linea);
            direccionCargada = stol(linea);
            indice.setDireccion(direccionCargada);


            if (load.eof()) {
                break;
            }
            myLista.insertarFinal(indice);
        }
    }
    load.close();
    myLista.bubbleInver();
    cout << "Mostrando Profesores..." << endl << endl;;
    cout << myLista.toString() << endl << endl;; ///ordeno indice

    ifstream load1("Profesores.txt", ios::in);

    if (load1.is_open()) {
        while (!load1.eof()) {
            string linea;

            getline(load1, linea, ',');
            if (load1.eof()) {
                break;
            }
            Profesores p;
            p.setRfc(linea);

            getline(load1, linea, ',');
            p.setName(linea);

            getline(load1, linea, ',');
            p.setPhone(linea);

            getline(load1, linea, ',');
            p.setEmail(linea);

            getline(load1, linea, ',');
            p.setArea(linea);

            getline(load1, linea);
            p.setStatus(linea);

            myLista2.insertarFinal(p);
        }
    }
    load1.close();
    myLista2.bubbleInver();
    cout << myLista2.toString() << endl;

}

void Menu::mostrarIndices()///listo, verificado
{
    ifstream load("Indice.txt", ios::in);

    if (load.is_open()) {
        while (!load.eof()) {
            string linea;
            long int direccionCargada;

            getline(load, linea, ',');
            if (load.eof()) {
                break;
            }
            Indice indice;
            indice.setRfc(linea);

            getline(load, linea, ',');
            indice.setStatus(linea);

            getline(load, linea);
            direccionCargada = stol(linea);
            indice.setDireccion(direccionCargada);

            if (load.eof()) {
                break;
            }

            cout << indice.getRfc() << "|" << indice.getStatus() << "|" << indice.getDireccion() << endl;
        }
    }
    load.close();
}

void Menu::ordenarProfesoresAscendente()
{
    ListaDoble<Indice> myLista;
    ListaDoble<Profesores> myLista2;
    long int direccionCargada;

    cout << "Ordenando Indices..." << endl << endl;

    ifstream load("Indice.txt", ios::in);

    if (load.is_open()) {
        while (!load.eof()) {
            string linea;

            direccionCargada = 0;

            getline(load, linea, ',');
            if (load.eof()) {
                break;
            }
            Indice indice;
            indice.setRfc(linea);

            getline(load, linea, ',');
            indice.setStatus(linea);

            getline(load, linea);
            direccionCargada = stol(linea);
            indice.setDireccion(direccionCargada);


            if (load.eof()) {
                break;
            }
            myLista.insertarFinal(indice);
        }
    }
    load.close();
    myLista.bubbleSort();
    cout << "Mostrando Profesores..." << endl << endl;;
    cout << myLista.toString() << endl << endl;; ///ordeno indice

    ifstream load1("Profesores.txt", ios::in);

    if (load1.is_open()) {
        while (!load1.eof()) {
            string linea;

            getline(load1, linea, ',');
            if (load1.eof()) {
                break;
            }
            Profesores p;
            p.setRfc(linea);

            getline(load1, linea, ',');
            p.setName(linea);

            getline(load1, linea, ',');
            p.setPhone(linea);

            getline(load1, linea, ',');
            p.setEmail(linea);

            getline(load1, linea, ',');
            p.setArea(linea);

            getline(load1, linea);
            p.setStatus(linea);

            myLista2.insertarFinal(p);
        }
    }
    load1.close();
    myLista2.bubbleSort();
    cout << myLista2.toString() << endl;

}

bool Menu::validar_RFC(const string &rfc)///listo, verificado
{
    bool flag = false;

    ifstream load_indice("Indice.txt", ios::in);
    if (load_indice.is_open()) {
        while (!load_indice.eof()) {
            string linea;
            long int direccionCargada;

            getline(load_indice, linea, ',');
            if (load_indice.eof()) {
                break;
            }
            Indice indice;
            indice.setRfc(linea);

            getline(load_indice, linea, ',');
            indice.setStatus(linea);

            getline(load_indice, linea);
            direccionCargada = stol(linea);
            indice.setDireccion(direccionCargada);

            if (indice.getRfc() == rfc) {
                flag = true;
            }

            if (load_indice.eof()) {
                break;
            }
        }
    }
    return flag;
}

bool Menu::validar_RFC_active(const string &rfc)///listo verificado
{
    bool flag = false;

    ifstream load_indice("Indice.txt", ios::in);
    if (load_indice.is_open()) {
        while (!load_indice.eof()) {
            string linea;
            long int direccionCargada;

            getline(load_indice, linea, ',');
            if (load_indice.eof()) {
                break;
            }
            Indice indice;
            indice.setRfc(linea);

            getline(load_indice, linea, ',');
            indice.setStatus(linea);

            getline(load_indice, linea);
            direccionCargada = stol(linea);
            indice.setDireccion(direccionCargada);

            if (indice.getRfc() == rfc and indice.getStatus() == "1") {
                flag = true;
            }

            if (load_indice.eof()) {
                break;
            }
        }
    }
    return flag;
}

bool Menu::validar_Email(const string &mail) ///listo, verificado
{
    regex validate("([a-z]|_(?!\\.))(([a-z0-9]|_(?!\\.))+|(\\.[a-z0-9]|_(?!\\.))+)*@[a-z]{1,29}\\.([a-z]{2,3})(.[a-z]{2,3})?$");

    return regex_match(mail, validate);
}
