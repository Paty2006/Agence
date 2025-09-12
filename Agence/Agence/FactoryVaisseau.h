#pragma once
#include <string>

class Vaisseau;
class Faction;

class FactoryVaisseau
{
public:
	enum class Rang { Junior, Senior, Veteran };
	 static Vaisseau* getRandomVaisseau();
	 static Faction* getRandomFaction();

};

