#include "certificatHTML.h"

certificatHTML::certificatHTML() : certificat{}
{

}
void certificatHTML::genereCertificat() const
{
    std::ofstream os(d_nomFichier);
    os << "<!DOCTYPE html>\n";
    os << "<html lang=\"fr\">\n";
    os << "<head>\n";
    os << "    <meta charset=\"UTF-8\">\n";
    os << "    <title>Certificat de reussite</title>\n";
    // os << "<style>\n"; // à ajouter après si besoin
    os << "</head>\n";
    os << "<body>\n";
    os << "    <div class=\"certificat\">\n";
    os << "        <h1>Certificat de reussite</h1>\n";
    //os << "        <p>Felicitations <strong>" << d_nomUtilisateur << "</strong> !</p>\n";
    //os << "        <p>Pour votre score de: <strong>" << d_score << "</strong></p>\n";
    //os << "        <p>Au questionnaire: <strong>" << d_nomquestionnaire << "</strong></p>\n";
    os << "    </div>\n";
    os << "</body>\n";
    os << "</html>\n";

}
