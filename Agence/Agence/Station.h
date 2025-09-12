#pragma once
#include <vector>
class Vaisseau;

class Station
{
private:
	int platinumDisponible;
	int vieStation;
	std::vector<Vaisseau*> vecVaisseau;
public:
	Station(int _platinumDisponible,int _vieStation);
	~Station();

	std::vector<Vaisseau*> getVaisseauDispo();
	void init();
	void ajouterVaisseau(Vaisseau* vaisseau);

};

