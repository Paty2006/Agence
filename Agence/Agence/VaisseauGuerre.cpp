#include "VaisseauGuerre.h"
#include "Utilitaire.h"

VaisseauGuerre::VaisseauGuerre(std::string _nom) : Vaisseau(2000, 80, 70, 30, 20, 1, 0)
{
	nom = _nom;
}
VaisseauGuerre::VaisseauGuerre(Faction* _faction) : VaisseauGuerre(Utilitaire::getRandomNom())
{
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}

VaisseauGuerre::VaisseauGuerre(Faction* _faction, int _niveau, int _experience): Vaisseau(2000, 80, 70, 30, 20, _niveau, _experience)
{
	nom = Utilitaire::getRandomNom();
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}

std::string VaisseauGuerre::to_string()
{
	
	std::string infoVaisseau = "Vaisseau de guerre " + nom + "\n";
	infoVaisseau = infoVaisseau + Vaisseau::to_string();
	return infoVaisseau;
}