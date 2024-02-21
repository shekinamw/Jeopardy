// questions.c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "questions.h"

question questions[NUM_QUESTIONS];

void initialize_game(void) {
    // Sample questions initialization
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        sprintf(questions[i].category, "Category%d", i / (NUM_QUESTIONS / NUM_CATEGORIES) + 1);
        sprintf(questions[i].question, "Sample question %d", i + 1);
        sprintf(questions[i].answer, "Answer to sample question %d", i + 1);
        questions[i].value = (i % (NUM_QUESTIONS / NUM_CATEGORIES) + 1) * 100;
        questions[i].answered = false;
    }
}

void display_categories(void) {
    // Display categories and values
    printf("Categories:\n");
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("%s\n", categories[i]);
    }
}

void display_question(char *category, int value) {
    // Display question for the given category and value
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("Category: %s  Value: $%d\n", questions[i].category, questions[i].value);
            printf("Question: %s\n", questions[i].question);
            return;
        }
    }
    printf("Question not found.\n");
}

bool valid_answer(char *category, int value, char *answer) {
    // Check if the answer is valid
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (strcmp(questions[i].answer, answer) == 0) {
                return true;
            }
        }
    }
    return false;
}

bool already_answered(char *category, int value) {
    // Check if the question has been answered
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return false;
}