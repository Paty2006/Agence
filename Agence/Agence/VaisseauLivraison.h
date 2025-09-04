#pragma once
#include "Vaisseau.h"
class VaisseauLivraison : public Vaisseau
{
public:
	VaisseauLivraison(std::string _nom);
	~VaisseauLivraison();
	virtual std::string to_string();

};

