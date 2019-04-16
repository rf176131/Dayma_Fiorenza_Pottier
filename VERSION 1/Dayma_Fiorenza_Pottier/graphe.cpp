#include "graphe.h"

/**
Sous-programme de chargement du graphe
----------------------------------------------------------------------------------------------------------------------------------------
**/
Graphe::Graphe(std::string nomFichier){
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    std::string id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifs>>id;
        ifs>>x;
        ifs>>y;
        ///m_sommets.insert({id, new Sommet{id,x,y}});
        int taille;
        ifs >> taille;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture taille du graphe");
        std::string id_voisin;
        //lecture des aretes
        for (int i=0; i<taille; ++i){
            //lecture des ids des deux extrémités
            ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
            ifs>>id_voisin; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
            //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
///            (m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
           /// (m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté
        }
    }

    }


/**
Affichage du graphe
----------------------------------------------------------------------------------------------------------------------------------------
**/
void Graphe::afficher() const{
    std::cout <<"Graphe : \n "<<std::endl;
///    std::cout << "Ordre du graphe : " << m_sommets.size() << "\n" <<std::endl ;

/*    for (auto &it : m_sommets)
    {
        std::cout << "Sommet :" ;
        it.second->afficherData() ;
        it.second->afficherVoisins();
        std::cout << std::endl ;
    }*/


}


/**
Destructeur de la classe graphe
----------------------------------------------------------------------------------------------------------------------------------------
**/
Graphe::~Graphe()
{

}


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
