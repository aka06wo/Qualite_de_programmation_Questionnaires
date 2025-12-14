#include "certificatText.h"

certificatText::certificatText() : certificat{}
{

}
 void certificatText::genereCertificat() const
 {
     std::ofstream os(d_nomFichier);
     //Afficheur::separateur(100,'=') ;
     os<<std::string(12,' ')<<"| CERTIFICAT DE REUSSITE |"<<std::string(12,' ')<<'\n';
     //os<<"Felicitations "<<d_nomUtilisateur << " pour votre score de : "<<d_score ;
     //os<<"\nau questionnaire ["<<d_nomquestionnaire<<"]\n";
    // Afficheur::separateur(100,'=') ;

 }
