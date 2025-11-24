#ifndef CODE_QUESTIONNAIRE_CERTIFICAT_H
#define CODE_QUESTIONNAIRE_CERTIFICAT_H

#include "json.hpp"
using nlohmann::json ;

class certificat
{
    public :
    certificat(const json &j);
    void certficatText () const ;
    void certficatHtml () const ;

    private :
    json d_infos ;
};

#endif //CODE_QUESTIONNAIRE_CERTIFICAT_H