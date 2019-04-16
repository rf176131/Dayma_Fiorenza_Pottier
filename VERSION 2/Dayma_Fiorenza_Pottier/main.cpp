#include <iostream>
#include <fstream>
#include "menu.h"
#include "graphe.h"

int main()
{
    //menuConsole();

    Graphe g{"triville.txt"};

    g.afficher();


    Svgfile svgout;



    return 0;
}
