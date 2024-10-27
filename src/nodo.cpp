#include "iostream"
#include "nodo.h"

template<class T>
nodo<T>::nodo(T info) {
    nodo::info = info;
}


template<class T>
T nodo<T>::getInfo() const {
    return info;
}

template<class T>
void nodo<T>::setInfo(T info) {
    nodo::info = info;
}

template<class T>
nodo<T> *nodo<T>::getPNext() const {
    return pNext;
}

template<class T>
void nodo<T>::setPNext(nodo *pNext) {
    nodo::pNext = pNext;
}





