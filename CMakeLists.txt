cmake_minimum_required(VERSION 4.0)
project(Code_Questionnaire)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Code_Questionnaire
        doctest.h
        cmake-build-debug/Fichier_Questionnaire.json
        json.hpp
        main.cpp
        Question.cpp
        Question.h
        QuestionChoixMultiple.cpp
        QuestionChoixMultiple.h
        Questionnaire.cpp
        Questionnaire.h
        QuestionnaireJSON.cpp
        QuestionnaireJSON.h
        QuestionNumerique.cpp
        QuestionNumerique.h
        QuestionTexte.cpp
        QuestionTexte.h)
