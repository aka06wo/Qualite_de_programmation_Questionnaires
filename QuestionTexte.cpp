#include "QuestionTexte.h"
#include <memory>
#include <cctype> //Pour la fonction tolower
using std::cout;
using std::cin;
using std::endl;


 QuestionTexte::QuestionTexte(const string &intitule,const string &reponse): Question{intitule},d_reponseCorrecte{reponse}
 {
 }

void QuestionTexte::afficherQuestion() const {
     cout<<intitule()<<endl ;
     cout<<"Saisissez la bonne reponse :\n" ;
 }

 void QuestionTexte::afficherReponse() const
 {
     cout<<"La reponse correcte est : "<<reponse()<<endl;
 }

 string QuestionTexte::reponse() const
 {
     return d_reponseCorrecte;
 }

bool QuestionTexte::validiteEntreeUtilisateur(const string &reponse) const {
    if (reponse.empty()) {
        cout<<"Veuillez entrez une reponse\n" ;
        return false ;
    }
     else
         return true ;
}

// C'est pas trop lourd en test ??
 bool QuestionTexte::verificationReponse(const string &reponse) const
 {
     if(reponse.length()!=d_reponseCorrecte.length())
        return false;//Si les textes n'ont pas la même taille,ils ne peuvent pas être égales
     else
     {
         for(int i=0;i<reponse.length();i++)
         {
             if(tolower(reponse[i])!=tolower(d_reponseCorrecte[i]))
             {
                 return false;
                 //tolower permet de convertir une lettre en miniscule
                 //Ce qui permet d'ignorer la casse lors de la comparaison
             }
         }
          return true;
     }
 }

//désolé je devais le faire pour tester
std::unique_ptr<Question> QuestionTexte::clone() const {
     return std::make_unique<QuestionTexte>(*this);
 }


json QuestionTexte::conversionJSON() const {
     return json{
         {"type", "texte"},
         {"question", intitule()},
         {"reponseCorrecte", reponse()}
     };
 }
