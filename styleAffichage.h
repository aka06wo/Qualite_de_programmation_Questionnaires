#ifndef CODE_QUESTIONNAIRE_STYLEAFFICHAGE_H
#define CODE_QUESTIONNAIRE_STYLEAFFICHAGE_H
#include <string>

//
// Classe utilitaire statique pour la gestion visuelle de l'interface console
//
class styleAffichage
{
public :
    //
    // Fonctions de mise en page pour la structure du questionnaire
    //
    static void affichageEnteteActivites (const std::string &msg) ;
    static void affichagePiedDePageActivites (const std::string &nom) ;
    static void affichageEnteteQuestion(const std::string &nomActivite, int numQuestion, int nbQuestions) ;
    static void affichagePiedDePageQuestion() ;

    //
    // Fonctions de stylisation du texte via les codes couleurs
    //
    static void ecritEnGras(const std::string &msg) ;
    static void ecritEnBleu(const std::string &msg) ;
    static void ecritEnRouge(const std::string &msg) ;
    static void ecritEnVert(const std::string &msg) ;
    static void ecritEnBleuCiel(const std::string &msg) ;
    static void ecritEnBleuCielGras(const std::string &msg) ;

private:
    //
    // Constructeur privé pour empêcher l'instanciation de la classe
    //
    styleAffichage() ;
};


#endif //CODE_QUESTIONNAIRE_STYLEAFFICHAGE_H