//
// Created by Davide on 28/01/2022.
//

#include "vertice.h"

template <class T>
vertice<T>::vertice(T data){
    vertice::data = data;
    adj = new linkedList<vertice*>;
    setVisit();
}

template <class T>
T vertice<T>::getData() const {
    return data;
}

template <class T>
void vertice<T>::setData(T data) {
    vertice::data = data;
}

template <class T>
linkedList<vertice<T> *> *vertice<T>::getAdj() const {
    return adj;
}

template <class T>
void vertice<T>::addEdge(vertice *v) {
    adj->push(v);
}

template <class T>
bool vertice<T>::searchEdge(vertice *v) {
    if(adj->search(v) != nullptr)
        return true;
    return false;
}

template <class T>
bool vertice<T>::removeEdge(vertice *v) {
    return adj->removeNode(v);
}

template<class T>
vertice<T> *vertice<T>::getP() const {
    return p;
}

template<class T>
void vertice<T>::setP(vertice<T> *p) {
    vertice::p = p;
}

template<class T>
int vertice<T>::getColor() const {
    return color;
}

template<class T>
void vertice<T>::setColor(int color) {
    vertice::color = color;
}

template<class T>
int vertice<T>::getD() const {
    return d;
}

template<class T>
void vertice<T>::setD(int d) {
    vertice::d = d;
}

template<class T>
int vertice<T>::getF() const {
    return f;
}

template<class T>
void vertice<T>::setF(int f) {
    vertice::f = f;
}

template<class T>
void vertice<T>::setVisit() {
    p = nullptr;
    color = 0;
    d = std::numeric_limits<int>::max();
    f = std::numeric_limits<int>::max();
}
