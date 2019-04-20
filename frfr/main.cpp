//
//  main.cpp
//  frfr
//
//  Created by Work-ING on 19/04/2019.
//  Copyright © 2019 Work-ING. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "menu.h"
#include "graphe.h"
#include "svgfile.h"



std::vector<int> convertisseur (long long unsigned int Decimal)
{
    long long unsigned int Binaire = 2;
    std::vector<int> tab;
    while (Binaire <= Decimal)
    {
        Binaire *= 2;
    }
    
    Binaire /= 2;
    while (Binaire != 0)
    {
        if (Binaire <= Decimal)
        {
            tab.push_back(1);
            Decimal -= Binaire;
        }
        else
        {
            tab.push_back(0);
        }
        Binaire /= 2;
        
    }
    return tab;
}








int main ()
{
    int n = 28;             //variable nbr espaces pour tabulation du texte
    int choix;
    int c=0;//variables pour choix du menu
    std::string fichier1;        //nom du premier fichier ÈtudiÈ
    std::string poidsfichier1;          //nom du fichier contenant les poids du premier fichier
    Svgfile out;

    std::cout << std::string(n, ' ')<< "|                                      |"<<std::endl
    << std::string(n, ' ')<< "|  0 - Quitter                         |"<<std::endl
    << std::string(n, ' ')<< "|  1 - Afficher un graphe              |"<<std::endl
    << std::string(n, ' ')<< "|  2 - Appliquer Kruskal               |"<<std::endl
    << std::string(n, ' ')<< "|  3 - Afficher sur le SVG             |"<<std::endl
    << std::string(n, ' ')<< "|______________________________________|"<<std::endl <<std::endl << std::string(n+10, ' ')<< " votre choix : ";
    std::cin >> choix;
    while (choix!=0)
    {
        
        switch (choix)
        {
                case 1:
            {
                std::cout << std::endl << std::endl;
                std::cout << std::endl << std::endl << std::endl << std::endl;
                std::cout << "Nom du fichier 1: ";
                std::cin >> fichier1;
                
                std::cout << std::endl;
                std::cout << "Nom du fichier contenant les poids du fichier 1: ";
                std::cin >> poidsfichier1;
                
                std::cout << std::endl;
                Graphe g{fichier1,poidsfichier1};
                Graphe h{fichier1,poidsfichier1, c};
                g.dessiner(out);
                h.dessiner(out);
                std::cout << "Votre graphe a ete dessine avec succes !" << std::endl;
            }
                break;
                
            case 2:
            {
                std::cout << std::endl << std::endl;
                std::cout << std::endl << std::endl << std::endl << std::endl;
                std::cout << "Nom du fichier 1: ";
                std::cin >> fichier1;
                
                std::cout << std::endl;
                std::cout << "Nom du fichier contenant les poids du fichier 1: ";
                std::cin >> poidsfichier1;
                
                std::cout << std::endl;
                Graphe g{fichier1,poidsfichier1};
                Graphe h{fichier1,poidsfichier1, c};
                g.Kruskal();
                h.Kruskal2();
                g.Afficher_Kruskal(out);
                h.Afficher_Kruskal2(out);
            }break;
            case 3:
            {
                
                    std::vector<int> tab;
                    std::vector<int> tab2;
                    Graphe g("/Users/Alex/Desktop/frfr/frfr/broadway.txt","//Users/Alex/Desktop/frfr/frfr/broadway_weights_0.txt");
                    int nb_sommet=g.return_NbSommet();
                    double nb_Arretes = g.return_NbArretes();
                    std::vector<std::pair<int,Aretes*>> List;
                    std::vector<std::vector<int>> Matrix;
                    std::vector<std::vector<int>> Matrix2;
                    long long unsigned int Decimal=std::pow(2, nb_Arretes);
                    
                    for (long long unsigned int i=0; i<std::pow(2, nb_Arretes); i++)
                    {
                        tab=convertisseur(Decimal);
                        Decimal++;
                        tab.erase(tab.begin());
                        Matrix.push_back(tab);
                        
                    }
                    
                    for (int a=0; a<Matrix.size(); a++)
                    {
                        int c=0;
                        size_t o = Matrix[a].size();
                        for (int f=0; f<Matrix[a].size(); f++)
                        {
                            if (Matrix[a][f]==1)
                            {
                                c++;
                            }
                            
                        }
                        if (c!=(nb_sommet-1))
                        {
                            for (size_t z=0; z<o; z++)
                            {
                                Matrix[a].erase(Matrix[a].begin());
                            }
                            
                        }
                        
                    }
                    
                    for (size_t i=0; i<Matrix.size(); i++)
                    {
                        for (size_t j=0; j<Matrix[i].size(); j++)
                        {
                            std::cout<<Matrix[i][j];
                        }
                        std::cout<<std::endl;
                    }
                    
                    
                
            }
                break;
                
            default:
                break;
        }
        std::cout << std::string(n, ' ')<< "|                                      |"<<std::endl
        << std::string(n, ' ')<< "|  0 - Quitter                         |"<<std::endl
        << std::string(n, ' ')<< "|  1 - Afficher un graphe              |"<<std::endl
        << std::string(n, ' ')<< "|  2 - Appliquer Kruskal               |"<<std::endl
        << std::string(n, ' ')<< "|  3 - Afficher sur le SVG             |"<<std::endl
        << std::string(n, ' ')<< "|______________________________________|"<<std::endl <<std::endl << std::string(n+10, ' ')<< " votre choix : ";
        std::cin >> choix;
    }
    
    
}
