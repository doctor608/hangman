/*
 * Hangman Game.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LIVES 6

const char* get_random_word(void);
void draw_hangman(int lives);

int main(void)
{
    int lives = LIVES;
    const char* word = get_random_word();

    for (;;) {
        draw_hangman(lives);
        draw_word()
        getchar();
    }

/*//      int len = strlen(argv[1]);*/

/*//      int ch;*/
/*//      ch = getchar(argv[1]);*/

/*//      while (ch != EOF)*/
/*//              if_symbols(ch, word[]);*/

    return 0;
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

void draw_hangman(int lives)
{
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
/*void check_symbol(char c, char word[])*/
/*{*/
    /*int len = strlen(word);*/
    /*int num = 0;*/

    /*for (int i = 0; i < len; ++i)*/
    /*        if (c == word[i]) {*/
    /*                for (int j = 0; j < i; ++j) {*/
    /*                        putchar(' ');*/

    /*                printf("%c", c);*/
    /*                break;*/
    /*                }*/
    /*        }*/
    /*        else {*/
    /*        ++num;*/
    /*        }*/
