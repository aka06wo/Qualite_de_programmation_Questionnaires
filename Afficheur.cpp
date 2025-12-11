#include "Afficheur.h"
#include <iostream>

void Afficheur::separateur(int largeur, char symbole)
{
    std::cout << std::string(largeur, symbole) << std::endl;
}

void Afficheur::messageSelonScore(double pourcentage)
{
    std::cout<< "Score obtenu : " + std::to_string(pourcentage) + '\n' ;

    if (pourcentage >= 90)
    {
        std::cout<< "Félicitations ! Tu es un génie, presque invincible !\n";
    }
    else if (pourcentage >= 75)
    {
        std::cout<< "Bravo ! Très bon travail \n";
    }
    else if (pourcentage >= 50)
    {
        std::cout<< "Pas mal ! Mais tu peux faire encore mieux, on croit en toi !\n";
    }
    else if (pourcentage >= 25)
    {
        std::cout<< "Hum... ça commence à se compliquer. Allez, courage !\n";
    }
    else
    {
        std::cout<< "Oups... peut-être que tu devrais revoir tes notes";
    }
}

void Afficheur::affichageConsole(const std::string &message)
{
    std::cout << message << std::endl;
}
