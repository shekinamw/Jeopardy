// jeopardy.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

#define BUFFER_LEN 256
#define NUM_PLAYERS 4

void tokenize(char *input, char **tokens);
void show_results(player *players, int num_players);

int main(int argc, char *argv[]) {
    player players[NUM_PLAYERS];
    char buffer[BUFFER_LEN] = { 0 };

    initialize_game();

    // Prompt for players names
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter the name of Player %d: ", i + 1);
        fgets(players[i].name, MAX_LEN, stdin);
        strtok(players[i].name, "\n");
        players[i].score = 0;
    }

    while (fgets(buffer, BUFFER_LEN, stdin) != NULL) {
        char *tokens[BUFFER_LEN];
        tokenize(buffer, tokens);
        char *command = tokens[0];

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "display") == 0) {
            display_categories();
        } else if (strcmp(command, "choose") == 0) {
            char *category = tokens[1];
            int value = atoi(tokens[2]);
            if (!already_answered(category, value)) {
                display_question(category, value);
                char answer[MAX_LEN];
                printf("Your answer: ");
                fgets(answer, MAX_LEN, stdin);
                strtok(answer, "\n");
                if (valid_answer(category, value, answer)) {
                    printf("Correct!\n");
                    players[rand() % NUM_PLAYERS].score += value;
                } else {
                    printf("Incorrect! The answer is: %s\n", get_answer(category, value));
                }
                mark_answered(category, value);
            } else {
                printf("This question has already been answered.\n");
            }
        }
    }

    show_results(players, NUM_PLAYERS);

    return EXIT_SUCCESS;
}