#include "EvaluationAdaptative.h"

EvaluationAdaptative::EvaluationAdaptative(const Questionnaire &questionnaire):Evaluation{questionnaire}
{
}



/*

    Aisse en fait Ã§a marche pour charger les questions depuis le questionnaires,

    mais je te proposes de que quand tu finisses d'affichers les questions et que t'as recuperes
    les endroits ou il s'est trompÃ©
    Pour commencer a lui poser les questions ou il s'est trompÃ©, fait lui savoir
    ( fait un affichage pour lui "Que voilÃ , qu'on lui repose les questions maintenant")


    Aisse en fait ça marche pour charger les questions depuis le questionnaires,

    mais je te proposes de que quand tu finisses d'affichers les questions et que t'as recuperes
    les endroits ou il s'est trompé
    Pour commencer a lui poser les questions ou il s'est trompé, fait lui savoir
    ( fait un affichage pour lui "Que voilà, qu'on lui repose les questions maintenant")

    Et regarde la methode separateur que j'ai mis dans evaluation, tu peux te servir de cela pour afficher tes '='


    ta methode est bien ecrite et tout, mais voilÃ  je te mets la barre un peu haute (j'ai confiance)
    Ameliore lÃ , comment tu la prÃ©sentes, optimise lÃ  et tout
    TU PEUX LE FAIRE :)



 */

void EvaluationAdaptative::lanceEvaluation()
{
    ++d_nbEssai;
    std::srand(std::time(nullptr));
    std::vector<int> d_IndQuestionsNonposees;
    for (int i=0; i<d_questionnaire->nombreDeQuestions(); ++i)
        d_IndQuestionsNonposees.push_back(i);

    //std::vector<int> d_questionsFaussees{};

    while(!d_IndQuestionsNonposees.empty() )
    {
        std::cout << std::string(100, '=') << '\n';
        int indiceAlea=rand()%(d_IndQuestionsNonposees.size());
        int indQuestion=d_IndQuestionsNonposees[indiceAlea];

        d_questionnaire->afficherQuestionNumero(indQuestion);

        std::string reponse=lireReponseValide(indQuestion);

        bool reponseCorrecte=d_questionnaire->verificationReponse(indQuestion,reponse);

        if(reponseCorrecte)
        {
            std::cout<< "[v] Bonne reponse !"<<'\n';
            ++d_score;
        }
        else
        {
            std::cout<<"[x] Mauvaise reponse !"<< '\n';
            d_tabIndiceErreur.push_back(indQuestion);

        }
        d_IndQuestionsNonposees.erase(d_IndQuestionsNonposees.begin()+indiceAlea);
        std::cout << std::string(100, '=') << '\n';
    }

    for(int i{0}; i<d_tabIndiceErreur.size(); ++i)
    {
        std::cout << std::string(100, '=') << '\n';
        d_questionnaire->afficherQuestionNumero(d_tabIndiceErreur[i]);
        std::string reponse=lireReponseValide(d_tabIndiceErreur[i]);

        bool reponseCorrecte=d_questionnaire->verificationReponse(d_tabIndiceErreur[i],reponse);

        if(reponseCorrecte)
        {
            std::cout<< "[v] Bonne reponse !"<<'\n';
            ++d_score;
        }
        else
        {
            std::cout<<"[x] Mauvaise reponse !"<< '\n';
        }
        std::cout << std::string(100, '=') << '\n';

    }
    resultatEvaluation();
}