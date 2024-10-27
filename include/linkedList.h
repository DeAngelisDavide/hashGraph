#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../src/nodo.cpp"

template <class T>
class linkedList {
private:
    nodo<T> *header = nullptr;
public:
    nodo<T> *getHeader() const;
    void setHeader(nodo<T> *header);

    void push(T v);
    nodo<T>* search(T v);
    bool removeNode(T v);

};

#endif // LINKEDLIST_H
