#ifndef CODE_QUESTIONNAIRE_ESSAI_H
#define CODE_QUESTIONNAIRE_ESSAI_H

#include <vector>

class essai
{
    public:
    friend class Evaluation ;

    /**
     Enregistre l'indice d'une question pour laquelle l'utilisateur a fait une erreur
     @param indiceErreur L'indice de la question mal repondue
     */
    void saisieErreurs(int indiceErreur);

    /**
     Incremente le score de l'essai courant (ajoute 1 point)
     */
    void augmenteScore();

    /**
     Renvoie le score actuel de l'essai
     @return Le nombre de bonnes reponses obtenues
     */
    int score() const;

    /**
     Renvoie le nombre total d'erreurs enregistrees lors de cet essai
     @return Le nombre d'erreurs
     */
    int nombreErreurs() const;

    /**
     Renvoie l'indice de la question correspondant à une erreur specifique
     @param indiceErreur La position de l'erreur dans la liste des erreurs
     @return L'indice de la question qui a ete mal repondue
     */
    int erreurNumero(int indiceErreur) const;

    /**
     Remet à zero le score et la liste des erreurs pour recommencer un essai
     */
    void reinitialise();

    private:
    int d_score ;
    std::vector<int> d_tabErreur ;
    /**
    Constructeur par defaut de la classe essai
    Initialise le score à 0 et vide la liste des erreurs
    */
    essai();
};


#endif //CODE_QUESTIONNAIRE_ESSAI_H