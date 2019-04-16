#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <iostream>


class Sommet
{
    protected:

        int m_id;           //indice du sommet
        double m_x, m_y;            //coordonnées du sommet


    public:

       // Sommet(std::string,double,double);
        void ajouterVoisin(const Sommet*);
        void afficherData() const;
        void afficherVoisins() const;

};

#endif // SOMMET_H_INCLUDED
