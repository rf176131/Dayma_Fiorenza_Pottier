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

        float m_poids1;         //premier poids
        float m_poids2;         //second poids

        Couleur m_couleur;
        int m_id1;
        int m_id2;

        Sommet *m_s1;     //premier sommet composant l'arète
        Sommet *m_s2;     //second sommet composant l'arète


    public :


        Aretes(float poid, float poid2, int id1, int id2);                    //constructeur 1
       // Aretes( float poid1, float poid2,int x1, int y1, int x2, int y2);

        Aretes(int id);             //deuxième constructeur
        ~Aretes();                  //destructeur


        float getPoids1();          //Accesseur du poids 1
        float getPoids2();          //Accesseur du poids 2

        int getm_id1();  //Accesseur de l'identifiant 1
        int getm_id2();  //Accesseur de l'identifiant 2

        void dessinerAretes(Svgfile &out);
        void afficher2();


        ///***************************************************************************************************************************
        ///***************************************************************************************************************************
        ///***************************************************************************************************************************
        ///***************************************************************************************************************************
        ///***************************************************************************************************************************
        ///***************************************************************************************************************************
        ///***************************************************************************************************************************
        ///***************************************************************************************************************************


        std::vector<Aretes*> remplir(float *tab,std::vector < Aretes* > m_CollectionAretes);

        Sommet *getm_s1();
        Sommet *getm_s2(); // Accesseur des sommets


        Aretes(float poids1, float poids2, Sommet *s1, Sommet *s2);
        Aretes(float p1,Sommet *s1,Sommet *s2);






};




#endif // ARETES_H_INCLUDED
