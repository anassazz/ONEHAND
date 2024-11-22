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
