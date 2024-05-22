#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "supemon_header.h"

    void launchRandomFight(Player* player, Item* items) {
        if (player->numSupemons == 0) {
            printf("You don't have any Supemons to fight with!\n");
            return;
        }

        int randomIndex = rand() % 3; 
        Supemon enemy;

        int enemyExperience = player->supemons[0].experience;
            switch (randomIndex) {
                case 0:
                    initializeSupemon(&enemy, "Supmander", 1, 1, 10, 10, 1, 1, 1, 1, 1, 1, 2, 2, 1, 0);
                    initializeSupemonMoves(&enemy, 1); 
                    break;
                case 1:
                    initializeSupemon(&enemy, "Supasaur", 1, 1, 9, 9, 1, 1, 1, 1, 3, 3, 2, 2, 2, 0);
                    initializeSupemonMoves(&enemy, 2); 
                    break;
                case 2:
                    initializeSupemon(&enemy, "Supirtle", 1, 1, 11, 11, 1, 1, 2, 2, 2, 2, 1, 1, 2, 0);
                    initializeSupemonMoves(&enemy, 3); 
                    break;
                default:
                    printf("Error: Invalid random index.\n");
                    return;
            }

            if (player->supemons[0].level > 2) {
                enemy.experience = enemyExperience;
            }
        

        if (player->difficulty == 1) {
            levelUpSupemonEasy(&enemy);
        } else {
            levelUpSupemonHard(&enemy);
        }

        enemy.current_hp = enemy.max_hp;
        printf("\nYou encountered a %s!\n", enemy.name);
        fight(player, &enemy, items);
    }
 
void fight(Player* player, Supemon* enemy, Item* items) {
    int Player_Speed = player->supemons[0].speed;
    int Enemy_Speed = enemy->speed;
    int runChance = Player_Speed * 100 / (Player_Speed + Enemy_Speed);

    while (enemy->current_hp > 0 && player->supemons[0].current_hp > 0) {
        displayStatsSideBySide(player, enemy);
        displayMenuOptions();

        int choice;
        printf("1, 2, 3, 4 or 5: ");
        if (scanf("%d", &choice) != 1) {
            printf("Error: invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                displayMoveOptions(&player->supemons[0]);
                printf("1, 2 or 3: ");
                int move_choice;
                if (scanf("%d", &move_choice) != 1) {
                    printf("Error: invalid input.\n");
                    while (getchar() != '\n');
                    continue;
                }
                move_choice -= 1;
                if (move_choice >= 0 && move_choice < player->supemons[0].numMoves) {
                    if (player->supemons[0].speed > enemy->speed) {
                        playerTurn(player, enemy, &player->supemons[0], move_choice);
                        enemyTurn(enemy, &player->supemons[0]);
                    } else {
                        enemyTurn(enemy, &player->supemons[0]);
                        playerTurn(player, enemy, &player->supemons[0], move_choice);
                    }
                } else {
                    printf("Invalid move selection.\n");
                }
                break;
            case 2:
                selectSupemon(player, &player->supemons[0]);
                enemyTurn(enemy, &player->supemons[0]);
                break;
            case 3:
                selectItem(player, player->items);
                break;
            case 4:
                captureSupemon(player, enemy);
                if (enemy->isCaptured == 1) {
                    return;
                } else 
                break;
              case 5:
                if (rand() % 100 < runChance) {
                    printf("You ran away successfully!\n");
                    return;
                } else {
                    printf("You couldn't run away!\n");
                    enemyTurn(enemy, &player->supemons[0]);
                }
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 5.\n");
                while(getchar() != '\n');
                break;
        }
        

    if (player->supemons[0].current_hp <= 0) {
        player->supemons[0].current_hp = 0;
        printf("Your Supemon has fainted!\n");
        if (player->numSupemons > 1) {
            printf("Choose another Supemon to continue the fight.\n");
            selectSupemon(player, &player->supemons[0]);
        } else {
            printf("You have no more Supemons left. You have lost the battle!\n");
            exit(0);
        }
    } else if (enemy->current_hp <= 0) {
        printf("Enemy Supemon defeated!\n\n");
        int exp = enemy->level * 1000 / 10;
        player->supemons[0].experience += exp;
        //cheatExperience(player, 25000); // Cheat pour l'experience
        printf("Your %s gained %d experience!\n",player->supemons[0].name, exp);
        levelUpSupemon(player, &player->supemons[0]);
        return;
    } else if (enemy->isCaptured == 1) {
        int exp = ((enemy->level * 1000 / 10) + ((enemy->level * 1000 / 10) / 2));
        player->supemons[0].experience += exp;
        printf("Your Supemon gained %d experience!\n", exp);
        levelUpSupemon(player, &player->supemons[0]);
        return;
    }   
}}


void playerTurn(Player* player, Supemon* enemy, Supemon* supemon, int moveChoice) {
    performMove(supemon, enemy, moveChoice);
}

void performMove(Supemon *attacker, Supemon *defender, int moveIndex) {
    if (moveIndex < 0 || moveIndex >= attacker->numMoves) {
        printf("Invalid move. Please enter a valid move number.\n");
        return;
    }

    Move selectedMove = attacker->moves[moveIndex];

    if (selectedMove.damage > 0) {
        float successRate = (float)attacker->accuracy / (attacker->accuracy + defender->evasion) + 0.1f;
        if ((rand() % 100) < (successRate * 100)) {
            float damage = (float)(attacker->attack * selectedMove.damage) / defender->defense;
            int finalDamage = (int)damage;
            if ((damage - finalDamage) > 0 && (rand() % 2 == 0)) {
                finalDamage++;
            }
            defender->current_hp -= finalDamage;
            printf("%s used %s! It dealt %d damage to %s!\n", attacker->name, selectedMove.name, finalDamage, defender->name);
        } else {
            printf("%s's attack missed!\n", attacker->name);
        }
    } else {
        if (strcmp(selectedMove.statAffected, "Defense") == 0) {
            attacker->defense += selectedMove.statEffect;
            printf("%s used %s! %s's Defense increased!\n", attacker->name, selectedMove.name, attacker->name);
        } else {
            printf("%s used %s! But it seems there was no effect...\n", attacker->name, selectedMove.name);
        }
    }
}




void displayMoves(Supemon* supemon) {
    printf("Moves:\n");
    int i;
    for (i = 0; i < supemon->numMoves; i++) {
        printf("%d. %s\n", i + 1, supemon->moves[i].name);
    }
}

void enemyTurn(Supemon* enemy, Supemon* playerSupemon) {
    if (enemy == NULL || playerSupemon == NULL) {
        printf("Error: Invalid pointers.\n");
        return;
    }

    if (playerSupemon->current_hp <= 0) {
        printf("The player's Supemon is knocked out. Enemy cannot attack.\n");
        return;
    }

    if (enemy->numMoves <= 0) {
        printf("The enemy has no moves available. It cannot attack.\n");
        return;
    }

    int randomMove = rand() % enemy->numMoves;
    performMove(enemy, playerSupemon, randomMove);
}

void displayEnemyStats(Supemon* enemy) {
    displaySeparator(33);
    printf("| %11s (Enemy)         |\n", enemy->name);
    displaySeparator(33);
    printf("| HP: %2d/%-2d  Lvl: %-2d          |\n", enemy->current_hp, enemy->max_hp, enemy->level);
    printf("| Atk: %-2d  Def: %-2d          |\n", enemy->attack, enemy->defense);
    printf("| Acc: %-2d  Eva: %-2d          |\n", enemy->accuracy, enemy->evasion);
    displaySeparator(33);
}

void supemonPassesOut(Enemy* supemon, Player* player) {
    printf("%s has passed out!\n", supemon->name);
        if (supemon->supemon.current_hp <= 0) {
            player->supcoins += 150;
            printf("You have gained 150 Supecoins!\n");
        } else if (player->supemons[0].current_hp <= 0) {
            player->supemons[0].current_hp = 0;
            printf("You have lost the battle!\n");
            exit(0);
        }
}

void displayMenuOptions() {
    displaySeparator(32);
    printf("| What will you do?              |\n");
    printf("| 1 - Move                       |\n");
    printf("| 2 - Change Supemon             |\n");
    printf("| 3 - Use item                   |\n");
    printf("| 4 - Capture                    |\n");
    printf("| 5 - Run away                   |\n");
    displaySeparator(32);
}

void displayMoveOptions(Supemon *supemon) {
    int maxLength = 6;
    int i;
    for (i = 0; i < supemon->numMoves; i++) {
        int len = strlen(supemon->moves[i].name);
        if (len > maxLength) {
            maxLength = len;
        }
    }

    int totalWidth = maxLength + 6;
    printf("+");
    for (i = 0; i < totalWidth; i++) printf("-");
    printf("+\n");

    for (i = 0; i < supemon->numMoves; i++) {
        printf("| %d - %-*s |\n", i + 1, maxLength, supemon->moves[i].name);
    }

    printf("| %d - %-*s |\n", 3, maxLength, "Cancel");

    printf("+");
    for (i = 0; i < totalWidth; i++) printf("-");
    printf("+\n");
}



void supemonBattleTurn(Player* player, Supemon* supemon)
{
    int Player_Speed = player->supemons[0].speed;
    int Enemy_Speed = supemon->speed;
}