#include "../includes/game.h"

void displayMainMenu()
{
    puts("# Welcome to Animals! #\n");
}

void displayCharacterCreationMenu()
{
    puts("# Choose your class! #\n");

    puts("Fat Cat:");
    puts("\tSturdy fellow, can take a punch, but not very agile\n");

    puts("Slim Cat:\n");
    puts("\tSlim fellow, fragile, but with very shap claws.\n");
}

void startFight(Animal *player, Animal *enemy, int window_width)
{
    float total_spaces = (window_width - strlen(player->name) - strlen(enemy->name) - strlen("vs"));
    float left_spaces = roundf(total_spaces / 8);
    float mid_spaces = roundf(total_spaces / 8 * 3);

    printSpaces(left_spaces);
    printf("%s", player->name);
    printSpaces(mid_spaces);
    printf("vs");
    printSpaces(mid_spaces);
    printf("%s\n", enemy->name);
    printCentered("FIGHT!", window_width);
    puts("");
    /* const char header[] = 
    int count = 
    count += strlen(player->name) + strlen(enemy->name);
    printSpaces();
    printf("%s vs %s...", player->name, enemy->name);
    puts("FIGHT!\n"); */
}

void printCentered(const char* text, unsigned int window_width)
{
    int count = (window_width - strlen(text)) / 2;
    printSpaces(count);
    puts(text);
}

void printCenteredNoNewline(const char* text, unsigned int window_width)
{
    int count = (window_width - strlen(text)) / 2;
    printSpaces(count);
    printf(text);
}

void printSpaces(unsigned int num)
{
    for (int i = 0; i < num; i++)
    {
        printf(" ");
    }
}