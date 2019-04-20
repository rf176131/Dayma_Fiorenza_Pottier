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
**/
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


}


/**
Destructeur de la classe graphe
----------------------------------------------------------------------------------------------------------------------------------------
**/
Graphe::~Graphe()
{

}


/**
Chargement des fichiers avec deux poids
----------------------------------------------------------------------------------------------------------------------------------------
**/
Graphe::Graphe(std::string nomFichier1,std::string nomFichier2)
{

    std::ifstream ifs{nomFichier1};
    std::ifstream ifs2{nomFichier2}; // lecture des deux fichiers(fichier avec les sommets et celui avec les poids
///***********************************************

    m_CollectionSommets.clear(); // on nettoie les vecteurs
    m_CollectionAretes.clear();
    m_a.clear();


///***********************************************/

    int rep,p;
    ifs2>>rep;
    ifs2>>p;
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier1 );
    int ordre;
    ifs >> ordre;
    m_nbSommet=ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
    {
        ifs>>id; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de l'indice du sommet");  // on lit les identifiants ainsi que les coordonnées des sommets
        ifs>>x; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de la coordonn�e x du sommet");
        ifs>>y; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de la coordonn�e y du sommet");
        m_CollectionSommets.push_back({new Sommet{id,x,y}});
    }
    int taille;
    ifs >> taille;
     m_nArretes=taille;
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
        ifs2>>poid1; // lecture des poids
        ifs2>>poid2;

        m_CollectionAretes.push_back(new Aretes(poid1,poid2,id,id_voisin));


///******************************************************************************************
        m_a.push_back(std::make_pair(poid1,sommet(id,id_voisin))); // remplissage du vecteur contenant les arretes avec le poid 1
        m_e.push_back(std::make_pair(poid2,sommet(id,id_voisin)));

    }


    m_v=new int(taille);
    for (int i = 0; i < taille; i++)  // remplissage du pointeur m_v où m_v[0]=0,...,m_v[i]=i
    {
        m_v[i] = i;
    }
    
    m_w=new int(taille);
    for (int i = 0; i < taille; i++)
    {
        m_w[i] = i;
    }

    ifs.close();
    ifs2.close();


///*******************************************************************************************



}


/**
Affichage console de la fichier avec les deux chargements
----------------------------------------------------------------------------------------------------------------------------------------
**/
/*
void Graphe::afficher2() const
{
    for (size_t i=0; i<m_CollectionAretes.size(); i++)
    {

        m_CollectionAretes[i]->afficher2();
    }
}*/



/**
Affichage du graphe dans un fichier SVG
----------------------------------------------------------------------------------------------------------------------------------------
**/
void Graphe::dessiner(Svgfile &out)
{

    out.addText(500,500, "Poids 1", out.makeRGB(252,47,3));
    out.addText(500,520, "Poids 2", out.makeRGB(32,150,9));

    for(size_t i = 0 ; i < m_CollectionAretes.size() ; ++i)                //parcours du vecteur de sommets
    {
        int id1, id2;           //variables intermédiares
        id1 = m_CollectionAretes[i]->getm_id1();                    //on récupère les coordonnées du premier sommet
        id2 = m_CollectionAretes[i]->getm_id2();                    //on récupère les coordonnées du second sommet
        out.addLine(m_CollectionSommets[id1]->getCoordX(), m_CollectionSommets[id1]->getCoordY(),  m_CollectionSommets[id2]->getCoordX(),  m_CollectionSommets[id2]->getCoordY(), out.makeRGB(0,0,0));          //affichage de la ligne
        out.addText((m_CollectionSommets[id1]->getCoordX() + m_CollectionSommets[id2]->getCoordX())/2-5,(m_CollectionSommets[id1]->getCoordY() + m_CollectionSommets[id2]->getCoordY())/2-5,m_CollectionAretes[i]->getPoids1(), out.makeRGB(252,47,3));         //affichage du premier poids
        out.addText((m_CollectionSommets[id1]->getCoordX() + m_CollectionSommets[id2]->getCoordX())/2+5,(m_CollectionSommets[id1]->getCoordY() + m_CollectionSommets[id2]->getCoordY())/2+5,m_CollectionAretes[i]->getPoids2(), out.makeRGB(32,150,9));         //affichage du second poids

    }

    for(size_t i = 0 ; i < m_CollectionSommets.size() ; ++i)                //parcours du vecteur de sommets
    {
        m_CollectionSommets[i]->dessinerSommet(out);                //on dessine les sommets
    }

}


///***********************************************************************************************************
///***********************************************************************************************************
///***********************************************************************************************************
///***********************************************************************************************************
///***********************************************************************************************************
///***********************************************************************************************************
///***********************************************************************************************************
///***********************************************************************************************************
///***********************************************************************************************************
///***********************************************************************************************************
///***********************************************************************************************************
///***********************************************************************************************************
///***********************************************************************************************************

std::vector<Sommet*> Graphe::getCollectionSommet()
{
    return m_CollectionSommets;
}


Graphe::Graphe(std::string nomFichier2,std::string nomFichier1,int hi) // meme constructeur que le precedents mais ici on implemente les arretes avec le second poids
{
    std::ifstream ifs{nomFichier2};
    std::ifstream ifs2{nomFichier1};
    m_CollectionSommets.clear();
    m_CollectionAretes.clear();
    m_c.clear();
    int rep,p;
    ifs2>>rep;
    ifs2>>p;
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier2 );
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
            throw std::runtime_error("Probleme lecture de la coordonnŽe x du sommet");
        ifs>>y; if(ifs.fail())
            throw std::runtime_error("Probleme lecture de la coordonnŽe y du sommet");
        m_CollectionSommets.push_back(new Sommet(id,x,y));
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
        //lecture des ids des deux extrémités
        ifs>>id;
        ifs>>id_voisin;

        ifs2>>h;
        ifs2>>poid1;
        ifs2>>poid2;
        m_CollectionAretes.push_back(new Aretes(poid1,poid2,id,id_voisin));
        m_c.push_back(std::make_pair(poid2, sommet(id,id_voisin))); // remplissage du vecteur avec poid 2
        m_f.push_back(std::make_pair(poid1, sommet(id,id_voisin)));
    }


    m_v=new int(taille);
    for (int i = 0; i < taille; i++)
    {
        m_v[i] = i;
    }
    
    m_w=new int(taille);
    for (int i = 0; i < taille; i++)
    {
        m_w[i] = i;
    }
    
    
    ifs.close();
    ifs2.close();
}

int Graphe::Trouver_sommet(int a)  //on cherche un sommet present dans le pointeur m_v
{
    if (a == m_v[a])
        return a;
    else

        return Trouver_sommet(m_v[a]); // fonction recursive
}

int Graphe::Trouver_sommet2(int a)  //on cherche un sommet present dans le pointeur m_v
{
    if (a == m_w[a])
        return a;
    else
        
        return Trouver_sommet(m_w[a]); // fonction recursive
}

void Graphe::Union_Sommet(int u, int w)
{
    m_v[u]=m_v[w];
}

void Graphe::Union_Sommet2(int u, int w)
{
    m_w[u]=m_w[w];
}


void Graphe::Kruskal()  // algorithme de Kruskal https://www.programiz.com/dsa/kruskal-algorithm
{
    int i, Rep1, Rep2;
    std::sort(m_a.begin(), m_a.end());// on tri part ordre croissant
    
    for (i = 0; i < m_a.size(); i++) // on parcour tout le vecteur
    {
        Rep1 = Trouver_sommet(m_a[i].second.first);
        Rep2 = Trouver_sommet(m_a[i].second.second);
        if (Rep1 != Rep2)
        {
            m_b.push_back(m_a[i]);
            m_g.push_back(m_e[i]);//on affecte a m_b un vecteur selectionné par l'algorithme
            Union_Sommet(Rep1, Rep2);
        }
    }

}

void Graphe::Kruskal2() // Pareil que le precedent mais avec d'autre vecteur https://www.programiz.com/dsa/kruskal-algorithm
{
     int Rep1, Rep2 ;
    std::sort(m_c.begin(), m_c.end());
    
    for (size_t j = 0; j < m_c.size(); j++)
    {
        Rep1 = Trouver_sommet(m_c[j].second.first);
        Rep2 = Trouver_sommet(m_c[j].second.second);

        if (Rep1 != Rep2)
        {
            m_d.push_back(m_c[j]);
            m_h.push_back(m_f[j]);
            Union_Sommet(Rep1, Rep2);
        }
    }
}


void Graphe::Afficher_Kruskal(Svgfile &out) // on affiche l'algorithme de Kruskal
{
    std::cout<<"Kruskal poids 1" << std::endl;
    std::cout << std::endl;
    std::cout << "Sommet :" << "Poids" << std::endl;
    float poidsTot1=0, poidsTot2 =0;
    
    for (size_t i = 0; i < m_b.size(); i++)// on parcour tout le vecteur pour l'afficher
    {
        int id1 = m_b[i].second.first;
        int id2 = m_b[i].second.second;
        poidsTot1 = poidsTot1 + m_b[i].first;
        poidsTot2 = poidsTot2 + m_g[i].first;
        std::cout << id1 << " - " << id2 << " : "<< m_b[i].first; // on affiche d'abord les sommets puis le poids de l'arretes
        std::cout << std::endl;
        out.addLine(m_CollectionSommets[id1]->getCoordX(), m_CollectionSommets[id1]->getCoordY(),  m_CollectionSommets[id2]->getCoordX(),  m_CollectionSommets[id2]->getCoordY(), out.makeRGB(252,47,3));          //affichage de la ligne
        out.addText((m_CollectionSommets[id1]->getCoordX() + m_CollectionSommets[id2]->getCoordX())/2-5,(m_CollectionSommets[id1]->getCoordY() + m_CollectionSommets[id2]->getCoordY())/2-5,m_b[i].first, out.makeRGB(252,47,3));
        
    }
    std::cout<<"Poid Total : "<<poidsTot1 <<std::endl;
    out.addText(100, 500, poidsTot1,out.makeRGB(252,47,3));
    std::cout<<"Poid Total 2 : "<<poidsTot2 <<std::endl;
    out.addText(150, 500, poidsTot2,out.makeRGB(252,47,3));
}

void Graphe::Afficher_Kruskal2(Svgfile &out) // identique au precedents
{
    std::cout<<"Kruskal poids 2" << std::endl;
    std::cout << std::endl;
    std::cout << "Sommet :" << "Poids" << std::endl;
    float poidsTot = 0, poidsTot2=0;
    for (size_t j = 0; j < m_d.size(); j++)
    {
        int id1 = m_d[j].second.first;
        int id2 = m_d[j].second.second;
        poidsTot = poidsTot + m_d[j].first;
        poidsTot2 = poidsTot2 + m_h[j].first;
        std::cout << m_d[j].second.first << " - " << m_d[j].second.second << " : "
        << m_d[j].first;
        std::cout << std::endl;
        
        out.addLine(m_CollectionSommets[id1]->getCoordX()+500, m_CollectionSommets[id1]->getCoordY(),  m_CollectionSommets[id2]->getCoordX()+500,  m_CollectionSommets[id2]->getCoordY(), out.makeRGB(0,0,0));
        out.addText((m_CollectionSommets[id1]->getCoordX() + m_CollectionSommets[id2]->getCoordX()+1000)/2-5,(m_CollectionSommets[id1]->getCoordY() + m_CollectionSommets[id2]->getCoordY())/2-5,m_d[j].first, out.makeRGB(0,0,0));
    }
    
    std::cout<<"Poid Total  : "<<poidsTot2 <<std::endl;
    out.addText(600, 500, poidsTot2,out.makeRGB(0,0,0));
    std::cout<<"Poid Total 2: "<<poidsTot <<std::endl;
    out.addText(650, 500, poidsTot,out.makeRGB(0,0,0));
}



int Graphe::return_NbSommet()
{
    return m_nbSommet;
}

int Graphe::return_NbArretes()
{
    return m_nArretes;
}


