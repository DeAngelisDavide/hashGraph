//
// Created by Davide on 28/01/2022.
//

#include "linkedList.h"

//getheader
template <class T>
nodo<T> *linkedList<T>::getHeader() const { return header;}

//setheader
template<class T>
void linkedList<T>::setHeader(nodo<T> *header) {
    linkedList::header = header;
}

//pushBack
template<class T>
void linkedList<T>::push(T v){
    nodo<T> *x = new nodo<T>(v);
    x->setPNext(header);
    header = x;
}

//search
template<class T>
nodo<T> *linkedList<T>::search(T v) {
    nodo<T> *x = header;

    while (x != nullptr && x->getInfo() != v)
        x = x->getPNext();

    return x;
}

//removeNode
template<class T>
bool linkedList<T>::removeNode(T v) {
    nodo<T> *x = header;
    nodo<T> *y;

    while (x != nullptr && x->getInfo() != v) {
        y = x;
        x = x->getPNext();
    }

    if (x == nullptr)
        return false;


    if (x == header)
        header = nullptr;
    else
        y->setPNext(x->getPNext());

    x->~nodo();
    return true;
}



