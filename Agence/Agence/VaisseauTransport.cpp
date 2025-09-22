#include "VaisseauTransport.h"
#include "Utilitaire.h"

VaisseauTransport::VaisseauTransport(std::string _nom) : Vaisseau(1500, 60, 45,40, 60, 1, 0)
{
	nom = _nom;
}
VaisseauTransport::VaisseauTransport(Faction* _faction) : VaisseauTransport(Utilitaire::getRandomNom())
{
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}
VaisseauTransport::VaisseauTransport(Faction* _faction, int _niveau, int _experience) : Vaisseau(1000, 20, 20, 50, 50, _niveau, _experience)
{
	nom =Utilitaire::getRandomNom();
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}

std::string VaisseauTransport::to_string()
{

	std::string infoVaisseau = "Vaisseau de transport " + nom+ "\n";
	infoVaisseau =  infoVaisseau + Vaisseau::to_string();
	return infoVaisseau;

}