#ifndef EVALUATIONADAPTATIVE_H
#define EVALUATIONADAPTATIVE_H

#include "Evaluation.h"

#include<iostream>
#include <vector>

class EvaluationAdaptative : public Evaluation
{
public:
    EvaluationAdaptative(const Questionnaire &questionnaire);
    void PremierPassage(std::vector<int>& tableau, bool &aQuitter) ;
    void SecondPassage() ;
    bool traiterReponse(int indice, const std::string& reponse) ;
    void lanceEvaluation() override;

private:
    std::vector <int> d_indicesErreursPremierPassage ;

};

#endif // EVALUATIONADAPTATIVE_H
