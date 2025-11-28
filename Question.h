#ifndef CODE_QUESTION_H
#define CODE_QUESTION_H

#include<string>
#include<memory>
#include "json.hpp"

using nlohmann::json ;
using std::string ;
using std::ostream;
using std::istream;

class Question
{
public :
    Question(const string& intitule) ;
    virtual ~Question() = default ;
    string intitule() const ;
    virtual void afficherQuestion() const =0;
    virtual void afficherReponse() const = 0;
    virtual string reponse() const = 0;
    virtual bool validiteEntreeUtilisateur(const string &reponse) const = 0 ;
    virtual bool verificationReponse(const string &reponse) const = 0 ;
    virtual std::unique_ptr<Question> clone() const=0 ;
    virtual json conversionJSON () const = 0;

private :
    string d_intitule ;
};


#endif //CODE_QUESTION_H
