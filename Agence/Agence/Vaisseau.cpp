#include "Vaisseau.h"

Vaisseau::Vaisseau( int _valeurMarchande,int _attaque, int _defense, int _vie, int _capacite, int _niveau, int _exp) :nom("monVaisseau")
{
	valeurMarchande = _valeurMarchande;
	attaque = _attaque;
	defense = _defense;
	vie = _vie;
	capacite = _capacite;
	exp = _exp;
	niveau = _niveau;

}

Vaisseau::~Vaisseau()
{
	//rien
}
int Vaisseau::GetAtt()
{
	return attaque;
}

int Vaisseau::GetDef()
{
	return defense;
}

int Vaisseau::GetVie()
{
	return vie;
}

std::string Vaisseau::to_string()
{
	return "Je suis un vaisseau";
}