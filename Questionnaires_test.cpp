#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Questionnaire.h"
#include "Question.h"
TEST_CASE("Constructeur par défaut de Questionnaire") {
    Questionnaire q;
    CHECK(q.nomQuestionnaire() == "Questionnaire Vide");
    CHECK(q.descriptionQuestionnaire() == "Ceci est un questionnaire vide");
    CHECK(q.nombreDeQuestions() == 0);
}
// teste pour le nom
TEST_CASE("Changer le nom du questionnaire") {
    Questionnaire q;

    q.changerNomQuestionnaire("NouveauNom");

    CHECK(q.nomQuestionnaire() == "NouveauNom");
    CHECK(q.descriptionQuestionnaire() == "Ceci est un questionnaire vide");
    CHECK(q.nombreDeQuestions() == 0);
}
// on teste la description
TEST_CASE("Changer la description du questionnaire") {
    Questionnaire q;

    q.changerDescriptionQuestionnaire("NouvelleDescription");

    CHECK(q.descriptionQuestionnaire() == "NouvelleDescription");
    CHECK(q.nomQuestionnaire() == "Questionnaire Vide");
    CHECK(q.nombreDeQuestions() == 0);
}
// le nombre de question pour le constructeur vide ,
// faudrai aussi faire pour le constructeur qui possede des questions
TEST_CASE("Nombre de questions initial") {
    Questionnaire q;

    CHECK(q.nombreDeQuestions() == 0);
}
TEST_CASE("Reinitialiser un questionnaire")
{

    // Créer un questionnaire NON vide
    Questionnaire q;
    q.changerNomQuestionnaire("NomTemporaire");
    q.changerDescriptionQuestionnaire("DescriptionTemp");

    // On ajoute une question via le constructeur avec vector
    std::vector<std::unique_ptr<Question>> questions;
    questions.push_back(std::make_unique<QuestionTexte>("UneQuestion"));

    // Reconstruire q avec des questions
    Questionnaire q2("TitreTest", "DescTest", questions);

    CHECK(q2.nomQuestionnaire() == "TitreTest");
    CHECK(q2.descriptionQuestionnaire() == "DescTest");
    CHECK(q2.nombreDeQuestions() == 1);

    //  On réinitialise
    q2.reinitialiser();

    //  Vérifications
    CHECK(q2.nomQuestionnaire() == "Questionnaire Vide");
    CHECK(q2.descriptionQuestionnaire() == "Ceci est un questionnaire vide");
    CHECK(q2.nombreDeQuestions() == 0);

}



