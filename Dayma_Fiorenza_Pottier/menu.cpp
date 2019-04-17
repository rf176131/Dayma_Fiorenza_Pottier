#include "menu.h"
#include "console.h"
#include <stdlib.h>

/**
Affichage de l'entête du menu
-------------------------------------------------------------------------------------------------------------------------------
**/
void affichageEnteteMenu()
{
    int n = 29; //variable nbr espaces pour tabulation du texte

    //en_tete menu
    std::cout << std::endl << std::string(n, ' ') << "                ______" << std::endl
              << std::string(n, ' ')              << "               |      |" << std::endl
              << std::string(n, ' ')              << " - - -- -- --- | MENU | --- -- -- - - " << std::endl
              << std::string(n, ' ')              << " |             |______|             |" << std::endl ;

}

/**
Affichage de l'entête bienvenue
-------------------------------------------------------------------------------------------------------------------------------
**/
void affichageEntete()
{
    int n = 10; //variable nbr espaces pour tabulation du texte

    Console console;

    console.setColor(COLOR_GREEN);//couleur affichage console en rouge

    std::cout << std::string(n, ' ') <<  "    ____    ___   _____   _   _  __     __  _____   _   _   _   _   _____  "<< std::endl
              << std::string(n, ' ') <<  "   | __ )  |_ _| | ____| | \\ | | \\ \\   / / | ____| | \\ | | | | | | | ____| "<< std::endl
              << std::string(n, ' ') <<  "   |  _ \\   | |  |  _|   |  \\| |  \\ \\ / /  |  _|   |  \\| | | | | | |  _|   "<< std::endl
              << std::string(n, ' ') <<  "   | |_) |  | |  | |___  | |\\  |   \\ V /   | |___  | |\\  | | |_| | | |___  "<< std::endl
              << std::string(n, ' ') <<  "   |____/  |___| |_____| |_| \\_|    \\_/    |_____| |_| \\_|  \\___/  |_____| "<< std::endl << std::endl;

    console.setColor(COLOR_WHITE);

    std::cout  << std::string(n+25, ' ') <<  " OPTIMISATEUR BI-CRITERE " << std::endl
              << std::string(n+18, ' ') <<  "                  par " << std::endl
              << std::string(n+13, ' ') <<  "Remi Fiorenza & Alexandre Dayma & Louis Pottier " << std::endl;
    console.setColor(COLOR_YELLOW);
    std::cout << "    _ _ __ __ ___ ____ _______________________________________________ ____ ___ ___ __ __ _ _ " << std::endl << std::endl;
    console.setColor(COLOR_WHITE);
    std::cout << "    _ _ __ __ ___ ____ _______________________________________________ ____ ___ ___ __ __ _ _ " << std::endl << std::endl;


}

/**
Affichage de l'entête du menu
-------------------------------------------------------------------------------------------------------------------------------
**/
void menuConsole()
{
    int n = 28; //variable nbr espaces pour tabulation du texte
    int choix; //variables pour choix du menu
    std::string fichier; //nom du fichier étudier
    bool sortie(false); //variable sortie boucle menu

    Console console;

    do //boucle de menu
    {
        affichageEntete();
        //affichage du menu
        std::cout << std::string(n, ' ')<< "|                                      |"<<std::endl
                  << std::string(n, ' ')<< "|  0 - Quitter                         |"<<std::endl
                  << std::string(n, ' ')<< "|                                      |"<<std::endl
                  << std::string(n, ' ')<< "|  1 - Saisir le nom du fichier        |"<<std::endl
                  << std::string(n, ' ')<< "|  2 - Afficher le graphe sur le svg   |"<<std::endl
                  << std::string(n, ' ')<< "|  3 - Lancer l'analyse                |"<<std::endl
                  << std::string(n, ' ')<< "|______________________________________|"<<std::endl <<std::endl << std::string(n+10, ' ')<< " votre choix : ";

        console.setColor(COLOR_RED); //saisie en rouge

        std::cin >> choix; //saisie du choix du menu

        console.setColor(COLOR_WHITE);

        if(choix == 0) //quitter
            sortie = true;

        if(choix == 1) //Saisir le nom du fichier - - - - - - - - - - - - - - - - - - - - - -
        {
            system("cls");
            std::cout << std::endl << std::endl;
            affichageEnteteMenu();
            std::cout << std::endl << std::endl << std::endl << std::endl;
            sortie = false;
            std::cout << "Nom du fichier : ";
            std::cin >> fichier;
            system("pause");

        }
        if(choix == 2)
        {
            Svgfile out;
            Graphe *g;

//            g->dessiner(out);

            std::cout << "Votre graphe a ete dessine avec succes !" << std::endl;



        }
        if(choix == 3)
        {

        }
    }
    while(sortie != true);  //si sortie "true" -> quitter la boucle et donc arriver au return 0 -> quitter programme
}
