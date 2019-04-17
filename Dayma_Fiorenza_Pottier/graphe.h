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
#include "couleur.h"

class Graphe
{
    private:

        std::vector < Aretes* > m_CollectionAretes;

        std::vector < Sommet*> m_CollectionSommets;

        //std::unordered_map<std::string,Sommet*> m_CollectionSommets;            //ensemble des sommets qui composent le graphe

    public:

        Graphe(std::string nomFichier);             //méthode de chargement du graphe
        Graphe(std::string nomFichier1,std::string nomFichier2);            //méthode du chargement du graphe
        ~Graphe();          //destructeur de la classe graphe

        void algoKruskal();

        void afficher() const;              //méthode d'affichage du graphe
        void afficher2() const;                 //méthode d'affichage du graphe


//        std::vector < Aretes*> AlgoKruskal(std::vector <Aretes*> arbreCouvrant)();


        void dessiner(Svgfile &out);

};

#endif // GRAPHE_H_INCLUDED
