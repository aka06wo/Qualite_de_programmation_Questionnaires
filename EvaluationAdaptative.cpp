#include "EvaluationAdaptative.h"
#include "Afficheur.h"

EvaluationAdaptative::EvaluationAdaptative(const Questionnaire &questionnaire,
                        std::unique_ptr<Afficheur> afficheur) : Evaluation{questionnaire,std::move(afficheur)}
{
}

void EvaluationAdaptative::PoseQuestionsDe(std::vector<int>& tableau)
{
    std::srand(std::time(nullptr));
    std::string reponseUtilisateur="";
     while(!tableau.empty())
    {
       d_afficheur->separateur(100,'=') ;

        int indiceAlea=rand()%(tableau.size());
        int indQuestion=tableau[indiceAlea];

        std::cout<<d_questionnaire->intituleQuestionNumero(indQuestion) ;
        std::cout<<d_questionnaire->instructionsQuestionNumero(indQuestion) ;

        getline(std::cin,reponseUtilisateur);

        reponseUtilisateur=lireReponseValide(indQuestion,reponseUtilisateur);

        bool reponseCorrecte=d_questionnaire->verificationReponse(indQuestion,reponseUtilisateur);

        if(reponseCorrecte)
        {
            std::cout<< "[v] Bonne reponse !"<<'\n';
            augmenteScore();
        }
        else
        {
            std::cout<<"[x] Mauvaise reponse !"<< '\n';
            enregistreErreurs(indQuestion) ;

        }
        tableau.erase(tableau.begin()+indiceAlea);
        d_afficheur->separateur(100,'=') ;
        std::cout<<'\n' ;
    }


}
void EvaluationAdaptative::ReposerQuestionsFausses()
{
    std::string reponseUtilisateur="";
    int i=d_questionnaire->nombreDeQuestions()-score();
    while(i!=0)
        {
        d_afficheur->separateur(100,'=') ;

        std::cout<<d_questionnaire->intituleQuestionNumero(i) ;
        std::cout<<d_questionnaire->instructionsQuestionNumero(i) ;

        getline(std::cin,reponseUtilisateur);

        reponseUtilisateur=lireReponseValide(i,reponseUtilisateur);

        bool reponseCorrecte=d_questionnaire->verificationReponse(i,reponseUtilisateur);

        if(reponseCorrecte)
        {
            std::cout<< "[v] Bonne reponse !"<<'\n';
            augmenteScore();
        }
        else
        {
            std::cout<<"[x] Mauvaise reponse !"<< '\n';
        }
        d_afficheur->separateur(100,'=') ;
        std::cout<<'\n' ;
        --i;

        }

}
void EvaluationAdaptative::lanceEvaluation()
{
    augmenteEssai();
    std::vector<int> d_IndQuestionsNonposees;
    for (int i=0; i<d_questionnaire->nombreDeQuestions(); ++i)
        d_IndQuestionsNonposees.push_back(i);

    std::vector<int> d_questionsFaussees{};

        PoseQuestionsDe(d_IndQuestionsNonposees);

        if(!d_questionsFaussees.empty())
        {
            std::cout<< "Vous avez terminez de répondre Au Questionnaire";//je vais revoir comment mieux le dire
            ReposerQuestionsFausses();
        }

    resultatEvaluation();
}
