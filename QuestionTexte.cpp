
#include "QuestionTexte.h"
#include <cctype> //Pour la fonction tolower
using std::cout;
using std::cin;
using std::endl;
 QuestionTexte::QuestionTexte(const string &intitule,const string &texte,const string &reponse):Question{intitule}
 ,d_texte{texte},d_reponseCorrecte{reponse}
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
 void QuestionTexte::afficherQuestion() const
 {
     //On utilise d'abord l'intiltulé de la question déjà défini dans la classe mère
     cout<<intitule()<<end;
     //Puis on ajoute la question texte de notre classe
     cout<<d_texte<<endl;
     //Ex:"Algorithme","Comment appelle t-on un noeud qui n'a pas de fils?"
 }
 bool QuestionTexte::verificationReponse(const string &reponse) const
 {
     if(reponse.length()!=d_reponseCorrecte.length)
        return false;//Si les textes n'ont pas la même taille,ils ne peuvent pas être égales
     else
     {
         for(int i=0;i<reponse.length;i++)
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
