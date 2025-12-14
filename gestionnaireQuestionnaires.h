#ifndef CODE_QUESTIONNAIRE_GESTIONNAIREQUESTIONNAIRES_H
#define CODE_QUESTIONNAIRE_GESTIONNAIREQUESTIONNAIRES_H


class gestionnaireQuestionnaires
{
    // la classe qui va gerer les differents questionnaires
    // on les charge tous et on demande à l'utilsateur le quel il veut prendre

    // a l'image de gestionnaireEvaluation
public :
    const Questionnaire& questionnaireTexte() const;
    const Questionnaire& questionnaireNumerique() const;
    const Questionnaire& questionnaireChoixMultiple() const;
    std::vector<Questionnaire>getParType(int type);
};


#endif //CODE_QUESTIONNAIRE_GESTIONNAIREQUESTIONNAIRES_H
