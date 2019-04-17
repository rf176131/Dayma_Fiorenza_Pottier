#ifndef ARETES_H_INCLUDED
#define ARETES_H_INCLUDED

#include "sommet.h"
#include <iostream>

/**
Classe contenant les données sur les arètes
-----------------------------------------------------------------------------------------
**/
class Aretes
{
    private :

        Sommet *m_s1;     //premier sommet composant l'arète
        Sommet *m_s2;     //second sommet composant l'arète
        float m_poids1;         //premier poids
        float m_poids2;         //second poids
        Couleur m_couleur;
        int m_id1;
        int m_id2;

    public :


        Aretes(float poids1, float poids2, Sommet *s1, Sommet *s2);                 //constructeur 1
        Aretes(float poid, float poid2, int fr, int hy);                    //constructeur 2

        Aretes(int id);             //deuxième constructeur
        ~Aretes();                  //destructeur


        float getPoids1();          //Accesseur du poids 1
        float getPoids2();          //Accesseur du poids 2

        Sommet*getm_s1();           //Accesseur du premier sommet
        Sommet*getm_s2();           //Accesseur du second sommet

        void dessinerAretes(Svgfile &out);
        void afficher2();



};




#endif // ARETES_H_INCLUDED
