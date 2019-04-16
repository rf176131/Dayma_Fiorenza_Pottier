#ifndef ARETES_H_INCLUDED
#define ARETES_H_INCLUDED

#include <iostream>
#include "sommet.h"
//#include "../sommet.h"

class Aretes
{
    private :

        Sommet *m_s1;     //premier sommet composant l'arète
        Sommet *m_s2;     //second sommet composant l'arète
        float m_poids1;         //premier poids
        float m_poids2;         //second poids

    public :


        Aretes(float poids1, float poids2, Sommet *s1, Sommet *s2);
        Aretes(int id);             //deuxième constructeur
        ~Aretes();                  //destructeur


        float getPoids1();
        float getPoids2();

        Sommet*getm_s1();
        Sommet*getm_s2();


};




#endif // ARETES_H_INCLUDED
