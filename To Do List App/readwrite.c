#include "readwrite.h"


void readTasks(taskProps tasks[MAX_TASKS], int* numTasks) {
    FILE* file = fopen(FILE_PATH, "r");
    if (!file) {
        printf("Unable to open file.\n");
        return;
    }

    *numTasks = 0;
    while (*numTasks < MAX_TASKS && fscanf(file, "{\"task\":\"%199[^\"]\",\"priority\":%d,\"done\":%d}\n", tasks[*numTasks].title, &tasks[*numTasks].priority, &tasks[*numTasks].done) == 3) {
        (*numTasks)++;
    }

    fclose(file);
}

void writeTasks(taskProps tasks[MAX_TASKS], int numTasks) {
    FILE* file = fopen(FILE_PATH, "w");
    if (!file) {
        printf("Unable to open file.\n");
        return;
    }

    for (int i = 0; i < numTasks; i++) {
        fprintf(file, "{\"task\":\"%s\",\"priority\":%d,\"done\":%d}\n", tasks[i].title, tasks[i].priority, tasks[i].done);
    }

    fclose(file);
}

void addTask(taskProps tasks[MAX_TASKS], int* numTasks) {
    printf("Entrez votre tache (ou 0 pour quitter):\n\n");
    fgets(tasks[*numTasks].title, MAX_TITLE_LENGTH, stdin);
    tasks[*numTasks].title[strcspn(tasks[*numTasks].title, "\n")] = '\0';

    if (strcmp(tasks[*numTasks].title, "0") == 0) {
        return;
    }

    printf("Entrez la priorite de votre tache (1: Low, 2: Medium, 3: High):\n\n");
    scanf("%d", &tasks[*numTasks].priority);
    getchar();
    printf("La tache est-elle terminee? (1: Oui, 0: Non):\n\n");
    scanf("%d", &tasks[*numTasks].done);
    getchar();

    (*numTasks)++;
    writeTasks(tasks, *numTasks);
}

void modifyTask(taskProps tasks[MAX_TASKS], int numTasks) {
    int modTask;
    printf("Entrez la tache a modifier (ou 0 pour quitter):\n\n");
    for (int i = 0; i < numTasks; i++) {
        printf("[%d]. %s | %s %s\n", i + 1, tasks[i].title, (tasks[i].priority == 1 ? "Low" : (tasks[i].priority == 2 ? "Medium" : "High")), tasks[i].done ? " [✓]" : " ");
    }
    printf("\n");
    scanf("%d", &modTask);
    getchar();

    if (modTask == 0) {
        return;
    }
    else if (modTask > 0 && modTask <= numTasks) {
        printf("Entrez votre nouvelle tache:\n\n");
        fgets(tasks[modTask - 1].title, MAX_TITLE_LENGTH, stdin);
        tasks[modTask - 1].title[strcspn(tasks[modTask - 1].title, "\n")] = '\0';
        printf("Entrez la nouvelle priorite (1: Low, 2: Medium, 3: High):\n\n");
        scanf("%d", &tasks[modTask - 1].priority);
        writeTasks(tasks, numTasks);
    } else {
        printf("Tache invalide\n\n");
    }
}

void deleteTask(taskProps tasks[MAX_TASKS], int* numTasks) {
    int delTask;
    printf("Entrez la tache a supprimer (ou 0 pour quitter):\n\n");
    for (int i = 0; i < *numTasks; i++) {
        printf("[%d]. %s | %s %s\n", i + 1, tasks[i].title, (tasks[i].priority == 1 ? "Low" : (tasks[i].priority == 2 ? "Medium" : "High")), tasks[i].done ? " [✓]" : " ");
    }
    printf("\n");
    scanf("%d", &delTask);
    getchar();

    if (delTask == 0) {
        return;
    }
    else if (delTask > 0 && delTask <= *numTasks) {
        for (int i = delTask - 1; i < *numTasks - 1; i++) {
            strcpy(tasks[i].title, tasks[i + 1].title);
            tasks[i].priority = tasks[i + 1].priority;
            tasks[i].done = tasks[i + 1].done;
        }
        (*numTasks)--;
        writeTasks(tasks, *numTasks);
    } else {
        printf("Tache invalide\n\n");
    }
}

void displayTasks(taskProps tasks[MAX_TASKS], int numTasks) {
    int dispTask;
    printf("Toutes les taches:\n\n");
    for (int i = 0; i < numTasks; i++) {
        printf("[%d]. %s | %s %s\n", i + 1, tasks[i].title, (tasks[i].priority == 1 ? "Low" : (tasks[i].priority == 2 ? "Medium" : "High")), tasks[i].done ? " [✓]" : " ");
    }
    printf("\n");

    printf("Entrez la tache a terminee (ou 0 pour quitter):\n\n");
    scanf("%d", &dispTask);
    getchar();

    if (dispTask == 0) {
        return;
    } else if (dispTask > 0 && dispTask <= numTasks) {
        tasks[dispTask - 1].done = true;
        writeTasks(tasks, numTasks);
    } else {
        printf("Tache invalide\n\n");
    }
}

void sortTasks(taskProps tasks[MAX_TASKS], int numTasks) {
    for (int i = 0; i < numTasks - 1; i++) {
        for (int j = i + 1; j < numTasks; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                taskProps temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    printf("Les taches sauvegarde (triées par ↓):\n\n");
    for (int i = 0; i < numTasks; i++) {
        printf("[%d]. %s | %s %s\n", i + 1, tasks[i].title, (tasks[i].priority == 1 ? "Low" : (tasks[i].priority == 2 ? "Medium" : "High")), tasks[i].done ? " [✓]" : " ");
    }
    printf("\n");
}