#include <iostream>
#include <fstream>
#include "menu.h"
#include "graphe.h"

int main()
{
    //menuConsole();

    Graphe g{"/Users/Work-ING/Desktop/Project#9/Project#9/triville.txt","/Users/Work-ING/Desktop/Project#9/Project#9/triville_weights_1.txt"};

    g.afficher2();


    Svgfile svgout;



    return 0;
}
