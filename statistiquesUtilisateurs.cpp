#include "statistiquesUtilisateurs.h"

std::string statistiquesUtilisateurs::messageSelonScore(double pourcentage) {
    std::string message{""} ;
    message += "Score obtenu : " + std::to_string(pourcentage) + '\n' ;

    if (pourcentage >= 90) {
        message += "Félicitations ! Tu es un génie, presque invincible !\n";
    }
    else if (pourcentage >= 75) {
        message += "Bravo ! Très bon travail \n";
    }
    else if (pourcentage >= 50) {
        message += "Pas mal ! Mais tu peux faire encore mieux, on croit en toi !\n";
    }
    else if (pourcentage >= 25) {
        message += "Hum... ça commence à se compliquer. Allez, courage !\n";
    }
    else {
        message += "Oups... peut-être que tu devrais revoir tes notes";
    }

    return message ;
}

