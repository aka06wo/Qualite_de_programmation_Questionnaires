#ifndef CODE_QUESTIONNAIRE_CERTIFICAT_H
#define CODE_QUESTIONNAIRE_CERTIFICAT_H

#include <string>

class certificat
{
public :
    /**
     Constructeur par defaut de la classe certificat
     */
    certificat();

    /**
     Methode virtuelle pure qui definit la structure de generation du certificat
     Cette methode doit être implementee par les classes filles (certificatHTML et certificatText)
     @param nomQuestionnaire Le nom du questionnaire reussi
     @param descriptionQ La description du questionnaire
     @param score Le score obtenu par l'utilisateur
     @param nbQuestions Le nombre total de questions du questionnaire
     */
    virtual void genereCertificat(const std::string &nomQuestionnaire,
                const std::string &descriptionQ, int score, int nbQuestions) const = 0;

    /**
     Destructeur virtuel par defaut
     */
    virtual ~certificat() = default;
private :

};

#endif //CODE_QUESTIONNAIRE_CERTIFICAT_H
