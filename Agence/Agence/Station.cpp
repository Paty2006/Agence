#include "Station.h"
#include "FactoryVaisseau.h"
#include <iostream>
#include <string>

using std::vector;

Station::Station(int _platinumDisponible, int _vieStation)
{
	platinumDisponible = _platinumDisponible;
	vieStation = _vieStation;
}

Station:: ~Station()
{
	for (Vaisseau* v : vecVaisseau)
	{
		delete v;
		v = nullptr;
	}
}

int Station::getVie()
{
	return vieStation;
}

int Station::getPlatinum()
{
	return platinumDisponible;
}

void Station::setPlatinum(int _platinum)
{
	platinumDisponible = _platinum;
}

vector<Vaisseau*> Station::getVaisseauDispo()
{
	return vecVaisseau;

}

void Station::init()
{
	for (int i = 0; i < 3; i++)
	{
		vecVaisseau.push_back(FactoryVaisseau::getRandomVaisseau());
	}
}

void Station::ajouterVaisseau(Vaisseau* vaisseau)
{
	vecVaisseau.push_back(vaisseau);

}

void Station::supprimerVaisseau(int index)
{
	if (index >= 0 && index < vecVaisseau.size())
	{
		(vecVaisseau).erase(vecVaisseau.begin() + index);
	}
	else
	{
		std::cout << "index non trouvé" << std::endl;

	}
}
std::string Station::to_string()
{

	return  "INFORMATION DE LA STATION \nPLATINUM DISPONIBLE: " + std::to_string(platinumDisponible) + "\n VIE RESTANTE: "
		+ std::to_string(vieStation) + "\n NOMBRE DE VAISSEAUX DISPONIBLES: " + std::to_string(getVaisseauDispo().size()) +
		"\n ";

}
