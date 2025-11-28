#ifndef CODE_QUESTIONNAIRE_CERTIFICAT_H
#define CODE_QUESTIONNAIRE_CERTIFICAT_H

#include "json.hpp"
using nlohmann::json ;

class certificat
{
    public :
    certificat();
    void certficatText () const ;
    void certficatHtml () const ;

    private :
};

#endif //CODE_QUESTIONNAIRE_CERTIFICAT_H