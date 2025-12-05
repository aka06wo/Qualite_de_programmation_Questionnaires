#ifndef CODE_QUESTIONNAIRE_STATISTIQUESUTILISATEURS_H
#define CODE_QUESTIONNAIRE_STATISTIQUESUTILISATEURS_H

#include "json.hpp"
using nlohmann::json ;

class statistiquesUtilisateurs
{
    // celui qui gere les resultats des utilisateurs
    // les conserve et charge depuis un fichier json
    /*
      Exemple de ce qu'il pourrait contenir
              {
            "Dom": [
              {
                "questionnaire": "Maths_Quiz1",
                "score": 8,
                "maxScore": 10,
                "temps": 320.5,                 // temps en secondes
                "questionsRatees": [2, 5],      // indices des questions ratées
                "reussi": true                   // vrai si score >= seuil de réussite
              },
              {
                "questionnaire": "Maths_Quiz1",
                "score": 6,
                "maxScore": 10,
                "temps": 280.0,
                "questionsRatees": [1, 4, 7],
                "reussi": false
              }
            ],
            "Amina": [
              {
                "questionnaire": "Histoire_Quiz2",
                "score": 9,
                "maxScore": 10,
                "temps": 400.0,
                "questionsRatees": [3],
                "reussi": true
              }
            ]
          }
     */
};


#endif //CODE_QUESTIONNAIRE_STATISTIQUESUTILISATEURS_H