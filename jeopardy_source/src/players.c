// players.c
#include <stdio.h>
#include <stdbool.h>
#include "players.h"

bool player_exists(player *players, int num_players, char *name) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

void update_score(player *players, int num_players, char *name, int score) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].score += score;
            break;
        }
    }
}