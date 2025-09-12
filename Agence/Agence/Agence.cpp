// Agence.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <ctime>
#include "Faction.h"
#include "FactionBleu.h"
#include "FactionRouge.h"
#include "FactoryVaisseau.h"
#include "Station.h"
#include "Utilitaire.h"
#include "Vaisseau.h"
#include "VaisseauGuerre.h"
#include "VaisseauLivraison.h"
#include "VaisseauTransport.h"
#include <string>
using std::vector;




int main()
{

    std::cout << "Hello World!\n";

    srand(time(NULL));
   
    std::cout << "...production d'un vaisseau" << std::endl;
    Vaisseau* monVaisseau = FactoryVaisseau::getRandomVaisseau();
    std::cout << monVaisseau->to_string();
    std::cout << "...production d'un vaisseau terminée" << std::endl;


    std::cout << "...production d'une station" << std::endl;
    Station* station = new Station(100, 10);
    std::cout << "...production d'une station terminée" << std::endl;

    station->init();
    std::cout << "la station compte " << station->getVaisseauDispo().size() << " vaisseau(x) " << std::endl;

    station->ajouterVaisseau(monVaisseau);
    std::cout << "la station compte " << station->getVaisseauDispo().size() << " vaisseau(x) " << std::endl;
    //trouver comment afficher les infos de chaque vaisseau de la statio
    vector<Vaisseau*> vecteurVaisseau(station->getVaisseauDispo());

    for (auto it = vecteurVaisseau.begin(); it < vecteurVaisseau.end(); it++)
    {
        std::cout << (*it)->to_string() << std::endl;
    }


    delete monVaisseau;
    
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
