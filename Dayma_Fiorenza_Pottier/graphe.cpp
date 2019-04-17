#include "graphe.h"
#include "svgfile.h"

/**
Sous-programme de chargement du graphe, cette méthode est fortement inspirée du TP2 écrit par Madame Palasi
----------------------------------------------------------------------------------------------------------------------------------------
**//*
Graphe::Graphe(std::string nomFichier)
{

    //std::ifstream("triville.txt", std::ios::in); POUR tester l'ouverture
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
    {
        ifs>>id; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de l'indice du sommet");
        ifs>>x; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de la coordonnée x du sommet");
        ifs>>y; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de la coordonnée y du sommet");
        m_CollectionSommets.push_back({new Sommet{id,x,y}});
    }
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    int id_voisin;
    int id_voisin2;
    //lecture des aretes
    for (int i=0; i<taille; ++i){
        ifs>>id_voisin2;
        //lecture des ids des deux extrémités
        ifs>>id; if(ifs.fail())
            throw std::runtime_error("Probleme lecture du premier sommet de l'arete");
        ifs>>id_voisin; if(ifs.fail())
            throw std::runtime_error("Probleme lecture du second sommet de l'arete");
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)

        m_CollectionAretes.push_back({new Aretes()})


        //(m_CollectionSommets.find(id))->second->ajouterVoisin((m_CollectionSommets.find(id_voisin))->second);
        //(m_CollectionSommets.find(id_voisin))->second->ajouterVoisin((m_CollectionSommets.find(id))->second);//remove si graphe orienté
    }
}*/



/**
Affichage du graphe
----------------------------------------------------------------------------------------------------------------------------------------
**//*
void Graphe::afficher() const
{
    std::cout <<"Graphe : \n "<<std::endl;
///    std::cout << "Ordre du graphe : " << m_sommets.size() << "\n" <<std::endl ;

    for (auto &it : m_CollectionSommets)
    {
        std::cout << "Sommet :" ;
        it->afficherData() ;
        it->afficherVoisins();
        std::cout << std::endl ;
    }


}*/


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
**//*
void Graphe::algoKruskal()
{
    std::vector <Aretes*> arbreCouvrant;            //vecteur dans lequel on insert les arètes utiles

//    Aretes *a;


    std::sort(m_CollectionAretes.begin(), m_CollectionAretes.end());            //tri croissant de la collection d'arètes

    arbreCouvrant.push_back(m_CollectionAretes.front());            //on ajoute la première arètes (qui est celle avec le plus petit poids dans l'arbre couvrant)

    //Parcourt du vecteur

    for(size_t i = 0 ; i < m_CollectionAretes.size() ; ++i)
    {


    }
}*/




/**
Chargement des fichiers avec deux poids
----------------------------------------------------------------------------------------------------------------------------------------
**/
Graphe::Graphe(std::string nomFichier1,std::string nomFichier2)
{

    std::ifstream ifs{nomFichier1};
    std::ifstream ifs2{nomFichier2};

   // std::vector <int> collectionAnnexe;
   //int x1, x2, y1, y2;             ///

    int rep,p;
    ifs2>>rep;
    ifs2>>p;
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier1 );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
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
        m_CollectionSommets.push_back({new Sommet{id,x,y}});
        //        svgout.addDisk(x,y,10, (r,v,b) );
    }
    int taille;
    ifs >> taille;
    int id_voisin;
    int id_voisin2;
    float poid1,poid2;
    int h;

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
     //   x1 = collectionAnnexe[(3*id_voisin2) + 1];                  ///
       // x2 = collectionAnnexe[(3*id) + 1];                          ///
        //y1 = collectionAnnexe[(3*id_voisin2) + 1];                  ///
        //y2 = collectionAnnexe[(3*id) + 1];                          ///
        m_CollectionAretes.push_back(new Aretes(poid1,poid2,id,id_voisin));

        //collectionAnnexe.push_back( new Aretes{poid1,poid2,x1, y1, x2, y2});             ///


        //Aretes(float poids1, float poids2, Sommet *s1, Sommet *s2);
        //m_CollectionAretes.push_

    }
}


/**
Affichage console de la fichier avec les deux chargements
----------------------------------------------------------------------------------------------------------------------------------------
**/

void Graphe::afficher2() const
{
    for (size_t i=0; i<m_CollectionAretes.size(); i++)
    {

        m_CollectionAretes[i]->afficher2();
    }
}



/**
Affichage du graphe danq un fichier SVG
----------------------------------------------------------------------------------------------------------------------------------------
**/
void Graphe::dessiner(Svgfile &out)
{

    for(size_t i = 0 ; i < m_CollectionAretes.size() ; ++i)                //parcours du vecteur de sommets
    {
        int id1, id2;           //variables intermédiares
        id1 = m_CollectionAretes[i]->getm_id1();                    //on récupère les coordonnées du premier sommet
        id2 = m_CollectionAretes[i]->getm_id2();                    //on récupère les coordonnées du second sommet
        out.addLine(m_CollectionSommets[id1]->getCoordX(), m_CollectionSommets[id1]->getCoordY(),  m_CollectionSommets[id2]->getCoordX(),  m_CollectionSommets[id2]->getCoordY(), out.makeRGB(0,0,0));          //affichage de la ligne
    }

    for(size_t i = 0 ; i < m_CollectionSommets.size() ; ++i)                //parcours du vecteur de sommets
    {
        m_CollectionSommets[i]->dessinerSommet(out);                //on dessine les sommets

    }

}








