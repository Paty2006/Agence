#include "FactionRouge.h"

FactionRouge::FactionRouge(int _attaque, int _defense, int _vie, int _capacite) : Faction(_attaque, _defense, _vie, _capacite)
{
	nom = "Rouge";
}
FactionRouge::FactionRouge() : Faction(2,3,4,5)
{
	nom = "Rouge";
}

FactionRouge::~FactionRouge()
{
	//rien
}
std::string FactionRouge::to_string()
{
	return "Je suis une faction rouge";
}