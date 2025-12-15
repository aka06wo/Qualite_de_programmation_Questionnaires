//
// Created by Mamadou Diallo on 11/12/2025.
//

#ifndef CODE_QUESTIONNAIRE_CERTIFICATHTML_H
#define CODE_QUESTIONNAIRE_CERTIFICATHTML_H

#include "certificat.h"

class certificatHTML : public certificat
{
    public:
    certificatHTML() ;
    void genereCertificat(const std::string &nomQuestionnaire,
                const std::string &descriptionQ, int score, int nbQuestions) const override;
};


#endif //CODE_QUESTIONNAIRE_CERTIFICATHTML_H