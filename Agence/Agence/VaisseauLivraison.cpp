#include "VaisseauLivraison.h"
#include "Utilitaire.h"

VaisseauLivraison::VaisseauLivraison(std::string _nom) : Vaisseau(1000, 20, 20, 50, 50,1, 0)
{
	nom = _nom;
}
VaisseauLivraison::VaisseauLivraison(Faction* _faction) : VaisseauLivraison(Utilitaire::getRandomNom())
{
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}
VaisseauLivraison::VaisseauLivraison(Faction* _faction, int _niveau, int _experience): Vaisseau(1000, 20, 20, 50, 50, _niveau, _experience)
{
	nom = Utilitaire::getRandomNom();
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}

std::string VaisseauLivraison::to_string()
{
	std::string infoVaisseau = "Vaisseau de livraison " + nom  + "\n";
	infoVaisseau = infoVaisseau + Vaisseau::to_string();
	return infoVaisseau;
		
}