#pragma once
#include "Vaisseau.h"

class VaisseauGuerre: public Vaisseau
{
public:
	VaisseauGuerre(std::string _nom);
	~VaisseauGuerre();
	virtual std::string to_string();

};

