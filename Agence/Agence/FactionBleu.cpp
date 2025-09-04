#include "FactionBleu.h"

FactionBleu::FactionBleu(int _attaque, int _defense, int _vie, int _capacite) : Faction( _attaque, _defense, _vie, _capacite)
{
	nom = "Bleu";
}
FactionBleu::FactionBleu() : Faction(5,4,3,2)
{
	nom = "Bleu";
}

FactionBleu::~FactionBleu()
{
	//rien
}
std::string FactionBleu::to_string()
{
	return "Je suis une faction bleue";
}