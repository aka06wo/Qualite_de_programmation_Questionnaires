#ifndef CODE_QUESTIONNAIRE_CERTIFICATHTML_H
#define CODE_QUESTIONNAIRE_CERTIFICATHTML_H

#include "certificat.h"
#include "fstream"

class certificatHTML : public certificat
{
    public:
    certificatHTML() ;
    void genereCertificat() const override;

    private:
        std::string d_nomFichier;
};


#endif //CODE_QUESTIONNAIRE_CERTIFICATHTML_H
