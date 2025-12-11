#ifndef CODE_QUESTIONNAIRE_STATISTIQUESUTILISATEURS_H
#define CODE_QUESTIONNAIRE_STATISTIQUESUTILISATEURS_H

#include "json.hpp"
using nlohmann::json ;

class statistiquesUtilisateurs
{
  public:
  statistiquesUtilisateurs();
  ~statistiquesUtilisateurs();
  std::string statistiquesPourUtilisateur(const std::string &nomUtilisateur) const ;

  private :
  json d_statistiquesUtilisateurs ;
  static std::string nomFichierStatistiquesJSON () ;
  static std::string NomFichierQuestionnairesSauvegarde() ;
  void chargerStatistiques() ;
  void sauverStatistiques() ;
  json extraireUtilisateur(const std::string &nomUtilisateur) const ;
};


#endif //CODE_QUESTIONNAIRE_STATISTIQUESUTILISATEURS_H