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
    // Array to hold players
    player players[NUM_PLAYERS];

    // Input buffer
    char buffer[BUFFER_LEN];

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players' names
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        fgets(buffer, BUFFER_LEN, stdin);
        strtok(buffer, "\n"); // Remove newline character
        strcpy(players[i].name, buffer);
        players[i].score = 0;
    }

    // Game loop
    while (true) {
        // Display categories and remaining questions
        display_categories();

        // Prompt for player's choice
        char selected_player[BUFFER_LEN];
        printf("\nEnter the name of the player who selects the question: ");
        fgets(buffer, BUFFER_LEN, stdin);
        strtok(buffer, "\n"); // Remove newline character
        strcpy(selected_player, buffer);

        // Validate player's name
        if (!player_exists(players, NUM_PLAYERS, selected_player)) {
            printf("Invalid player name. Please enter a valid player's name.\n");
            continue;
        }

        // Prompt for category and value
        char selected_category[BUFFER_LEN];
        int selected_value;
        printf("Enter the category and value of the question (e.g., programming 100): ");
        scanf("%s %d", selected_category, &selected_value);

        // Check if the question has already been answered
        if (already_answered(selected_category, selected_value)) {
            printf("This question has already been answered. Please select another one.\n");
            continue;
        }

        // Display the question
        display_question(selected_category, selected_value);

        // Prompt for the answer
        printf("Enter your answer (starting with 'what is' or 'who is'): ");
        fgets(buffer, BUFFER_LEN, stdin);
        strtok(buffer, "\n"); // Remove newline character

        // Check if the answer is correct
        if (valid_answer(selected_category, selected_value, buffer)) {
            printf("Correct!\n");
            // Update player's score
            update_score(players, NUM_PLAYERS, selected_player, selected_value);
        } else {
            printf("Incorrect! The answer is: %s\n", get_answer(selected_category, selected_value));
        }

        // Mark the question as answered
        mark_answered(selected_category, selected_value);

        // Check if all questions have been answered
        if (all_questions_answered()) {
            break;
        }
    }

    // Display final results
    printf("\nFinal results:\n");
    show_results(players, NUM_PLAYERS);

    return 0;
}

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens) {
    // Tokenize the input string and store the tokens in the tokens array
    char *token = strtok(input, " "); // Tokenize by space
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
    // Sort the players by score (you need to implement this)
    // Then display each player's name and score
    printf("Game Results:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}
