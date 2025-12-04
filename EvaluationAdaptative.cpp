#include "EvaluationAdaptative.h"
#include "certificat.h"

EvaluationAdaptative::EvaluationAdaptative(const Questionnaire &questionnaire):Evaluation{questionnaire}
{
}

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
            std::cout<< "[v] Bonne réponse !"<<'\n';
            ++d_score;
        }
        else
        {
            std::cout<<"[x] Mauvaise réponse !"<< '\n';
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
            std::cout<< "[v] Bonne réponse !"<<'\n';
            ++d_score;
        }
         else
        {
            std::cout<<"[x] Mauvaise réponse !"<< '\n';
        }
        std::cout << std::string(100, '=') << '\n';

    }
  resultatEvaluation();
}

/*void EvaluationAdaptative::resultatEvaluation() const
{

    //pour l'instant avant les certificat
    std::cout<< "Resultat :"<< d_score<<"/"<<d_questionnaire->nombreDeQuestions()<< '\n';
    std::cout<< "Nombre d'Essais" << d_nbEssai<< '\n';

}
*/
