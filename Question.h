#ifndef CODE_QUESTION_H
#define CODE_QUESTION_H

#include<string>
#include<memory>
#include "json.hpp"

class Question
{
public :
    /**
     Constructeur qui sera utilisé par les classes dérivées
     * @param intitule L'intitulé de la question
     */
    Question(const std::string& intitule) ;

    /**
     Destructeur virtuel (polymorphisme)
     */
    virtual ~Question() = default ;

    /**
     Methode virtuelle redefini par les classes derivées
     * @return L'intitulé de la question
     */
    virtual std::string intitule() const = 0 ;

    /**
     Methode virtuelle redefini par les classes derivées
     * @return Les instuctions de la question
     */
    virtual std::string instructionsQuestion() const = 0 ;

    /**
     Methode virtuelle redefini par les classes derivées
     * @return La reponse de la question
     */
    virtual std::string reponse() const = 0;

   /**
    Methode virtuelle redefini par les classes derivées,
    elle verifie que la saisie
    de l'utilisateur est valide pour la question
    * @return Vrai si la saisie est valide, faux sinon
    */
    virtual bool validiteEntreeUtilisateur(const std::string &reponse) const = 0 ;

     /**
     Methode virtuelle redefini par les classes derivées,
     elle verifie la réponse de l'utilisateur
     * @return Vrai si la réponse est juste, faux sinon
     */
    virtual bool verificationReponse(const std::string &reponse) const = 0 ;

    /**
     Methode virtuelle redefini par les classes derivées,
     elle renovoie un clone (copie polymorphe)
     * @return Un nouveau pointeur dynamique sur l'objet créée
     */
    virtual std::unique_ptr<Question> clone() const=0 ;

   /**
    Methode virtuelle redefini par les classes derivées,
    Elle convertit la question en format JSON pour la sauvegarde du questionnaire
    * @return L'intitulé de la question
    */
    virtual nlohmann::json conversionJSON () const = 0;

   /**
    Methode virtuelle redefini par les classes derivées
    * @return Le type de la question (QCM, Numerique ou Texte)
    */
    virtual std::string typeQuestion() const = 0 ;

    protected :
    std::string d_intitule ;
};


#endif //CODE_QUESTION_H
