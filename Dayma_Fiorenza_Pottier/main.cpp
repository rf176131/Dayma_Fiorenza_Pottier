#include <iostream>
#include <fstream>
#include "menu.h"
#include "graphe.h"
#include "svgfile.h"

int main()
{
    //menuConsole();

    Svgfile out;

    out.addGrid();

    Graphe g{"triville.txt","trivile_weights_ 1"};

    //menuConsole();

    g.afficher();

//    g.dessiner(out);


    return 0;
}
