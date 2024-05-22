#include <stdio.h>
#include <string.h>
#include "supemon_header.h"

void playerName(Player* player) {
    printf("Enter your name: ");
    fgets(player->name, sizeof(player->name), stdin);
    while (player->name[0] == '\0' || player->name[0] == '\n' || player->name[0] == ' '){
        fgets(player->name, sizeof(player->name), stdin);
        if (player->name[0] == '\0' || player->name[0] == '\n' || player->name[0] == ' ') {
            printf("Please enter a valid name: ");

        }
    }
    player->name[strcspn(player->name, "\n")] = 0;
}

void displayPlayerStatsInBattle(Player* player) {
    displaySeparator(33);
    printf("| %s's %1s       |\n",player->name, player->supemons[0].name);
    displaySeparator(33);
    printf("| HP: %2d/%-2d  Lvl: %-2d          |\n", player->supemons[0].current_hp, player->supemons[0].max_hp, player->supemons[0].level);
    printf("| Atk: %-2d  Def: %-2d          |\n", player->supemons[0].attack, player->supemons[0].defense);
    printf("| Acc: %-2d  Eva: %-2d          |\n", player->supemons[0].accuracy, player->supemons[0].evasion);
    displaySeparator(33);
}

void displaySupemon(Player* player){
    int i;
    for (i = 0; i < player->numSupemons; i++){
        printf("%d -  %s       %d/%d\n",i+1, player->supemons[i].name, player->supemons[i].current_hp, player->supemons[i].max_hp);
    }
}

void playerInventory(Player* player, Item* items) {
    int i;
    printf("Your inventory:\n");
    for (i = 0; i < 4; i++) {
        printf("%d. %s x%d\n", i + 1, items[i].name, player->items[i].quantity);
    }
    printf("\nYou have %d Supecoins.\n", player->supcoins);
}

void initializePlayer(Player* player, char* name) {
    if (player == NULL || name == NULL) {
        printf("Error: Invalid pointers provided to initializePlayer.\n");
        return;
    }

    strncpy(player->name, name, sizeof(player->name) - 1);
    player->name[sizeof(player->name) - 1] = '\0';

    player->supcoins = 0;
    player->numSupemons = 0;
}
void displayItemsInventory(Player*player, Item* items) {
    int i;
    for (i = 0; i < 4; i++) {
        printf("%d. %s x%d\n", i + 1, items[i].name, player->items[i].quantity);
    }
}