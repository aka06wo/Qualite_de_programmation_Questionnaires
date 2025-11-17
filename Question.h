#ifndef CODE_QUESTION_H
#define CODE_QUESTION_H

#include<string>
#include<memory>

using std::string ;
using std::ostream;
using std::istream;

class Question
{
public :
    Question(const string& intitule) ;
    virtual ~Question() = default ;
    string intitule() const ;
    virtual bool verificationReponse(const string &reponse) const = 0 ;
    void afficherQuestion() const ;
    virtual void afficherReponse() const = 0;
    virtual string reponse() const = 0;
    //virtual string Type_Question() const = 0;
    virtual std::unique_ptr<Question> clone() const ;

private :
    string d_intitule ;
};


#endif //CODE_QUESTION_H
