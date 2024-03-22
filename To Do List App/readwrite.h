#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifndef READWRITE_H
#define READWRITE_H

#define MAX_TASKS 100
#define MAX_TITLE_LENGTH 200
#define FILE_PATH "database.json"

typedef struct taskProperties {
    char title[MAX_TITLE_LENGTH];
    int priority;
    bool done;
} 
taskProps;

void readTasks(taskProps tasks[MAX_TASKS], int* numTasks);
void writeTasks(taskProps tasks[MAX_TASKS], int numTasks);
void addTask(taskProps tasks[MAX_TASKS], int* numTasks);
void modifyTask(taskProps tasks[MAX_TASKS], int numTasks);
void deleteTask(taskProps tasks[MAX_TASKS], int* numTasks);
void displayTasks(taskProps tasks[MAX_TASKS], int numTasks);
void sortTasks(taskProps tasks[MAX_TASKS], int numTasks);

#endif