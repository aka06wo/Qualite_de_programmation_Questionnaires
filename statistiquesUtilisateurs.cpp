#include <fstream>
#include "statistiquesUtilisateurs.h"


statistiquesUtilisateurs::statistiquesUtilisateurs() : d_statistiquesUtilisateurs{json::object()}
{
    chargerStatistiques();
}

statistiquesUtilisateurs::~statistiquesUtilisateurs() {
    sauverStatistiques() ;
}

std::string statistiquesUtilisateurs::nomFichierStatistiquesJSON() {
    return std::string{"statistiquesUtilisateurs.json"};
}

std::string statistiquesUtilisateurs::NomFichierQuestionnairesSauvegarde() {
    return std::string{"statistiquesUtilisateursSauvegarde.json"};
}


void statistiquesUtilisateurs::chargerStatistiques()
{
    std::ifstream fichierStatistiques {nomFichierStatistiquesJSON()} ;
    if (fichierStatistiques.is_open())
    {
        try {
            fichierStatistiques>>d_statistiquesUtilisateurs ;
            fichierStatistiques.close();
        } catch (const json::parse_error &e) {
            // std::cerr << "Erreur JSON : " << e.what() << std::endl;
            return ;
        }
    }
}

void statistiquesUtilisateurs::sauverStatistiques()
{
    std::ofstream fichier_sauv(NomFichierQuestionnairesSauvegarde());
    fichier_sauv << d_statistiquesUtilisateurs.dump(4);
    fichier_sauv.close();
}

json statistiquesUtilisateurs::extraireUtilisateur(const std::string &nomUtilisateur) const
{
    json utilisateur {json::object()};
    try {
        utilisateur = d_statistiquesUtilisateurs.at(nomUtilisateur);
        return utilisateur;
    } catch (const json::out_of_range &e) {
        return utilisateur ;
    }
}




/*
 A terminer plus tard, faire attention au temps (on l'implemente ou pas ??) et aux stats du type

 Meilleure score,
 temps total
 nombre de questionnaires
 nombre d'essai par questionnaire
 */
std::string statistiquesUtilisateurs::statistiquesPourUtilisateur
        (const std::string &nomUtilisateur) const
{
    json utilisateur {extraireUtilisateur(nomUtilisateur)} ;
    if (utilisateur.empty())
    {
        return std::string("Aucune donnée trouvée pour l'utilisateur : "+nomUtilisateur) ;
    }
    else
    {
        return "" ;
    }
}




