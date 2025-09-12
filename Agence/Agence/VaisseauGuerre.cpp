#include "VaisseauGuerre.h"

VaisseauGuerre::VaisseauGuerre(std::string _nom) : Vaisseau(2000, 80, 70, 30, 20, 1, 0)
{
	nom = _nom;
}
VaisseauGuerre::VaisseauGuerre(Faction* _faction) : VaisseauGuerre("mon Vaisseau Guerre De Faction " + _faction->GetNom())
{
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}

VaisseauGuerre::VaisseauGuerre(Faction* _faction, int _niveau, int _experience): Vaisseau(2000, 80, 70, 30, 20, _niveau, _experience)
{
	nom = "mon Vaisseau Guerre De Faction " + _faction->GetNom();
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}
VaisseauGuerre::~VaisseauGuerre()
{
	//rien
}
std::string VaisseauGuerre::to_string()
{
	
	std::string infoVaisseau = "Je suis le vaisseau de guerre " + nom + "\n";
	infoVaisseau = infoVaisseau + "|Attaque: " + std::to_string(attaque) + "| Defense: " + std::to_string(defense) + "| Vie: " + std::to_string(vie) +
		"| Capacite:  " + std::to_string(capacite) + "| Niveau: " + std::to_string(niveau) + "| Experience: " + std::to_string(exp) + "|\n| Faction: " + faction->GetNom() + " |";
	return infoVaisseau;
}