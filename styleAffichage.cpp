#include "styleAffichage.h"
#include <iostream>

styleAffichage::styleAffichage()
{

}

void styleAffichage::affichageEnteteActivites(const std::string &nom)
{
    std::cout <<'\n' << std::string(70,'~') << std::endl;
    ecritEnGras("          LANCEMENT : " + nom +"             \n") ;
    std::cout << std::string(70,'~') << std::endl;
}

void styleAffichage::affichagePiedDePageActivites(const std::string &nom)
{
    std::cout<<'\n' ;
    ecritEnGras( "--- FIN [ " + nom + " ] ---\n") ;
    std::cout <<std::string(70,'=')<<"\n\n" ;
    std::cout<<'\n' ;
}


void styleAffichage::affichageEnteteQuestion(const std::string &nomActivite, int numQuestion, int nbQuestions)
{
    std::cout << '\n' ;
    std::cout << std::string(70,'=')<< std::endl ;
    std::cout << std::string(70,'-')<< std::endl ;
    ecritEnGras("         "+nomActivite+" | Progression : [" + std::to_string(numQuestion + 1)
                                                                    + "/" + std::to_string(nbQuestions) + "]\n") ;
    std::cout << std::string(70,'-')<< std::endl ;
}


void styleAffichage::affichagePiedDePageQuestion()
{
    std::cout << std::string(70,'=') << std::endl << std::endl ;
}


void styleAffichage::ecritEnGras(const std::string &msg)
{
    const std::string BOLD = "\033[1m";
    const std::string RESET = "\033[0m";
    std::cout << BOLD << msg << RESET ;
}

void styleAffichage::ecritEnBleu(const std::string &msg)
{
    const std::string BLUE = "\033[34m";
    const std::string RESET = "\033[0m";
    std::cout << BLUE << msg << RESET ;
}

void styleAffichage::ecritEnRouge(const std::string &msg)
{
    const std::string RED = "\033[31m";
    const std::string RESET = "\033[0m";
    std::cout << RED << msg << RESET ;
}

void styleAffichage::ecritEnVert(const std::string &msg)
{
    const std::string GREEN = "\033[32m";
    const std::string RESET = "\033[0m";
    std::cout << GREEN << msg << RESET << std::endl;
}

void styleAffichage::ecritEnBleuCiel(const std::string &msg)
{
    const std::string CYAN = "\033[36m";
    const std::string RESET = "\033[0m";
    std::cout << CYAN << msg << RESET;
}

void styleAffichage::ecritEnBleuCielGras(const std::string &msg)
{
    const std::string BOLD_CYAN = "\033[1;36m";
    const std::string RESET = "\033[0m";
    std::cout << BOLD_CYAN << msg << RESET;
}

