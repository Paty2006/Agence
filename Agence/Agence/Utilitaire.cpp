#include "Utilitaire.h"
#include <iostream>
#include <ctime>
#include <vector>



int Utilitaire::genererNb(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

std::string Utilitaire::getRandomNom()
{

    std::vector<std::string> Noms = { "Liberator", "Eternal Horizon", "Nova Hunter", "Starbreaker",
        "Solaris Prime", "Iron Comet", "Shadow Voyager", "Nebula Spear", "Titan Fury", "Aurora Dawn",
        "Crimson Phantom", "Galaxy Serpent", "Void Stalker", "Infinity Blade", "Stellar Forge",
        "Orion Wing", "Black Nova", "Astral Raider", "Celestial Hammer", "Quantum Arrow", "Dark Horizon",
        "Lunar Vortex", "Solar Fang", "Valkyrie Spear", "Cosmos Harbinger", "Echo of Eternity",
        "Storm Breaker", "Meteor Fang", "Dragon of Void", "Sirius Flame", "Oblivion Edge", 
        "Eclipse Rider", "Thunder Comet", "Specter Wing", "Nemesis Core", "Helios Wrath", "Phantom Horizon",
        "Omega Vortex", "Astralis Fang", "Shadow Spear", "Venom Star", "Vortex Rider", "Nebula Storm", 
        "Iron Horizon", "Void Reaver", "Celestial Fang", "Starlight Phantom", "Orion Fang",
        "Solar Wrath", "Eternal Spear" };

    return Noms[Utilitaire::genererNb(0, Noms.size() - 1)];

}

void Utilitaire::AfficherImageDebut()
{
    
    std::cout << "          /\\           \n";
    std::cout << "         /  \\          \n";
    std::cout << "        / /\\ \\         \n";
    std::cout << "       / /  \\ \\        \n";
    std::cout << "      /_/____\\_\\       \n";
    std::cout << "        |    |         \n";
    std::cout << "        |    |         \n";
    std::cout << "        |    |         \n";
    std::cout << "       /| |  |\\        \n";
    std::cout << "      /_|_|__|_\\       \n";
    std::cout << "        /_/\\_\\         \n";
}
