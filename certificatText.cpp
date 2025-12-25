#include <iostream>

#include "certificatText.h"

certificatText::certificatText() : certificat{}
{

}


void certificatText::genereCertificat(const std::string &nomQuestionnaire,
                const std::string &descriptionQ, int score, int nbQuestions) const
{
    // Calcul du pourcentage de réussite
    double pourcentage = (nbQuestions > 0) ? (static_cast<double>(score) / nbQuestions) * 100 : 0;

    // --- EN-TÊTE STYLE DIPLÔME ---
    std::cout << "\n  ══════════════════════════════════════════════════════════" << std::endl;
    std::cout << "                                                            " << std::endl;
    std::cout << "                  CERTIFICAT DE RÉUSSITE                    " << std::endl;
    std::cout << "                                                            " << std::endl;
    std::cout << "  ══════════════════════════════════════════════════════════" << std::endl;

    std::cout << "\n  FÉLICITATIONS !" << std::endl;

    std::cout << "\n  Vous avez complété avec succès l'évaluation :" << std::endl;
    std::cout << "  > " << nomQuestionnaire << std::endl;

    std::cout << "\n  THÉMATIQUE :" << std::endl;
    std::cout << "  " << descriptionQ << std::endl;

    std::cout << "\n  ----------------------------------------------------------" << std::endl;
    std::cout << "  VOTRE BILAN FINAL :" << std::endl;
    std::cout << "\n    SCORE     : " << score << " / " << nbQuestions << std::endl;
    std::cout << "    PRÉCISION : " << (int)pourcentage << "%" << std::endl;
    std::cout << "  ----------------------------------------------------------" << std::endl;

    std::cout << "\n============================================================\n" << std::endl;
}