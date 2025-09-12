#include "Utilitaire.h"
#include <iostream>
#include <ctime>



int Utilitaire::genererNb(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}
