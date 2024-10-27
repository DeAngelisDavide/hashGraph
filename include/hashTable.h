#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <cmath>
#include "../src/vertice.cpp"

template <class I>
class hashTable {
private:
    int dim;
    vertice<I> **T;
    int hashFunction1(I key);
    int hashFunction2(I key);
    int doppioHashing(I key, int i);
public:
    hashTable(int n);
    int hashInsert(vertice<I> *key);
    vertice<I> *hashSearch(I key);
    int getDim() const;
    vertice<I> *getVertice(int i);
};


#endif // HASHTABLE_H
