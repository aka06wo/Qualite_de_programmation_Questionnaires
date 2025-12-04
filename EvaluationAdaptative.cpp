#include "EvaluationAdaptative.h"
#include "certificat.h"

EvaluationAdaptative::EvaluationAdaptative(const Questionnaire &questionnaire):Evaluation{questionnaire}
{
}
std::string EvaluationAdaptative::lireReponseValide(int indiceQuestion ) const
{
       std::string  reponse = reponseUtilisateurQuestion();
    while (!d_questionnaire->validiteEntreeUtilisateur(indiceQuestion, reponse)) {
        std::cout << "Entrée invalide, veuillez saisir une entrée valide.\n";
        reponse = reponseUtilisateurQuestion();
        //std::cout<<"Entrée invalide ! Veuillez saisir un nombre : " ;
        // si je veux faire cela, dire ce qu'il faut rentrer
        // il faut que les autres tests soit bien fait avec des if else
        // sur validite entreeutilisatuer
    }
    return reponse;

}
void EvaluationAdaptative::lanceEvaluation()
{
    ++d_nbEssai;
    std::srand(std::time(nullptr));
    std::vector<int> d_IndQuestionsNonposees;
    for (int i=0; i<d_questionnaire->nombreDeQuestions(); ++i)
        d_IndQuestionsNonposees.push_back(i);

    std::vector<int> d_questionsFaussees{};

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
            d_questionsFaussees.push_back(indQuestion);

        }
        d_IndQuestionsNonposees.erase(d_IndQuestionsNonposees.begin()+indiceAlea);
        std::cout << std::string(100, '=') << '\n';
    }

    for(int i{0}; i<d_questionsFaussees.size(); ++i)
    {
        std::cout << std::string(100, '=') << '\n';
        d_questionnaire->afficherQuestionNumero(d_questionsFaussees[i]);
        std::string reponse=lireReponseValide(d_questionsFaussees[i]);

        bool reponseCorrecte=d_questionnaire->verificationReponse(d_questionsFaussees[i],reponse);

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

}

void EvaluationAdaptative::resultatEvaluation() const
{

    //pour l'instant avant les certificat
    std::cout<< "Resultat :"<< d_score<<"/"<<d_questionnaire->nombreDeQuestions()<< '\n';
    std::cout<< "Nombre d'Essais" << d_nbEssai<< '\n';
    std::string nomUtilisateurs;
    std::cout<< "Saisissez votre nom :";
    std::cin>>nomUtilisateurs;
    certificat c(nomUtilisateurs,d_questionnaire->nomQuestionnaire(),d_score);
     std::string nomFichier = "certificat_" + nomUtilisateur + ".html";
    std::ofstream fichier(nomFichier);

    if (!fichier)
    {
        std::cerr << "Erreur : impossible de créer le fichier certificat.\n";
        return;
    }
    c.certificatHtml(fichier);
    fichier.close();
    std::cout << "Certificat généré !" << std::endl;
}

