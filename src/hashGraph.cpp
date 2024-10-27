#include "hashGraph.h"

template <class I>
hashGraph<I>::hashGraph(int n){
    T = new hashTable<I>(n);
}

template <class I>
vertice<I> *hashGraph<I>::searchVertice(I u) {
    return T->hashSearch(u);
}

template <class I>
int hashGraph<I>::addVertice(I u)
{
    if (searchVertice(u) == nullptr)
    {
        vertice<I> *a = new vertice<I>(u);
        if (T->hashInsert(a) != -1)
            //Vertice inserito
            return 1;
        else {
            //L'hashtable è piena
            a->~vertice();
            return 0;
        }
    }
    //Il vertice esiste già
    return -1;
}

template <class I>
int hashGraph<I>::addEdge(I u, I v) {
    vertice<I> *a = searchVertice(u);
    vertice<I> *b = searchVertice(v);

    //se i vertici non esistono nell'hash table allora li crea
    if (a != nullptr && b != nullptr)
        if (!a->searchEdge(b)) {
            a->addEdge(b);
            return 1;
        }
        else //L'arco gia esiste
            return 0;
    //Uno dei due vertici non esiste
    return -1;
}

template <class I>
int hashGraph<I>::searchEdge(I u, I v) {
    vertice<I> *a = T->hashSearch(u);
    vertice<I> *b = T->hashSearch(v);

    if(a != nullptr && b != nullptr)
        if (a->searchEdge(b))
            //L'arco esiste
            return 1;
        else
            //L'arco non eiste
            return 0;

    //Uno dei due vertici non eeiste
    return  -1;
}

template <class I>
int hashGraph<I>::removeEdge(I u, I v) {
    vertice<I> *a = T->hashSearch(u);
    vertice<I> *b = T->hashSearch(v);

    //Se esistono nell'hashtable
    if(a != nullptr && b != nullptr)
        if(a->removeEdge(b))
            //L'arco è stato rimosso
            return 1;
        else
            //L'arco non esiste
            return 0;

    //Uno dei due vertici non esiste
    return -1;
}

template <class I>
void hashGraph<I>::dfs(vertice<I> *s) {
    enum {white, gray, black};
    for (int i = 0; i < T->getDim(); i++) {
        vertice<I> *u = T->getVertice(i);
        if ( u != nullptr)
             if (u->getColor()!= white)
                 u->setVisit();
    }
    int time = 0;
    dfs_visit(s, time);
}



template <class I>
void hashGraph<I>::dfs_visit(vertice<I> *s, int &time) {
    enum {white, gray, black};
    s->setColor(gray);
    s->setD(time++);

    nodo<vertice<I>*> *u = s->getAdj()->getHeader();
    while (u != nullptr) {
        if (u->getInfo()->getColor() == white) {
            u->getInfo()->setP(s);
            dfs_visit(u->getInfo(), time);
        }
        u= u->getPNext();
    }
    s->setColor(black);
    s->setF(time++);
}

template <class I>
void hashGraph<I>::printDfsVisit() {
    std::cout<<"Il risultato della dfs dalla sorgente stabilita e'\n";

    for (int i = 0; i < T->getDim(); i++) {
        vertice<I> *u = T->getVertice(i);
        if ( u != nullptr)
            if(u->getD() != std::numeric_limits<int>::max())
                std::cout<<"Vertice:"<<u->getData()<<"\nTempo di inizio scoperta: "<<u->getD()<<"\nTempo di fine scoperta: "<<u->getF()<<std::endl;
            else
                std::cout<<"Vertice:"<<u->getData()<<" non scoperto dalla sorgente\n";
    }

}

template<class I>
int hashGraph<I>::getDimension() {
    return T->getDim();
}
