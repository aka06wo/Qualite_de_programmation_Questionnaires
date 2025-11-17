#include "QuestionTexte.h"
#include <memory>
#include <cctype> //Pour la fonction tolower
using std::cout;
using std::cin;
using std::endl;

 QuestionTexte::QuestionTexte(const string &intitule,const string &reponse): Question{intitule},d_reponseCorrecte{reponse}
 {
 }

 void QuestionTexte::afficherReponse() const
 {
     cout<<"La réponse correcte est: "<<d_reponseCorrecte<<endl;
 }

 string QuestionTexte::reponse() const
 {
     return d_reponseCorrecte;
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
