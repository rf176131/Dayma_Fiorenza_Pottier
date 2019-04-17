#include "aretes.h"

/**
Constructeur pour la fonction avec le graphe avec deux poids
------------------------------------------------------------------
**/
Aretes::Aretes(float poid, float poid2, int id1, int id2)
            :m_poids1(poid),m_poids2(poid2),m_id1(id1),m_id2(id2)
{

}

/**
Destructeur de la classe Ar�tes
------------------------------------------------------------------
**/
Aretes::~Aretes()
{

}


/**
Accesseur de l'attribut poids1
------------------------------------------------------------------
**/
float Aretes::getPoids1()
{
    return m_poids1;
}


/**
Accesseur de l'attribut poids2
------------------------------------------------------------------
**/
float Aretes::getPoids2()
{
    return m_poids2;
}

/**
Accesseur du premier sommet de l'ar�te
------------------------------------------------------------------
**//*
Sommet *Aretes::getm_s1()
{
    return m_s1;
}*/

/**
Accesseur du deuxi�me sommet de l'ar�te
------------------------------------------------------------------
**//*
Sommet *Aretes::getm_s2()
{
    return m_s2;
}*/



/**
M�thode d'affichage des ar�tes avec deux poids dans la console
------------------------------------------------------------------
**/
void Aretes::afficher2()
{
    std::cout<<std::endl;
    std::cout <<"poid 1 :"<< m_poids1<<" poid2 : " <<m_poids2 << std::endl;
    std::cout<<std::endl;
    std::cout <<"Sommet :"<< std::endl;
    std::cout<<std::endl;
    std::cout<< m_id1 << " : " << m_id2 << std::endl;
}

/**
Accesseur sur le premier ID
------------------------------------------------------------------
**/
int Aretes::getm_id1()
{
    return m_id1;
}

/**
Accesseur sur le second second ID
------------------------------------------------------------------
**/
int Aretes::getm_id2()
{
    return m_id2;
}
/*
Aretes::Aretes(float poids1, float poids2, int x1, int y1, int x2, int y2)
        :m_poids1{poids1}, m_poids2{poids2}, m_id1{x1}, m_id2{y1}, m_id3{x2}, m_id4{y2}
{

}*/

