#include "certificatHTML.h"
#include <fstream>

certificatHTML::certificatHTML() : certificat{}
{

}

void certificatHTML::genereCertificat(const std::string &nomQuestionnaire,
                const std::string &descriptionQ, int score, int nbQuestions) const
{
    std::ofstream fichier("certificatHtml");

    fichier << "<!DOCTYPE html>\n";
    fichier << "<html lang=\"fr\">\n";
    fichier << "<head>\n";
    fichier << "    <meta charset=\"UTF-8\">\n";
    fichier << "    <title>Certificat de reussite</title>\n";
    // os << "<style>\n"; // à ajouter après si besoin
    fichier << "</head>\n";
    fichier << "<body>\n";
    fichier << "    <div class=\"certificat\">\n";
    fichier << "        <h1>Certificat de reussite</h1>\n";
    fichier << "            <p>Felicitations pour votre score de " + std::to_string(score) +
                                "sur " + std::to_string(nbQuestions) + "sur le questionnaire ["+nomQuestionnaire +
                                    "] qui portait sur : " + descriptionQ + "</p>";
    fichier << "    </div>\n";
    fichier << "</body>\n";
    fichier << "</html>\n";

    fichier.close();
}

