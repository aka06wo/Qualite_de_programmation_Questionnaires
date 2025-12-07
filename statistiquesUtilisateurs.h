#ifndef CODE_QUESTIONNAIRE_STATISTIQUESUTILISATEURS_H
#define CODE_QUESTIONNAIRE_STATISTIQUESUTILISATEURS_H

#include "json.hpp"
using nlohmann::json ;

class statistiquesUtilisateurs
{
  public:
  statistiquesUtilisateurs();
  static std::string nomFichierStatistiques();
  std::string messageSelonScore(double pourcentage) ;

  private :
  json d_statistiquesUtilisateurs ;


  /*
   Fichier JSON déja mis en place
   */


};


#endif //CODE_QUESTIONNAIRE_STATISTIQUESUTILISATEURS_H