#include "questions.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the array of questions
question questions[NUM_QUESTIONS];

// Initialize the game with sample questions
void initialize_game(void) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        sprintf(questions[i].category, "Category%d", i / (NUM_QUESTIONS / NUM_CATEGORIES) + 1);
        sprintf(questions[i].question, "Sample question %d", i + 1);
        sprintf(questions[i].answer, "Answer to sample question %d", i + 1);
        questions[i].value = (i % (NUM_QUESTIONS / NUM_CATEGORIES) + 1) * 100;
        questions[i].answered = false;
    }
}

// Display remaining categories and their corresponding question values
void display_categories(void) {
    printf("Remaining Categories and Question Values:\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (!questions[i].answered) {
            printf("%s - $%d\n", questions[i].category, questions[i].value);
        }
    }
}

// Display question for the given category and value
void display_question(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("Category: %s  Value: $%d\n", questions[i].category, questions[i].value);
            printf("Question: %s\n", questions[i].question);
            return;
        }
    }
    printf("Question not found.\n");
}

// Check if the answer is valid for the given category and value
bool valid_answer(char *category, int value, char *answer) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (strcmp(questions[i].answer, answer) == 0) {
                return true;
            }
        }
    }
    return false;
}

// Check if the question has already been answered
bool already_answered(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return false;
}
