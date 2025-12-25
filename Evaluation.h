#ifndef CODE_QUESTIONNAIRE_EVALUATION_H
#define CODE_QUESTIONNAIRE_EVALUATION_H

#include "Questionnaire.h"
#include "essai.h"

#include <string>
#include <vector>

class Evaluation
{
    public:
    /**
     Constructeur avec le questionnaire (on stocke un pointeur constant)
     @param questionnaire l'objet questionnaire
     */
    Evaluation(const Questionnaire &questionnaire);

    /**
     Destructeur virtuel (utilisation du polymorphisme)
     */
    virtual ~Evaluation() = default;

    /**
     @return Le nombre total de questions contenues dans l'objet
     */
    int nombreDeQuestions() const ;

    /**
     Verifie si la reponse fournie par l'utilisateur est correcte pour une question donnee
     @param i L'indice de la question à verifier
     @param rep La reponse proposee par l'utilisateur
     @return Vrai si la reponse correspond à la solution attendue, Faux sinon
     */
    bool reponseJuste (int i, const std::string &rep) const ;

    /**
     Renvoie la reponse attendue pour une question precise
     @param i L'indice de la question concernee
     @return La reponse correcte
     */
    std::string reponseNumero (int i) const ;

    /**
     @return Le nombre de tentatives sur un questionnaire
     */
    int nombreEssais() const ;

    /**
     @return l'objet essai (qui est en cours)
     */
    essai dernierEssai() const ;

    /**
     @return le score de l'utilisateur liée à l'essai en cours
     */
    int scoreDernierEssai() const ;

    /**
     Augmente le score sur l'essai en cours (pour une bonne réponse)
     */
    void augmenteScore() ;

    /**
     Cree une nouvelle tentative en mémoire
     */
    void augmenteEssai() ;

    /**
     Enregistre l'erreur commise par l'utilisateur
     * @param indiceErreur l'indice de l'erreur (son indice dans le tableau de questions)
     */
    void enregistreErreurs(int indiceErreur) ;

    /**
     Affiche les erreurs commises par l'utilisateur
     sur son dernier essai (Questions et réponses)
     * @param numEssai Numero de l'essai (tableau d'essai)
     */
     void afficherErreursEssaiNum(int numEssai) const ;

    /**
    Affiche toutes les erreurs commises par l'utilisateur
    */
    void erreursCommisesEssais() const ;

    /**
     Change le questionnaire pointé par l'evaluation
     * @param nouveauQuestionnaire le nouveau questionnaire
     */
    void changerQuestionnaire(const Questionnaire &nouveauQuestionnaire);

    /**
     @return le pourcentage de réussite du dernier Essai
     */
    double pourcentageReussite() const;

    /**
     @return le message à afficher à la fin de l'evaluation (pourcentage de réussite, message personnalisé)
     */
    std::string resultatEvaluation() const ;

    /**
     Affiche la question
     @param i la question numero i
     @param nbQuestions le nombre de questions
     */
    void affichageQuestionNumero (int i, int nbQuestions) const ;

    /**
    Assure la lecture d'une reponse utilisateur et verifie sa validite selon le type de question
    Si la saisie est invalide, la methode redemande une saisie à l'utilisateur
    @param indiceQuestion L'indice de la question concernee
    @param reponse La chaine de caracteres initialement saisie
    @return Une chaine de caracteres correspondant à une reponse valide
    */
    std::string lireReponseValide(int indiceQuestion, const std::string &reponse) const ;

    /**
     La methode qui lance l'evaluation concernée
     */
    virtual void lanceEvaluation() = 0 ;

    /**
     Methode utilitaire pour generer une ligne de separation visuelle dans la console
     @param c Le caractere utilise pour la separation (ex: '-', '*')
     @param k Le nombre de fois que le caractere doit être repete
     @return La chaine de caracteres de separation
     */
    static std::string separateur(const char &c, int k) ;

    /**
    Genere un message de feedback adapte en fonction du pourcentage de reussite obtenu
    @param pourcentage Le score final exprime en pourcentage (entre 0 et 100)
    @return Un message de felicitation ou d'encouragement
    */
    static std::string messageSelonScore(double pourcentage) ;


    private :
    const Questionnaire *d_questionnaire ;
    std::vector<essai> d_essais;
};


#endif //CODE_QUESTIONNAIRE_EVALUATION_H
