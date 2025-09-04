#include "VaisseauTransport.h"

VaisseauTransport::VaisseauTransport(std::string _nom) : Vaisseau(1500, 60, 45,40, 60, 20, 7)
{
	nom = _nom;
}
VaisseauTransport::~VaisseauTransport()
{
	//rien
}
std::string VaisseauTransport::to_string()
{
	return "Je suis le vaisseau de transport " + nom;
}