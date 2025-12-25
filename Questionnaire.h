#ifndef CODE_QUESTIONNAIRE_H
#define CODE_QUESTIONNAIRE_H

#include<string>
#include <vector>
#include <memory>
#include <set>

#include "json.hpp"
#include "Question.h"

class Questionnaire
{
    public :
    friend class QuestionnaireJSON ;

    /**
     Constructeur par defaut de la classe Questionnaire
     */
    Questionnaire() ;

    /**
     Constructeur de la classe Questionnaire avec parametres
     @param nom Le nom du questionnaire
     @param description La description du questionnaire (optionnelle)
     @param Questions Le vecteur contenant les questions (unique_ptr pour la gestion memoire)
     */
    Questionnaire(const std::string &nom, const std::string &description = "" ,
                    const std::vector<std::unique_ptr<Question>> &Questions = {});

    /**
     @return Le nom du questionnaire
     */
    std::string nomQuestionnaire() const ;

    /**
     @return La description du questionnaire
     */
    std::string descriptionQuestionnaire() const ;

    /**
     @return Le nombre total de questions presentes dans le questionnaire
     */
    int nombreDeQuestions() const ;

    /**
     Renvoie l'intitule de la question à l'indice i
     @param i L'indice de la question
     @return L'intitule de la question
     */
    std::string intituleQuestionNumero(int i) const ;

    /**
     Renvoie les instructions specifiques (ex: "Saisir un nombre") de la question à l'indice i
     @param i L'indice de la question
     @return Les instructions de la question
     */
    std::string instructionsQuestionNumero(int i) const ;

    /**
     Renvoie la reponse correcte attendue pour la question à l'indice i
     @param i L'indice de la question
     @return La reponse attendue
     */
    std::string reponseQuestionNumero(int i) const ;

    /**
     Verifie si la saisie de l'utilisateur est conforme au type de la question (ex: chiffres pour une numerique)
     @param i L'indice de la question
     @param reponse La chaine saisie par l'utilisateur
     @return Vrai si la saisie est valide, Faux sinon
     */
    bool validiteEntreeUtilisateur(int i, const std::string &reponse) const ;

    /**
     Verifie si la reponse fournie par l'utilisateur correspond à la reponse attendue
     @param i L'indice de la question
     @param reponse La reponse à verifier
     @return Vrai si la reponse est correcte, Faux sinon
     */
    bool verificationReponse(int i, const std::string &reponse) const ;

    /**
     Renvoie le type de la question situee à l'indice donne (ex: "texte", "numerique", "choixMultiples")
     @param i L'indice de la question
     @return Le type de la question
     */
    std::string typeQuestionNumero(int i) const ;

    /**
     Renvoie la liste de tous les types de questions differents presents dans le questionnaire
     @return Un ensemble (set) contenant les noms uniques des types de questions
     */
    std::set<std::string> nomsDifferentsTypesQuestions() const ;

    private :
    std::string d_nom ;
    std::string d_description ;
    std::vector<std::unique_ptr<Question>> d_Questions ;

    /**
     Change le nom du questionnaire
     @param nomQuestionnaire Le nouveau nom du questionnaire
     */
    void changerNomQuestionnaire(const std::string &nomQuestionnaire);

    /**
     Change la description du questionnaire
     @param descriptionQuestionnaire La nouvelle description du questionnaire
     */
    void changerDescriptionQuestionnaire(const std::string &descriptionQuestionnaire);

    /**
     Ajoute une nouvelle question au questionnaire
     @param q Pointeur intelligent (unique_ptr) vers la question à ajouter
     */
    void ajouterQuestion(std::unique_ptr<Question> q);

    /**
     Convertit l'objet Questionnaire courant en un format JSON
     @return Un objet JSON contenant toutes les donnees du questionnaire (nom, description, questions)
     */
    nlohmann::json conversionQuestionnaireJson() const ;
};


#endif //CODE_QUESTIONNAIRE_H
