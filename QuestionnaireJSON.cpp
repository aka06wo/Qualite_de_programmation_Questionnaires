#include <fstream>
#include "QuestionnaireJSON.h"
#include "Questionnaire.h"
#include "QuestionNumerique.h"
#include "QuestionTexte.h"
#include "QuestionChoixMultiple.h"


std::string QuestionnaireJSON::NomFichierQuestionnaire() {
    return "Fichier_Questionnaire.json";
}

std::string QuestionnaireJSON::NomFichierQuestionnairesSauvegarde() {
    return "Fichier_Questionnaire_Sauvegarde.json";
}

QuestionnaireJSON::QuestionnaireJSON() : d_nomQuestionnaire{}, d_monFichier{json::object()}
{
}

QuestionnaireJSON::QuestionnaireJSON(const std::string &nomQuestionnaire) :
    d_nomQuestionnaire(nomQuestionnaire), d_monFichier{json::object()}
{
}

std::string QuestionnaireJSON::nomQuestionnaire() const {
    return d_nomQuestionnaire ;
}

void QuestionnaireJSON::changerQuestionnaire(const std::string &nomQuestionnaire) {
    d_nomQuestionnaire = nomQuestionnaire;
}

bool QuestionnaireJSON::ouvertureFichier(const std::ifstream &fichier) const{
    return (fichier.is_open());
}

bool QuestionnaireJSON::conversionJSON(json &fichierJSON,std::ifstream &fichier) {
    try {
        fichier>>fichierJSON ;
    } catch (const json::parse_error &e) {
        // std::cerr << "Erreur JSON : " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool QuestionnaireJSON::lireFichierJSON(json &fichierJSON, const std::string &nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!ouvertureFichier(fichier))
        return false;

    return conversionJSON(fichierJSON, fichier);
}

bool QuestionnaireJSON::extraireQuestionnaire(
    const json &fichierJSON, const std::string &nomQuestionnaire, json &questionnaireJSON) {
    try {
        questionnaireJSON = fichierJSON.at(nomQuestionnaire);
    } catch (const json::out_of_range &e) {
        // std::cerr << "Questionnaire '" << nomQuestionnaire << "' manquant → " << e.what() << std::endl;
        return false;
    }
    return true;
}

void QuestionnaireJSON::extraireDescription(const json &fichierJSON, Questionnaire &questionnaire) {
    try {
        std::string description = fichierJSON.at("description") ;
        questionnaire.changerDescriptionQuestionnaire(description);
    } catch (const json::out_of_range &e) {
        //std::cerr << "Questionnaire " << "Description manquante" << e.what() << std::endl;
    }
}

json QuestionnaireJSON::extraireQuestions(const json &questionnaireJSON) {
    try {
        return questionnaireJSON.at("questions");
    } catch (const json::out_of_range &e) {
        std::cerr << "Aucune question trouvée → " << e.what() << std::endl;
        return json::array(); // retourne un tableau vide
    }
}

void QuestionnaireJSON::ajouterQuestionDepuisJSON(Questionnaire &questionnaire, const json &questionnaireJSON) {
    try {
        std::string type = questionnaireJSON.at("type");

        if (type == "choixMultiples")
        {
            questionnaire.ajouterQuestion(std::make_unique<QuestionChoixMultiple>(
                questionnaireJSON.at("question"), questionnaireJSON.at("reponsesPossibles"),
                questionnaireJSON.at("numReponseCorrecte")));
        } else if (type == "numerique")
        {
            questionnaire.ajouterQuestion(std::make_unique<QuestionNumerique>(
                questionnaireJSON.at("question"), questionnaireJSON.at("reponseCorrecte"),
                questionnaireJSON.at("limiteMax"), questionnaireJSON.at("limiteMin")));
        } else if (type == "texte")
        {
            questionnaire.ajouterQuestion(std::make_unique<QuestionTexte>(
                questionnaireJSON.at("question"), questionnaireJSON.at("reponseCorrecte")));
        }
        // else  std::cerr << "Type de question inconnu → question ignorée." << std::endl;
    } catch (const json::out_of_range &e) {
        std::cerr << "Question ignorée : clé manquante " << e.what() << std::endl;
    }
}


void QuestionnaireJSON::chargerDansQuestionnaire(Questionnaire &questionnaire) {
    if (questionnaire.nombreDeQuestions()!=0) {
        std::cout<<"Questionnaire non vide, risque de perte des données ou de doublons"<<std::endl ;
        return ;
    }

    if (!lireFichierJSON(d_monFichier, NomFichierQuestionnaire()))
        return;

    json monQuestionnaire;
    if (!extraireQuestionnaire(d_monFichier, nomQuestionnaire(), monQuestionnaire))
        return;

    questionnaire.changerNomQuestionnaire(nomQuestionnaire()) ;
    extraireDescription(monQuestionnaire, questionnaire);

    json questions = extraireQuestions(monQuestionnaire);

    for (const auto &q : questions) {
        ajouterQuestionDepuisJSON(questionnaire, q);
    }

}


void QuestionnaireJSON::sauvegarderQuestionnaire(const Questionnaire &questionnaire) const {
    json tousLesQuestionnaires;
    std::ifstream monFichier(NomFichierQuestionnaire());
    monFichier >> tousLesQuestionnaires;
    monFichier.close();

    tousLesQuestionnaires[questionnaire.nomQuestionnaire()]=questionnaire.conversionQuestionnaireJson();

    std::ofstream fichier_sauv(NomFichierQuestionnairesSauvegarde());
    fichier_sauv << tousLesQuestionnaires.dump(4);
    fichier_sauv.close();
}
