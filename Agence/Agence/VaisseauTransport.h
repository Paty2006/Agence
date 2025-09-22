#pragma once

#include "Vaisseau.h";


class VaisseauTransport : public Vaisseau
{
public:
	VaisseauTransport(std::string _nom);
	VaisseauTransport(Faction* _faction);
	VaisseauTransport(Faction* _faction, int _niveau, int _experience);
	std::string to_string() override;
};

