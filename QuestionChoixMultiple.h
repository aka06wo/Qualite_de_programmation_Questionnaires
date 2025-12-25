#ifndef CODE_QUESTIONCHOIXMULTIPLE_H
#define CODE_QUESTIONCHOIXMULTIPLE_H

#include "Question.h"
#include <vector>
#include <memory>

class QuestionChoixMultiple : public Question
{
    public:
    /**
     Le constructeur de Question choix multiple
     * @param question l'intitulé de la question
     * @param reponsesPossibles Un tableau de string qui contient les réponses possibles
     * @param numReponse Le numero de la bonne réponse
     */
    QuestionChoixMultiple(const std::string &question,
                          const std::vector<std::string> &reponsesPossibles, int numReponse);

    /**
     @return le nombre de choix pour la question
     */
    int nombreDeChoix() const ;

    /**
    @return l'indice de la bonne réponse (NumReponse - 1)
     */
    int indiceReponse() const ;

    /**
     * @param i l'indice de la reponse
     * @return Le réponse numero i
     */
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
