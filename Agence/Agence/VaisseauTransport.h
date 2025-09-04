#pragma once
#include "Vaisseau.h"
class VaisseauTransport : public Vaisseau
{
public:
	VaisseauTransport(std::string _nom);
	~VaisseauTransport();
	virtual std::string to_string();
};

