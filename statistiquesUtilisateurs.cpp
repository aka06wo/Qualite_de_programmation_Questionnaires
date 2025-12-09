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

std::string statistiquesUtilisateurs::messageSelonScore(double pourcentage)
{
    std::string message{""} ;
    message += "Score obtenu : " + std::to_string(pourcentage) + '\n' ;

    if (pourcentage >= 90) {
        message += "Félicitations ! Tu es un génie, presque invincible !\n";
    }
    else if (pourcentage >= 75) {
        message += "Bravo ! Très bon travail \n";
    }
    else if (pourcentage >= 50) {
        message += "Pas mal ! Mais tu peux faire encore mieux, on croit en toi !\n";
    }
    else if (pourcentage >= 25) {
        message += "Hum... ça commence à se compliquer. Allez, courage !\n";
    }
    else {
        message += "Oups... peut-être que tu devrais revoir tes notes";
    }

    return message ;
}


void statistiquesUtilisateurs::chargerStatistiques() {
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

    }
}




