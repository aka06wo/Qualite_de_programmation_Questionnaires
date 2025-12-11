#ifndef CODE_QUESTIONNAIRE_AFFICHEUR_H
#define CODE_QUESTIONNAIRE_AFFICHEUR_H

#include <string>

class Afficheur
{
    public :
    static void separateur(int largeur, char symbole) ;
    static void messageSelonScore(double pourcentage) ;
    static void affichageConsole(const std::string &message) ;

    private :
    Afficheur();
};


#endif //CODE_QUESTIONNAIRE_AFFICHEUR_H
