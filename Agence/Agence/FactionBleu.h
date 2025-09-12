#pragma once
#include <string>

#include "Faction.h"

class FactionBleu : public Faction
{
public:
	FactionBleu();
	FactionBleu(int _attaque, int _defense, int _vie, int _capacite);
	~FactionBleu();
	std::string  to_string();
};

