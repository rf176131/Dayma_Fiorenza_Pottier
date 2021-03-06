#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include "svgfile.h"
#include <vector>
#include <iostream>
#include "couleur.h"

/**
Classe contenant les donn�es et les m�thodes concernant les sommets
---------------------------------------------------------------------------------------------
**/
class Sommet
{
    private:

        int m_id;           //indice du sommet
        double m_x, m_y;            //coordonn�es du sommet

        std::vector <const Sommet*> m_voisins;

        Couleur m_couleur;


    public:

        Sommet(int ,double,double);             //constructeur de la classe sommet

        Sommet();

        //Sommet(std::string id, std::vector < const Sommet*> voisins);

        double getCoordX();
        double getCoordY();

        void dessinerSommet(Svgfile &out);

        void ajouterVoisin(const Sommet*);
        void afficherData() const;
        void afficherVoisins() const;




};

#endif // SOMMET_H_INCLUDED
