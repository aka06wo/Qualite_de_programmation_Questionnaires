#ifndef CODE_QUESTIONNAIRE_CERTIFICATTEXT_H
#define CODE_QUESTIONNAIRE_CERTIFICATTEXT_H

#include "certificat.h"

class certificatText : public certificat
{
    public:
    certificatText() ;
    void genereCertificat(const std::string &nomQuestionnaire,
                const std::string &descriptionQ, int score, int nbQuestions) const override;
};


#endif //CODE_QUESTIONNAIRE_CERTIFICATTEXT_H