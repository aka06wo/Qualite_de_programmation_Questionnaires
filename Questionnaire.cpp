#include "Questionnaire.h"
#include "Question.h"

Questionnaire::Questionnaire(const string &titre, const vector<std::unique_ptr<Question>>& Questions):
    d_titre{titre}, d_nbQuestions{0}
{
    // on peut mouver un tableau entier ou pas ?? je suis plus sûr de ce que je dis 

    d_Questions.reserve(Questions.size()) ; // juste pour optimiser
    // on doit faire std::move(q->clone()) ou pas ? en a t'on besoin de clone ?
    for (const auto &q : Questions) {
        d_Questions.push_back(q->clone()); // copie polymorphe
        d_nbQuestions++;
    }
}

string Questionnaire::titre() const
{
    return d_titre ;
}

int Questionnaire::nombreDeQuestions() const {
    return d_nbQuestions;
}

void Questionnaire::ajouterQuestion(std::unique_ptr<Question> q)
{
    d_Questions.push_back(std::move(q));
    d_nbQuestions++;
}

/**void Questionnaire::sauvegarder(ostream& os) const
{
    os << d_titre << "\n";
    os << d_Questions.size() << "\n";
    for(const auto& q : d_Questions)
    {
        q->sauvegarder(os);
    }

}
**/

void Questionnaire::apprentissage() const
{
    std::cout << " Apprentissage : " << d_titre << " \n";
        for (const auto &q : d_Questions)
        {
            q->afficherQuestion() ;
            std::cout<<'\n' ;
            q->afficherReponse() ;
        }
}
/**void Questionnaire::charger(istream& ist)
{
    // � definir apres
}
**/
/**void Questionnaire::afficherQuestions() const
{
    for (const auto& q : d_Questions)
    {
            q->afficherQuestion();
    }
}**/
