#include "graphe.h"
#include <iterator>



/*
std::vector < Aretes*> Graphe::AlgoKruskal(std::vector <Aretes*> arbreCouvrant)
{

    std::sort(m_CollectionAretes.begin(), m_CollectionAretes.end());            //tri croissant de la collection d'arètes

    arbreCouvrant.push_back(m_CollectionAretes.begin());



    return arbreCouvrant;
}
*/



/**
Algorithme de Kruskal pour le coût 1
----------------------------------------------------------------------------------------------------------------------------------------
**/
void Graphe::algoKruskal()
{
    std::vector <Aretes*> arbreCouvrant;            //vecteur dans lequel on insert les arètes utiles

    Aretes *a;


    std::sort(m_CollectionAretes.begin(), m_CollectionAretes.end());            //tri croissant de la collection d'arètes

    arbreCouvrant.push_back(m_CollectionAretes.front());            //on ajoute la première arètes (qui est celle avec le plus petit poids dans l'arbre couvrant)

    //Parcourt du vecteur

    for(size_t i = 0 ; i < m_CollectionAretes.size() ; ++i)
    {


    }



}
