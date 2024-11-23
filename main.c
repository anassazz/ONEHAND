#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct { 
    int jour;
    int mois;
    int annee;
}Date;
typedef struct {
    char titre[50];
    char description[255];
    char priorite[10]; // "High" ou "Low"
    Date date_echeance;     
} Tache;

Tache taches[100];
int nb_taches = 0;

void afficher_menu() {
    printf("\n=== Gestionnaire de Tâches ===\n");
    printf("1. Ajouter une tâche\n");
    printf("2. Afficher les tâches\n");
    printf("3. Modifier une tâche\n");
    printf("4. Supprimer une tâche\n");
    printf("5. Filtrer les tâches par priorité\n");
    printf("6. Quitter\n");
    printf("Choisissez une option : ");
}

void ajouter_tache() {
    if (nb_taches >= 100) {
        printf("La liste des tâches est pleine.\n");
        return;
    }

    Tache nouvelle_tache;

    printf("Titre : ");
    scanf(" %[^\n]", nouvelle_tache.titre);
    printf("Description : ");
    scanf(" %[^\n]", nouvelle_tache.description);
    //date//////
    printf("Date d'échéance (AAAA-MM-JJ) :\n ");
    printf("Jour:");
    scanf("%d", &nouvelle_tache.date_echeance.jour);
    printf("Mois:");
    scanf("%d", &nouvelle_tache.date_echeance.mois);
    printf("Année:");
    scanf("%d", &nouvelle_tache.date_echeance.annee);
    //printf("Année--:%d",nouvelle_tache.date_echeance.annee);
    /////////
    printf("Priorité (High/Low) : ");
    scanf("%s", nouvelle_tache.priorite);

    taches[nb_taches++] = nouvelle_tache;
    printf("Tâche ajoutée avec succès.\n");
            printf("Date d'échéance : %d/%d/%d\n", nouvelle_tache.date_echeance.jour,nouvelle_tache.date_echeance.mois,nouvelle_tache.date_echeance.annee);

}

void afficher_taches() {
    if (nb_taches == 0) {
        printf("Aucune tâche à afficher.\n");
        return;
    }

    for (int i = 0; i < nb_taches; i++) {
        printf("\nTâche %d :\n", i + 1);
        printf("Titre : %s\n", taches[i].titre);
        printf("Description : %s\n", taches[i].description);
        printf("Date d'échéance : %d/%d/%d\n", taches[i].date_echeance.jour,taches[i].date_echeance.mois,taches[i].date_echeance.annee);
        printf("Priorité : %s\n", taches[i].priorite);
    }
}

 // Modifier une tâche 
void modifier_tache() {
    int index;
    printf("Entrez le numéro de la tâche à modifier : ");
    scanf("%d", &index);

    if (index < 1 || index > nb_taches) {
        printf("Numéro de tâche invalide.\n");
        return;
    }


    printf("Modifier le titre (%s) : ", taches[index - 1].titre);
    scanf(" %[^\n]", taches[index - 1].titre);
    printf("Modifier la description (%s) : ", taches[index - 1].description);
    scanf(" %[^\n]", taches[index - 1].description);
    //date//////
    printf("Date d'échéance (AAAA-MM-JJ) :\n ");
    printf("Jour: ");
    scanf("%d", &taches[index - 1].date_echeance.jour);
    printf("Mois: ");
    scanf("%d", &taches[index - 1].date_echeance.mois);
    printf("Année: ");
    scanf("%d", &taches[index - 1].date_echeance.annee);
    /////////    
    printf("Modifier la priorité (%s) : ", taches[index - 1].priorite);
    scanf("%s", taches[index - 1].priorite);

    printf("Tâche modifiée avec succès.\n");
}

        //Supprimer une tâche 
void supprimer_tache() {
    int index;
    printf("Entrez le numéro de la tâche à supprimer : ");
    scanf("%d", &index);

    if (index < 1 || index > nb_taches) {
        printf("Numéro de tâche invalide.\n");
        return;
    }

    for (int i = index - 1; i < nb_taches - 1; i++) {
        taches[i] = taches[i + 1];
    }
    nb_taches--;

    printf("Tâche supprimée avec succès.\n");
}

        //Filtrer les tâches par priorité
 void filtrer_par_priorite() {
    char priorite[10];
    printf("Entrez la priorité à filtrer (High/Low) : ");
    scanf("%s", priorite);

    for (int i = 0; i < nb_taches; i++) {
        if (strcmp(taches[i].priorite, priorite) == 0) {
            printf("\nTâche %d :\n", i + 1);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Date d'échéance : %s\n", taches[i].date_echeance.annee, taches[i].date_echeance.mois,taches[i].date_echeance.jour);
            printf("Priorité : %s\n", taches[i].priorite);
        }
    }
}
// La boucle principale gère l'interaction avec l'utilisateur.ss
     int main() {
    int choix;

    do {
        afficher_menu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_tache();
                break;
            case 2:
                afficher_taches();
                break;
            case 3:
                modifier_tache();
                break;
            case 4:
                supprimer_tache();
                break;
            case 5:
                filtrer_par_priorite();
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    } while (choix != 6);

    return 0;
}
  