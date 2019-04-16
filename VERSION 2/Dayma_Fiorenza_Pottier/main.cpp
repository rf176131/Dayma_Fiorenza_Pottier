#include <iostream>
#include <fstream>
#include "menu.h"
#include "graphe.h"

int main()
{
    //menuConsole();

    Graphe g{"triville.txt"};

    g.afficher();
    g.algoKruskal();



    Svgfile svgout;



    return 0;
}
