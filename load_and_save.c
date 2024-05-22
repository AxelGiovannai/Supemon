#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "supemon_header.h"

int loadGame(Player* player){
    FILE *file = fopen("Save/player.sav", "rb");
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }
    fread(player, sizeof(Player), 1, file);
    fclose(file);
    
    displayMenuAdaptive("Game loaded successfully!", NULL, 0, 26);
    return 0;
}


int saveGame(Player* player){
    struct stat statPlayer = {0};

    if (stat("Save", &statPlayer) == -1) {
        if (mkdir("Save", 0700) == -1) {
            perror("Error creating directory Save");
            return 1;
        }
    }

    FILE *file = fopen("Save/player.sav", "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }
    fwrite(player, sizeof(Player), 1, file);
    fclose(file);
    
    displayMenuAdaptive("Game saved successfully!", NULL, 0, 26);
    return 0;
}