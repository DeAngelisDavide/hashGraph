#ifndef VERTICE_H
#define VERTICE_H

#include "../src/linkedList.cpp"
#include "iostream"
#include "limits"

template <class T>
class vertice {
private:
    T data;
    linkedList<vertice*> *adj;
    vertice *p;
    int color;
    int d;
    int f;

public:
    vertice(T data);

    T getData() const;
    void setData(T data);

    linkedList<vertice *> *getAdj() const;

    vertice<T> *getP() const;

    void setP(vertice<T> *p);

    int getColor() const;

    void setColor(int color);

    int getD() const;

    void setD(int d);

    int getF() const;

    void setF(int f);

    void addEdge(vertice *v);
    bool searchEdge(vertice* v);
    bool removeEdge(vertice* v);
    void setVisit();
};

#endif // VERTICE_H
