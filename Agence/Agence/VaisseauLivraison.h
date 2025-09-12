#pragma once

#include "Vaisseau.h";

class VaisseauLivraison : public Vaisseau
{
public:
	VaisseauLivraison(std::string _nom);
	VaisseauLivraison(Faction* _faction);
	VaisseauLivraison(Faction* _faction, int _niveau, int _experience);
	~VaisseauLivraison() override;
	std::string to_string() override;

};

