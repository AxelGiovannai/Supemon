#include <stdio.h>
#include "supemon_header.h"

void displayItems(Item* items, int numItems, Player* player) {
    printf("Items available in the shop:\n");
    int i;
    for (i = 0; i < numItems; i++) {
        printf("%d. %s - Price: %d\n", items[i].itemID, items[i].name, items[i].price);
    }
    printf("\n%d. Exit\n", numItems + 1);

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    clearInputBuffer();

    if (choice > 0 && choice <= numItems) {
        Item selected = items[choice - 1];
        printf("%s: %d Supcoins each. How many would you like to buy? (Max: %d)\n", selected.name, selected.price, items[choice - 1].quantityMax);
        int quantityToBuy;
        scanf("%d", &quantityToBuy);
        clearInputBuffer();
        if (quantityToBuy > player->items[choice - 1].quantityMax - player->items[choice - 1].quantity) {
            printf("You can't get that much %s!\n", selected.name);
        } else if (quantityToBuy > 0) {
            buyItem(player, items, choice - 1, quantityToBuy);
        } else {
            printf("Invalid quantity.\n");
        }
    } else if (choice == numItems + 1) {
        printf("Exiting shop.\n");
    } else {
        printf("Invalid choice. Please enter a number from 1 to %d.\n", numItems + 1);
    }
}

void enterShop(Player* player, Item* items, int numItems) {
    displayItems(items, numItems, player);
    
    printf("You have left the shop.\n");
}

void buyItem(Player* player,Item* items, int itemNumber, int quantity){
    if (player->supcoins < items[itemNumber].price * quantity && player->items[itemNumber].quantity + quantity > player->items[itemNumber].quantityMax) {
        printf("You don't have enough Supcoins to buy that item.\n");
        return;
    } else {
        int actualQuantity = player->items[itemNumber].quantity; 
        player->supcoins -= items[itemNumber].price * quantity;
        player->items[itemNumber] = items[itemNumber];
        player->items[itemNumber].quantity += quantity;
    }
    printf("You have bought the item.\n");
}
