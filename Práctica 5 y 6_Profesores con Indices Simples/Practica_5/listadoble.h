#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <exception>

#include <iostream>
#include <stdexcept>

template<class T>
class NodoD{
    private:
        T dato;
        NodoD<T> *sig;
        NodoD<T> *ant;
    public:
        NodoD(const T &d){
            dato = d;
            sig = nullptr;
            ant = nullptr;
        }
        template <class> friend class ListaDoble;
    };

template<class T>
class ListaDoble
{
    private:
        NodoD<T> *primero;
        NodoD<T> *ultimo;
        int size;

//        void quickSort(NodoD<T> *left, NodoD<T> *right);
//        NodoD<T> *partition(NodoD<T> *left, nodoD<T> *right);

    public:
        ListaDoble();
        bool vacia();

        void insertarInicio(const T &dato);
        void insertarFinal(const T &dato);
        void insertar(const T &dato, int posicion);

        void eliminarInicio();
        void eliminarFinal();
        void eliminarPos(int posicion);

        void swapData(T &a, T &b);
        void bubbleSort();
        void bubbleInver();
//        void quickSort();



        T& operator[] (int posicion);
        int getSize();

        std::string toString();
};

template<class T>
ListaDoble<T>::ListaDoble()
{
    primero = ultimo = nullptr;
    size = 0;
}

template<class T>
int ListaDoble<T>::getSize()
{
    return size;
}

template<class T>
std::string ListaDoble<T>::toString()
{
    std::string result;
    NodoD<T>* aux(primero);

    while(aux != nullptr) {
        result += aux->dato.toString() + "\n";

        aux = aux->sig;
    }
    return result;

}

template<class T>
bool ListaDoble<T>::vacia()
{
    return primero == nullptr;
}

template<class T>
void ListaDoble<T>::insertarInicio(const T &dato)
{
    if (vacia()) {
       NodoD<T> *nuevo = new NodoD<T>(dato);
       primero = nuevo;
       ultimo = nuevo;
    }else{
        NodoD<T> *nuevo = new NodoD<T>(dato);
        nuevo->sig = primero;
        primero->ant = nuevo;
        primero = nuevo;
    }
    size++;
}

template<class T>
void ListaDoble<T>::insertarFinal(const T &dato)
{
    if (vacia()) {
       NodoD<T> *nuevo = new NodoD<T>(dato);
       primero = nuevo;
       ultimo = nuevo;
    }else{
        NodoD<T> *nuevo = new NodoD<T>(dato);
        nuevo->ant = ultimo;
        ultimo->sig = nuevo;
        ultimo = nuevo;
    }
    size++;
}

template<class T>
void ListaDoble<T>::insertar(const T &dato, int posicion)
{
    if(posicion < 0 || posicion >= size){
        throw std::out_of_range("Pos no valida, insertando");
    }else {
        if (posicion == 0) {
            insertarInicio(dato);
        }else {
            NodoD<T> *nuevo = new NodoD<T> (dato);
            NodoD<T> *temp = primero;
            unsigned int contador = 0;

            while (temp != nullptr) {
                if (contador++ == posicion) {
                    nuevo->ant = temp->ant;
                    nuevo->sig = temp;
                    temp->ant->sig = nuevo;
                    temp->ant = nuevo;
                    size++;
                    break;
                }
                temp = temp->sig;
            }
        }
    }
}

template<class T>
void ListaDoble<T>::eliminarInicio()
{
    if(vacia()){
        throw std::out_of_range("Lista vacia, eliminando");
    }
    if (primero==ultimo) {
        delete primero;
        primero = ultimo = nullptr;
    }else{
        NodoD<T> *temp = primero;
        temp->sig->ant = nullptr;
        primero = primero->sig;
        delete temp;
    }
    size--;
}

template<class T>
void ListaDoble<T>::eliminarFinal()
{
    if(vacia()){
        throw std::out_of_range("Lista vacia, eliminar final");
    }
    if (primero==ultimo) {
        delete primero;
        primero = ultimo = nullptr;
    }else{
        NodoD<T> *temp = ultimo;
        temp->ant->sig = nullptr;
        ultimo = temp->ant;
        delete temp;
    }
    size--;
}

template<class T>
void ListaDoble<T>::eliminarPos(int posicion)
{
    if(vacia()){
        throw std::out_of_range("Lista vacia, eliminar pos");
    }
    if(posicion < 0 || posicion >= size){
        throw std::out_of_range("Pos no valida, eliminar pos");
    }
    if (posicion == 0) {
        eliminarInicio();
    }else if (posicion == size - 1) {
        eliminarFinal();
    }else {
        NodoD<T> * temp = primero;
        int contador = 0;

        while (temp!= nullptr) {
            if (contador++ == posicion) {
                temp->ant->sig = temp->sig;
                temp->sig->ant = temp->ant;
                size--;
                delete temp;
            }
            temp = temp->sig;
        }
    }
}

template<class T>
T &ListaDoble<T>::operator[](int posicion)
{
    if(posicion < 0 || posicion >= size){
        throw std::out_of_range("Pos no valida, operador [], LD");
    }

    NodoD<T> *temp = primero;
    int contador = 0;

    while (temp != nullptr and contador != posicion) {
        temp = temp->sig;
        contador ++;
    }
    return temp->dato;
}

template <class T>
void ListaDoble<T>::swapData(T &a, T &b){
    T aux;
    aux = a;
    a=b;
    b=aux;
}

template <class T>
void ListaDoble<T>::bubbleSort()
{
    NodoD<T> *current = primero;
    T dummy;

    if (current == NULL) return;
    if (current->sig == NULL) return;

    int swapped = 1;
    while (swapped){
        current = primero;
         //last pass unless there is a swap
        swapped = 0;
        while (current->sig != NULL){
            //swapped ++;
            if (current->dato > current->sig->dato){
                swapped = 1; //swap, will need to re-enter while loop
                //actual number swap
                dummy = current->dato;
                current->dato = current->sig->dato;
                current->sig->dato = dummy;
            }
            current = current->sig;
        }
        if (swapped)
            current = primero;
    }

}

template<class T>
void ListaDoble<T>::bubbleInver()
{
    NodoD<T> *current = primero;
    T dummy;

    if (current == NULL) return;
    if (current->sig == NULL) return;

    int swapped = 1;
    while (swapped){
        current = primero;
         //last pass unless there is a swap
        swapped = 0;
        while (current->sig != NULL){
            //swapped ++;
            if (current->dato < current->sig->dato){
                swapped = 1; //swap, will need to re-enter while loop
                //actual number swap
                dummy = current->dato;
                current->dato = current->sig->dato;
                current->sig->dato = dummy;
            }
            current = current->sig;
        }
        if (swapped)
            current = primero;
    }
}

//template<class T>
//void ListaDoble::quickSort()
//{
//    quickSort(primero, ultimo);
//}

/*
Considers last element as pivot, places the pivot element at its
   correct position in sorted array, and places all smaller (smaller than
   pivot) to left of pivot and all greater elements to right of pivot
//NodoD<T>* partition(NodoD<T> *l, NodoD<T> *h)
//{
//    // set pivot as h element
//    int x  = h->data;

//    // similar to i = l-1 for array implementation
//    Node *i = l->prev;

//    // Similar to "for (int j = l; j <= h- 1; j++)"
//    for (Node *j = l; j != h; j = j->next)
//    {
//        if (j->data <= x)
//        {
//            // Similar to i++ for array
//            i = (i == NULL)? l : i->next;

//            swap(&(i->data), &(j->data));
//        }
//    }
//    i = (i == NULL)? l : i->next; // Similar to i++
//    swap(&(i->data), &(h->data));
//    return i;
//}
*/

//template<class T>
//void ListaDoble<T>::quickSort(NodoD<T> *left, NodoD<T> *right)
//{
//    if (right != NULL && left != right && left != right->sig) {

//    }
//}

//template<class T>
//NodoD<T> *ListaDoble<T>::partition(NodoD<T> *left, nodoD<T> *right)
//{
//    T x = right->dato;


//    NodoD<T> *i = left->ant;

//    for (NodoD<T> *j = left; j != right; j = j->sig) {
//        if (j->dato <= x) {
//            i = (i == NULL)? left : i->sig;
//            swapData(i->dato, j->dato);
//        }
//    }
//    i = (i == NULL)? left : i->sig;
//    swapData(i->dato, h->dato);
//    return i;
//}


#endif // LISTADOBLE_H

