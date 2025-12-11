#include "EvaluationAdaptative.h"
#include "Afficheur.h"

EvaluationAdaptative::EvaluationAdaptative(const Questionnaire &questionnaire):Evaluation{questionnaire}
{
}

// utiliser augmente score, erreur, et essai
// pour pouvoir mettre leurs attributs en privée et juste utilisez les methodes
// deja fait dans evaluation seconde chance
// eva adaptative ??
void EvaluationAdaptative::PoseQuestions(vector<int>& tableau,vector<int>& TableauErreurs )
{
     while(!tableau.empty())
    {
        Afficheur::separateur(100,'=');

        int indiceAlea=rand()%(tableau.size());
        int indQuestion=tableau[indiceAlea];

        std::cout<<d_questionnaire->intituleQuestionNumero(indQuestion) ;
        std::cout<<d_questionnaire->instructionsQuestionNumero(indQuestion) ;

        std::string reponse=lireReponseValide(indQuestion);

        bool reponseCorrecte=d_questionnaire->verificationReponse(indQuestion,reponse);

        if(reponseCorrecte)
        {
            std::cout<< "[v] Bonne reponse !"<<'\n';
            augmenteScore();
        }
        else
        {
            std::cout<<"[x] Mauvaise reponse !"<< '\n';
            TableauErreurs.push_back(indQuestion);

        }
        tableau.erase(tableau.begin()+indiceAlea);
        Afficheur::separateur(100,'=') ;
        std::cout<<'\n' ;
    }


}
void EvaluationAdaptative::lanceEvaluation()
{
    augmenteEssai();
    std::srand(std::time(nullptr));
    std::vector<int> d_IndQuestionsNonposees;
    for (int i=0; i<d_questionnaire->nombreDeQuestions(); ++i)
        d_IndQuestionsNonposees.push_back(i);

    std::vector<int> d_questionsFaussees{};

        PoseQuestions(d_IndQuestionsNonposees,d_questionsFaussees);

        if(!d_questionsFaussees.empty())
        {
            cout<< "Vous avez terminez de répondre Au Questionnaire";//je vais revoir comment mieux le dire

            PoseQuestions(d_questionsFaussees,d_tabIndiceErreur);
        }

    resultatEvaluation();
}
