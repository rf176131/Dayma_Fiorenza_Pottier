#include <iostream>
#include <fstream>
#include "menu.h"
#include "graphe.h"

int main()
{
    //menuConsole();

    Graphe g{"/Users/Work-ING/Desktop/ale/exec/triville.txt","/Users/Work-ING/Desktop/ale/exec/triville_weights_1.txt"};

    g.afficher2();


    Svgfile svgout;



    return 0;
}
