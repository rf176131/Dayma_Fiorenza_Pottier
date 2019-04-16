#include "sommet.h"


/**
Constructeur de la classe sommet
---------------------------------------------------------------------------------------------
**/
Sommet::Sommet(std::string id,double x,double y)
        :m_id{id},m_x{x},m_y{y}
{
}


Sommet::Sommet(std::string id, std::vector <const Sommet*> voisins)
    :m_id{id},m_voisins{voisins}
{

}

/**
Méthode d'ajout d'un voisin
---------------------------------------------------------------------------------------------
**/
void Sommet::ajouterVoisin(const Sommet* voisin)
{
    m_voisins.push_back(voisin);
}



void Sommet::afficherData() const
{
     std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;
}

void Sommet::afficherVoisins() const
{
    std::cout<<"  voisins :"<<std::endl;
    for(auto v:m_voisins) {
        v->afficherData();
    }
}


