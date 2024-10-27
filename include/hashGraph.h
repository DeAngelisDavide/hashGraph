#ifndef HASHGRAPH_H
#define HASHGRAPH_H


#include "../src/hashTable.cpp"

template <class I>
class hashGraph {
private:
    hashTable<I> *T;
    void dfs_visit(vertice<I> *s, int &time);
public:
    hashGraph(int n);
    vertice<I> *searchVertice(I u);
    int addVertice(I u);
    int addEdge(I u, I v);
    int searchEdge(I u, I v);
    int removeEdge(I u, I v);
    void dfs(vertice<I> *s);
    void printDfsVisit();
    int getDimension();
};

#endif // HASHGRAPH_H
