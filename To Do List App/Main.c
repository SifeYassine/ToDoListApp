#include "readwrite.h"

int main() {
    
    int choix;
    taskProps tasks[MAX_TASKS];
    int numTasks = 0;

    while (true) {
        printf("Menu de Selection:\n\n[1]. Ajouter une tache\n[2]. Modifier une tache\n[3]. Supprimer une tache\n[4]. Afficher touts les taches\n[5]. Filtrer les taches\n[6]. Quitter\n\n");
        
        scanf("%d", &choix);
        getchar();

        readTasks(tasks, &numTasks);

        switch (choix) {
            case 1: {
                // Add task
                addTask(tasks, &numTasks);
                break;
            }

            case 2: {
                // Modify task
                modifyTask(tasks, numTasks);
                break;
            }

            case 3: {
                // Delete task
                deleteTask(tasks, &numTasks);
                break;
            }

            case 4: {
                // Display all tasks
                displayTasks(tasks, numTasks);
                break;

            }

            case 5: {
                // Sort tasks by priority in descending order
                sortTasks(tasks, numTasks);
                break;
            }

            case 6: {
                // Exit the program
                printf("Au revoir!\n");
                return 0; 
            }

            default:
                printf("Choix invalide\n\n");
        }
    }

    return 0;
}
