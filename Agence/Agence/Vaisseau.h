#pragma once
#include <string>

using std::string;

class Vaisseau
{
protected:
	int valeurMarchande;
	int attaque;
	int defense;
	int vie;
	int capacite;
	int niveau;
	std::string nom;
	int exp;
public:
	Vaisseau(int _valeurMarchande, int _attaque, int _defense, int _vie, int _capacite, int _niveau, int _exp);
	~Vaisseau();
	int GetAtt();
	int GetDef();
	int GetVie();
	virtual std::string to_string();

};

