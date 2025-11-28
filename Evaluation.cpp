#include "Evaluation.h"
#include "QuestionNumerique.h"
#include "QuestionChoixMultiple.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <cctype>

Evaluation::Evaluation(const Questionnaire &questionnaire) : d_questionnaire(&questionnaire),
                        d_nbEssai{0}, d_score{0}, d_tabIndiceErreur{}
{
}

std::string Evaluation::reponseUtilisateurQuestion() const {
    std::string reponse ;
    std::cin>>reponse;
    return reponse;
}

void Evaluation::nettoyerBuffer() const {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool Evaluation::estEntierValide(const std::string& str) const {
    if (str.empty()) return false;

    size_t start = 0;
    if (str[0] == '-' || str[0] == '+') {
        if (str.size() == 1) return false;
        start = 1;
    }

    for (size_t i = start; i < str.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(str[i]))) {
            return false;
        }
    }
    return true;
}

bool Evaluation::estChoixValide(const std::string& str, int nbChoix) const {
    if (!estEntierValide(str)) return false;

    try {
        int choix = std::stoi(str);
        return choix >= 1 && choix <= nbChoix;
    } catch (...) {
        return false;
    }
}

std::string Evaluation::obtenirReponseValidee(int indexQuestion) const {
    std::string typeQuestion = d_questionnaire->typeQuestion(indexQuestion);

    if (typeQuestion == "numerique") {
        // Validation pour question numérique
        std::string reponse;
        while (true) {
            std::cout << "> ";
            std::cin >> reponse;

            if (estEntierValide(reponse)) {
                nettoyerBuffer();
                return reponse;
            } else {
                std::cout << "❌ Erreur : Veuillez saisir un nombre entier valide." << std::endl;
                std::cout << "Réessayez : ";
                nettoyerBuffer();
            }
        }
    } else if (typeQuestion == "choixMultiples") {
        // Validation pour question à choix multiples
        int nbChoix = d_questionnaire->nombreChoixQuestion(indexQuestion);
        std::string reponse;

        while (true) {
            std::cout << "> ";
            std::cin >> reponse;

            if (estChoixValide(reponse, nbChoix)) {
                nettoyerBuffer();
                return reponse;
            } else {
                std::cout << "❌ Erreur : Veuillez saisir un nombre entre 1 et " << nbChoix << "." << std::endl;
                std::cout << "Réessayez : ";
                nettoyerBuffer();
            }
        }
    } else {
        // Question texte - pas de validation spéciale nécessaire
        std::string reponse;
        std::cout << "> ";
        std::cin >> reponse;
        nettoyerBuffer();
        return reponse;
    }
}
