#include <stdio.h>
#include <string.h>
#include "supemon_header.h"

Item *initializeShopItems()
{
    static Item items[MAX_ITEMS] = {
        {"Potion",1, 100},
        {"Super Potion",2, 300},
        {"Phenix Tail",3, 500},
        {"Rare Candy",4, 700},
    };
    return items;
}

void initializeItems(Item* item, const char* name, int itemID ,int price, int quantity)
{
    if (item == NULL)
    {
        printf("Error: Invalid pointers provided to initializeItems.\n");
        return;
    }

    strncpy(item->name, name, sizeof(item->name) - 1);
    item->name[sizeof(item->name) - 1] = '\0';
    item->itemID = itemID;
    item->price = price;
    item->quantity = quantity;
    item->sellPrice = price / 2;
}

void createItem(Item* items)
{
    initializeItems(&items[0], "Potion", 1, 100, 0);
    initializeItems(&items[1], "Super Potion", 2, 300, 0);
    initializeItems(&items[2], "Phenix Tail", 3, 500, 0);
    initializeItems(&items[3], "Rare Candy", 4, 700, 0);
}

void usePotion(Player *player, Supemon *supemon)
{   
    displaySupemon(player);
    printf("Choose a Supemon to use the Potion on: ");
    int choice;
    scanf("%d", &choice);
    clearInputBuffer();

    if (player->supemons[choice - 1].current_hp == player->supemons[choice - 1].max_hp)
    {
        printf("%s is already at full health!\n", player->supemons[choice - 1].name);
        return;
    } else if (player->items[0].quantity == 0)
    {
        printf("You don't have any Potions left!\n");
        return;
    }else if (player->supemons[choice - 1].current_hp == 0)
    {
        printf("%s has fainted and can't use a Potion!\nUse a Phenix Tail or go to Supemon Center to heal him\n", player->supemons[choice - 1].name);
        return;
    } 
    else {
        player->supemons[choice - 1].current_hp += 5;
        if (player->supemons[choice - 1].current_hp > player->supemons[choice - 1].max_hp)
        {
            player->supemons[choice - 1].current_hp = player->supemons[choice - 1].max_hp;
        }
        player->items[0].quantity--;
    }

    printf("%s used a Potion on %s. %s's HP is now %d/%d.\n", player->name, player->supemons[choice - 1].name, player->supemons[choice - 1].name, player->supemons[choice - 1].current_hp, player->supemons[choice - 1].max_hp);
}
void useSuperPotion(Player *player, Supemon *supemon)
{
    displaySupemon(player);
    printf("Choose a Supemon to use the Super Potion on: ");
    int choice;
    scanf("%d", &choice);
    clearInputBuffer();

    if (player->supemons[choice - 1].current_hp == player->supemons[choice - 1].max_hp)
    {
        printf("%s is already at full health!\n", player->supemons[choice - 1].name);
        return;
    } else if (player->items[1].quantity == 0)
    {
        printf("You don't have any Super Potions left!\n");
        return;
    }else if (player->supemons[choice - 1].current_hp == 0)
    {
        printf("%s has fainted and can't use a Super Potion!\nUse a Phenix Tail or go to Supemon Center to heal him\n", player->supemons[choice - 1].name);
        return;
    } 
    else {
        player->supemons[choice - 1].current_hp += 10;
        if (player->supemons[choice - 1].current_hp > player->supemons[choice - 1].max_hp)
        {
            player->supemons[choice - 1].current_hp = player->supemons[choice - 1].max_hp;
        }
        player->items[1].quantity--;
    }

    printf("%s used a Super Potion on %s. %s's HP is now %d/%d.\n", player->name, player->supemons[choice - 1].name, player->supemons[choice - 1].name, player->supemons[choice - 1].current_hp, player->supemons[choice - 1].max_hp);
}
void usePhenixTail(Player *player, Supemon *supemon)
{
    displaySupemon(player);
    printf("Choose a Supemon to use the Phenix Tail on: ");
    int choice;
    scanf("%d", &choice);
    clearInputBuffer();

    if (player->supemons[choice - 1].current_hp != 0)
    {
        printf("%s is still ready to fight !\n", player->supemons[choice - 1].name);
        return;
    } else if (player->items[2].quantity == 0)
    {
        printf("You don't have any Phenix Tails left!\n");
        return;
    }else if (player->supemons[choice - 1].current_hp == 0)
    {
        player->supemons[choice - 1].current_hp = player->supemons[choice - 1].max_hp;
        player->items[2].quantity--;
        printf("%s used a Phenix Tail on %s. %s's HP is now %d/%d.\n", player->name, player->supemons[choice - 1].name, player->supemons[choice - 1].name, player->supemons[choice - 1].current_hp, player->supemons[choice - 1].max_hp);
        return;
    } 
    else {
        player->supemons[choice - 1].current_hp = player->supemons[choice - 1].max_hp;
        player->items[2].quantity--;
    }

    printf("%s used a Phenix Tail on %s. %s's HP is now %d/%d.\n", player->name, player->supemons[choice - 1].name, player->supemons[choice - 1].name, player->supemons[choice - 1].current_hp, player->supemons[choice - 1].max_hp);
}

void useRareCandy(Player *player, Supemon *supemon)
{
    displaySupemon(player);
    printf("Choose a Supemon to use the Rare Candy on: ");
    int choice;
    scanf("%d", &choice);
    clearInputBuffer();

    if (player->items[3].quantity == 0)
    {
        printf("You don't have any Rare Candies left!\n");
        return;
    } else {
        player->supemons[choice - 1].level++;
        increaseStatsBy30Percent(&player->supemons[choice - 1]);
        player->items[3].quantity--;
    }

    printf("%s used a Rare Candy on %s. %s's level is now %d.\n", player->name, player->supemons[choice - 1].name, player->supemons[choice - 1].name, player->supemons[choice - 1].level);
}

void selectItem(Player *player, Item *items)
{
    displayItemsInventory(player, items);
    printf("\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    clearInputBuffer();

    switch (choice)
    {
        case 1:
            usePotion(player, &player->supemons[0]);
            break;
        case 2:
            useSuperPotion(player, &player->supemons[0]);
            break;
        case 3:
            usePhenixTail(player, &player->supemons[0]);
            break;
        case 4:
            useRareCandy(player, &player->supemons[0]);
            break;
        default:
            break;
    }


    printf("You have left the shop.\n");
}