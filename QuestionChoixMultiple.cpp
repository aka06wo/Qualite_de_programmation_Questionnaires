#include "QuestionChoixMultiple.h"
// pour is digit
#include <cctype>

QuestionChoixMultiple::QuestionChoixMultiple(const string &question,
                    const std::vector<string> &reponsesPossibles, int numReponse) :
    Question{question}, d_reponsesPossibles{reponsesPossibles}, d_indiceReponse{numReponse-1}
{
}

string QuestionChoixMultiple::reponse() const {
    return choixNumero(d_indiceReponse);
}

int QuestionChoixMultiple::nombreDeChoix() const
{
    return d_reponsesPossibles.size() ;
}

// tester si i ne depasse pas les élements du tableau ?
string QuestionChoixMultiple::choixNumero(int i) const
{
    return d_reponsesPossibles[i] ;
}

void QuestionChoixMultiple::afficherQuestion() const {
    std::cout<<intitule()<<std::endl ;
    if (d_reponsesPossibles.size() != 0) {
        for (int i = 0; i < d_reponsesPossibles.size(); i++) {
            std::cout<<i+1<<"- "<<d_reponsesPossibles[i]<<std::endl ;
        }
    }
    std::cout<<"Saisissez le numéro de la bonne réponse :\n" ;
}

void QuestionChoixMultiple::afficherReponse() const {
    std::cout<<"La bonne reponse est : "+ std::to_string(d_indiceReponse+1) + " - " + reponse()<<std::endl;
}

bool QuestionChoixMultiple::validiteEntreeUtilisateur(const std::string &reponse) const {
    if (reponse.empty()) {
        std::cout << "Veuillez entrer le numero de la bonne reponse\n";
        return false;
    }

    try {
        int valeur = std::stoi(reponse);
        if (valeur < 0 || valeur > d_reponsesPossibles.size()) {
            std::cout << "Numero de réponse hors plage, veuillez entrez un numéro valide\n";
            return false;
        }
        else
            return true;
    }
    catch (const std::invalid_argument&) {
        std::cout << "Veuillez saisir un numero valide\n";
        return false;
    }
    catch (const std::out_of_range&) {
        std::cout << "Nombre trop grand, veuillez saisir un numéro valide\n";
        return false;
    }
}

bool QuestionChoixMultiple::verificationReponse(const string &reponse) const {
    return std::stoi(reponse) == d_indiceReponse + 1 ;
}

std::unique_ptr<Question> QuestionChoixMultiple::clone() const {
    return std::make_unique<QuestionChoixMultiple>(*this) ;
}

json QuestionChoixMultiple::conversionJSON() const {
    return json {
        {"type", "choixMultiples"},
        {"question", intitule()},
        {"reponsesPossibles", d_reponsesPossibles},
        {"numReponseCorrecte", d_indiceReponse}
    } ;
}
