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
    virtual void sauvegarder(ostream& os) const = 0; // pour que chaque question sache se sauvegarder elle meme
    virtual void charger(istream& ist) = 0;
    virtual string Type_Question() const = 0; //savoir le type de question: si c'est numerique , texte ,ou choix multiple


private :
    string d_intitule ;
};


#endif //CODE_QUESTION_H
