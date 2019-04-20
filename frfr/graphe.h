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


#define sommet std::pair<int,int>             ///pour le code ajouté



class Graphe
{
    private:


        std::vector < Aretes* > m_CollectionAretes;

        std::vector < Sommet*> m_CollectionSommets;

        ///**********************************************************************************************************************Partie alexandre
        ///**********************************************************************************************************************Partie alexandre
        ///**********************************************************************************************************************Partie alexandre

        std::vector<Aretes*> m_arbre;

       // std::pair <int,int> sommet;

        std::vector<std::pair<float,sommet>> m_a;
        std::vector<std::pair<float,sommet>> m_b;
        std::vector<std::pair<float,sommet>> m_c;
        std::vector<std::pair<float,sommet>> m_d;
        std::vector<std::pair<float,sommet>> m_e;
        std::vector<std::pair<float,sommet>> m_f;
        std::vector<std::pair<float,sommet>> m_g;
        std::vector<std::pair<float,sommet>> m_h;
        int*m_v;
        int*m_w;
        int m_nbSommet;
        int m_nArretes;

        void dessinerKruskal(Svgfile &out);




    public:

        Graphe(std::string nomFichier);             //méthode de chargement du graphe
        Graphe(std::string nomFichier1,std::string nomFichier2);
        Graphe(std::string nomFichier2,std::string nomFichier1,int hi);            //méthode du chargement du graphe
        ~Graphe();          //destructeur de la classe graphe

        void afficher() const;              //méthode d'affichage du graphe
        void afficher2() const;                 //méthode d'affichage du graphe

        void dessiner(Svgfile &out);
        void dessiner1(Svgfile &out);

        std::vector<Sommet*> getCollectionSommet();
        std::vector<Sommet*> retour();
        std::vector < Aretes* > m_ListeArrete();
        void afficher3(std::vector < Aretes* > m_ListeArrete);


        int Trouver_sommet(int a);
        int Trouver_sommet2(int a);
        void Union_Sommet(int u,int w); //fonction pour utiliser l'algorithme de Kruskal
        void Union_Sommet2(int u,int w);
        void Kruskal();
        void Afficher_Kruskal(Svgfile &out);
        void Kruskal2();
        void Afficher_Kruskal2(Svgfile &out);
        int return_NbSommet();
        int return_NbArretes();








};

#endif // GRAPHE_H_INCLUDED
