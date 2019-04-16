#include "graphe.h"
#include "svgfile.h"

/**
Sous-programme de chargement du graphe, cette m�thode est fortement inspir�e du TP2 �crit par Madame Palasi
----------------------------------------------------------------------------------------------------------------------------------------
**/
Graphe::Graphe(std::string nomFichier)
{
    Svgfile svgout;
    uint8_t r,v,b;
    r = 121;
    v = 248;
    b = 248;

    //std::ifstream("triville.txt", std::ios::in); POUR tester l'ouverture
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
    for (int i=0; i<ordre; ++i)
    {
        ifs>>id; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de l'indice du sommet");
        ifs>>x; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de la coordonn�e x du sommet");
        ifs>>y; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de la coordonn�e y du sommet");
        m_CollectionSommets.insert({id,new Sommet{id,x,y}});
//        svgout.addDisk(x,y,10, (r,v,b) );
    }
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    std::string id_voisin;
    std::string id_voisin2;
    //lecture des aretes
    for (int i=0; i<taille; ++i){
        ifs>>id_voisin2;
        //lecture des ids des deux extr�mit�s
        ifs>>id; if(ifs.fail())
            throw std::runtime_error("Probleme lecture du premier sommet de l'arete");
        ifs>>id_voisin; if(ifs.fail())
            throw std::runtime_error("Probleme lecture du second sommet de l'arete");
        //ajouter chaque extr�mit� � la liste des voisins de l'autre (graphe non orient�)
        (m_CollectionSommets.find(id))->second->ajouterVoisin((m_CollectionSommets.find(id_voisin))->second);
        (m_CollectionSommets.find(id_voisin))->second->ajouterVoisin((m_CollectionSommets.find(id))->second);//remove si graphe orient�
    }
}



/**
Affichage du graphe
----------------------------------------------------------------------------------------------------------------------------------------
**/
void Graphe::afficher() const{
    std::cout <<"Graphe : \n "<<std::endl;
///    std::cout << "Ordre du graphe : " << m_sommets.size() << "\n" <<std::endl ;

    for (auto &it : m_CollectionSommets)
    {
        std::cout << "Sommet :" ;
        it.second->afficherData() ;
        it.second->afficherVoisins();
        std::cout << std::endl ;
    }


}


/**
Destructeur de la classe graphe
----------------------------------------------------------------------------------------------------------------------------------------
**/
Graphe::~Graphe()
{

}


/**
Algorithme de Kruskal pour le co�t 1
----------------------------------------------------------------------------------------------------------------------------------------
**/
void Graphe::algoKruskal()
{
    std::vector <Aretes*> arbreCouvrant;            //vecteur dans lequel on insert les ar�tes utiles

    Aretes *a;


    std::sort(m_CollectionAretes.begin(), m_CollectionAretes.end());            //tri croissant de la collection d'ar�tes

    arbreCouvrant.push_back(m_CollectionAretes.front());            //on ajoute la premi�re ar�tes (qui est celle avec le plus petit poids dans l'arbre couvrant)

    //Parcourt du vecteur

    for(size_t i = 0 ; i < m_CollectionAretes.size() ; ++i)
    {


    }



}

Graphe::Graphe()
{
    
}

std::unordered_map<std::string,Sommet*> Graphe::retour()
{
    return m_CollectionSommets;
}

Graphe::Graphe(std::string nomFichier1,std::string nomFichier2)
{
    std::ifstream ifs{nomFichier1};
    std::ifstream ifs2{nomFichier2};
    int rep,p;
    ifs2>>rep;
    ifs2>>p;
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier1 );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    std::string id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
    {
        ifs>>id; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de l'indice du sommet");
        ifs>>x; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de la coordonn�e x du sommet");
        ifs>>y; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de la coordonn�e y du sommet");
        m_CollectionSommets.insert({id,new Sommet{id,x,y}});
        //        svgout.addDisk(x,y,10, (r,v,b) );
    }
    int taille;
    ifs >> taille;
    std::string id_voisin;
    std::string id_voisin2;
    float poid1,poid2;
    std::string h,S1,S2;
   
    //lecture des aretes
    for (int i=0; i<taille; ++i)
    {
        ifs>>id_voisin2;
        //lecture des ids des deux extr�mit�s
        ifs>>id;
        ifs>>id_voisin;
        
        ifs2>>h;
        ifs2>>poid1;
        ifs2>>poid2;
        m_CollectionAretes.push_back(new Aretes(poid1,poid2,id,id_voisin));
        
        (m_CollectionSommets.find(id))->second->ajouterVoisin((m_CollectionSommets.find(id_voisin))->second);
        (m_CollectionSommets.find(id_voisin))->second->ajouterVoisin((m_CollectionSommets.find(id))->second);
    }
}

void Graphe::afficher2()
{
    for (int i=0; i<m_CollectionAretes.size(); i++)
    {
        m_CollectionAretes[i]->afficher2();
    }
}
