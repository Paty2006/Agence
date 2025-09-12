#include "Faction.h"
class Vaisseau;
Faction::Faction(int _attaque, int _defense, int _vie, int _capacite) : nom("maFaction")
{
	attaque = _attaque;
	defense = _defense;
	vie = _vie;
	capacite = _capacite;
}

Faction::Faction()
{
	attaque = 0;
	defense = 0;
	vie = 0;
	capacite = 0;
	nom = "maFaction";
}

Faction::~Faction()
{
	//rien
}
int Faction::GetAtt()
{
	return attaque;
}
int Faction::GetDef()
{
	return defense;
}
int Faction::GetVie()
{
	return vie;
}
int Faction::GetCapacite()
{
	return capacite;
}

std::string Faction::GetNom()
{
	return nom;
}
std::string Faction::to_string()
{
	return "Je suis une faction";
}