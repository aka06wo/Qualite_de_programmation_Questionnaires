#ifndef CODE_QUESTIONNAIRE_CERTIFICATTEXT_H
#define CODE_QUESTIONNAIRE_CERTIFICATTEXT_H

#include "certificat.h"

class certificatText : public certificat
{
    public:
    certificatText() ;
    void genereCertificat() const override;

    private:
       std::string d_nomFichier;
};


#endif //CODE_QUESTIONNAIRE_CERTIFICATTEXT_H
