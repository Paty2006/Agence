#include "VaisseauLivraison.h"


VaisseauLivraison::VaisseauLivraison(std::string _nom) : Vaisseau(1000, 20, 20, 50, 50,1, 0)
{
	nom = _nom;
}
VaisseauLivraison::VaisseauLivraison(Faction* _faction) : VaisseauLivraison("mon Vaisseau Livraison De Faction " + _faction->GetNom())
{
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}
VaisseauLivraison::VaisseauLivraison(Faction* _faction, int _niveau, int _experience): Vaisseau(1000, 20, 20, 50, 50, _niveau, _experience)
{
	nom = "mon Vaisseau Livraison De Faction " + _faction->GetNom();
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}
VaisseauLivraison::~VaisseauLivraison()
{
	//rien
}
std::string VaisseauLivraison::to_string()
{
	std::string infoVaisseau = "Je suis le vaisseau de livraison " + nom  + "\n";
	infoVaisseau = infoVaisseau + "|Attaque: " + std::to_string(attaque) + "| Defense: " + std::to_string(defense) + "| Vie: " + std::to_string(vie) +
		"| Capacite:  " + std::to_string(capacite) + "| Niveau: " + std::to_string(niveau) + "| Experience: " + std::to_string(exp) +"|\n| Faction: " + faction->GetNom() + " |";
	return infoVaisseau;
		
}