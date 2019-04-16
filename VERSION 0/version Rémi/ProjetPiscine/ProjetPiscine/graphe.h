#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "aretes.h"
#include "sommet.h"


class Graphe
{
    private:

        std::vector < Aretes* > m_CollectionAretes;
        std::vector < Sommet* > m_CollectionSommets;

    public:

        void algoKruskal();
//        std::vector < Aretes*> AlgoKruskal(std::vector <Aretes*> arbreCouvrant)();

};


#endif // GRAPHE_H_INCLUDED
