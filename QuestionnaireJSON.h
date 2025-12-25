#ifndef CODE_PROJET_QUESTIONNAIREJSON_H
#define CODE_PROJET_QUESTIONNAIREJSON_H

#include "json.hpp"

class Questionnaire ;

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
    bool conversionJSON(nlohmann::json &fichierJSON,std::ifstream &fichier) const ;

    /**
     Tente à la foix de lire le fichier JSON et de le convertir en objet JSON
     @param fichierJSON Objet JSON à avoir en resultat
     @param nomFichier Nom du fichier JSON
     @return Vrai s'il a reussi à lire et convertir le fichier, faux sinon
     */
    bool lireFichierJSON(nlohmann::json &fichierJSON, const std::string &nomFichier) const ;

    /**
     Extrait le questionnaire en format json dans le fichier json questionniareJSON
     * @param fichierJSON Le fichier contenant tous les questionnaires
     * @param nomQuestionnaire Le nom du questionnaire à extraire
     * @param questionnaireJSON Le fichier JSON résultat
     * @return vrai s'il a réussi à extraire le questionnaire
     */
    bool extraireQuestionnaire(const nlohmann::json &fichierJSON, const std::string &nomQuestionnaire,
               nlohmann::json &questionnaireJSON) ;

    /**
     Extrait la description du questionnaire dans le fichier JSON et le stocke dans le questionnaires (l'objet questionnaire)
     * @param fichierJSON le fichier JSON qui contient le questionnaire
     * @param questionnaire le questionnaire qu'on aura en résultat
     */
    void extraireDescription(const nlohmann::json &fichierJSON,Questionnaire &questionnaire) ;

    /**
     Extrait le tableau de questions en format JSON depuis le questionnaire contenu dans le fichier JSON
     * @param questionnaireJSON le fichier JSON contenant le questionnaire
     * @return un tableau de questions en format JSON
     */
    nlohmann::json extraireQuestions(const nlohmann::json &questionnaireJSON) ;

    /**
     * Ajoute dans le questionnaire la question (JSON)
     * @param questionnaire le questionnaire résultat
     * @param questionJSON la question en format JSON
     */
    void ajouterQuestionDepuisJSON(Questionnaire &questionnaire, const nlohmann::json &questionJSON) ;

    /**
     Charge tout le contenu du questionnaire stocké dans le fichier JSON dans l'objet questionnaire
     @param questionnaire le questionnaire résultat
     */
    void chargerDansQuestionnaire(Questionnaire &questionnaire) ;

    /**
     Sauvegarde dans un fichier en format JSON tout le contenu du questionnaire
     @param questionnaire
     */
    void sauvegarderQuestionnaire(const Questionnaire &questionnaire) const ;

    /**
     Renvoie les noms des différents questionnaires présents dans le fichier
     @return un tableau de string contenant les noms des questionnaires
     */
    std::vector<std::string> nomsDifferentsQuestionnaires() const ;

    private:
    std::string d_nomQuestionnaire ;
    nlohmann::json d_monFichier ;

    /**
     @return Le nom du fichier JSON qui contient tous les questionnaires
     */
    static std::string NomFichierQuestionnaire() ;
     /**
     @return Le nom du fichier JSON de sauvegarde
     */
    static std::string NomFichierQuestionnairesSauvegarde() ;
};


#endif //CODE_PROJET_QUESTIONNAIREJSON_H
