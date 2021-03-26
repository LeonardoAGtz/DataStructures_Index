#include "lista_invertida.h"

Lista_Invertida::Lista_Invertida() { }

void Lista_Invertida::inicializate()//Listo
{
    d = NULL; //La raíz de la lista de departamentos es igual a nulo
    l = NULL; //La raíz de la lista de nodos es igual a nulo
}

bool Lista_Invertida::emptyD()//Listo
{    
    return d == NULL;
    //Retorno si la lista está vacia o no
}

bool Lista_Invertida::emptyL()//Listo
{
    return l == NULL;
    //Retorno si la lista está vacia o no
}

TDA_Department *Lista_Invertida::getDepartment(string &name_of_department)//Listo
{
    TDA_Department *aux;

    aux = d;

    while (aux != NULL) {
        if (aux->department == name_of_department) {
            return aux;
        }
        aux = aux->next_on_list_department;
    }

    return NULL;
}

TDA_List *Lista_Invertida::getNode(string &name_of_node)//Listo
{
    TDA_List *aux;

    aux = l;

    while (aux != NULL) {
        if (aux->rfc == name_of_node) {
            return aux;
        }
        aux = aux->next_on_list;
    }

    return NULL;
}

void Lista_Invertida::createTeacher(Teacher &t)//Listo Verificado
{
    string temp = t.getRfc();
    if (existeProfe(temp)== false) {
        Index index;

        index.setRfc(t.getRfc());

        ofstream save(TEACH, ios::app); //Paso 1, guardar los datos del profesor

        save.seekp(0, ios::end);
        index.setAddress(save.tellp());

        save << t.getRfc()        << ",";
        save << t.getName()       << ",";
        save << t.getPhone()      << ",";
        save << t.getEmail()      << ",";
        save << t.getDepartment() << endl;

        save.close();

        ofstream save1(INDEX, ios::app); //Paso 2, guardar en indice

        save1 << index.getRfc()     << ",";
        save1 << index.getAddress() << endl;

        save1.close();

        //Paso 3 en 2 casos
        string departamento(t.getDepartment());
        string rfcUnique(t.getRfc());
        if (getDepartment(departamento) == NULL) { //Si el departamento no se ha ingresado en la lista
            insertDepartment(departamento); //Se inserta el departamento
            TDA_Department *department; //Se crea un objeto de este tipo para poder insertar el nodo
            department = getDepartment(departamento); //el objeto tomará el valor del departamento insertado
            insertNode(department,rfcUnique); //Finalmente insertamos el nodo correspondiente

        }
        else {//Caso contrario que el nodo departamento ya se encuentre en la lista
            TDA_Department *department;
            department = getDepartment(departamento);
            insertNode(department,rfcUnique);//Solo insertamos el nodo correspondiente con el mismo metodo de arriba.
        }

    }

//    saveData();

}

void Lista_Invertida::showTeachers()//Listo Verificado
{
    int address;

    ifstream load(INDEX, ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string line;

            getline(load, line, ',');
            if (load.eof()) {
                break;
            }
            getline(load, line);
            address = stoi(line);

            ifstream load1(TEACH, ios::in);
            if (load1.is_open()) {
                load1.seekg(address, ios::beg);
                string line;
                Teacher t;
                getline(load1, line, ',');
                t.setRfc(line);
                getline(load1, line, ',');
                t.setName(line);
                getline(load1, line, ',');
                t.setPhone(line);
                getline(load1, line, ',');
                t.setEmail(line);
                getline(load1, line);
                t.setDepartment(line);

                cout << t.getRfc() << "|" << t.getName() << "|" << t.getPhone()
                << "|" << t.getEmail() << "|" << t.getDepartment() << "|" << address <<  endl;
            }
            load1.close();

            if (load.eof()) {
                break;
            }
        }
    }
    load.close();

    TDA_Department *aux;
    aux = d;

    while (aux != NULL) {
        cout << aux->department << endl;
        aux = aux->next_on_list_department;
    }
}

void Lista_Invertida::insertDepartment(string &name_of_department)//Listo Verificado
{
    TDA_Department *nuevo = new TDA_Department;

    nuevo->department = name_of_department;
    nuevo->next_on_list_department = NULL;
    nuevo->first_on_department = NULL;

    if (emptyD()) {
        d = nuevo;
    }
    else {
        TDA_Department *aux;
        aux = d;
        while (aux->next_on_list_department != NULL) {
            aux = aux->next_on_list_department;
        }
        aux->next_on_list_department = nuevo;
    }

    /*Creo un nuevo nodo de tipo departamento
     * Asigno sus punteros a nulo y seteo su nombre
     * Si la lista de departamentos está vacia, mi nuevo nodo será la raíz
     * Caso contrario, Uso un auxiliar de tipo departamento y recorro la lista hasta
     * que el ultimo nodo en su campo next_on_list sea Nulo y ahí lo inserto.
     */
}

void Lista_Invertida::insertNode(TDA_Department *departamento,string &name_of_node)//Listo Verificado
{
    TDA_List *nuevo = new TDA_List;

    nuevo->rfc = name_of_node;
    nuevo->next_on_department = NULL;
    nuevo->next_on_list = NULL;


    if (emptyL()) {
        l = nuevo;
        departamento->first_on_department = nuevo;
    }
    else {
        TDA_List *aux;
        aux = l;
        while (aux->next_on_list != NULL) {
            aux = aux->next_on_list;
        }
        aux->next_on_list = nuevo;

        if (departamento->first_on_department == NULL) {
            departamento->first_on_department = nuevo;
        }
        else {
            TDA_List *aux2;
            aux2 = departamento->first_on_department;
            while (aux2->next_on_department != NULL) {
                aux2 = aux2->next_on_department;
            }
            aux2->next_on_department = nuevo;
        }
    }

  /*Creo un nuevo nodo de tipo lista
   * Asignos sus valores de punteros a nulo y seteo su ID
   * Si la lista de nodos lista esta vacia, ahora la raíz es el nuevo nodo
   * Caso contrario hago un nodo lista auxiliar
   * Lo recorro por la lista hasta el ultimo en su campo nex_on_list que sea igual a nulo y
   * ahi lo inserto.
   * Si el departamento que me dieron, en su campo primero en departamento es igual a nulo
   * Mi nuevo nodo lista, sera el primero
   * Si el departamento en ese campo no es nulo, significa que ya hay un nodo como primero.
   * Para esto uso un segundo auxiliar de tipo lista y recorro a partir del primero en departamento
   * y me voy moviendo en por el campo, next_on_department, cuando llego al final
   * ligo el nuevo nodo en el campo next_on_department del anterior.
   */
}

void Lista_Invertida::printByDepartment(TDA_Department *departamento) //Listo Verificado
{
    system("cls");
    cout << "Imprimiendo profesores del Departamento: " << departamento->department << endl << endl;
    TDA_List *aux;
    aux = departamento->first_on_department;

    while (aux->next_on_department != NULL) {
        findTeacher(aux->rfc);
        aux = aux->next_on_department;
    }
    findTeacher(aux->rfc);
}

void Lista_Invertida::printList() //Listo Verificado
{
    TDA_List *aux;
    aux = l;
    cout << "La lista será imrpresa con el siguiente formato: " << endl;
    cout << "KEY | ADDRESS MEMORY | NOL | NOD" << endl;

    /*while (aux->next_on_list != NULL) {
        string nol,nod;
        if (aux->next_on_list == NULL) {
            nol = "-1";
        }
        else {
            nol = aux->next_on_list->rfc;
        }
        if (aux->next_on_department == NULL) {
            nod = "-1";
        }
        else {
            nod = aux->next_on_department->rfc;
        }
        cout << aux->rfc << " | " << &aux << " | " << nol << " | " << nod << endl;
        aux = aux->next_on_list;
    }
    string nol,nod;
    if (aux->next_on_list == NULL) {
        nol = "-1";
    }
    else {
        nol = aux->next_on_list->rfc;
    }
    if (aux->next_on_department == NULL) {
        nod = "-1";
    }
    else {
        nod = aux->next_on_department->rfc;
    }
    cout << aux->rfc << " | " << &aux << " | " << nol << " | " << nod << endl;
    */

    while (aux != NULL) {
        cout << aux->rfc << " | " << aux << " | ";

        if (aux->next_on_list == NULL) {
            cout << "-1" << " | ";
        } else { cout << aux->next_on_list << " | ";}

        if (aux->next_on_department == NULL) {
            cout << "-1" << endl;
        } else { cout << aux->next_on_department << endl;}

        aux = aux->next_on_list;

        try {
            if (aux == NULL) {
                break;
            }
        } catch (...) { }
    }
}

void Lista_Invertida::modifyTeacher(string &rfc)//Listo Verificado
{
    Teacher t;
    Index i;
    string c1,c2,c3;
    bool cambiar = false;

    ifstream lo(TEACH, ios::in);
    if (lo.is_open()) {
        while (!lo.eof()) {
            string str;

            getline(lo, str, ',');
            t.setRfc(str);
            if (lo.eof()) {
                break;
            }
            getline(lo, str, ',');
            t.setName(str);
            getline(lo, str, ',');
            t.setPhone(str);
            getline(lo, str, ',');
            t.setEmail(str);
            getline(lo, str);
            t.setDepartment(str);

            if (t.getRfc() == rfc) {
                string nuevo;
                string opcional;
                cout << "Nuevo nombre: ";
                getline(cin, nuevo);
                t.setName(nuevo);
                c3 = t.getRfc();
start3:
                cout << "Telefono nuevo: ";
                getline(cin, nuevo);
                if (nuevo.size() < 10 or nuevo.size() > 10) {
                    goto start3;
                }
                t.setPhone(nuevo);
start4:
                cout << "Email nuevo: ";
                getline(cin, nuevo);
                if (validar_Email(nuevo)==false) {
                    goto start4;
                }
                t.setEmail(nuevo);

start:
                cout << "Quieres cambiar el Departamento? (S/N): ";
                getline(cin, opcional);

                if (opcional == "S" or opcional == "s") {
                    cout << "Nuevo Departamento: ";
                    getline(cin, c2);
                    c1 = t.getDepartment();
                    t.setDepartment(c2);
                    cambiar = true;
                } else if (opcional == "N" or opcional == "n") {
                    cambiar = false;
                } else { goto start;}
            }

            i.setRfc(t.getRfc());

            ofstream sp(TEMP1, ios::app);
            sp.seekp(0, ios::end);
            i.setAddress(sp.tellp());

            sp << t.getRfc()        << ",";
            sp << t.getName()       << ",";
            sp << t.getPhone()      << ",";
            sp << t.getEmail()      << ",";
            sp << t.getDepartment() << endl;

            sp.close();

            ofstream si(TEMP2, ios::app);

            si << i.getRfc()     << ",";
            si << i.getAddress() << endl;

            si.close();
        }
    }
    lo.close();

    if (cambiar == true) {
        string nuevoDpto(c2), anteriorDpto(c1), rfcNode(c3);
        TDA_List *actual, *anterior;
        TDA_Department *auxNewDpto, *auxAntDpto;
        bool new_depto = false;

        auxNewDpto = d;
        auxAntDpto = d;
        actual = l;

         if (getDepartment(nuevoDpto)==NULL) {//Si el nuevo departamento no existe, lo creo
             insertDepartment(nuevoDpto);
             new_depto = true;
         }

         try {
         } catch (...) {

             while (actual->rfc != rfcNode) {//Recorro hasta encontrar mi nodo actual
                 actual = actual->next_on_list;
             }

             while (auxAntDpto->department != anteriorDpto) {//Recorro la lista anterior para posicionar mi aux ant
                 auxAntDpto = auxAntDpto->next_on_list_department;
             }

             anterior = auxAntDpto->first_on_department;

             while (anterior->next_on_department->rfc != rfcNode) {//Posiciono mi aux ant
                 anterior = anterior->next_on_department;
             }

             while (auxNewDpto->department != nuevoDpto) {//Mientras el auxiliar de dpto no se posicione en el nuevo, recorro
                 auxNewDpto = auxNewDpto->next_on_list_department;
             }

             if (new_depto == true) {
                 auxNewDpto->first_on_department = actual;
                 anterior->next_on_department = actual->next_on_department;
                 actual->next_on_department = NULL;
             } else{
                 TDA_List *nodeOnDpto;
                 nodeOnDpto = auxNewDpto->first_on_department;
                 while (nodeOnDpto->next_on_department != NULL) {
                     nodeOnDpto = nodeOnDpto->next_on_department;
                 }
                 nodeOnDpto->next_on_department = actual;
                 anterior->next_on_department = actual->next_on_department;
                 actual->next_on_department = NULL;
             }


//             while (auxNewDpto->department != nuevoDpto) {
//                 auxNewDpto = auxNewDpto->next_on_list_department;
//             }

//             auxList1 = auxNewDpto->first_on_department;

//             while (auxList1->next_on_department != NULL) {
//                 auxList1 = auxList1->next_on_department;
//             }

//             auxList1->next_on_department = actual;

//             while (auxAntDpto->department != anteriorDpto) {
//                 auxAntDpto = auxAntDpto->next_on_list_department;
//             }

//             auxList2 = auxAntDpto->first_on_department;

//             while (auxList2->next_on_department != actual) {
//                 auxList2 = auxList2->next_on_department;
//             }

//             auxList2->next_on_department = actual->next_on_department;
//             actual->next_on_department = NULL;
         }

/*
//        TDA_Department *newDepartment = getDepartment(nuevoDpto);

        if (getDepartment(nuevoDpto)==NULL) {
            TDA_Department *auxDpto, *nuevo;

            nuevo->department = nuevoDpto;
            nuevo->first_on_department = NULL;
            nuevo->next_on_list_department = NULL;
            auxDpto = d;

            while (auxDpto->next_on_list_department != NULL) {
                auxDpto = auxDpto->next_on_list_department;
            }
            auxDpto->next_on_list_department = nuevo;

            auxDpto = d;

            while (auxDpto->department != anteriorDpto) {
                auxDpto = auxDpto->next_on_list_department;
            }

            if (auxDpto->first_on_department->rfc == rfcNode) {
                nuevo->first_on_department = auxDpto->first_on_department;
                auxDpto->first_on_department = auxDpto->first_on_department->next_on_department;
                nuevo->first_on_department->next_on_department = NULL;
            } else {
                TDA_List *aux2, *aux3;
                aux2 = auxDpto->first_on_department;

                while (aux2->rfc != rfcNode) {
                    aux3 = aux2;
                    aux2 = aux2->next_on_department;
                }

                aux3->next_on_department = aux2->next_on_department;
                nuevo->first_on_department = aux2;
                aux2->next_on_department = NULL;
            }

            insertDepartment(nuevo);

        } else {
            TDA_Department *auxNewDpto = d, *auxAntDpto = d;

            while (auxNewDpto->department != nuevoDpto) {
                auxNewDpto = auxNewDpto->next_on_list_department;
            }

            auxList1 = auxNewDpto->first_on_department;

            while (auxList1->next_on_department != NULL) {
                auxList1 = auxList1->next_on_department;
            }

            auxList1->next_on_department = actual;

            while (auxAntDpto->department != anteriorDpto) {
                auxAntDpto = auxAntDpto->next_on_list_department;
            }

            auxList2 = auxAntDpto->first_on_department;

            while (auxList2->next_on_department != actual) {
                auxList2 = auxList2->next_on_department;
            }

            auxList2->next_on_department = actual->next_on_department;
            actual->next_on_department = NULL;
        }*/

    } else if (cambiar == false) {
        cout << "El departamento original se mantuvo" << endl;
    }

    remove(TEACH);
    rename(TEMP1, TEACH);
    remove(INDEX);
    rename(TEMP2, INDEX);
    remove(LISTI);
    remove(DEPRT);

    deleteAll();
    loadData();
    saveData();
}

void Lista_Invertida::deleteTeacher(string &name_of_node)//Listo Verificado
{
    TDA_Department *auxDepartment;
    TDA_List *auxList, *actual, *auxnewDep, *anteriorList, *anteriorDep, *primero;

    auxDepartment = d;
    auxList = l;
    auxnewDep = l;
    actual = l;
    anteriorList = l;
    anteriorDep = l;
    primero = l;

    while (auxDepartment != NULL) {
        actual = auxDepartment->first_on_department;//actual es el primero del deparatamento
        if (actual->rfc == name_of_node) {//Si el rfc de actual es el buscado
            if (actual == l) {
                l = actual->next_on_list;
                auxDepartment->first_on_department = actual->next_on_department;
                delete(actual);
            } else {
            while (anteriorList->next_on_list->rfc != name_of_node) {
                anteriorList = anteriorList->next_on_list;//Conseguimos el nodo que apunta en la lista a actual
            }
            auxnewDep = actual->next_on_department; //el nuevo primero de departamento sera el que sigue de actual
            auxList = actual->next_on_list;//el nuevo de la lista sera el que sigue de actual

            auxDepartment->first_on_department = auxnewDep;//conectamos el nuevo primer de departamento con el departamento
//            anteriorList->next_on_list = auxList;//conectamos el anterior de lista con el nuevo siguiente
            anteriorList->next_on_list = actual->next_on_list;
            delete(actual);//borramos actual
            }
        }
        else {//Si la condicion de arriba no se cumplio
            anteriorDep = auxDepartment->first_on_department;//Aterior de departamento = al primero del departamento
            actual = actual->next_on_department;//Actual es el siguiente en el departamento
            while (actual != NULL) {//Mientras que actual sea diferente de nulo
                if (actual->rfc == name_of_node) {//Verificamos si el nombre coincide
                    while (anteriorList->next_on_list->rfc != name_of_node) {//Si el nombre coincide hacemos un recoorido al anterior de la lista
                        anteriorList = anteriorList->next_on_list;//hasta que este en su campo siguiente de lista sea nuestro rfc
                    }
                    auxnewDep = actual->next_on_department;//el aux departamento es el siguiente del actual
                    auxList = actual->next_on_list;//el auxiliar de lista es el siguiente de actual

                    anteriorDep->next_on_department =  auxnewDep;//conectamos el anterior del departamento con el aux
                    anteriorList->next_on_list = auxList;//conectamos el anterior de lista con el aux
                    delete(actual);//eliminamos actual
                }
                anteriorDep = actual;//anterior es igual a actual
                actual = actual->next_on_department;//Incrementamos actual
            }
        }
        auxDepartment = auxDepartment->next_on_list_department;//incrementamos el departamento
    }


    ///Verificamos si el departamento se ha quedado sin profesores

    TDA_Department *department, *auxLD;

    department = d;
    auxLD = d;

    while (department != NULL) {
        if (department->first_on_department == NULL) {
            auxLD->next_on_list_department = department->next_on_list_department;
            delete(department);
        }
        auxLD = department;
        department = department->next_on_list_department;
    }

    Teacher t;
    Index i;

    ifstream l(TEACH, ios::in);
    if (l.is_open()) {
        while (!l.eof()) {
            string str;

            getline(l, str, ',');
            t.setRfc(str);
            if (l.eof()) {
                break;
            }
            getline(l, str, ',');
            t.setName(str);
            getline(l, str, ',');
            t.setPhone(str);
            getline(l, str, ',');
            t.setEmail(str);
            getline(l, str);
            t.setDepartment(str);

            if (t.getRfc() == name_of_node) {
                continue;
            }
            else {

            i.setRfc(t.getRfc());

            ofstream sp(TEMP1, ios::app);
            sp.seekp(0, ios::end);
            i.setAddress(sp.tellp());

            sp << t.getRfc()        << ",";
            sp << t.getName()       << ",";
            sp << t.getPhone()      << ",";
            sp << t.getEmail()      << ",";
            sp << t.getDepartment() << endl;

            sp.close();

            ofstream si(TEMP2, ios::app);

            si << i.getRfc()     << ",";
            si << i.getAddress() << endl;

            si.close();
            }
        }
    }
    l.close();

    remove(TEACH);
    rename(TEMP1, TEACH);
    remove(INDEX);
    rename(TEMP2, INDEX);
    remove(LISTI);
    remove(DEPRT);

    deleteAll();
    loadData();
    saveData();
}

void Lista_Invertida::saveData() //Listo
{
    TDA_Department *auxDepartment;
    TDA_List *auxList;

    auxDepartment = d;

    while (auxDepartment != NULL){
        ofstream s(DEPRT, ios::app);
        s << auxDepartment->department << ",";
        s << auxDepartment->first_on_department->rfc << endl;
        s.close();

        auxDepartment = auxDepartment->next_on_list_department;
    }

    auxList = l;

    while (auxList != NULL) {
        string nombre = auxList->rfc;

        ofstream s1(LISTI, ios::app);
        s1 << nombre << ",";
        if (auxList->next_on_department == NULL) {
            string proxDep = "-1";
            s1 << proxDep << endl;
        } else { s1 << auxList->next_on_department->rfc << endl; }
        s1.close();

        auxList = auxList->next_on_list;
    }
}

void Lista_Invertida::findTeacher(string &rfc)//Listo
{
    int address;

    ifstream load(INDEX, ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string line, indexrfc;

            getline(load, line, ',');
            indexrfc = line;
            if (load.eof()) {
                break;
            }
            getline(load, line);
            address = stoi(line);

            if (indexrfc == rfc) {

                ifstream load1(TEACH, ios::in);
                if (load1.is_open()) {
                    load1.seekg(address, ios::beg);
                    string line;
                    Teacher t;
                    getline(load1, line, ',');
                    t.setRfc(line);
                    getline(load1, line, ',');
                    t.setName(line);
                    getline(load1, line, ',');
                    t.setPhone(line);
                    getline(load1, line, ',');
                    t.setEmail(line);
                    getline(load1, line);
                    t.setDepartment(line);

                    cout << t.getRfc() << "|" << t.getName() << "|" << t.getPhone()
                    << "|" << t.getEmail() << "|" << t.getDepartment() << "|" << address <<  endl;
                }
                load1.close();
                break;
            }

            if (load.eof()) {
                break;
            }
        }
    }
    load.close();
}

void Lista_Invertida::loadData()
{
    ifstream l(TEACH, ios::in);
    if (l.is_open()) {
        while (!l.eof()) {
            Teacher t;
            string line;

            getline(l, line, ',');
            t.setRfc(line);
            if (l.eof()) {
                break;
            }
            getline(l, line, ',');
            t.setName(line);
            getline(l, line, ',');
            t.setPhone(line);
            getline(l, line, ',');
            t.setEmail(line);
            getline(l, line);
            t.setDepartment(line);
            if (l.eof()) {
                break;
            }

            string dpto(t.getDepartment());
            string rfcUnique(t.getRfc());

            if (getDepartment(dpto) == NULL) {
                insertDepartment(dpto);
                TDA_Department *department;
                department = getDepartment(dpto);
                insertNode(department, rfcUnique);
            } else {
                TDA_Department *department;
                department = getDepartment(dpto);
                insertNode(department, rfcUnique);
            }

        }
    }
    l.close();
}

void Lista_Invertida::deleteAll()
{
    TDA_Department *auxD;
    TDA_List *auxL;

    while (l != NULL) {
        auxL = l;
        l = l->next_on_list;
        delete(auxL);
    }

    while (d != NULL) {
        auxD = d;
        d = d->next_on_list_department;
        delete(auxD);
    }
}

bool Lista_Invertida::existeProfe(string &rfc)
{
    int address;
    bool existe = false;

    ifstream load(INDEX, ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string line, indexrfc;

            getline(load, line, ',');
            indexrfc = line;
            if (load.eof()) {
                break;
            }
            getline(load, line);
            address = stoi(line);

            if (indexrfc == rfc) {
                existe = true;
                break;
            }

            if (load.eof()) {
                break;
            }
        }
    }
    load.close();

    return existe;
}

bool Lista_Invertida::validar_Email(const string &mail)
{
    regex validate("([a-z]|_(?!\\.))(([a-z0-9]|_(?!\\.))+|(\\.[a-z0-9]|_(?!\\.))+)*@[a-z]{1,29}\\.([a-z]{2,3})(.[a-z]{2,3})?$");

    return regex_match(mail, validate);
}
