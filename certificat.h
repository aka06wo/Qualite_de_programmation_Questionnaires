#ifndef CODE_QUESTIONNAIRE_CERTIFICAT_H
#define CODE_QUESTIONNAIRE_CERTIFICAT_H

#include <string>

class certificat
{
public :
    certificat();
    virtual void genereCertificat(const std::string &nomQuestionnaire,
                const std::string &descriptionQ, int score, int nbQuestions) const = 0;
private :

};

#endif //CODE_QUESTIONNAIRE_CERTIFICAT_H
