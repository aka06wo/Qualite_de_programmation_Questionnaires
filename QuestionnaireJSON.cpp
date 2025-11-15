#include "QuestionnaireJSON.h"
#include <fstream>

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
                // make unique et on modifie le questionnaire
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

}

void QuestionnaireJSON::sauvegarderQuestionnaire(const Questionnaire &questionnaire) const {

}
