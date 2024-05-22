#ifndef SUPEMON_HEADER_H
#define SUPEMON_HEADER_H

#define MAX_MOVES 4
#define MAX_NAME_LENGTH 20
#define MAX_QUANTITY 99
#define MAX_ITEMS 6 
#define MAX_SUPEMON 5

typedef struct Move {
    char name[20];
    int damage; 
    char statAffected[10]; 
    int statEffect; 
} Move;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int level;
    int experience;
    int current_hp;
    int max_hp;
    int attack;
    int baseAttack;
    int defense;
    int baseDefense;
    int evasion;
    int baseEvasion;
    int accuracy;
    int baseAccuracy;
    int speed;
    int numMoves;
    int isCaptured;
    Move moves[MAX_MOVES];
} Supemon;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Supemon supemon;
} Enemy;


typedef struct {
    char name[MAX_NAME_LENGTH];
    int itemID;
    int quantity;
    int quantityMax[MAX_QUANTITY];
    int price;
    int sellPrice;
    int amount;
    int maxAmount[MAX_ITEMS];
} Item;   

typedef struct {
    char name[MAX_NAME_LENGTH];
    int supcoins;
    int numSupemons;
    int numItems;
    int difficulty;
    Supemon supemons[MAX_SUPEMON];
    Item items[MAX_ITEMS];
} Player;
void clearInputBuffer();
void playerName(Player* player);
void difficultyLevel(Player* player);
void displaySeparator(int length);
void displayMoves(Supemon* supemon);
void initializeSupemonMoves(Supemon* supemon, int supemonType);
void initializeSupemon(Supemon* supemon, char* name, int level, int experience, int current_hp, int max_hp, int attack, int base_attack, int defense, int base_defense, int evasion, int base_evasion, int accuracy, int base_accuracy, int speed, int isCaptured);
void chooseInitialSupemon(Player* player);
int loadGame(Player* player);
int saveGame(Player* player);
void enterShop(Player* player, Item* items, int numItems);
void startCombat(Player* player, Supemon* enemy);
void playerTurn(Player* player, Supemon* enemy, Supemon* supemon, int move_choice);
void enemyTurn(Supemon* playerSupemon, Supemon* enemy);
void increaseStatsBy30Percent(Supemon *supemon);
void levelUpSupemonHard(Supemon *supemon);
void levelUpSupemonEasy(Supemon *supemon);
void levelUpSupemon(Player *player, Supemon *supemon);
void launchRandomFight(Player* player,  Item* items);
void mainMenu(Player* player, Item* items);
void displaySupemonStats(Supemon* supemon);
void displayPlayerStatsInBattle(Player* player);
void initRandom();
void gainExperience(Supemon* supemon, int experience);
void performMove(Supemon *attacker, Supemon *defender, int move);
void usePotion(Player* player, Supemon* supemon);
void useEther(Supemon* supemon);
void startGame(Player* player, Item* items);
void fight(Player* player, Supemon* enemy, Item* items);
void buyItem(Player* player,Item* items, int itemNumber, int quantity);
void displayItems(Item* items, int numItems, Player* player);
void playerInventory(Player* player, Item* items);
void displayEnemyStats(Supemon* enemy);
void displayMenuOptions();
void displayMoveOptions();
Item* initializeShopItems();
void createItem(Item* items);
void initializeItems(Item *item, const char* name, int itemID ,int price, int quantity);
void displaySeparatorWithSpace(int length, int space);
void displayStatsSideBySide(Player* player, Supemon* enemy);
void printTwoFormattedLines(const char* leftFormat, const char* rightFormat);
void displayCombinedStats(Supemon* enemy, Player* player);
void displaySupemon(Player* player);
void captureSupemon(Player* player, Supemon* enemy);
void emptySupemon(Player* player);
void emptyItems(Player* player);
void displayMenu(const char* title, char* options[], int numOptions);
void displayMenuAdaptive(const char* title, char* options[], int numOptions, int stringWidth);
void healSupemon(int heal, Supemon* supemon);
void usePotion(Player* player, Supemon* supemon);
void selectSupemon(Player* player, Supemon* Supemon);
void selectItem(Player *player, Item *items);
void displayItemsInventory(Player*player, Item* items);
void useSuperPotion(Player *player, Supemon *supemon);
void supemonCenter(Player *player);
void usePhenixTail(Player *player, Supemon *supemon);
void useRareCandy(Player *player, Supemon *supemon);


void cheatExperience(Player* player, int experience);


#endif 
