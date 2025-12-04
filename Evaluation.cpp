#include "Evaluation.h"
#include "certificat.h"

Evaluation::Evaluation(const Questionnaire &questionnaire) : d_questionnaire(&questionnaire),
    d_nbEssai{0}, d_score{0}, d_tabIndiceErreur{}
{
}

std::string Evaluation::reponseUtilisateurQuestion() const
{
    std::string reponse ;
    std::cin>>reponse;
    return reponse;
}
std::string Evaluation::lireReponseValide(int indiceQuestion) const
{
    std::string reponse;
    reponse = reponseUtilisateurQuestion();
    while (!d_questionnaire->validiteEntreeUtilisateur(indiceQuestion, reponse))
    {
        reponse = reponseUtilisateurQuestion();
    }
    return reponse;
}
void Evaluation::resultatEvaluation() const
{
    std::cout << "Vous avez une score de "+ std::to_string(d_score)
              +" sur "+std::to_string(d_questionnaire->nombreDeQuestions()) ;
              if(d_score>70)
                genererCertificatHtml();
}
void Evaluation::genererCertificatHtml() const
{
 std::string nomUtilisateur;
    std::cout<< "Saisissez votre nom :";
    std::cin>>nomUtilisateur;
    certificat c(nomUtilisateur,d_questionnaire->nomQuestionnaire(),d_score);
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
void Evaluation::genererCertificatText() const
{
  //revoir ça car je ne sais pas si c'est la peine de le faire
}
