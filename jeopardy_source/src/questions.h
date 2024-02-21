#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include <stdbool.h>

#define MAX_LEN 256
#define NUM_CATEGORIES 3
#define NUM_QUESTIONS 12

typedef struct {
    char category[MAX_LEN];
    char question[MAX_LEN];
    char answer[MAX_LEN];
    int value;
    bool answered;
} question;

extern char categories[NUM_CATEGORIES][MAX_LEN];
extern question questions[NUM_QUESTIONS];

extern void initialize_game(void);
extern void display_categories(void);
extern void display_question(char *category, int value);
extern bool valid_answer(char *category, int value, char *answer);
extern bool already_answered(char *category, int value);

#endif /* QUESTIONS_H_ */
