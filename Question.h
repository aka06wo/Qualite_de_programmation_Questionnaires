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
    virtual bool verificationReponse(string reponse) const = 0 ;
    virtual void afficherQuestion() const ;
    virtual void afficherReponse() const = 0;
    virtual string reponse() const = 0;
    virtual std::unique_ptr<Question> clone() const = 0; //apres faudrai implementer clone() dans chaque classe derivee

private :
    string d_intitule ;
};


#endif //CODE_QUESTION_H
