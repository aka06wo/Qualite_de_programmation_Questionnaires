#ifndef CODE_QUESTIONNAIRE_CERTIFICAT_H
#define CODE_QUESTIONNAIRE_CERTIFICAT_H

#include <iostream>
#include <fstream>
#include <sstream>


/*
 *mettre en classe abstraite et changer pour ne pas le construire avec un nom, il faut
 *qu'il gere tout les utilisateurs
 */

// a faire sans const std::string& nomUtilisateur,const std::string& nomQuestionnaire,int score

class certificat
{
public :
    certificat();
    virtual void genereCertificat() const = 0;

private :
    // il faut pas qu'on les stockes
    std::string d_nomUtilisateur,d_nomquestionnaire;
    int d_score;

};

#endif //CODE_QUESTIONNAIRE_CERTIFICAT_H
