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

/**
Méthode permettant de dessiner les arètes dans le fichier svg
------------------------------------------------------------------
**/
void Aretes::dessinerAretes(Svgfile &out)
{
    m_couleur.modifier(65,105,225);
    out.addLine(m_s1->getCoordX() , m_s1->getCoordY() , m_s2->getCoordX() , m_s2->getCoordY(), m_couleur);

}


/**
Méthode d'affichage des arètes avec deux poids dans la console
------------------------------------------------------------------
**/
void Aretes::afficher2()
 {
 /*Graphe G;
 std::unordered_map<std::string,Sommet*> m_CollectionSommets;
 m_CollectionSommets=G.retour();
 m_s1=m_CollectionSommets.find(id1)->second;
 m_s2=m_CollectionSommets.find(id2)->second;*/

    std::cout<<std::endl;
    std::cout <<"poid 1 :"<< m_poids1<<" poid2 : " <<m_poids2 << std::endl;
    std::cout<<std::endl;
    std::cout <<"Sommet :"<< std::endl;
    std::cout<<std::endl;
    std::cout<< m_id1 << " : " << m_id2 << std::endl;



 }


/**
Constructeur pour la fonction avec le graphe avec deux poids
------------------------------------------------------------------
**/
Aretes::Aretes(float poid, float poid2, int fr, int hy)
            :m_poids1(poid),m_poids2(poid2),m_id1(fr),m_id2(hy)
{

}
