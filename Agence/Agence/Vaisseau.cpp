#include "Vaisseau.h"
#include "FactoryVaisseau.h"
Vaisseau::Vaisseau( int _valeurMarchande,int _attaque, int _defense, int _vie, int _capacite, int _niveau, int _exp, std::string _nom)
{
	valeurMarchande = _valeurMarchande;
	attaque = _attaque;
	defense = _defense;
	vie = _vie;
	capacite = _capacite;
	exp = _exp;
	niveau = _niveau;
	nom = _nom;

}

Vaisseau::Vaisseau(Faction* _faction) : Vaisseau(0,0,0,0,0,1,0)
{
	faction = _faction;
	attaque += faction->GetAtt();
	defense += faction->GetDef();
	vie += faction->GetVie();
	capacite += faction->GetCapacite();
}
Vaisseau::~Vaisseau()
{
	delete faction; 
	faction = nullptr;
}
int Vaisseau::GetAtt()
{
	return attaque;
}

int Vaisseau::GetDef()
{
	return defense;
}

int Vaisseau::GetValeur()
{
	return valeurMarchande;
}

int Vaisseau::GetVie()
{
	return vie;
}

std::string  Vaisseau::GetNom()
{
	return nom;
}
std::string Vaisseau::to_string()
{
	return  "|Attaque: " + std::to_string(attaque) + "| Defense: " + std::to_string(defense) + "| Vie: " + std::to_string(vie) +
		"| Capacite:  " + std::to_string(capacite) + "| Niveau: " + std::to_string(niveau) + "| Experience: " + std::to_string(exp) + "|\n| Faction: " + faction->GetNom() + " |";
}


