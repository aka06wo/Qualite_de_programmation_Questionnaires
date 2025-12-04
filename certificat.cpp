#include "certificat.h"

certificat::certificat(const std::string& nomUtilisateur,const std::string& nomQuestionnaire,int score):
    d_nomUtilisateur{nomUtilisateur},d_nomquestionnaire{nomQuestionnaire},d_score{score}
{
}

void certificat::certificatText(std::ostream& os) const
{
    os<<std::string(100,'=')<<'\n';
    os<<std::string(12,' ')<<"| CERTIFICAT DE REUSSITE |"<<std::string(12,' ')<<'\n';
    os<<std::string(100,'=')<<'\n';
    os<<"Félicitations "<<d_nomUtilisateur << " pour votre score de: ";
    os<<d_score << "au questionnaire "<<d_nomquestionnaire<<'\n';

}
void certificat::certificatHtml(std::ostream& os) const
{
    os<<"!DOCTYPE html\n";
    os<<"<html>\n";
    os<<"<head>\n";
    os<<"<meta charset=\"UTF-8\">\n <title>Certificat de réussite</title>\n";
    //os<<"<style>\n"; a ajouter aprés
    os<<"<div class=\"certificat\">\n";
    os<<"<h1>Certificat de réussite</h1>\n";
    os<<"<p>Félicitations <strong>" << d_nomUtilisateur << "</strong> !</p>";
    os<<" pour votre score de: "<<d_score<<"</h2>";
    os<<" au questionnaire <strong>" << d_nomquestionnaire << "</strong>\n";
    os<<"/p>\n";
    os<<"</div>\n";
    os<<"</body>\n";
    os<<"</html>\n";
}
