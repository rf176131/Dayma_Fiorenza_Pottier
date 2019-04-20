#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include "svgfile.h"
#include <vector>
#include <iostream>
#include "couleur.h"

/**
Classe contenant les données et les méthodes concernant les sommets
---------------------------------------------------------------------------------------------
**/
class Sommet
{
    private:

        int m_id;           //indice du sommet

        double m_x, m_y;            //coordonnées du sommet

        std::vector <const Sommet*> m_voisins;

        Couleur m_couleur;



    public:

        Sommet(int ,double,double);             //constructeur de la classe sommet
        Sommet();
        Sommet(int idd);


        int getm_id();

        double getCoordX();  //Pour acceder au coordonnŽes des sommets
        double getCoordY();

        void dessinerSommet(Svgfile &out);

        void ajouterVoisin(const Sommet*);
        void afficherData() const;
        void afficherVoisins() const;


        ///******************************************************************************************
        ///******************************************************************************************
        ///******************************************************************************************
        ///******************************************************************************************

        Sommet(int id, std::vector < const Sommet*> voisins);



};

#endif // SOMMET_H_INCLUDED
