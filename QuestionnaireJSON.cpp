#include "QuestionnaireJSON.h"
#include "QuestionChoixMultiple.h"
#include <fstream>
#include <memory>

#include "QuestionNumerique.h"
#include "QuestionTexte.h"

std::string QuestionnaireJSON::NomFichierQuestionnaire() {
    return "Fichier_Questionnaire.json";
}

QuestionnaireJSON::QuestionnaireJSON() : d_nomQuestionnaire{}, d_monFichier{json::object()}
{
}

QuestionnaireJSON::QuestionnaireJSON(const string &nomQuestionnaire) :
    d_nomQuestionnaire(nomQuestionnaire), d_monFichier{json::object()}
{
}

std::string QuestionnaireJSON::nomQuestionnaire() const {
    return d_nomQuestionnaire ;
}

void QuestionnaireJSON::changerQuestionnaire(const std::string &nomQuestionnaire) {
    d_nomQuestionnaire = nomQuestionnaire;
}

bool QuestionnaireJSON::ouvertureFichier(const std::ifstream &monFichier) const{
    return (monFichier.is_open());
}

bool QuestionnaireJSON::conversionJSON(json &monJSON, std::ifstream &monFichier) {
    try {
        monFichier>>monJSON ;
    } catch (const json::parse_error &e) {
        // std::cerr << "Erreur JSON : " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool QuestionnaireJSON::lireFichierJSON(json &d_monFichier, const std::string &nomFichier) {
    std::ifstream monFichier(nomFichier);
    if (!ouvertureFichier(monFichier))
        return false;

    return conversionJSON(d_monFichier, monFichier);
}

bool QuestionnaireJSON::extraireQuestionnaire(
    const json &d_monFichier, const std::string &nomQuestionnaire, json &monQuestionnaire) {
    try {
        monQuestionnaire = d_monFichier.at(nomQuestionnaire);
    } catch (const json::out_of_range &e) {
        // std::cerr << "Questionnaire '" << nomQuestionnaire << "' manquant → " << e.what() << std::endl;
        return false;
    }
    return true;
}

json QuestionnaireJSON::extraireQuestions(const json &monQuestionnaire) {
    try {
        return monQuestionnaire.at("questions");
    } catch (const json::out_of_range &e) {
        std::cerr << "Aucune question trouvée → " << e.what() << std::endl;
        return json::array(); // retourne un tableau vide pour que la boucle for ne fasse rien
    }
}

void QuestionnaireJSON::ajouterQuestionDepuisJSON(Questionnaire &questionnaire, const json &q) {
    try {
        std::string type = q.at("type");

        if (type == "choixMultiples") {
            questionnaire.ajouterQuestion(std::make_unique<QuestionChoixMultiple>(
                q.at("question"), q.at("reponsesPossibles"), q.at("numReponseCorrecte")));
        } else if (type == "numerique") {
            questionnaire.ajouterQuestion(std::make_unique<QuestionNumerique>(
                q.at("question"), q.at("reponseCorrecte"), q.at("limiteMax"), q.at("limiteMin")));
        } else if (type == "texte") {
            questionnaire.ajouterQuestion(std::make_unique<QuestionTexte>(
                q.at("question"), q.at("reponseCorrecte")));
        } else {
            std::cerr << "Type de question inconnu → question ignorée." << std::endl;
        }
    } catch (const json::out_of_range &e) {
        std::cerr << "Question ignorée : clé manquante → " << e.what() << std::endl;
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
    if (!extraireQuestionnaire(d_monFichier, d_nomQuestionnaire, monQuestionnaire))
        return;

    json questions = extraireQuestions(monQuestionnaire);

    for (const auto &q : questions) {
        ajouterQuestionDepuisJSON(questionnaire, q);
    }

    // optionnelle
    if (monQuestionnaire.contains("description")) {
        questionnaire.changerDescriptionQuestionnaire(monQuestionnaire["description"]);
    }

    questionnaire.changerNomQuestionnaire(d_nomQuestionnaire);
}


// il reste a securiser celui la
void QuestionnaireJSON::sauvegarderQuestionnaire(const Questionnaire &questionnaire) const {
    json tousLesQuestionnaires;
    std::ifstream monFichier(NomFichierQuestionnaire());
    monFichier >> tousLesQuestionnaires;
    monFichier.close();

    tousLesQuestionnaires[questionnaire.nombreDeQuestions()]=questionnaire.conversionQuestionnaireJson();

    std::ofstream fichier_out(NomFichierQuestionnaire());
    fichier_out << tousLesQuestionnaires.dump(4);
    fichier_out.close();
}
