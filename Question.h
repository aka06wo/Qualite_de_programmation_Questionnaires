#ifndef CODE_QUESTION_H
#define CODE_QUESTION_H

#include<string>
#include<memory>
#include "json.hpp"

class Question
{
public :
    Question(const std::string& intitule) ;
    virtual ~Question() = default ;
    virtual std::string intitule() const = 0 ;
    virtual std::string instructionsQuestion() const = 0 ;
    virtual std::string reponse() const = 0;
    virtual bool validiteEntreeUtilisateur(const std::string &reponse) const = 0 ;
    virtual bool verificationReponse(const std::string &reponse) const = 0 ;
    virtual std::unique_ptr<Question> clone() const=0 ;
    virtual nlohmann::json conversionJSON () const = 0;

    protected :
    std::string d_intitule ;
};


#endif //CODE_QUESTION_H
