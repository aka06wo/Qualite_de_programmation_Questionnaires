#include "EvaluationAdaptative.h"
#include "Afficheur.h"

EvaluationAdaptative::EvaluationAdaptative(const Questionnaire &questionnaire):Evaluation{questionnaire}
{
}

// utiliser augmente score, erreur, et essai
// pour pouvoir mettre leurs attributs en privée et juste utilisez les methodes
// deja fait dans evaluation seconde chance
// eva adaptative ??

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
        Afficheur::separateur(100,'=') ;

        int indiceAlea=rand()%(d_IndQuestionsNonposees.size());
        int indQuestion=d_IndQuestionsNonposees[indiceAlea];

        std::cout<<d_questionnaire->intituleQuestionNumero(indQuestion) ;
        std::cout<<d_questionnaire->instructionsQuestionNumero(indQuestion) ;

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
        Afficheur::separateur(100,'=') ;
        std::cout<<'\n' ;
    }

    /*
     Il faut que l'utilisateur sache que tu commences l'examen sur les questions ou il avait faut
     Juste un affichage
     du style (Lui dire qu'on lui repose les questions sur les quels il avait pas trouvé la reponse
     */

    for(int i{0}; i<d_tabIndiceErreur.size(); ++i)
    {
        Afficheur::separateur(100,'=') ;
        std::cout<<d_questionnaire->intituleQuestionNumero(d_tabIndiceErreur[i]) ;
        std::cout<<d_questionnaire->instructionsQuestionNumero(d_tabIndiceErreur[i]) ;
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
        Afficheur::separateur(100,'=') ;
        std::cout <<'\n';

    }
    resultatEvaluation();
}