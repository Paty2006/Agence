#include "VaisseauTransport.h"

VaisseauTransport::VaisseauTransport(std::string _nom) : Vaisseau(1500, 60, 45,40, 60, 1, 0)
{
	nom = _nom;
}
VaisseauTransport::VaisseauTransport(Faction* _faction) : VaisseauTransport("mon Vaisseau Transport De Faction " + _faction->GetNom())
{
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}
VaisseauTransport::VaisseauTransport(Faction* _faction, int _niveau, int _experience) : Vaisseau(1000, 20, 20, 50, 50, _niveau, _experience)
{
	nom = "mon Vaisseau Transport De Faction " + _faction->GetNom(); 
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}
VaisseauTransport::~VaisseauTransport()
{
	//rien
}
std::string VaisseauTransport::to_string()
{

	std::string infoVaisseau = "Je suis le vaisseau de transport " + nom+ "\n";
	infoVaisseau = infoVaisseau + "|Attaque: " + std::to_string(attaque) + "| Defense: " + std::to_string(defense) + "| Vie: " + std::to_string(vie) +
		"| Capacite:  " + std::to_string(capacite) + "| Niveau: " + std::to_string(niveau) + "| Experience: " + std::to_string(exp) + "|\n| Faction: " + faction->GetNom() + " |";
	return infoVaisseau;

}