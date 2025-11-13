//
// Created by Ibrahima Diallo on 03/11/2025.
//

#ifndef CODE_QUESTION_H
#define CODE_QUESTION_H
#include<string>
#include<iostream>
#include<memory>
using std::string ;
using std::ostream;
using std::istream;
class Question {
public :
    Question(const string& intitule) ;
    virtual ~Question() = default ;
    string intitule() const ;
    virtual bool verificationReponses(string reponse) const = 0 ; // on lui pose une question et on verifie s'il elle est juste ou pas
    virtual void afficherQuestion() const ;
    virtual void afficherReponse() const = 0;
    virtual string Reponse() const = 0;
     virtual std::unique_ptr<Question> clone() const = 0; //apres faudrai implementer clone() dans chaque classe dérivée
protected :
    string d_intitule ;

};


#endif //CODE_QUESTION_H
