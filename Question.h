#ifndef CODE_QUESTION_H
#define CODE_QUESTION_H

#include <iostream>
#include<string>
#include<memory>
#include "json.hpp"

class Question
{
public :
    Question(const std::string& intitule) ;
    virtual ~Question() = default ;
    std::string intitule() const ;



    // il faut pas qu'on afficher, sa responsabilité c'est de renvoyer la question et reponse


    virtual void afficherQuestion() const =0;
    virtual void afficherReponse() const = 0;
    virtual std::string reponse() const = 0;
    virtual bool validiteEntreeUtilisateur(const std::string &reponse) const = 0 ;
    virtual bool verificationReponse(const std::string &reponse) const = 0 ;
    virtual std::unique_ptr<Question> clone() const=0 ;
    virtual nlohmann::json conversionJSON () const = 0;


    private :
    std::string d_intitule ;
};


#endif //CODE_QUESTION_H
