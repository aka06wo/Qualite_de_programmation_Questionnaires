#include "certificat.h"

certificat::certificat(const std::string& nomUtilisateur,const std::string& nomQuestionnaire,int score):d_nomUtilisateur{nomUtilisateur},d_nomquestionnaire{nomQuestionnaire},d_score{score}
{
}
std::string certificat::lireFichier(const std::string &nomFichier) const
{
    std::ifstream fichier(nomFichier);
    if (!fichier)
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << nomFichier << '\n';
        return "";
    }

    std::string contenu;
    std::string ligne;
    while (std::getline(fichier, ligne))
    {
        contenu += ligne + '\n';
    }

    return contenu;
}
void certificat::remplacer(std::string& texte,
                           const std::string& nomQues,
                           const std::string& score) const
{
    auto echanger = [&](const std::string &a, const std::string &b)
    {
        size_t pos = 0;
        while ((pos = texte.find(a, pos)) != std::string::npos)
        {
            texte.replace(pos, a.size(), b);
            pos += b.size();
        }
    };

    echanger("{{nom}}", d_nomUtilisateur);
    echanger("{{evaluation}}", nomQues);
    echanger("{{score}}", score);

    if (d_score >= 70)
        echanger("{{message}}", "F?licitations pour votre r?ussite !");
    else
        echanger("{{message}}", "Merci pour votre participation.\n N'h?sitez pas ? retenter votre chance!");
}
void certificat::certficatText () const
{
    std::string modele = lireFichier("certificat.txt");

    if (modele.empty())
    {
        std::cerr << "Erreur : modele certificat.txt introuvable.\n";
        return;
    }

    remplacer(modele, d_nomquestionnaire, std::to_string(d_score));

    std::ofstream fichier("certificat_final.txt");
    fichier << modele;

    std::cout << "Certificat texte genere : certificat_final.txt\n";
}

void certificat::certficatHtml () const
{
    std::string modele = lireFichier("certificat.html");
    if (modele.empty()) return;

    remplacer(modele, d_nomquestionnaire, std::to_string(d_score));

    std::ofstream fichier("certificat_final.html");
    fichier << modele;

    std::cout << "Certificat HTML genere : certificat_final.html\n";
}