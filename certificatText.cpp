#include <iostream>

#include "certificatText.h"

certificatText::certificatText() : certificat{}
{

}

void certificatText::genereCertificat(const std::string &nomQuestionnaire,
                const std::string &descriptionQ, int score, int nbQuestions) const
{
    std::cout << std::string(100,'%') + '\n' ;
    std::cout << "Felicitations pour votre score de " + std::to_string(score) +
                                "sur " + std::to_string(nbQuestions) + "sur le questionnaire ["+nomQuestionnaire +
                                    "] qui portait sur : " + descriptionQ +'\n' ;
    std::cout << std::string(100,'%') + '\n' ;

}
