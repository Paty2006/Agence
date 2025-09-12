#pragma once
#include <string>
#include "Faction.h"

class FactionRouge : public Faction
{
public:
	FactionRouge();
	FactionRouge(int _attaque, int _defense, int _vie, int _capacite);
	~FactionRouge();
	std::string to_string();
};

