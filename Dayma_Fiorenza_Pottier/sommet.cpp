#include "sommet.h"


/**
Constructeur de la classe sommet
---------------------------------------------------------------------------------------------
**/
Sommet::Sommet(int id,double x,double y)
        :m_id{id},m_x{x},m_y{y}
{
}

/*
Sommet::Sommet(std::string id, std::vector <const Sommet*> voisins)
    :m_id{id},m_voisins{voisins}
{

}
*/
/**
M�thode d'ajout d'un voisin
---------------------------------------------------------------------------------------------
**//*
void Sommet::ajouterVoisin(const Sommet* voisin)
{
    m_voisins.push_back(voisin);
}*/


/**
M�thode d'affichage des donn�es d'un sommet
---------------------------------------------------------------------------------------------
**/
void Sommet::afficherData() const
{
     std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;
}

/**
M�thode d'affichage des donn�es d'un voisin
---------------------------------------------------------------------------------------------
**//*
void Sommet::afficherVoisins() const
{
    std::cout<<"  voisins :"<<std::endl;
    for(auto v:m_voisins) {
        v->afficherData();
    }
}*/

/**
Accesseur sur l'abscisse du sommet
---------------------------------------------------------------------------------------------
**/
double Sommet::getCoordX()
{
    return m_x;
}

/**
Accesseur sur l'ordonn�e du sommet
---------------------------------------------------------------------------------------------
**/
double Sommet::getCoordY()
{
    return m_y;
}


/**
Constructeur par d�faut
---------------------------------------------------------------------------------------------
**/
Sommet::Sommet()
{

}

/**
M�thode permettant de dessiner un sommet
---------------------------------------------------------------------------------------------
**/
void Sommet::dessinerSommet(Svgfile &out)
{

    m_couleur.modifier(135, 206, 235);
    out.addDisk(m_x, m_y, 20, m_couleur);
    out.addText(m_x, m_y, m_id,out.makeRGB(238, 53, 13));
}


/**
Accesseur de l'identifiant d'un sommet
---------------------------------------------------------------------------------------------
**/
int Sommet::getm_id()
{
    return m_id;
}


