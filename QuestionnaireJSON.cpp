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

void QuestionnaireJSON::chargerDansQuestionnaire(Questionnaire &questionnaire) {
    if (questionnaire.nombreDeQuestions()==0)
    {
        // faire un try catch sur le fichier, s'il est pas ouvert
        std::ifstream monFichier(NomFichierQuestionnaire());
        monFichier >> d_monFichier ;

        // try catch si il questionnaire n'existe pas, il retourn {}, je dois faire un affichage pour
        // savoir ce qui s'est passée
        json d_Questionnaire = d_monFichier[d_nomQuestionnaire];
        questionnaire.changerNomQuestionnaire(d_nomQuestionnaire);
        questionnaire.changerDescriptionQuestionnaire(d_Questionnaire["description"]);

        for (const auto &q : d_Questionnaire["questions"])
        {
            if (q.value("type","Indefini")=="choixMultiples")
            {
                questionnaire.ajouterQuestion(std::make_unique<QuestionChoixMultiple>
                            (q["question"],q["reponsesPossibles"],q["numReponseCorrecte"])) ;
            }
            else if (q.value("type","Indefini")=="numerique")
            {
                questionnaire.ajouterQuestion(std::make_unique<QuestionNumerique>(q["question"],q["reponseCorrecte"])) ;
            }
            else if (q.value("type","Indefini")=="texte")
            {
                questionnaire.ajouterQuestion(std::make_unique<QuestionTexte>(q["question"],q["reponseCorrecte"])) ;
            }
        }
    }
    else
    {
        std::cout<<"Questionnaire non vide, risque de perte des données ou de doublons"<<std::endl ;
    }
}

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
