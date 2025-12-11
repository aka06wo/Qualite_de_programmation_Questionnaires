#include "AfficheurConcole.h"
#include <iostream>

AfficheurConcole::AfficheurConcole() : Afficheur{}
{

}


void AfficheurConcole::separateur(int largeur, char symbole) const
{
    std::cout << std::string(largeur, symbole) << std::endl;
}

void AfficheurConcole::messageSelonScore(double pourcentage) const
{
    std::cout<< "Score obtenu : " + std::to_string(pourcentage) + "%\n" ;

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

void AfficheurConcole::affiche(const std::string &message) const
{
    std::cout << message ;
}