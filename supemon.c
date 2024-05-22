#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "supemon_header.h"

void initializeSupemon(Supemon *supemon, char *name, int level, int experience, int current_hp, int max_hp, int attack, int base_attack, int defense, int base_defense, int evasion, int base_evasion, int accuracy, int base_accuracy, int speed, int isCaptured)
{
    if (supemon == NULL || name == NULL)
    {
        printf("Error: Invalid pointers provided to initializeSupemon.\n");
        return;
    }

    strncpy(supemon->name, name, sizeof(supemon->name) - 1);
    supemon->name[sizeof(supemon->name) - 1] = '\0';

    supemon->level = level;
    supemon->experience = experience;
    supemon->current_hp = current_hp;
    supemon->max_hp = max_hp;
    supemon->attack = attack;
    supemon->baseAttack = base_attack;
    supemon->defense = defense;
    supemon->baseDefense = base_defense;
    supemon->evasion = evasion;
    supemon->baseEvasion = base_evasion;
    supemon->accuracy = accuracy;
    supemon->baseAccuracy = base_accuracy;
    supemon->speed = speed;
    supemon->isCaptured = isCaptured;
}

void chooseInitialSupemon(Player *player)
{
    while (player->numSupemons == 0)
    {
        int choice;
        char* options[] = {"Supmander", "Supasaur", "Supirtle"};
        displayMenuAdaptive("Choose your first Supemon", options, 3, 35);
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input. Please enter a number from 1 to 3.\n\n");
            clearInputBuffer();
            continue;
        }
        switch (choice)
        {
        case 1:
            initializeSupemon(&player->supemons[0], "Supmander", 1, 1, 10, 10, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1);
            player->numSupemons = 1;
            initializeSupemonMoves(&player->supemons[0], 1);
            break;
        case 2:
            initializeSupemon(&player->supemons[0], "Supasaur", 1, 1, 9, 9, 1, 1, 1, 1, 3, 3, 2, 2, 2, 1);
            player->numSupemons = 1;
            initializeSupemonMoves(&player->supemons[0], 2);
            break;
        case 3:
            initializeSupemon(&player->supemons[0], "Supirtle", 1, 1, 11, 11, 1, 1, 2, 2, 2, 2, 1, 1, 2, 1);
            player->numSupemons = 1;
            initializeSupemonMoves(&player->supemons[0], 3);
            break;
        default:
            printf("\nInvalid input. Please enter a number from 1 to 3.\n\n");
            clearInputBuffer();
            break;
        }
    }
    printf("\nYou have chosen: %s\n", player->supemons[0].name);
}

void initializeSupemonMoves(Supemon *supemon, int supemonType) {
    if (supemon == NULL) {
        printf("Error: Supemon pointer is NULL.\n");
        return;
    }

    switch (supemonType) {
    case 1: // Supmander
        supemon->moves[0] = (Move){"Scratch", 3, "", 0};
        supemon->moves[1] = (Move){"Grawl", 0, "Attack", 1}; 
        supemon->numMoves = 2;
        break;
    case 2: // Supasaur
        supemon->moves[0] = (Move){"Pound", 2, "", 0}; 
        supemon->moves[1] = (Move){"Foliage", 0, "Evasion", 1}; 
        supemon->numMoves = 2;
        break;
    case 3: // Supirtle
        supemon->moves[0] = (Move){"Pound", 2, "", 0}; 
        supemon->moves[1] = (Move){"Shell", 0, "Defense", 1};
        supemon->numMoves = 2;
        break;
    default:
        printf("Invalid Supemon type. No moves initialized.\n");
        return;
    }
}

void selectSupemon(Player *player, Supemon *supemon)
{
    int choice;
    displaySupemon(player);
    printf("Select a Supemon: ");
    scanf("%d", &choice);
    clearInputBuffer();
    if (choice < 1 || choice > player->numSupemons)
    {
        printf("Invalid choice. Please try again.\n");
        selectSupemon(player, supemon);
    }
    else
    {
        Supemon temp = player->supemons[0];
        player->supemons[0] = player->supemons[choice - 1];
        player->supemons[choice - 1] = temp;
    }
}
void captureSupemon(Player *player, Supemon *enemy) {
    
    float captureChance = ((float)(enemy->max_hp - enemy->current_hp) / enemy->max_hp - 0.5) * 100; 
    if (captureChance < 0) captureChance = 0; 

    if (rand() % 100 < captureChance) { 
        int i;
        for (i = 0; i < 5; i++) {
            if (player->supemons[i].name[0] == '\0') { 
                player->supemons[i] = *enemy;
                printf("You captured %s\n", enemy->name);
                player->numSupemons += 1;
                enemy->isCaptured = 1;
                displaySupemon(player); 
                return; 
            }
        }
        printf("Your team is full. You cannot capture %s\n", enemy->name);
    } else {
        displaySupemon(player); 
        enemyTurn(enemy, &player->supemons[0]);
        printf("You failed to capture the enemy Supemon!\n");
    }
}

void healSupemon(int heal, Supemon *supemon)
{
    supemon->current_hp += heal;
    if (supemon->current_hp > supemon->max_hp)
    {
        supemon->current_hp = supemon->max_hp;
    }
}

void levelUpSupemonHard(Supemon *supemon) {
    while (supemon->experience >= (supemon->level * 1000 + ((supemon->level - 1) * (supemon->level - 1) * 100 / 2))) {
        supemon->level += 1;
        increaseStatsBy30Percent(supemon);
    }
}

void levelUpSupemonEasy(Supemon *supemon)
{
    int exp = 0;
    for (exp = 0; exp < supemon->experience; exp += 1)
    {
        if (supemon->experience >= 500 && supemon->level < 2 )
        {
        supemon->level += 1;
        increaseStatsBy30Percent(supemon);
        }
        if (supemon->level > 1 && (supemon->experience >= 500 + (supemon->level -1) * 1000)) 
        {
        supemon->level += 1;
        increaseStatsBy30Percent(supemon);
        }
    }
    
}

void increaseStatsBy30Percent(Supemon *supemon)
{
    supemon->max_hp += supemon->max_hp * 0.3;
    if (rand() % 2 == 0)
    {
        supemon->max_hp = (int)supemon->max_hp;
    }
    else
    {
        supemon->max_hp = (int)(supemon->max_hp + 1); 
    }

    supemon->attack += supemon->attack * 0.3;
    if (rand() % 2 == 0)
    {
        supemon->attack = (int)supemon->attack; 
    }
    else
    {
        supemon->attack = (int)(supemon->attack + 1); 
    }

    supemon->defense += supemon->defense * 0.3;
    if (rand() % 2 == 0)
    {
        supemon->defense = (int)supemon->defense; 
    }
    else
    {
        supemon->defense = (int)(supemon->defense + 1); 
    }

    supemon->evasion += supemon->evasion * 0.3;
    if (rand() % 2 == 0)
    {
        supemon->evasion = (int)supemon->evasion; 
    }
    else
    {
        supemon->evasion = (int)(supemon->evasion + 1);
    }

    supemon->accuracy += supemon->accuracy * 0.3;
    if (rand() % 2 == 0)
    {
        supemon->accuracy = (int)supemon->accuracy; 
    }
    else
    {
        supemon->accuracy = (int)(supemon->accuracy + 1);
    }

    supemon->speed += supemon->speed * 0.3;
    if (rand() % 2 == 0)
    {
        supemon->speed = (int)supemon->speed;
    }
    else
    {
        supemon->speed = (int)(supemon->speed + 1);
    }
}

void levelUpSupemon(Player* player, Supemon *supemon)
{
    int difficulty = player->difficulty;
    switch (difficulty)
    {
    case 1:
        levelUpSupemonEasy(supemon);
        break;
    case 2:
        levelUpSupemonHard(supemon);
        break;
    
    default:
        printf("Invalid difficulty level. Supemon not leveled up.\n");
        break;
    }
}

void supemonCenter(Player *player)
{
    char* options[] = {"Heal Supemons  -1000 supecoins", "Exit Supemon Center"};
    displayMenuAdaptive("Supemon Center", options, 2, 35); 
    int i;
    printf("Enter your choice: ");
    scanf("%d", &i);
    clearInputBuffer();
    switch (i)
    {
    case 1:
        if (player->supcoins < 1000)
        {
            printf("You don't have enough supecoins to heal your Supemons.\n");
            break;
        }
        else
        {
            player->supcoins -= 1000;
            for (i = 0; i < player->numSupemons; i++)
            {
            player->supemons[i].current_hp = player->supemons[i].max_hp;
            }
            printf("All Supemons have been healed!\n\n");
            printf("You have %d supecoins left.\n", player->supcoins);
            break;
        }
    case 2:
        printf("Exiting Supemon Center.\n");
        break;
    default:
        printf("Invalid choice. Please enter a number from 1 to 2.\n");
        break;
    }
        
}