cmake_minimum_required(VERSION 4.0)
project(Qualite_de_programmation_Questionnaires)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Qualite_de_programmation_Questionnaires
        main.cpp
        Question.cpp
        Question.h
        QuestionChoixMultiple.cpp
        QuestionChoixMultiple.h
        Questionnaire.cpp
        Questionnaire.h
        QuestionNumerique.cpp
        QuestionNumerique.h
        QuestionTexte.cpp
        QuestionTexte.h)
