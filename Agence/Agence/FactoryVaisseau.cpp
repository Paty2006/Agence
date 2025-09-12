#include "FactoryVaisseau.h"
#include "Utilitaire.h"
#include "FactionRouge.h"
#include "FactionBleu.h"
#include "VaisseauGuerre.h"
#include "VaisseauLivraison.h"
#include "VaisseauTransport.h"
#include "Faction.h"

Vaisseau* FactoryVaisseau::getRandomVaisseau()
{
	Vaisseau* vaisseau(0);
	Faction* maFaction = getRandomFaction();

	int niveau = 1;
	int experience = 0;
	Rang rang = (Rang)Utilitaire::genererNb(1, 3);
	if (rang == Rang::Junior)
	{
		niveau = Utilitaire::genererNb(1, 15);
		experience = Utilitaire::genererNb(1, 30);
	}
	else if (rang == Rang::Senior)
	{
		niveau = Utilitaire::genererNb(16, 30);
		experience = Utilitaire::genererNb(31, 60);
	}
	else
	{
		niveau = Utilitaire::genererNb(31, 50);
		experience = Utilitaire::genererNb(61, 100);
	}
	
	int  typeV = Utilitaire::genererNb(1, 3);
	if (typeV == 1)
		vaisseau = new VaisseauGuerre(maFaction, niveau, experience);
	else if (typeV == 2)
		vaisseau = new VaisseauLivraison(maFaction,niveau, experience);
	else
		vaisseau = new VaisseauTransport(maFaction, niveau, experience);

	return vaisseau;
}

Faction* FactoryVaisseau::getRandomFaction()
{
	int typeF = Utilitaire::genererNb(1, 2);
	Faction* maFaction(0);
	
	if (typeF == 1)
		maFaction = new FactionRouge;
	else
		maFaction = new FactionBleu;

	return maFaction;
}