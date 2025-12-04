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
   void certificatHtml(std::ostream& os) const;
    void certificatText(std::ostream& os) const;

private :
    std::string d_nomUtilisateur,d_nomquestionnaire;
    int d_score;

};

#endif //CODE_QUESTIONNAIRE_CERTIFICAT_H
