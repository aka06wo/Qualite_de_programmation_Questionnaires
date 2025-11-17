#include "QuestionnaireJSON.h"
#include "QuestionChoixMultiple.h"
#include <fstream>
#include <memory>

QuestionnaireJSON::QuestionnaireJSON(const string &nomQuestionnaire) :
    d_nomQuestionnaire(nomQuestionnaire), d_monFichier{json::array()}
{
}

std::string QuestionnaireJSON::nomQuestionnaire() const {
    return d_nomQuestionnaire ;
}

void QuestionnaireJSON::chargerQuestionnaire(Questionnaire &questionnaire) {
    if (questionnaire.nombreDeQuestions()!=0)
    {
        std::ifstream monFichier("Ficher_Questionnaire.json");
        monFichier >> d_monFichier ;

        json d_monQuestionnaire = d_monFichier[d_nomQuestionnaire];
        for (const auto &q : d_monQuestionnaire["questions"])
        {
            if (q.value("type","Indefini")=="choixMultiples")
            {
                questionnaire.ajouterQuestion(std::make_unique<QuestionChoixMultiple>
                            (q["question"],q["reponsesPossibles"],q["numReponseCorrecte"])) ;
            }
            else if (q.value("type","Indefini")=="numerique")
            {
                // make unique et on modifie le questionnaire
            }
            else if (q.value("type","Indefini")=="texte")
            {
                // make unique et on modifie le questionnaire
            }
        }
    }
    else
    {
        std::cout<<"Questionnaire non vide, risque de perte des données ou de doublons"<<std::endl ;
    }
}

void QuestionnaireJSON::ajouterQuestion(const std::unique_ptr<Question> &q) const {
    // il faut que je sache le type de la question pour ajouter
}

void QuestionnaireJSON::sauvegarderQuestionnaire(const Questionnaire &questionnaire) const {
    // je remets le json dans le fichier
}
