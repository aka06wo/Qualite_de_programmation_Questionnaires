#include "gestionnaireQuestionnaires.h"
#include <vector>
#include
std::vector<Questionnaire> gestionnaireQuestionnaires::getParType(int type) {
    std::vector<Questionnaire>resultat;

    for (const auto& q : tousLesQuestionnaires) {
        if (q.type() == type) {
            resultat.push_back(q);
        }
    }
    return resultat;
}
