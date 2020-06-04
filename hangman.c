/*
 * Hangman Game.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LIVES          6
#define EMPTY_LETTER '_'
#define PROMPT "GUESS: "

void print_rules(void);
const char* get_random_word(void);
void draw_hangman(int lives);
void draw_word_repr(const char* word_repr);
char get_user_guess(const char* prompt);
void init_word_repr(char* word_repr, int size, int val);

int main(void)
{
    int lives = LIVES;
    const char* word = get_random_word();

    char word_repr[strlen(word) + 1];
    init_word_repr(word_repr, sizeof(word_repr) - 1, EMPTY_LETTER);

    print_rules();

    int ch;
    for (;;) {
        draw_hangman(lives);
        draw_word_repr(word_repr);
        ch = get_user_guess(PROMPT);
        printf("ch is %c\n", ch);
        getchar();
    }

    return 0;
}

char get_user_guess(const char* prompt)
{
    int ch;
    while (printf("%s", prompt) && (ch = getchar()) != EOF) {
        while (getchar() != '\n')
            ;
        if (isalpha(ch))
            return ch;
    }
    return EOF;
}

void init_word_repr(char* word_repr, int size, int val)
{
    memset(word_repr, val, size);
    word_repr[size] = '\0';
}

void print_rules(void)
{
    puts("Rules:");
    puts("I will pick a random word.");
    printf("%s %d %s\n", "You will have", LIVES,
            "attempts to guess it, otherwise you will get hanged.");
    puts("Press any key to begin...");
    getchar();
}

/*
 * Returns a pointer to a random word picked from 'words' array.
 */
const char* get_random_word(void)
{
    srand(time(NULL));
    const char* words[] = {
        "apple",
        "king",
        "lemon",
        "lion",
        "sandwich",
        "quarantine",
        "queue",
        "zebra",
    };

    int rand_pos = rand() % (sizeof(words) / sizeof(words[1]));
    return words[rand_pos];
}

void draw_word_repr(const char* word_repr)
{
    printf("\n%s", "WORD: ");
    for (; *word_repr; ++word_repr)
        printf("%c ", *word_repr);
    puts("");
}

void draw_hangman(int lives)
{
    system("clear");
    switch (lives) {
    case 0:
        puts("|-----");
        puts("|  |  ");
        puts("|  O  ");
        puts("| /|\\");
        puts("| / \\");
        break;
    case 1:
        puts("|-----");
        puts("|  |  ");
        puts("|  O  ");
        puts("| /|\\");
        puts("| /   ");
        break;
    case 2:
        puts("|-----");
        puts("|  |  ");
        puts("|  O  ");
        puts("| /|\\");
        puts("|     ");
        break;
    case 3:
        puts("|-----");
        puts("|  |  ");
        puts("|  O  ");
        puts("| /|  ");
        puts("|     ");
        break;
    case 4:
        puts("|-----");
        puts("|  |  ");
        puts("|  O  ");
        puts("|  |  ");
        puts("|     ");
        break;
    case 5:
        puts("|-----");
        puts("|  |  ");
        puts("|  O  ");
        puts("|     ");
        puts("|     ");
        break;
    case 6:
        puts("|-----");
        puts("|  |  ");
        puts("|     ");
        puts("|     ");
        puts("|     ");
        break;
    }
}
