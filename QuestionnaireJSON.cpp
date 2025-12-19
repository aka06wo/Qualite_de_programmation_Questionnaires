#include <fstream>
#include "QuestionnaireJSON.h"
#include "Questionnaire.h"
#include "QuestionNumerique.h"
#include "QuestionTexte.h"
#include "QuestionChoixMultiple.h"
#include <iostream>


std::string QuestionnaireJSON::NomFichierQuestionnaire()
{
    return "Fichier_Questionnaire.json";
}

std::string QuestionnaireJSON::NomFichierQuestionnairesSauvegarde()
{
    return "Fichier_Questionnaire_Sauvegarde.json";
}

QuestionnaireJSON::QuestionnaireJSON() : d_nomQuestionnaire{}, d_monFichier{json::array()}
{
}

QuestionnaireJSON::QuestionnaireJSON(const std::string &nomQuestionnaire) :
    d_nomQuestionnaire{nomQuestionnaire}, d_monFichier{json::object()}
{
}

std::string QuestionnaireJSON::nomQuestionnaire() const
{
    return d_nomQuestionnaire ;
}

void QuestionnaireJSON::changerQuestionnaire(const std::string &nomQuestionnaire)
{
    d_nomQuestionnaire = nomQuestionnaire;
}

bool QuestionnaireJSON::ouvertureFichier(const std::ifstream &fichier) const
{
    return (fichier.is_open());
}

bool QuestionnaireJSON::conversionJSON(json &fichierJSON,std::ifstream &fichier) const
{
    try {
        fichier>>fichierJSON ;
        fichier.close();
    } catch (const json::parse_error&) {
        // std::cerr << "Erreur JSON : " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool QuestionnaireJSON::lireFichierJSON(json &fichierJSON, const std::string &nomFichier) const
{
    std::ifstream fichier(nomFichier);
    if (!ouvertureFichier(fichier))
        return false;

    return conversionJSON(fichierJSON, fichier);
}

bool QuestionnaireJSON::extraireQuestionnaire(
    const json &fichierJSON, const std::string &nomQuestionnaire, json &questionnaireJSON)
{
    // Je suppose que le fichier est bien construit, sinon try catch sur
    // json::out_of_range & comme les autres
    for (const auto& q : fichierJSON)
    {
        if (q.at("nom") == nomQuestionnaire)
        {
            questionnaireJSON = q;
            return true;
        }
    }
    return false;
}

void QuestionnaireJSON::extraireDescription(const json &fichierJSON, Questionnaire &questionnaire) {
    try {
        std::string description = fichierJSON.at("description") ;
        questionnaire.changerDescriptionQuestionnaire(description);
    } catch (const json::out_of_range &) {
        //std::cerr << "Questionnaire " << "Description manquante" << e.what() << std::endl;
    }
}

json QuestionnaireJSON::extraireQuestions(const json &questionnaireJSON)
{
    try {
        return questionnaireJSON.at("questions");
    } catch (const json::out_of_range &) {
        //std::cerr << "Aucune question trouvée → " << e.what() << std::endl;
        return json::array(); // retourne un tableau vide
    }
}

void QuestionnaireJSON::ajouterQuestionDepuisJSON(Questionnaire &questionnaire, const json &questionnaireJSON)
{
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
    } catch (const json::out_of_range &) {
        //std::cerr << "Question ignorée : clé manquante " << e.what() << std::endl;
    }
}


void QuestionnaireJSON::chargerDansQuestionnaire(Questionnaire &questionnaire)
{
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


void QuestionnaireJSON::sauvegarderQuestionnaire(const Questionnaire &questionnaire) const
{
    json tousLesQuestionnaires{};
    if ( ! lireFichierJSON(tousLesQuestionnaires, NomFichierQuestionnairesSauvegarde()))
    {
        tousLesQuestionnaires = json::array() ;
    }
    json nouveauQ = questionnaire.conversionQuestionnaireJson();

    bool trouve = false;
    for (auto &q : tousLesQuestionnaires)
    {
        if (q.at("nom") == questionnaire.nomQuestionnaire()) {
            q = nouveauQ;
            trouve = true;
            break;
        }
    }

    // Si pas trouvé, on ajoute à la fin
    if (!trouve) {
        tousLesQuestionnaires.push_back(nouveauQ);
    }

    std::ofstream fichier_sauv(NomFichierQuestionnairesSauvegarde());
    if (fichier_sauv.is_open())
    {
        fichier_sauv << tousLesQuestionnaires.dump(4);
        fichier_sauv.close();
    }
}


std::vector<std::string> QuestionnaireJSON::nomsDifferentsQuestionnaires() const
{
    std::vector<std::string> listeNoms{};
    json FichierJSON;
    if (!lireFichierJSON(FichierJSON, NomFichierQuestionnaire()))
    {
        return listeNoms;
    }
    for(const auto& questionnaireJSON: FichierJSON)
    {
        listeNoms.push_back(questionnaireJSON.at("nom"));
    }
    return listeNoms;
}
