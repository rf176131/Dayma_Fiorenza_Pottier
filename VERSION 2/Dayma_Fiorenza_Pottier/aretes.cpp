#include "aretes.h"

/**
Constructeur de la classe Arètes
------------------------------------------------------------------
**/
Aretes::Aretes(float poids1, float poids2, Sommet *s1, Sommet *s2)
        : m_poids1{poids1}, m_poids2{poids2}, m_s1{s1}, m_s2{s2}
{

}

/**
Destructeur de la classe Arètes
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
Accesseur du premier sommet de l'arète
------------------------------------------------------------------
**/
Sommet *Aretes::getm_s1()
{
    return m_s1;
}

/**
Accesseur du deuxième sommet de l'arète
------------------------------------------------------------------
**/
Sommet *Aretes::getm_s2()
{
    return m_s2;
}

