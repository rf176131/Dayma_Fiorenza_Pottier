#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <vector>
#include <iostream>


class Sommet
{
    protected:

        std::string m_id;           //indice du sommet
        double m_x, m_y;            //coordonnées du sommet

        std::vector <const Sommet*> m_voisins;


    public:

        Sommet(std::string ,double,double);             //constructeur de la classe sommet

        Sommet(std::string id, std::vector < const Sommet*> voisins);


        void ajouterVoisin(const Sommet*);
        void afficherData() const;
        void afficherVoisins() const;

};

#endif // SOMMET_H_INCLUDED
