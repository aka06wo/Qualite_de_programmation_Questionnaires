#include "certificat.h"

certificat::certificat():
    d_nomquestionnaire{},d_score{}
{
}

/*
 ça marche, seul point négatif, ici on crée une classe par utilisateur, 1000 utilisateurs, 1000 classes c'est beaucoup
 il faut une seule classe qui gere touts les utilisateurs, donc constructeur vide
 si on veut un fichier html, on dit a la classe de generer pour la personne donnée en parametre

*/
