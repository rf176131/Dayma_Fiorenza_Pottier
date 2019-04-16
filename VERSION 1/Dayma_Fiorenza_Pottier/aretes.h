#ifndef ARETES_H_INCLUDED
#define ARETES_H_INCLUDED

#include "sommet.h"
#include <iostream>

/**
Classe contenant les donn�es sur les ar�tes
-----------------------------------------------------------------------------------------
**/
class Aretes
{
    private :

        Sommet *m_s1;     //premier sommet composant l'ar�te
        Sommet *m_s2;     //second sommet composant l'ar�te
        float m_poids1;         //premier poids
        float m_poids2;         //second poids

    public :


        Aretes(float poids1, float poids2, Sommet *s1, Sommet *s2);
        Aretes(int id);             //deuxi�me constructeur
        ~Aretes();                  //destructeur


        float getPoids1();          //Accesseur du poids 1
        float getPoids2();          //Accesseur du poids 2

        Sommet*getm_s1();           //Accesseur du premier sommet
        Sommet*getm_s2();           //Accesseur du second sommet


};




#endif // ARETES_H_INCLUDED
