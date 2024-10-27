#ifndef NODO_H
#define NODO_H


template <class T>
class nodo {

private:
    T info;
    nodo *pNext = nullptr;
public:
    nodo(T info);

    T getInfo() const;
    void setInfo(T info);

    nodo<T> *getPNext() const;

    void setPNext(nodo *pNext);

};

#endif // NODO_H
