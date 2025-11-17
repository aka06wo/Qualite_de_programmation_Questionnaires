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

json QuestionnaireJSON::conversionJSON(const Questionnaire &q) const {

}

void QuestionnaireJSON::sauvegarderQuestionnaire(const Questionnaire &questionnaire) const {
    json tousLesQuestionnaires;
    std::ifstream monFichier("Fichier_Questionnaire.json");
    monFichier >> tousLesQuestionnaires;
    monFichier.close();

    for (auto &q : tousLesQuestionnaires)
    {
        if (q["titre"] == questionnaire.nomQuestionnaire()) {
            q= conversionJSON(questionnaire); // ton questionnaire converti en json
            break;
        }
    }
    // écrire tout le tableau
    std::ofstream fichier_out("Fichier_Questionnaire.json");
    fichier_out << tousLesQuestionnaires.dump(4);
    fichier_out.close();
}
