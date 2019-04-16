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

    Graphe();
        ~Graphe();          //destructeur de la classe graphe
        void algoKruskal();
        Graphe(std::string nomFichier);             //méthode de chargement du graphe
        void afficher() const;              //méthode d'affichage du graphe
    void afficher2();
        std::unordered_map<std::string,Sommet*> retour();
    Graphe(std::string nomFichier1,std::string nomFichier2);
//       std::vector < Aretes*> AlgoKruskal(std::vector <Aretes*> arbreCouvrant)();

};

#endif // GRAPHE_H_INCLUDED
