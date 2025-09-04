#include "VaisseauGuerre.h"

VaisseauGuerre::VaisseauGuerre(std::string _nom) : Vaisseau(2000, 80, 70, 30, 20, 40, 4)
{
	nom = _nom;
}
VaisseauGuerre::~VaisseauGuerre()
{
	//rien
}
std::string VaisseauGuerre::to_string()
{
	return "Je suis le vaisseau de guerre " + nom ;
}