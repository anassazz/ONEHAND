#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TACHES 100

typedef struct {
    char titre[50];
    char description[255];
    char date_echeance[11]; // Format : AAAA-MM-JJ
    char priorite[10];      // "High" ou "Low"
} Tache;

Tache taches[MAX_TACHES];
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
    if (nb_taches >= MAX_TACHES) {
        printf("La liste des tâches est pleine.\n");
        return;
    }

    Tache nouvelle_tache;

    printf("Titre : ");
    scanf(" %[^\n]", nouvelle_tache.titre);
    printf("Description : ");
    scanf(" %[^\n]", nouvelle_tache.description);
    printf("Date d'échéance (AAAA-MM-JJ) : ");
    scanf("%s", nouvelle_tache.date_echeance);
    printf("Priorité (High/Low) : ");
    scanf("%s", nouvelle_tache.priorite);

    taches[nb_taches++] = nouvelle_tache;
    printf("Tâche ajoutée avec succès.\n");
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
        printf("Date d'échéance : %s\n", taches[i].date_echeance);
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

    Tache *tache = &taches[index - 1];

    printf("Modifier le titre (%s) : ", tache->titre);
    scanf(" %[^\n]", tache->titre);
    printf("Modifier la description (%s) : ", tache->description);
    scanf(" %[^\n]", tache->description);
    printf("Modifier la date d'échéance (%s) : ", tache->date_echeance);
    scanf("%s", tache->date_echeance);
    printf("Modifier la priorité (%s) : ", tache->priorite);
    scanf("%s", tache->priorite);

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
            printf("Date d'échéance : %s\n", taches[i].date_echeance);
            printf("Priorité : %s\n", taches[i].priorite);
        }
    }
}
       