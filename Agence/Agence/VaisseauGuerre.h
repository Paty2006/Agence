#pragma once

#include "Vaisseau.h";


class VaisseauGuerre: public Vaisseau
{
public:
	VaisseauGuerre(std::string _nom);
	VaisseauGuerre(Faction* _faction);
	VaisseauGuerre(Faction* _faction, int _niveau, int _experience);
	~VaisseauGuerre() override;
	std::string to_string() override;

};

