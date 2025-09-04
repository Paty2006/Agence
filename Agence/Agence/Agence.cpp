// Agence.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Faction.h"
#include "FactionRouge.h"
#include "FactionBleu.h"
#include "Vaisseau.h"
#include "VaisseauGuerre.h"
#include "VaisseauLivraison.h"
#include "VaisseauTransport.h"

int main()
{
    std::cout << "Hello World!\n";

    VaisseauGuerre monVaisseauGuerre( "Arthur" );
    VaisseauLivraison monVaisseauLivraison("Larissa");
    VaisseauTransport  monVaisseauTransport("Dallas");

    FactionRouge maFactionRouge(5, 5, 5, 5);
    FactionBleu maFactionBleu;

    std::cout << "Hello " << maFactionRouge.GetNom() << " , tu es ma nouvelle faction rouge\n";
    std::cout << "Hello " << maFactionBleu.GetNom() << " , tu es ma nouvelle faction bleu\n";

    std::cout << "Hello, " << monVaisseauGuerre.to_string() << "\n";
    std::cout << "Hello, " << monVaisseauLivraison.to_string() << "\n";
    std::cout << "Hello, " << monVaisseauTransport.to_string() << "\n";

    
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
