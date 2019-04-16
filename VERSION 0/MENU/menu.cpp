#include <iostream>
#include "menu.h"

void affichage_entete()
{
    int n = 10; //variable nbr espaces pour tabulation du texte

    std::cout << std::string(n, ' ') <<  "    ____    ___   _____   _   _  __     __  _____   _   _   _   _   _____  "<< std::endl
              << std::string(n, ' ') <<  "   | __ )  |_ _| | ____| | \\ | | \\ \\   / / | ____| | \\ | | | | | | | ____| "<< std::endl
              << std::string(n, ' ') <<  "   |  _ \\   | |  |  _|   |  \\| |  \\ \\ / /  |  _|   |  \\| | | | | | |  _|   "<< std::endl
              << std::string(n, ' ') <<  "   | |_) |  | |  | |___  | |\\  |   \\ V /   | |___  | |\\  | | |_| | | |___  "<< std::endl
              << std::string(n, ' ') <<  "   |____/  |___| |_____| |_| \\_|    \\_/    |_____| |_| \\_|  \\___/  |_____| "<< std::endl << std::endl;
    std::cout  << std::string(n+25, ' ') <<  " OPTIMISATEUR BI-CRITERE " << std::endl
              << std::string(n+18, ' ') <<  "                  par " << std::endl
              << std::string(n+13, ' ') <<  "Remi Fiorenza & Alexandre Dayma & Louis Pottier " << std::endl;
    std::cout << "    _ _ __ __ ___ ____ _______________________________________________ ____ ___ ___ __ __ _ _ " << std::endl << std::endl;
    std::cout << std::endl << std::string(n+17, ' ') << "                  ______" << std::endl
              << std::string(n+17, ' ')              << "                 |      |" << std::endl
              << std::string(n+17, ' ')              << "  ______________ | MENU | ______________ " << std::endl
              << std::string(n+17, ' ')              << " |               |______|               |" << std::endl ;

}

void menu_console()
{
    int n = 28; //variable nbr espaces pour tabulation du texte
    int choix; //variables pour choix du menu
    std::string fichier; //nom du fichier étudier
    bool sortie(false); //variable sortie boucle menu

    do //boucle de menu
    {
        affichage_entete();
        //affichage du menu
        std::cout << std::string(n, ' ')<< "|                                      |"<<std::endl
                  << std::string(n, ' ')<< "|  0 - Quitter                         |"<<std::endl
                  << std::string(n, ' ')<< "|                                      |"<<std::endl
                  << std::string(n, ' ')<< "|  1 - Saisir le nom du fichier        |"<<std::endl
                  << std::string(n, ' ')<< "|______________________________________|"<<std::endl <<std::endl << std::string(n+10, ' ')<< " votre choix : ";

        std::cin >> choix; //saisie du choix du menu

        if(choix == 0) //quitter
            sortie = true;

        if(choix == 1) //Saisir le nom du fichier - - - - - - - - - - - - - - - - - - - - - -
        {
            sortie = false;
            std::cout << "Nom du fichier : ";
            std::cin >> fichier;
            system("pause");
        }
    }
    while(sortie != true);  //si sortie "true" -> quitter la boucle et donc arriver au return 0 -> quitter programme
}
