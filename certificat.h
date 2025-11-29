#ifndef CODE_QUESTIONNAIRE_CERTIFICAT_H
#define CODE_QUESTIONNAIRE_CERTIFICAT_H

#include "json.hpp"
using nlohmann::json ;
#include <iostream>
#include <fstream>
#include <sstream>

class certificat
{
public :
    certificat(const std::string& nomUtilisateur,const std::string& nomQuestionnaire,int score);
    void certficatText () const ;
    void certficatHtml () const ;

private :
    std::string d_nomUtilisateur,d_nomquestionnaire;
    int d_score;


    std::string lireFichier(const std::string& nomFichier) const;
    void remplacer(std::string& texte,
                   const std::string& nomQues,
                   const std::string& scoreAuQuestionnaire) const;
};

#endif //CODE_QUESTIONNAIRE_CERTIFICAT_H
