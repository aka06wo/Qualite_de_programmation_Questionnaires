#include "QuestionTexte.h"
#include <memory>
#include <iostream>
#include <cctype> //Pour la fonction tolower

using std::cout;
using std::endl;
using std::string;


 QuestionTexte::QuestionTexte(const string &intitule,const string &reponse): Question{intitule},d_reponseCorrecte{reponse}
 {
 }

string QuestionTexte::intitule() const
{
    return string{d_intitule+'\n'};
}

string QuestionTexte::instructionsQuestion() const {
     return string {"Saisissez la bonne reponse\n"} ;
 }

string QuestionTexte::reponse() const
{
     return string{d_reponseCorrecte+'\n'} ;
 }

bool QuestionTexte::validiteEntreeUtilisateur(const string &reponse) const {
    if (reponse.empty()) {
        std::cout<<"Veuillez entrez une reponse\n" ;
        return false ;
    }
     else
         return true ;
}


 bool QuestionTexte::verificationReponse(const string &reponse) const
 {
     if(reponse.length()!=d_reponseCorrecte.length())
        return false;
     else
     {
         for(int i=0;i<reponse.length();i++)
         {
             if(tolower(reponse[i])!=tolower(d_reponseCorrecte[i]))
             {
                 return false;
                 //tolower permet de convertir une lettre en miniscule
             }
         }
         return true;
     }
 }


std::unique_ptr<Question> QuestionTexte::clone() const {
     return std::make_unique<QuestionTexte>(*this);
 }


nlohmann::json QuestionTexte::conversionJSON() const {
     return nlohmann::json {
         {"type", "texte"},
         {"question", intitule()},
         {"reponseCorrecte", reponse()}
     };
 }
