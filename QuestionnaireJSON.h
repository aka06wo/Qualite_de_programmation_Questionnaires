#ifndef CODE_PROJET_QUESTIONNAIREJSON_H
#define CODE_PROJET_QUESTIONNAIREJSON_H

#include "json.hpp"
#include <memory>

class Questionnaire ;

using nlohmann::json ;

class QuestionnaireJSON
{
     public:
    /**
     Constructeur par defaut de la classe QuestionnaireJSON
     */
    QuestionnaireJSON() ;

    /**
     Constructeur avec le nom du questionnaire
     @param nomQuestionnaire Le nom du questionnaire à extraire
     */
    QuestionnaireJSON (const std::string &nomQuestionnaire) ;

    /**
     Change le questionnaire à charger
     @param nomQuestionnaire Le nom du nouveau questionnaire
     */
    void changerQuestionnaire(const std::string &nomQuestionnaire) ;

    /**
     Renvoie le nom du questionnaire
     @return Le nom du questionnaire courant
     */
    std::string nomQuestionnaire() const ;

    /**
     Tente d'ouvrir le fichier en parametre
     @param fichier Le fichier à ouvir
     @return Vrai s'il a reussi à ouvrir le fichier, Faux sinon
     */
    bool ouvertureFichier(const std::ifstream &fichier) const;

    /**
     Tente de convertir le fichier JSON en objet JSON
     @param fichier Le fichier JSON d'origine stockée dans un fichier hors du code
     @param fichierJSON L'objet JSON à avoir en resultat
     @return Vrai s'il a reussi à le convertir, Faux sinon
     */
    bool conversionJSON(json &fichierJSON,std::ifstream &fichier) const ;

    /**
     Tente à la foix de lire le fichier JSON et de le convertir en objet JSON
     @param fichierJSON Objet JSON à avoir en resultat
     @param nomFichier Nom du fichier JSON
     @return Vrai s'il a reussi à lire et convertir le fichier, faux sinon
     */
    bool lireFichierJSON(json &fichierJSON, const std::string &nomFichier) const ;


   // Je continue après

    bool extraireQuestionnaire(const json &fichierJSON, const std::string &nomQuestionnaire, json &questionnaireJSON) ;
    void extraireDescription(const json &fichierJSON,Questionnaire &questionnaire) ;
    json extraireQuestions(const json &questionnaireJSON) ;
    void ajouterQuestionDepuisJSON(Questionnaire &questionnaire, const json &questionnaireJSON) ;
    void chargerDansQuestionnaire(Questionnaire &questionnaire) ;
    void sauvegarderQuestionnaire(const Questionnaire &questionnaire) const ;
    std::vector<std::string> nomsDifferentsQuestionnaires() const ;

    private:
    std::string d_nomQuestionnaire ;
    json d_monFichier ;
    static std::string NomFichierQuestionnaire() ;
    static std::string NomFichierQuestionnairesSauvegarde() ;
};


#endif //CODE_PROJET_QUESTIONNAIREJSON_H
