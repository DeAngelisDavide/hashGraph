#include "hashTable.h"

template <class I>
hashTable<I>::hashTable(int n) {
    hashTable::dim = n;
    T = new vertice<I> *[n];
    for (int i = 0; i < dim; i++)
        T[i] = nullptr;
}

template <class I>
//Metodo della divisione
int hashTable<I>::hashFunction1(I key) {
    std::hash<I> hash;
    return hash(key) % dim;
}
template <class I>
//Metodo della moltiplicazione
int hashTable<I>::hashFunction2(I key) {
    std::hash<I> hash;
    float a = 0.54;
    float mod = 1;
    float k = hash(key);
//Parte frazionaria
    float pf = k*a-(float)floor((k*a));
    return floor(dim * pf);

}

template <class I>
int hashTable<I>::doppioHashing(I key, int i) {
    return (hashFunction1(key) + i*hashFunction2(key)) % dim;
}

template <class I>
int hashTable<I>::hashInsert(vertice<I> *key) {
    int i = 0, j;
    do {
        j = doppioHashing(key->getData(), i);
        if(T[j] == nullptr ) {
            T[j] = key;
            return j;
        }
        i++;
    } while (i != dim);
    return -1;
}

template <class I>
vertice<I> *hashTable<I>::hashSearch(I key) {
    int i = 0, j;
    do {
        j = doppioHashing(key, i);
        if(T[j] != nullptr && T[j]->getData() == key )
            return T[j];

        i++;
    } while (i != dim && T[j] != nullptr);
    return nullptr;
}

template <class I>
int hashTable<I>::getDim() const {
    return dim;
}

template <class I>
vertice<I> *hashTable<I>::getVertice(int i) {
    if (i < dim)
        return T[i];
    else
        return nullptr;
}



