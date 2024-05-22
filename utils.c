#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "supemon_header.h"

void initRandom() {
    srand(time(NULL));
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void displaySeparator(int length) {
    int i;
    printf("+");
    for (i = 0; i < length; i++) printf("-");
    printf("+");
    printf("\n");
}

void displaySeparatorWithSpace(int length, int space) {
    int i;
    int j;
    for (i = 0; i < length; i++) {
        printf("-");
    }
    for (j = 0; j < space; j++) {
        printf(" ");
    }
    for (i = 0; i < length; i++) {
        printf("-");
    }
    printf("\n");
}
void printTwoFormattedLines(const char* leftBuffer, const char* rightBuffer) {
    int totalLength = 40;
    int i;
    int j;

    printf("| %s", leftBuffer);
    for ( i = strlen(leftBuffer); i < totalLength; i++) {
        putchar(' ');
    }
    printf("|");

    printf("           ");

    printf("| %s", rightBuffer);
    for ( j = strlen(rightBuffer); j < totalLength; j++) {
        putchar(' ');
    }
    printf("|\n");
}

void displayStatsSideBySide(Player* player, Supemon* enemy) {
    int separatorLength = 34;
    char separator[separatorLength + 1];
    memset(separator, '-', separatorLength);
    separator[separatorLength] = '\0';

    char leftBuffer[100], rightBuffer[100];
    printf("%s     %s\n", separator, separator);

    snprintf(leftBuffer, sizeof(leftBuffer), "%s's %s", player->name, player->supemons[0].name);
    snprintf(rightBuffer, sizeof(rightBuffer), "%s (Enemy)", enemy->name);
    printf("| %-31s|     | %-31s|\n", leftBuffer, rightBuffer);
    displaySeparatorWithSpace(34, 5);

    // HP
    int hpLength = snprintf(NULL, 0, "HP: %2d/%-2d", player->supemons[0].current_hp, player->supemons[0].max_hp);
    int space = 31 - hpLength - 8; // 31 est la largeur totale, 8 est la longueur de "Lvl: %d" avec %d etant un nombre à deux chiffres
    snprintf(leftBuffer, sizeof(leftBuffer), "HP: %2d/%-2d%*sLvl: %d", 
            player->supemons[0].current_hp, player->supemons[0].max_hp, space, "", player->supemons[0].level);
    hpLength = snprintf(NULL, 0, "HP: %2d/%-2d", enemy->current_hp, enemy->max_hp);
    space = 31 - hpLength - 8;
    snprintf(rightBuffer, sizeof(rightBuffer), "HP: %2d/%-2d%*sLvl: %d", 
            enemy->current_hp, enemy->max_hp, space, "", enemy->level);
    printf("| %-31s|     | %-31s|\n", leftBuffer, rightBuffer);

    int atkLength = snprintf(NULL, 0, "Atk: %d", player->supemons[0].attack);
    space = 30 - atkLength - 8;
    snprintf(leftBuffer, sizeof(leftBuffer), "Atk: %d%*sDef: %d", 
            player->supemons[0].attack, space, "", player->supemons[0].defense);
    atkLength = snprintf(NULL, 0, "Atk: %d", enemy->attack);
    space = 30 - atkLength - 8;
    snprintf(rightBuffer, sizeof(rightBuffer), "Atk: %d%*sDef: %d", 
            enemy->attack, space, "", enemy->defense);
    printf("| %-31s|     | %-31s|\n", leftBuffer, rightBuffer);

    int accLength = snprintf(NULL, 0, "Acc: %d", player->supemons[0].accuracy);
    space = 30 - accLength - 8;
    snprintf(leftBuffer, sizeof(leftBuffer), "Acc: %d%*sEva: %d", 
            player->supemons[0].accuracy, space, "", player->supemons[0].evasion);
    accLength = snprintf(NULL, 0, "Acc: %d", enemy->accuracy);
    space = 30 - accLength - 8;
    snprintf(rightBuffer, sizeof(rightBuffer), "Acc: %d%*sEva: %d", 
            enemy->accuracy, space, "", enemy->evasion);
    printf("| %-31s|     | %-31s|\n", leftBuffer, rightBuffer);

    printf("%s     %s\n", separator, separator);
}
void displayMenu(const char* title, char* options[], int numOptions) {
    printf("+--------------------------------+\n");
    printf("| %-30s |\n", title);
    int i;
    for ( i = 0; i < numOptions; i++) {
        printf("| %d - %-25s |\n", i + 1, options[i]);
    }
    printf("+--------------------------------+\n");
}
void displayMenuAdaptive(const char* title, char* options[], int numOptions, int stringWidth) {
    int borderLength = stringWidth + 4;
    char borderLine[borderLength + 1];
    memset(borderLine, '-', borderLength);
    borderLine[borderLength] = '\0';

    printf("+%s+\n", borderLine);
    printf("| %-*s |\n", stringWidth+2, title);
    printf("+%s+\n", borderLine);

    int i;
    for (i = 0; i < numOptions; i++) {
        printf("| %d - %-*s |\n", i + 1, stringWidth-2, options[i]);
    }

    printf("+%s+\n", borderLine);
}
void emptySupemon(Player* player){
    Supemon emptySupemon = {""};
    int i;
    for (i = 0; i < 6; i++){
        player->supemons[i] = emptySupemon;
    }
}
void emptyItems(Player* player){
    Item emptyItems = {""};
    int i;
    for (i = 0; i < 6; i++){
        player->items[i] = emptyItems;
    }
}

void difficultyLevel(Player* player){
    char* difficultyOptions[] = {"Supinfo", "Algorithmic"};
    displayMenuAdaptive("Choose a leveling system:  ", difficultyOptions,2, 26);
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    clearInputBuffer();
    if (choice == 1){
        player->difficulty = 1;
        printf("\nYou have chosen classical mode.\n\n");
    } else if (choice == 2){
        player->difficulty = 2;
        printf("\nYou have chosen Hard mode.\n\n");
    } else {
        printf("Invalid choice. Please enter a number from 1 to 2.\n");
        difficultyLevel(player);
    }
}

void cheatExperience(Player* player, int experience){

        player->supemons[0].experience += experience;
        player->supemons[0].attack = 999999;
        player->supemons[0].defense += 1;
        player->supemons[0].defense *= 3;
        player->supemons[0].accuracy += 1;
        player->supemons[0].accuracy *= 3;
        player->supemons[0].evasion += 1;
        player->supemons[0].evasion *= 3;
        levelUpSupemon(player, &player->supemons[0]);
        printf("%d\n", player->supemons[0].experience);
}
