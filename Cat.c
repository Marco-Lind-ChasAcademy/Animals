#include "Cat.h"

Cat *initCat(char *name)
{
    char *sound = "Meow!";
    char *species = "Cat";
    unsigned int weight = randNum(1, 10);
    unsigned int height = randNum(10, 30);
    unsigned int speed = randNum(25, 50);
    unsigned int strength = randNum(1, 10);
    unsigned int hp = randNum(5, 100);
    unsigned int claw_length = randNum(3, 10);

    Cat *cat = malloc(sizeof(Cat));
    if (cat == NULL)
    {
        puts("ALLOCATION FAILED");
        return 0;
    }
    
    cat->claw_length = claw_length;

    cat->base = initAnimal(name, weight, height, sound, speed, species, strength, hp);
    if (cat->base == NULL)
    {
        free(cat);
        return 0;
    }

    return cat;
}

void deInitCat(Cat **cat)
{
    deInitAnimal(&(*cat)->base);
    free(*cat);
    *cat = NULL;
}

void displayCatInfo(Cat *cat)
{
    displayAnimalInfo(cat->base);
    printf("%s claw length: %u mm\n", cat->base->species, cat->claw_length);
    puts("");
}

unsigned int catCrazyClawSlash(Cat *attacker, Animal *victim)
{
    unsigned int damage = 0;
    unsigned int max = attacker->base->strength * attacker->claw_length;
    damage = randNum(attacker->base->strength * 10, max);
    victim->hp -= damage;

    printf("%s slashes like crazy, hitting %s\n\n", attacker->base->name, victim->name);

    if (victim->hp == 0)
    {
        printf("%s fainted...\n\n", victim->name);
    }
    

    return damage;
}