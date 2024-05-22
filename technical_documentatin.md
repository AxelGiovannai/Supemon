Supemon Game Technical Documentation
Overview

The Supemon game is a console-based adventure where players capture, battle, and train creatures called Supemons. This documentation provides a comprehensive overview of the game's technical aspects, focusing on its core functionalities including game initialization, player management, item and Supemon handling, saving and loading game states, and combat mechanics.
Files and Modules

The game's source code is divided into several C files, each handling specific aspects of the game:

    main.c: Manages the main game loop, including game start, loading, and navigation through main menus.
    player.c: Contains functions related to player actions such as managing player stats, inventory, and Supemon.
    item.c: Defines item-related functionalities, including item initialization and usage.
    supemon.c: Handles Supemon-related actions such as initialization, leveling up, and move sets.
    shop.c: Implements the shop functionality where players can buy items.
    load_and_save.c: Manages saving and loading game states to and from a file.
    fight.c: Controls combat mechanics between Supemons.
    utils.c: Provides utility functions used across the game, such as input clearing and random number initialization.
    supemon_header.h: Header file declaring structures, constants, and functions used throughout the game.

Core Components
Game Initialization and Main Loop

The game starts in main.c, where the player is presented with options to start a new game, load an existing game, or exit. Based on the selection, the game initializes player and item states or loads them from a file. The main loop then handles navigation through various game menus and functionalities.
Player Management

player.c manages player data, including name, Supemons, items, and stats. Players can view their Supemon and item inventory, select a Supemon for battles, and manage their stats during combat. The player's stats are vital for battles and interacting with different game elements like the shop and Supemon Center.
Item Handling

Items are managed in item.c, where they are initialized, listed, and used. Items can affect Supemons' stats in battles, heal them, or have special effects like reviving a fainted Supemon. The shop functionality in shop.c allows players to purchase items using in-game currency (Supcoins).
Supemon Entities

supemon.c is dedicated to Supemon entities, including their initialization, stats, moves, and leveling up. Supemons are central to the game, as players capture and train them for battles. Each Supemon has unique stats and moves, influencing its performance in combat.
Combat Mechanics

Combat between Supemons is handled in fight.c. Battles allow players to use moves, change active Supemon, use items, attempt to capture wild Supemons, or flee. Combat mechanics involve turn-based decisions, with outcomes influenced by Supemons' stats and chosen moves.
Utility Functions

utils.c includes utility functions such as clearing the input buffer and initializing random numbers. These functions support various aspects of the game, ensuring smooth gameplay and user interaction.
Saving and Loading

The game's state can be saved to and loaded from a file, as managed by load_and_save.c. This functionality allows players to preserve their progress and continue their adventure in subsequent sessions.
Conclusion

This documentation provides an overview of the technical structure and functionalities of the Supemon game. By dividing responsibilities across multiple files and modules, the game achieves a modular and maintainable codebase. This structure facilitates the addition of new features and bug fixes, ensuring a seamless gaming experience.

# Combat Module: fight.c

## Description
The `fight.c` module handles the combat logic in the Supemon game, managing battles between the player's Supemons and opponents. It includes functions for initiating combat, executing player and enemy turns, and resolving battle outcomes.

## Functions

### `void launchRandomFight(Player* player, Item* items)`
Initiates a battle with a randomly chosen enemy Supemon. Prepares the player and the enemy for the fight, setting their stats and moves.

### `void fight(Player* player, Supemon* enemy, Item* items)`
Manages the turn-based combat loop, allowing the player to make decisions such as attacking, using items, or attempting to capture the enemy Supemon.

### `void playerTurn(Player* player, Supemon* enemy, Supemon* supemon, int moveChoice)`
Processes the player's turn based on the selected action: attack, use item, switch Supemon, attempt capture, or flee.

### `void performMove(Supemon *attacker, Supemon *defender, int moveIndex)`
Executes the specified move of the attacking Supemon against the defender, calculating damage or applying effects based on the move's properties.

### `void enemyTurn(Supemon* enemy, Supemon* playerSupemon)`
Automatically decides and performs an action for the enemy Supemon during its turn, using a simple AI logic.

## Constants

### `int MAX_MOVES`
Defines the maximum number of moves a Supemon can have. Essential for managing the array sizes of moves in combat logic.
# Supemon Module: supemon.c

## Description
The `supemon.c` file encompasses the functionality related to Supemon entities within the game. It includes the logic for initializing Supemons, choosing the player's initial Supemon, managing Supemon moves and battles, and various utility functions to support Supemon attributes and actions.

## Functions

### `void initializeSupemon(Supemon* supemon, char* name, int level, int experience, int current_hp, int max_hp, int attack, int base_attack, int defense, int base_defense, int evasion, int base_evasion, int accuracy, int base_accuracy, int speed, int isCaptured)`
Initializes a Supemon's attributes based on provided parameters, setting up its stats and battle capabilities.

### `void chooseInitialSupemon(Player* player)`
Allows the player to choose their initial Supemon from a selection of available Supemons, setting up the player's starting companion.

### `void initializeSupemonMoves(Supemon* supemon, int supemonType)`
Sets up the moves for a Supemon based on its type, enabling it to perform actions during battles.

### `void levelUpSupemon(Player* player, Supemon* supemon)`
Calculates and applies experience points towards a Supemon's growth, handling the leveling up process and stat increases.

### `void captureSupemon(Player* player, Supemon* enemy)`
Handles the logic for attempting to capture wild Supemons during encounters, incorporating them into the player's roster if successful.

### `void healSupemon(int heal, Supemon* supemon)`
Applies healing to a Supemon, restoring its health points up to its maximum capacity.

### `void supemonCenter(Player* player)`
Represents a facility where the player can heal their Supemons for a fee, fully restoring their health points and preparing them for further adventures.

## Constants

### `int MAX_SUPEMON`
Defines the maximum number of Supemons a player can have in their roster, impacting gameplay and strategic decisions.

### `int MAX_MOVES`
Specifies the maximum number of moves a Supemon can learn, dictating the diversity and strategy in battles.

## Dependencies

- `supemon_header.h`: This header file is crucial for `supemon.c`, providing the necessary structure definitions, function prototypes, and constants that enable the manipulation and management of Supemons within the game.

# Item Module: item.c

## Description
The `item.c` file is dedicated to managing the item system within the Supemon game. It includes functionalities for initializing game items, managing their effects, and handling interactions between items and Supemons or the player. Items play a crucial role in the game, providing healing, stat boosts, or other benefits to assist the player in their journey.

## Functions

### `Item* initializeShopItems()`
- **Description**: Initializes the shop's inventory with predefined items available for purchase by the player.
- **Returns**: A static array of `Item` structures, each representing a different item that can be bought.

### `void initializeItems(Item* item, const char* name, int itemID, int price, int quantity)`
- **Description**: Sets the attributes for an individual item, including its name, ID, price, and initial quantity.
- **Parameters**:
  - `Item* item`: Pointer to the item to be initialized.
  - `const char* name`: The name of the item.
  - `int itemID`: The unique identifier for the item.
  - `int price`: The purchase price of the item.
  - `int quantity`: The initial quantity of the item.

### `void createItem(Item* items)`
- **Description**: A utility function that calls `initializeItems` for each item to be created and added to the game's inventory or shop.
- **Parameters**:
  - `Item* items`: Array of items to be initialized.

### `void usePotion(Player* player, Supemon* supemon)`
- **Description**: Applies the effects of a Potion item to a specified Supemon, healing it.
- **Parameters**:
  - `Player* player`: The player using the item.
  - `Supemon* supemon`: The Supemon on which the item is used.

### `void useSuperPotion(Player* player, Supemon* supemon)`, `void usePhenixTail(Player* player, Supemon* supemon)`, `void useRareCandy(Player* player, Supemon* supemon)`
- **Description**: Similar to `usePotion`, these functions apply the effects of more powerful or specialized items, such as Super Potions, Phenix Tails, and Rare Candies, providing stronger healing, reviving fainted Supemons, or boosting their level, respectively.

### `void selectItem(Player* player, Item* items)`
- **Description**: Presents the player with a list of their items and allows them to select one to use.
- **Parameters**:
  - `Player* player`: The player selecting the item.
  - `Item* items`: The player's inventory of items.

## Constants

### `MAX_ITEMS`
- **Description**: Defines the maximum number of different items that can be stored in the player's inventory or the game's item system.

## Dependencies

- `supemon_header.h`: This header file is essential for `item.c`, as it provides the definitions for the `Player`, `Supemon`, and `Item` structures, along with necessary function prototypes and constants used throughout the item management system.

# Shop Module: shop.c

## Description
The `shop.c` file manages the in-game shop where players can purchase items for use in their adventure. This module integrates closely with the game's item system, allowing for dynamic interaction between the player and the shop's inventory.

## Functions

### `void displayItems(Item* items, int numItems, Player* player)`
- **Description**: Displays the items available for purchase in the shop, including their names, prices, and a prompt for the player to make a selection.
- **Parameters**:
  - `Item* items`: The array of items available in the shop.
  - `int numItems`: The number of items available.
  - `Player* player`: The player interacting with the shop.

### `void enterShop(Player* player, Item* items, int numItems)`
- **Description**: Manages the player's interaction with the shop, allowing them to view and purchase items.
- **Parameters**:
  - `Player* player`: The player entering the shop.
  - `Item* items`: The array of items available in the shop.
  - `int numItems`: The number of items available for purchase.

### `void buyItem(Player* player, Item* items, int itemNumber, int quantity)`
- **Description**: Handles the logic for purchasing an item, including deducting the cost from the player's currency and adding the item to the player's inventory.
- **Parameters**:
  - `Player* player`: The player buying the item.
  - `Item* items`: The array of available items.
  - `int itemNumber`: The index of the item being purchased.
  - `int quantity`: The quantity of the item being purchased.

## Dependencies

- `supemon_header.h`: This header file is crucial for `shop.c`, providing the necessary structure definitions (`Player` and `Item`), function prototypes, and constants that enable the shopping functionality within the game.

# Player Module: player.c

## Description
The `player.c` file encompasses the functionalities related to the player's interactions within the Supemon game. This module includes player initialization, inventory management, displaying player and Supemon stats, and other player-centric actions.

## Functions

### `void playerName(Player* player)`
- **Description**: Prompts the player to enter their name, which is then stored within the player's data structure.
- **Parameters**:
  - `Player* player`: The player whose name is being set.

### `void displayPlayerStatsInBattle(Player* player)`
- **Description**: Displays the stats of the player's active Supemon during battle, including health points, level, and combat stats.
- **Parameters**:
  - `Player* player`: The player whose Supemon's stats are being displayed.

### `void displaySupemon(Player* player)`
- **Description**: Lists all Supemons currently owned by the player, along with their health status.
- **Parameters**:
  - `Player* player`: The player whose Supemon roster is being displayed.

### `void playerInventory(Player* player, Item* items)`
- **Description**: Displays the items currently held by the player, including item quantities and other relevant details.
- **Parameters**:
  - `Player* player`: The player whose inventory is being displayed.
  - `Item* items`: The array of items to display from the player's inventory.

### `void initializePlayer(Player* player, char* name)`
- **Description**: Initializes the player's profile, setting the name and default values for other attributes like Supcoins and inventory slots.
- **Parameters**:
  - `Player* player`: The player being initialized.
  - `char* name`: The name to assign to the player.

### `void displayItemsInventory(Player* player, Item* items)`
- **Description**: Similar to `playerInventory`, but focused specifically on displaying the player's item inventory for selection during gameplay.
- **Parameters**:
  - `Player* player`: The player whose item inventory is being displayed.
  - `Item* items`: The array of items in the player's possession.

## Dependencies

- `supemon_header.h`: This header file is vital for `player.c`, as it provides the definitions for the `Player`, `Supemon`, and `Item` structures, along with the necessary function prototypes and constants used throughout the player management system.

# Utility Module: utils.c

## Description
The `utils.c` file contains auxiliary functions that support various features throughout the Supemon game. These utilities include random number generation, input clearing, and display formatting, which are essential for smooth gameplay and user interface management.

## Functions

### `void initRandom()`
- **Description**: Initializes the random number generator used in the game. This function should be called at the start of the program to ensure that random values generated throughout the game are unpredictable.
- **Usage**: Called at the beginning of the game to seed the random number generator.

### `void clearInputBuffer()`
- **Description**: Clears the input buffer to prevent unwanted characters from affecting subsequent input operations. This function is particularly useful after taking input with `scanf` to remove any remaining newline characters.
- **Usage**: Called after input operations to clean up the input buffer.

### `void displaySeparator(int length)`
- **Description**: Prints a horizontal separator line of a specified length. This utility function enhances the visual layout of the game's text-based interface.
- **Parameters**:
  - `int length`: The length of the separator line.
- **Usage**: Used in various parts of the game to separate sections of text for better readability.

### `void displaySeparatorWithSpace(int length, int space)`
- **Description**: Extends `displaySeparator` by adding a specified amount of space before printing the separator line, allowing for more complex formatting in the game's UI.
- **Parameters**:
  - `int length`: The length of the separator line.
  - `int space`: The amount of space (in characters) to insert before the separator line.
- **Usage**: Useful for creating indented or aligned text layouts in the game interface.

### `void printTwoFormattedLines(const char* leftBuffer, const char* rightBuffer)`
- **Description**: Prints two lines of text side by side, formatted within a set width. This function is used to display stats or options in a dual-column format.
- **Parameters**:
  - `const char* leftBuffer`: The text to display on the left side.
  - `const char* rightBuffer`: The text to display on the right side.
- **Usage**: Employed in battle screens, inventory management, or anywhere else that requires a comparative or dual-column display of information.

## Dependencies
No specific dependencies are required for the `utils.c` file as it provides foundational support functions that do not directly depend on game-specific structures or headers. However, it is implicitly linked with the overall project through its utility functions being called across various modules.

# Save and Load Module: load_and_save.c

## Description
The `load_and_save.c` file is responsible for the persistence mechanism in the Supemon game. It includes functions to save the current state of the player's game to a file and load it back, allowing players to resume their progress at a later time.

## Functions

### `int saveGame(Player* player)`
- **Description**: Saves the current game state, including player and Supemon information, to an external file.
- **Parameters**:
  - `Player* player`: The player whose game state is being saved.
- **Returns**: An integer indicating success (0) or failure (1) of the save operation.
- **Usage**: Called when the player chooses to save their game.

### `int loadGame(Player* player)`
- **Description**: Loads a previously saved game state from a file, restoring the player's progress.
- **Parameters**:
  - `Player* player`: The player structure where the loaded game state will be stored.
- **Returns**: An integer indicating success (0) or failure (1) of the load operation.
- **Usage**: Called at the start of the game or when the player selects to load a saved game.

## Dependencies

- `supemon_header.h`: This header file is essential for `load_and_save.c`, as it provides the definitions for the `Player` structure along with necessary constants and function prototypes. It ensures that the save and load functions can access and manipulate the player's data correctly.

# Main Module: main.c

## Description
The `main.c` file serves as the entry point for the Supemon game. It orchestrates the initial setup, including displaying the main menu, handling user selections for starting a new game, loading an existing game, or exiting. This module integrates various components of the game to provide a seamless player experience.

## Functions

### `int main()`
- **Description**: The main function initializes the game environment, displays the main menu, and processes player inputs for navigating through the game's options.
- **Returns**: An integer indicating the exit status of the program, where `0` signifies a successful termination.

### `void mainMenu(Player* player, Item* items)`
- **Description**: Displays the main menu of the game and handles the player's navigation through starting a new game, loading a game, entering the shop, managing inventory, and saving or loading the game state.
- **Parameters**:
  - `Player* player`: The player engaging with the main menu.
  - `Item* items`: The array of items available in the game, used when the player accesses the shop or inventory.
- **Usage**: Called within the `main` function to present the primary game options to the player.

### `void startGame(Player* player, Item* items)`
- **Description**: Initializes a new game session by setting up the player's starting conditions, including choosing an initial Supemon and allocating starting items or resources.
- **Parameters**:
  - `Player* player`: The player starting a new game.
  - `Item* items`: The array of items to be initialized for the new game session.
- **Usage**: Invoked when the player selects to start a new game from the main menu.

## Dependencies

- `supemon_header.h`: This header file is critical for `main.c`, providing the necessary structure definitions (`Player` and `Item`), function prototypes, and constants that enable the game's core functionality and integration of different modules.

# Header File: supemon_header.h

## Description
The `supemon_header.h` file contains declarations for structures, constants, and function prototypes used across the Supemon game, especially within the `fight.c` module.

## Structures

### `typedef struct Supemon`
Defines the attributes of a Supemon, including health points, attack, defense, and special moves.

### `typedef struct Player`
Represents the player, including their inventory of Supemons and items.

## Functions

### `void initializeSupemonMoves(Supemon* supemon, int supemonType)`
Initializes the moveset of a Supemon based on its type.

### `void captureSupemon(Player* player, Supemon* enemy)`
Attempts to capture an enemy Supemon, adding it to the player's roster if successful.

## Constants

### `int MAX_SUPEMON`
Specifies the maximum number of Supemons a player can hold at any time, impacting the size of the player's Supemon array.

## Dependencies
- `supemon_header.h`: This header is crucial for `fight.c`, providing necessary structure definitions and function prototypes to enable combat mechanics.

