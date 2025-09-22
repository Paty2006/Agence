#pragma once
#include <vector>
#include "Vaisseau.h";
using std::string;

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
	void supprimerVaisseau(int index);
	int getVie();
	int getPlatinum();
	void setPlatinum(int _platinum);
	virtual std::string to_string();
};

