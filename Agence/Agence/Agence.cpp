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
#include <conio.h>
using std::vector;


//DÉCLARATION DES VARIABLES GLOBALES

std::vector<Vaisseau*> vecVaisseauDispoAAchat;
std::vector<Vaisseau*> vecVaisseauEnExploration;
std::vector<int> tourRetourDExploration;
std::vector<int> tourDepartEnExploration;


int numeroTour = 1;

//PROTOTYPES
void PasserTour();
void VoirInfoStation(Station* station);
void VoirListeVaisseauDispo(Station* station);
void AcheterVaisseau(int index, Station* station);
void AcheterVaisseau(Station* station);
void EnvoyerEnExploration(int index, Station* station);
void EnvoyerVaisseauEnExploration(Station* station);
void RentrerDExploration(int index, Station* station);
void AfficherMenu(Station* station);




// DÉCLARATION DU MAIN

int main()
{
	Utilitaire::AfficherImageDebut();
	std::cout << "BIENVENUE AU JEU DE L'AGENCE SPATIALE!!!\n";

    srand(time(NULL));
   
    Station station(100000, 100);
    station.init();

	std::cout << "PESEZ SUR UNE TOUCHE POUR COMMENCER\n";
	_getch();

	while (numeroTour <= station.getVie())
	{
		system("CLS");

		std::cout << "\n\nTour " << numeroTour << "\n";

		//verifier si un vaisseau revient d'exploration
		for (int i = 0; i < tourRetourDExploration.size(); i++)
		{
			if (numeroTour == tourRetourDExploration[i])
			{
				RentrerDExploration(i, &station);
			}
		}

		AfficherMenu(&station);
	}

	std::cout << "LA PARTIE EST TERMINEE!!\n";

	for (Vaisseau* v : vecVaisseauDispoAAchat)
	{
		delete v;
		v = nullptr;
	}

	for (Vaisseau* v : vecVaisseauEnExploration)
	{
		delete v;
		v = nullptr;
	}

}




//DÉCLARATION DES FONCTIONS
void PasserTour()
{
	numeroTour = numeroTour + 1;
}

void VoirInfoStation(Station* station)
{

	std::cout << station->to_string() << std::endl;


	PasserTour();
	std::cout << "Pesez sur une touche pour continuer" << std::endl;
	_getch();
}

void VoirListeVaisseauDispo(Station* station)
{
	std::cout << "\nVOICI LA LISTE DE VOS VAISSEAUX\n" << std::endl;

	for (auto vaisseau : station->getVaisseauDispo())
	{
		std::cout << vaisseau->to_string() << std::endl;
	}
	PasserTour();
	std::cout << "Pesez sur une touche pour continuer" << std::endl;
	_getch();
}

void AcheterVaisseau(int index, Station* station)
{
	//verifier sil dispose d'assez de platinum pour acheter le vaisseau
	if (station->getPlatinum() >= vecVaisseauDispoAAchat[index]->GetValeur())
	{
		//déduire le montant du vaisseau de la RÉSERVE DE PLATINUM
		station->setPlatinum(station->getPlatinum() - vecVaisseauDispoAAchat[index]->GetValeur());

		// ajouter le vaisseau achete à la liste des vaisseaux dispo
		station->ajouterVaisseau(vecVaisseauDispoAAchat[index]);

		//enlever le vaisseau acheté de la liste des vaisseaux à acheter

		vecVaisseauDispoAAchat.erase(vecVaisseauDispoAAchat.begin() + index);

		std::cout << "Felicitations, vous venez d'acheter un nouveau vaisseau" << std::endl;

		PasserTour();
	}
	else
	{
		std::cout << "Vous ne disposez pas d'assez de platinum pour acheter ce vaisseau" << std::endl;

	}

}

void AcheterVaisseau(Station* station)
{
	std::cout << "\nVOICI LA LISTE DES VAISSEAUX DISPONIBLES A L ACHAT\n" << std::endl;

	int numeroVaisseau = 1;
	for (auto vaisseau : vecVaisseauDispoAAchat)
	{
		std::cout << numeroVaisseau << ") " << vaisseau->to_string() << std::endl;
		numeroVaisseau = numeroVaisseau + 1;
	}

	std::cout << "\nEntrez le numero correspondant au Vaisseau que vous voulez acheter ou autre chose si vous avez change d'avis\n" << std::endl;

	int entree;
	if (std::cin >> entree)
	{
		if (entree <= 5 && entree >= 1)
		{
			AcheterVaisseau(entree - 1, station);
		}
		else
		{
			std::cout << "Aucun vaisseau n'a ete choisi" << std::endl;
		}

	}
	else
	{
		std::cout << "Aucun vaisseau n'a ete choisi" << std::endl;
	}
	std::cout << "Pesez sur une touche pour continuer" << std::endl;
	_getch();
}

void EnvoyerEnExploration(int index, Station* station)
{
	//ajouter le vaisseau dans le vecteur de vaisseaux en exploration
	vecVaisseauEnExploration.push_back(station->getVaisseauDispo()[index]);

	//le retirer du vecteur de vaisseau disponibles dans la station

	station->supprimerVaisseau(index);

	//déterminer aléatoirement son nombre de tours
	int nombreTourExploration = Utilitaire::genererNb(2, 5);

	//consigner son  tour  de retour dans le vecteur de date de retour d'exploration
	tourRetourDExploration.push_back(numeroTour + nombreTourExploration);

	//consigner son  tour  de depart dans le vecteur de date de depart en exploration
	tourDepartEnExploration.push_back(numeroTour);

	std::cout << "Ce vaisseau est a ete envoye en exploration sans accros!" << std::endl;


}

void EnvoyerVaisseauEnExploration(Station* station)
{
	std::cout << "\nVOICI LA LISTE DES VAISSEAUX DISPONIBLES DANS LA STATION\n" << std::endl;

	int numeroVaisseau = 1;
	for (auto vaisseau : station->getVaisseauDispo())
	{
		std::cout << numeroVaisseau << ") " << vaisseau->to_string() << std::endl;
		numeroVaisseau = numeroVaisseau + 1;
	}

	std::cout << "\nEntrez le numero correspondant au Vaisseau que vous voulez envoyer en exploration \nou autre chose si vous avez change d'avis\n" << std::endl;

	int entree;
	if (std::cin >> entree)
	{
		if (entree <= 5 && entree >= 1)
		{
			EnvoyerEnExploration(entree - 1, station);
			PasserTour();
		}
		else
		{
			std::cout << "Aucun vaisseau n'a ete choisi" << std::endl;
		}

	}
	else
	{
		std::cout << "Aucun vaisseau n'a ete choisi" << std::endl;
	}
	std::cout << "Pesez sur une touche pour continuer" << std::endl;
	_getch();
}

void RentrerDExploration(int index, Station* station)
{
	//l'ajouter aux vaisseaux disponibles dans la station
	station->ajouterVaisseau(vecVaisseauEnExploration[index]);

	std::cout << vecVaisseauEnExploration[index]->GetNom() << " est rentre d'exploration " << std::endl;

	// verifier si il a ramené des ressources en se basant sur le nombre de tours d'exploration
	int aleatoire = Utilitaire::genererNb(1, 10);
	int nombreTourEnExploration = tourRetourDExploration[index] - tourDepartEnExploration[index];
	bool ramenerRessource = false;

	if ((aleatoire < 2 && nombreTourEnExploration == 2) || (aleatoire < 4 && nombreTourEnExploration == 3) ||
		(aleatoire < 6 && nombreTourEnExploration == 4) || (aleatoire < 9 && nombreTourEnExploration == 5))
	{
		ramenerRessource = true;
		std::cout << "\nIl a ramene des ressources de son exploration!\n";
		// si oui, les ajouter au platinum de la station
		int platinumRamene = Utilitaire::genererNb(100, 500);
		std::cout << "\nVous gagnez " << platinumRamene << " platinum de plus!\n";
		station->setPlatinum(station->getPlatinum() + platinumRamene);

	}
	else
		std::cout << "\nMalheureusement, il n'a trouve aucune ressource durant son exploration!\n";


	//le retirer du vecteur de vaisseau en exploration

	vecVaisseauEnExploration.erase(vecVaisseauEnExploration.begin() + index);

	//retirer la date correspondante dans le vecteur tour de retour
	tourRetourDExploration.erase(tourRetourDExploration.begin() + index);

	//retirer la date correspondante dans le vecteur tour de depart
	tourDepartEnExploration.erase(tourDepartEnExploration.begin() + index);
}

void AfficherMenu(Station* station)
{

	//on génère des vaisseaux pouvant etre achetés(il y en aura toujours 5 de disponibles
	while (vecVaisseauDispoAAchat.size() < 5)
	{
		vecVaisseauDispoAAchat.push_back(FactoryVaisseau::getRandomVaisseau());
	}


	std::cout << "\nQue souhaitez vous faire? \n\n";

	std::cout << "1)Voir les informations de la station" << std::endl;
	std::cout << "2)Voir la liste des Vaisseaux disponibles dans la station" << std::endl;
	std::cout << "3)Acheter un Vaisseau " << std::endl;
	std::cout << "4)Envoyer un vaisseau en exploration " << std::endl;
	std::cout << "5)Passer un tour " << std::endl;

	int entree;

	if (std::cin >> entree)
	{
		switch (entree)
		{
		case 1:
			VoirInfoStation(station);
			break;
		case 2:
			VoirListeVaisseauDispo(station);
			break;
		case 3:
			AcheterVaisseau(station);
			break;
		case 4:
			EnvoyerVaisseauEnExploration(station);
			break;
		case 5:
			PasserTour();
			break;
		default:
			std::cout << "Vous avez entre un nombre invalide" << std::endl;
			break;
		}

	}
	else
	{
		std::cout << "Vous n'avez pas entre un nombre" << std::endl;
	}
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
