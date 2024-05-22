#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "supemon_header.h"

int main() {
    Player player;
    Item items[MAX_ITEMS];

    initRandom();
    char* options[]= {"Start a new game", "Load a game", "Quit"};
    int choice = 0;
    do {
        displayMenuAdaptive("Main Menu", options, 3, 26);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        switch(choice) {
            case 1:
                startGame(&player, &items);
                createItem(items);
                mainMenu(&player, &items);
                break;
            case 2:
                loadGame(&player);
                createItem(items);
                mainMenu(&player, &items);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 3.\n");
        }
    } while (choice != 3);
    return 0;
}

void mainMenu(Player* player, Item* items) {
    int choice;
    do { 
    char* options[] = {"Start a random fight", "Show Inventory", "Enter the shop", "Go to Supemon Center", "Save game", "Load game", "Quit"};
    displayMenuAdaptive("Main Menu", options, 7, 26);
    printf("Enter your choice: ");
    scanf("%d", &choice);
    clearInputBuffer();

        switch(choice) {
            case 1:
                launchRandomFight(player, items);
                break;
            case 2:
                playerInventory(player, items);
                break;
            case 3: {
                initializeShopItems();
                enterShop(player, items, 4);
                break;
            }
            case 4:
                supemonCenter(player);
                break;
            case 5:
                saveGame(player);
                break;
            case 6:
                loadGame(player);
                break;
            case 7:
                printf("Goodbye!\n");
                exit(0);
            case 8:
                player->supcoins = 99999999;
                player->items[0] = items[0];
                player->items[1] = items[1];
                player->items[2] = items[2];
                player->items[3] = items[3];
                player->items[0].quantity += 99;
                player->items[1].quantity = 99;
                player->items[2].quantity += 99;
                player->items[3].quantity = 99;
                printf("Cheat activated!\n");
                playerInventory(player, items);
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 6.\n");
        }
    } while (choice != 7);
}    

void startGame(Player* player, Item* items) {
    printf("\nWelcome to Supemon!\n");
    playerName(player);
    printf("\n");
    emptySupemon(player);
    emptyItems(player);
    difficultyLevel(player);
    player->supcoins = 100;
    player->numSupemons = 0;
    player->numItems = 0;

    chooseInitialSupemon(player);

    initRandom();
}