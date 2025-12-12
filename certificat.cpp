#include "certificat.h"

certificat::certificat():
    d_nomUtilisateur{},d_nomquestionnaire{},d_score{}
{
}

/*
 �a marche, seul point n�gatif, ici on cr�e une classe par utilisateur, 1000 utilisateurs, 1000 classes c'est beaucoup
 il faut une seule classe qui gere touts les utilisateurs, donc constructeur vide
 si on veut un fichier html, on dit a la classe de generer pour la personne donn�e en parametre

certificat::certificat(const std::string& nomUtilisateur,const std::string& nomQuestionnaire,int score):
    d_nomUtilisateur{nomUtilisateur},d_nomquestionnaire{nomQuestionnaire},d_score{score}
{
}


 //Et si on demandais pas os en parametres et qu'on affichait directement ?

void certificat::certificatText(std::ostream& os) const
{
    os << std::string(100,'=') << std::endl ;
    os<<std::string(12,' ')<<"| CERTIFICAT DE REUSSITE |"<<std::string(12,' ')<<'\n';
    os<<"Felicitations "<<d_nomUtilisateur << " pour votre score de : "<<d_score ;
    os<<"\nau questionnaire ["<<d_nomquestionnaire<<"]\n";
    os << std::string(100,'=') << std::endl ;
}


void certificat::certificatHtml(std::ostream& os) const
{
    os << "<!DOCTYPE html>\n";
    os << "<html lang=\"fr\">\n";
    os << "<head>\n";
    os << "    <meta charset=\"UTF-8\">\n";
    os << "    <title>Certificat de reussite</title>\n";
    // os << "<style>\n"; // � ajouter apr�s si besoin
    os << "</head>\n";
    os << "<body>\n";
    os << "    <div class=\"certificat\">\n";
    os << "        <h1>Certificat de reussite</h1>\n";
    os << "        <p>Felicitations <strong>" << d_nomUtilisateur << "</strong> !</p>\n";
    os << "        <p>Pour votre score de: <strong>" << d_score << "</strong></p>\n";
    os << "        <p>Au questionnaire: <strong>" << d_nomquestionnaire << "</strong></p>\n";
    os << "    </div>\n";
    os << "</body>\n";
    os << "</html>\n";
}


*/

