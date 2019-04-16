#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "svgfile.h"
#include "aretes.h"
#include "sommet.h"
#include <unordered_map>

class Graphe
{
    private:

        std::vector < Aretes* > m_CollectionAretes;
        std::unordered_map<std::string,Sommet*> m_CollectionSommets;

    public:

        ~Graphe();          //destructeur de la classe graphe
        void algoKruskal();
        Graphe(std::string nomFichier);             //méthode de chargement du graphe
        void afficher() const;              //méthode d'affichage du graphe
//        std::vector < Aretes*> AlgoKruskal(std::vector <Aretes*> arbreCouvrant)();

};

#endif // GRAPHE_H_INCLUDED
