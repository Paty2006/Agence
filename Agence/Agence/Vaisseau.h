#pragma once

#include <string>

#include "Faction.h";

using std::string;

class Vaisseau
{
private:
	

protected:
	Faction* faction;
	int valeurMarchande;
	int attaque;
	int defense;
	int vie;
	int capacite;
	int niveau;
	std::string nom;
	int exp;
public:
	Vaisseau(int _valeurMarchande, int _attaque, int _defense, int _vie, int _capacite, int _niveau, int _exp, std::string _nom = "monVaisseau");
	Vaisseau(Faction* _faction);
	virtual ~Vaisseau();
	int GetAtt();
	int GetDef();
	int GetVie();
	virtual std::string to_string();

};

