#include "VaisseauLivraison.h"

VaisseauLivraison::VaisseauLivraison(std::string _nom) : Vaisseau(1000, 20, 20, 50, 50,15, 5)
{
	nom = _nom;
}
VaisseauLivraison::~VaisseauLivraison()
{
	//rien
}
std::string VaisseauLivraison::to_string()
{
	return "Je suis le vaisseau de livraison " + nom;
}