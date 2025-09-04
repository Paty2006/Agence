#pragma once

#include <string>
using std::string;

class Faction
{
private:
protected:
	int attaque;
	int defense;
	int vie;
	int capacite;
	std::string nom;
public:
	Faction();
	Faction(int _attaque, int _defense, int _vie, int _capacite);
	~Faction();
	std::string GetNom();
	virtual std::string to_string();

};

