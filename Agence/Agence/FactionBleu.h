#pragma once
#include "Faction.h"
class FactionBleu : public Faction
{
public:
	FactionBleu();
	FactionBleu(int _attaque, int _defense, int _vie, int _capacite);
	~FactionBleu();
	virtual std::string to_string();

};

