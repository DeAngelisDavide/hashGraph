#include <iostream>
#include <fstream>
#include <sstream>
#include "src/hashGraph.cpp"

//Inizializza l'hashtable con il file di input
hashGraph<int> *inizializza();
void menu(hashGraph<int> *T);
//Funzione che fa inserire all'utente i dati
bool inputVertici(int &u, int &v);
bool verifyInt(int &i);

int main() {

    hashGraph<int> *T = inizializza();
    if (T == nullptr) {
        std::cout << "Errore nell'apertura del file o il numero dei vertici non rende possibile alcuna operazione";
        return -1;
    }
    menu(T);
    return 0;
}

//Inizializza l'hashtable con il file di input
hashGraph<int> *inizializza(){

    //Inizializzazione del file
    std::string path =  "../T2/Q1/input0_2_1.txt", choice;
    std::cout<<"1 per inserire il path del percorso file\nUn altro valore per "<<path<<std::endl;
    std::cin>>choice;

    if (choice == "1" )
    {
        std::cout<<"Inserire il path"<<std::endl;
        std::cin>>path;
    }

    std::ifstream f (path);

    if(f.fail())
        return nullptr;

    //u e v conteranno gli identificativi dei vertici
    std::string buffer, u, v;
    std::getline(f, buffer);
    int n = std::stoi(buffer);

    if (n <= 0)
        return nullptr;

    hashGraph<int> *T = new hashGraph<int>(n);

    for (int i = 0; i < n; i++)
        T->addVertice(i);


    while (buffer.length() != 0 && !f.eof()) {
        std::getline(f, buffer);
        if (buffer.length() != 0) {
            std::stringstream s(buffer);
            s >> u >> v;
            int a = std::stoi(u), b = std::stoi(v);

            if (a < n && b < n) {
                //Se u era già esistente
                if (T->addEdge(a, b) == 0)
                    std::cout << "Non e' stato inserito l'arco " << u << "-" << v << " perche' esiste gia\n'";
            } else
                std::cout << "Non e' stato possibile creare l'arco " << u << "-" << v
                          << ". Uno o entrambi i vertici non sono presenti nell'grafo" << std::endl;
        }
    }
    return T;
}

void menu(hashGraph<int> *T){
    bool cicle = true;
    int choice, u, v;
    vertice<int> *s;
    while (cicle)
    {
        std::cout<<"Inserisci:\n '1' per addEdge\n '2' per removeEdge\n '3' per findEdge\n '4' per DFS\n'0' per terminare\n";

        if(!verifyInt(choice))
            choice = 40;

        switch (choice) {
            case 1:
                if(inputVertici(u,v)) {
                    //Se i vertici eissotno nell'hashGraph
                    if (u < T->getDimension() && v < T->getDimension())
                        if (T->addEdge(u, v) == 1)
                            std::cout << "L'arco e' stato inserito con successo\n";
                        else
                            std::cout<<"L'arco non e' stato inserito perche' gia' esistente\n";
                    else
                        std::cout << "Uno o entrambi i vertici non esistono\n";
                }
                break;

            case 2:
                if (inputVertici(u,v)) {
                    if (u < T->getDimension() && v < T->getDimension())
                        if (T->removeEdge(u, v) == 1)
                            std::cout << "Eliminazione avvenuta con successo\n";
                        else
                            std::cout << "Eliminazione non avvenuta: L'arco non esiste\n";
                    else
                        std::cout << "Uno o entrambi i vertici non esistono\n";
                }
                break;
            case 3:
                if(inputVertici(u,v)) {
                    if (u < T->getDimension() && v < T->getDimension())
                        if (T->searchEdge(u, v) == 1)
                            std::cout << "L'arco esiste\n";
                        else
                            std::cout << "L'arco non esiste\n";
                    else
                        std::cout << "Uno o entrambi i vertici non esistono\n";
                }
                break;

            case 4:
                std::cout<<"Inserisci la sorgente s:\n";

                if (!verifyInt(u))
                    break;

                if (u < T->getDimension()) {
                    s = T->searchVertice(u);
                    T->dfs(s);
                    T->printDfsVisit();
                }
                else
                    std::cout<<"Errore: il vertice non esiste\n";

                break;

            case 0:
                cicle = false;
                break;

            default:
                std::cout<<"Inserisci un valore valido\n";
        }
    }
}

//Funzione che fa inserire all'utente i dati
bool inputVertici(int &u, int &v)
{
    //stringhe prova per veere che l'input è corretto
    std::string p1, p2;

    std::cout<<"Arco (u,v)\n Inserisci u:\n";
    std::cin >> p1;
    try {
        u = std::stoi(p1);
    }
    catch (std::exception const&err){
        std::cout<<"Errore nell'input u\n";
        return false;
    }

    std::cout<<"Inserisci v\n";
    std::cin >> p2;
    try {
        v = std::stoi(p2);
    }
    catch (std::exception const &err){
        std::cout<<"Errore nell' input v\n";
        return false;
    }
    return true;
}

bool verifyInt(int &i){
    std::string p;

    std::cin >> p;
    try {
        i = std::stoi(p);
    }
    catch (std::exception const&err){
        std::cout<<"Errore nell'input\n";
        return false;
    }
    return true;
}
