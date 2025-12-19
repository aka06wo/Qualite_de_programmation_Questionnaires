#ifndef CODE_QUESTIONCHOIXMULTIPLE_H
#define CODE_QUESTIONCHOIXMULTIPLE_H

#include "Question.h"
#include <vector>
#include <memory>

class QuestionChoixMultiple : public Question
{
    public:
    QuestionChoixMultiple(const std::string &question,
                const std::vector<std::string> &reponsesPossibles, int numReponse);
    int nombreDeChoix() const ;
    int indiceReponse() const ;
    std::string choixNumero(int i) const ;
    std::string intitule() const override ;
    std::string instructionsQuestion() const override;
    std::string reponse() const override ;
    bool validiteEntreeUtilisateur(const std::string &reponse) const override ;
    bool verificationReponse(const std::string &reponse) const override ;
    std::unique_ptr<Question> clone() const override ;
    nlohmann::json conversionJSON () const override ;
    std::string typeQuestion() const override ;

    private:
    std::vector<std::string> d_reponsesPossibles ;
    int d_indiceReponse ;
};


#endif //CODE_QUESTIONCHOIXMULTIPLE_H
